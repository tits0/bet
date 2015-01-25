#include "pgdbcommon.h"


ERROR_CODES_BACCT CreateGetgain(soci::session& sql) {

    try
    {

      sql << " DROP FUNCTION IF EXISTS  getgain(IN Poptid bet.opt_id%TYPE, IN Psid bet.s_id%TYPE); \
        CREATE FUNCTION getgain(IN Poptid bet.opt_id%TYPE, IN Psid bet.s_id%TYPE) RETURNS numeric AS  $$ \
        DECLARE \
            Curr_Qseq_id bigint; \
            Qsid bet.s_id%TYPE;  \
            QPlaced numeric;   \
            QGrandtotal numeric;  \
            QOpttotal numeric;  \
            Qgain numeric;    \
        BEGIN                \
        Poptid = Poptid-1;   \
        if Poptid<0  THEN    \
            return -1;       \
        END IF;              \
        if  Poptid> 20 THEN  \
            return -1;       \
        END IF;              \
        select opttotal, placed INTO QOpttotal, QPlaced from options where s_id=Psid and opt_id=Poptid; \
        select total INTO  Qtotal from scheme where scheme.s_id= Psid; \
        RAISE NOTICE 'Qtotal here is %', Qtotal; \
        Qgain = Qtotal - QOpttotal;  \
        return Qgain;    \
        END;   \
        $$ LANGUAGE plpgsql; ";

    }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return ERROR_OTHER;
    }    
    return ERROR_OK;
   
}


ERROR_CODES_BACCT CreateCalculateRewards(soci::session& sql) {

    try
    {
      sql << " \
        drop FUNCTION IF EXISTS CalcRewards(IN Poptid bet.opt_id%TYPE, IN Psid bet.s_id%TYPE); \
        CREATE FUNCTION CalcRewards(IN Poptid bet.opt_id%TYPE, IN Psid bet.s_id%TYPE) RETURNS numeric AS  $$  \
        DECLARE \
            Qseq_id bigint[20];  \
            Qno_of_opts smallint;  \
            Qtotal numeric;  \
            vgain numeric;    \
            bet_rec bet%rowtype; \
            bet_cur CURSOR (coptid bet.opt_id%TYPE, csid bet.s_id%TYPE) FOR \
            SELECT * FROM bet WHERE s_id =csid and opt_id =coptid ; \
            count bigint; \
        BEGIN \
        Poptid = Poptid-1;   \
        if Poptid<0  THEN    \
            return -1;       \
        END IF;              \
        if  Poptid> 20 THEN  \
            return -1;       \
        END IF;              \
        Qtotal =  getgain( Poptid, Psid); \
        if  Qtotal = 0 THEN  \
            Qtotal := 1;  \
        END IF;
        
        RAISE NOTICE 'Qtotal here is %', Qtotal; 

        count := 0;
        EXECUTE INSERT INTO films SELECT ( bet.s_id, bet.opt_id, bet.u_id, bet.points, 
        bet.bettime, (Qtotal * bet.points)/ AS gain ) FROM bet WHERE s_id=Psid and opt_id=Poptid ;
        OPEN bet_cur ( Psid, Poptid );
        LOOP
            count := count + 1;
            FETCH bet_cur INTO bet_rec;
            EXIT WHEN NOT FOUND;
            gain = Qtotal / bet_rec.points  
            RAISE NOTICE 'count %, gain % points %',  bet_rec.points, gain, bet_rec.points ; 
            insert into 
        END LOOP;
        CLOSE bet_cur;
        END;
        $$ LANGUAGE plpgsql; ";
    }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return ERROR_OTHER;
    }    
    return ERROR_OK;
}

ERROR_CODES_BACCT CreateplaceBet()
{

    try
    {
        
      sql << " \
        DROP FUNCTION IF EXISTS  placebet(IN Puid bet.u_id%TYPE, IN Psid bet.s_id%TYPE, IN Poptid bet.opt_id%TYPE, IN Pbetpoints bet.points%TYPE) ; \
        CREATE FUNCTION placebet(IN Puid bet.u_id%TYPE, IN Psid bet.s_id%TYPE, IN Poptid bet.opt_id%TYPE, IN Pbetpoints bet.points%TYPE) RETURNS boolean AS  $$ \
        DECLARE \
            gain numeric;    \
        BEGIN  \
        BEGIN TRANSACTION; \
        UPDATE scheme set total=total+Pbetpoints, placed=placed+1 where s_id=Psid; \
        IF NOT FOUND THEN -- UPDATE didn't touch anything \
            RAISE NOTICE 'scheme or option not found % / %', Psid, Poptid; \
            RAISE EXCEPTION 'scheme or option not found % / %', Psid, Poptid; \
            RETURN FALSE;\
        END IF; \
        UPDATE options set opttotal=opttotal+Pbetpoints, placed=placed+1 where s_id=Psid and opt_id=Poptid; \
        IF NOT FOUND THEN -- UPDATE didn't touch anything \
            RAISE NOTICE 'scheme or option not found % / %', Psid, Poptid; \
            RAISE EXCEPTION 'scheme or option not found % / %', Psid, Poptid; \
            RETURN FALSE;\
        END IF; \
        INSERT into bet( s_id, opt_id , u_id, points, bettime ) \
        values ( Psid, Poptid, Puid, Pbetpoints, now());  \
        RETURN TRUE; \
        END; \
        $$ LANGUAGE plpgsql; ";
    }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return ERROR_OTHER;
    }   
    return ERROR_OK;

}