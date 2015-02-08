#include "pgdbcommon.h"


ERROR_CODES_BACCT CreateGetgain(soci::session& sql) {

    try
    {

        std::cerr << "START getgain !! " << '\n';
      sql << " DROP FUNCTION IF EXISTS  getgain(IN Poptid bet.opt_id%TYPE, IN Psid bet.s_id%TYPE); \
        CREATE FUNCTION getgain(IN Poptid bet.opt_id%TYPE, IN Psid bet.s_id%TYPE) RETURNS numeric AS  $$ \
        DECLARE \
            Curr_Qseq_id bigint; \
            Qsid bet.s_id%TYPE;  \
            QPlaced numeric;   \
            QGrandtotal numeric;  \
            Qtotal numeric;  \
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
        std::cerr << "DONE getgain !! " << '\n';

    }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return ERROR_OTHER;
    }    
    return ERROR_OK;
   
}


ERROR_CODES_BACCT CreateCalculateRewards(soci::session& sql) 
{

    try
    {
        std::cerr << "START CalcRewards !! " << '\n';
      sql << " \
        drop FUNCTION IF EXISTS CalcRewards(IN Poptid bet.opt_id%TYPE, IN Psid bet.s_id%TYPE);                  \n\
        CREATE FUNCTION CalcRewards(IN Poptid bet.opt_id%TYPE, IN Psid bet.s_id%TYPE) RETURNS numeric AS  $$    \n\
        DECLARE                                                                                                 \n\
            Qno_of_opts smallint;                                                                               \n\
            Qtotal numeric;                                                                                     \n\
            Qgain numeric;                                                                                      \n\
            bet_rec bet%rowtype;                                                                                \n\
            Qcount bigint;                                                                                      \n\
            bet_cur CURSOR (coptid bet.opt_id%TYPE, csid bet.s_id%TYPE) FOR                                     \n\
            SELECT bet.opt_id, bet.u_id, sum(bet.points),                                                       \n\
            options.opttotal FROM bet INNER JOIN options ON bet.s_id=csid and bet.s_id=options.s_id group by bet.s_id, bet.opt_id, bet.u_id;  \n\
        BEGIN                                       \n\
        Poptid = Poptid-1;                          \n\
        if Poptid<0  THEN                           \n\
            return -1;                              \n\
        END IF;                                     \n\
        Qgain =  getgain( Poptid, Psid);            \n\
        if  Qtotal = 0 THEN                         \n\
            Qtotal := 1;                            \n\
        END IF;                                     \n\
        RAISE NOTICE 'Qtotal here is %', Qtotal;    \n\
        Qcount := 0;                                \n\
        --EXECUTE INSERT INTO bet_archive SELECT ( bet.s_id, bet.opt_id, bet.u_id, bet.points,       \n\
        --bet.bettime, (Qtotal * bet.points)/ AS gain ) FROM bet WHERE s_id=Psid and opt_id=Poptid ; \n\
        OPEN bet_cur ( Psid, Poptid );          \n\
        LOOP                                    \n\
            Qcount := Qcount + 1;               \n\
            FETCH bet_cur INTO bet_rec;         \n\
            EXIT WHEN NOT FOUND;                \n\
            if bet_rec.opt_id = Poptid THEN     \n\
            Qgain = (Qgain * bet_rec.points)/ bet_rec.opttotal;                               \n\
            RAISE NOTICE 'count %, gain % points %',  Qcount, Qgain, bet_rec.points ;         \n\
            UPDATE u_table set points = points + gain WHERE u_id = bet_rec.u_id;              \n\
             ELSE                                                                             \n\
            UPDATE u_table set points = points - bet_rec.points WHERE u_id = bet_rec.u_id;    \n\
             END IF;                                                                          \n\
        END LOOP;                                                                             \n\
        CLOSE bet_cur;                                                                        \n\
        END;   \n\
        $$ LANGUAGE plpgsql; ";
        std::cerr << "DONE CalcRewards !! " << '\n';
        
    }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return ERROR_OTHER;
    }    
    return ERROR_OK;
}

ERROR_CODES_BACCT CreatePlaceBet(soci::session& sql)
{

    try
    {
        
        std::cerr << "START placebet !! " << '\n';
      sql << " \
        DROP FUNCTION IF EXISTS  placebet(IN Puid bet.u_id%TYPE, IN Psid bet.s_id%TYPE, IN Poptid bet.opt_id%TYPE, IN Pbetpoints bet.points%TYPE) ; \n\
        CREATE FUNCTION placebet(IN Puid bet.u_id%TYPE, IN Psid bet.s_id%TYPE, IN Poptid bet.opt_id%TYPE, IN Pbetpoints bet.points%TYPE) RETURNS boolean AS  $$ \n\
        DECLARE                                                                                             \n\
            gain numeric;                                                                                   \n\
        BEGIN                                                                                               \n\
                                                                                                            \n\
        UPDATE scheme set total=total+Pbetpoints, placed=placed+1 where s_id=Psid;                          \n\
        IF NOT FOUND THEN -- UPDATE didn't touch anything                                                   \n\
            RAISE NOTICE 'scheme or option not found % / %', Psid, Poptid;                                  \n\
            RAISE EXCEPTION 'scheme or option not found % / %', Psid, Poptid;                               \n\
            RETURN FALSE;                                                                                   \n\
        END IF;                                                                                             \n\
        UPDATE options set opttotal=opttotal+Pbetpoints, placed=placed+1 where s_id=Psid and opt_id=Poptid; \n\
        IF NOT FOUND THEN -- UPDATE didn't touch anything                                                   \n\
            RAISE NOTICE 'scheme or option not found % / %', Psid, Poptid;                                  \n\
            RAISE EXCEPTION 'scheme or option not found % / %', Psid, Poptid;                               \n\
            RETURN FALSE;                                                                                   \n\
        END IF;                                                                                             \n\
        INSERT into bet( s_id, opt_id , u_id, points, bettime )                                             \n\
        values ( Psid, Poptid, Puid, Pbetpoints, now());                                                    \n\
        RETURN TRUE;                                                                                        \n\
        END; \n\
        $$ LANGUAGE plpgsql;";
        std::cerr << "DONE placebet !! " << '\n';
    }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return ERROR_OTHER;
    }   
    return ERROR_OK;

}