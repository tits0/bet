#include "pgdbcommon.h"


ERROR_CODES_BACCT CreateGetgain(soci::session& sql) {

    try
    {
        
      sql << " \
                drop FUNCTION IF EXISTS  getgain(IN Poptid bet.opt_id%TYPE, IN Psid bet.s_id%TYPE); \
        CREATE FUNCTION getgain(IN Poptid bet.opt_id%TYPE, IN Psid bet.s_id%TYPE) RETURNS numeric AS  $$ \
        DECLARE \
            Qseq_id bigint[20]; \
            Curr_Qseq_id bigint; \
            Qsid bet.s_id%TYPE;  \
            Qno_of_opts smallint; \
        Qseq_id_0 bigint; Qseq_id_1 bigint; Qseq_id_2 bigint; Qseq_id_3 bigint; Qseq_id_4 bigint;  \
        Qseq_id_5 bigint; Qseq_id_6 bigint; Qseq_id_7 bigint; Qseq_id_8 bigint; Qseq_id_9 bigint;  \
        Qseq_id_10 bigint; Qseq_id_11 bigint; Qseq_id_12 bigint; Qseq_id_13 bigint; Qseq_id_14 bigint;  \
        Qseq_id_15 bigint; Qseq_id_16 bigint; Qseq_id_17 bigint; Qseq_id_18 bigint; Qseq_id_19 	bigint; \
            Qtotal numeric;  \
            gain numeric;    \
        BEGIN                \
        Poptid = Poptid-1;   \
        if Poptid<0  THEN    \
            return -1;       \
        END IF;             \
        if  Poptid> 20 THEN  \
            return -1;       \
        END IF;              \
        select s_id, no_of_opts , seq_01, seq_02, seq_03 , seq_04, seq_05, seq_06, seq_07, seq_08, seq_09, seq_10, \
        seq_11, seq_12, seq_13, seq_14, seq_15, seq_16, seq_17, seq_18, seq_19, seq_20,     \
        total INTO   \
        Curr_Qseq_id, Qno_of_opts, Qseq_id_0, Qseq_id_1, Qseq_id_2, Qseq_id_3, Qseq_id_4, \
        Qseq_id_5, Qseq_id_6, Qseq_id_7, Qseq_id_8, Qseq_id_9,    \
        Qseq_id_10, Qseq_id_11, Qseq_id_12, Qseq_id_13, Qseq_id_14,  \
        Qseq_id_15, Qseq_id_16, Qseq_id_17, Qseq_id_18, Qseq_id_19,   \
        Qtotal from scheme_option_summary where scheme_option_summary.s_id= Psid; \
        Qseq_id[0]=Qseq_id_0; \
        Qseq_id[1]=Qseq_id_1; \
        Qseq_id[2]=Qseq_id_2; \
        Qseq_id[3]=Qseq_id_3; \
        Qseq_id[4]=Qseq_id_4; \
        Qseq_id[5]=Qseq_id_5; \
        Qseq_id[6]=Qseq_id_6; \
         Qseq_id[7]=Qseq_id_7; \
         Qseq_id[8]=Qseq_id_8; \
         Qseq_id[9]=Qseq_id_9; \
        Qseq_id[10]=Qseq_id_10; \
        Qseq_id[11]=Qseq_id_11; \
        Qseq_id[12]=Qseq_id_12; \
        Qseq_id[13]=Qseq_id_13; \
        Qseq_id[14]=Qseq_id_14; \
        Qseq_id[15]=Qseq_id_15; \
        Qseq_id[16]=Qseq_id_16; \
        Qseq_id[17]=Qseq_id_17; \
        Qseq_id[18]=Qseq_id_18; \
        Qseq_id[19]=Qseq_id_19; \
        RAISE NOTICE 'Qtotal here is %', Qtotal; \
        if  Poptid> Qno_of_opts THEN   \
            return -1;   \
        END IF;   \
        gain = Qtotal - Qseq_id[Poptid];  \
        return gain;    \
        END;   \
        $$ LANGUAGE plpgsql; ";
    }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return ERROR_OTHER;
    }    
   
}


ERROR_CODES_BACCT CalculateRewards(soci::session& sql) {

/*        
    try
    {
      sql << " 
        drop FUNCTION IF EXISTS CalcRewards(IN Poptid bet.opt_id%TYPE, IN Psid bet.s_id%TYPE);
        CREATE FUNCTION CalcRewards(IN Poptid bet.opt_id%TYPE, IN Psid bet.s_id%TYPE) RETURNS numeric AS  $$ 
        DECLARE
            Qseq_id bigint[20]; 
            Qno_of_opts smallint; 
            Qseq_id_0 bigint; Qseq_id_1 bigint; Qseq_id_2 bigint; Qseq_id_3 bigint; Qseq_id_4 bigint;  
            Qseq_id_5 bigint; Qseq_id_6 bigint; Qseq_id_7 bigint; Qseq_id_8 bigint; Qseq_id_9 bigint;  
            Qseq_id_10 bigint; Qseq_id_11 bigint; Qseq_id_12 bigint; Qseq_id_13 bigint; Qseq_id_14 bigint;  
            Qseq_id_15 bigint; Qseq_id_16 bigint; Qseq_id_17 bigint; Qseq_id_18 bigint; Qseq_id_19 	bigint; 
            Qtotal numeric;  
            vgain numeric;
            bet_rec bet%rowtype; 
            bet_cur CURSOR (coptid bet.opt_id%TYPE, csid bet.s_id%TYPE) FOR 
            SELECT * FROM bet WHERE s_id =csid and opt_id =coptid ;
            count bigint;
        BEGIN
        
        Poptid = Poptid-1;   
        if Poptid<0  THEN    
            return -1;
        END IF;
        if  Poptid> 20 THEN
            return -1;  
        END IF;
        
        Qtotal =  getgain( Poptid, Psid);
        if  Qtotal = 0 THEN
            Qtotal := 1;  
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
  */ 
}


