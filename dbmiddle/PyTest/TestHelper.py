import psycopg2
import subprocess 
import multiprocessing
import subprocess

    
def checkTableExists( conn, sch_str, table_str ):
    exists = False
    try:
        cur = conn.cursor()
        cur.execute("SELECT EXISTS(SELECT * FROM information_schema.tables WHERE  table_schema = '" + sch_str + "' AND table_name ='" + table_str + "' );")
        exists = cur.fetchone()[0]
        print exists
        cur.close()
    except psycopg2.Error as e:
        raise e
    return exists

def initdb( ):
    exists = False
    try:
        return_code = subprocess.call(["../Debug/dbmiddle", "--initdb"])
        exists = True
    except psycopg2.Error as e:
        raise e
    return exists


def checkSchemeTable( conn, scheme_name, options, total):
    rows = False
    try:
        cur = conn.cursor()
        import pdb
        pdb.set_trace()
        qery = """ SELECT s_id , scheme_name, permission, createtime, endtime, uid_created, options, total, placed, isarchived FROM scheme where scheme_name=  '%s' and options = %d and total=%d ;""" % (scheme_name, options, total)
        cur.execute(qery)
        rows = cur.fetchall()
        #exists = cur.fetchone()[0]
        print rows
        cur.close()
    except psycopg2.Error as e:
        raise e
    return rows


import urllib2
import json
# Whatever structure you need to send goes here:

class JSONDefs():
    def __init__(self): 
     

        self.UID_TAG_BACCT = "uid"
        self.SESSION_TAG_BACCT =  "session"
        self.SCHEME_TAG_BACCT =  "scheme"
        self.SCHEME_DAYS_BACCT =  "sch_days"
        self.SCHEME_HRS_BACCT =  "sch_hrs"

        self.SCHEME_ID_TAG_BACCT = "schid"
        self.SCHEME_TOTAL_TAG_BACCT = "schtot"
        self.SCHEME_START_TAG_BACCT=  "schstart"
        self.SCHEME_END_TAG_BACCT=  "schend"

        self.OPTIONS_TAG_BACCT =  "options"
        self.OPTION_ID_TAG_BACCT = "optid"
        self.OPTION_PTS_BACCT = "optpt"
        self.OPTION_LIST_BACCT = "optlist"
        self.BET_POINTS_TAG_BACCT = "betpt"

        self.OPTIONS_UNAME_BACCT  = "uname"
        self.OPTIONS_ADDR_BACCT  = "addr"
        self.OPTIONS_PASS_BACCT  = "pss"


        self.sjson_0="{\"uid\":12345567, \"session\":\"7654321\" , \"scheme\":\"s1\", \"options\":[] }"
        self.sjson_1="{\"uid\":12345567, \"session\":\"7654321\" , \"scheme\":\"s2\", \"options\":[\"opt1\"] }"
        self.sjson_2="{\"uid\":12345567, \"session\":\"7654321\" , \"scheme\":\"s3\", \"options\":[\"opt1\", \"opt2\"] }"
        self.sjson_20="{\"uid\":12345567, \"session\":\"7654321\" , \"scheme\":\"s4\", \"options\":[\"opt1\", \"opt2\", \"opt3\", \"opt4\", \"opt5\", \
     \"opt6\", \"opt7\", \"opt8\", \"opt9\", \"opt10\", \"opt11\", \"opt12\", \"opt13\", \"opt14\", \"opt15\", \"opt16\", \"opt17\", \"opt18\", \"opt19\", \
     \"opt20\"] }"

        self.sjson_22="{\"uid\":12345567, \"session\":\"7654321\", \"scheme\":\"s5\", \"options\":[\"opt1\", \"opt2\", \"opt3\", \"opt4\", \"opt5\", \
     \"opt6\", \"opt7\", \"opt8\", \"opt9\", \"opt10\", \"opt11\", \"opt12\", \"opt13\", \"opt14\", \"opt15\", \"opt16\", \"opt17\", \"opt18\", \"opt19\", \
     \"opt20\", \"opt21\", \"opt22\"] }"

        self.sjson_bet_100="{\"uid\":1, \"session\":\"7654321\" , \"schid\":1 , \"optid\":1, \"betpt\":100 }"
        self.sjson_bet_100_2="{\"uid\":2, \"session\":\"7654322\" , \"schid\":1 , \"optid\":2, \"betpt\":100 }"

        self.sjson_user_1="{\"uname\":\"a1\", \"addr\":\"a@a.com\" , \"pss\":\"pa1\" }"
        self.sjson_user_2="{\"uname\":\"b2\", \"addr\":\"b@b.com\" , \"pss\":\"pa2\" }"
        self.sjson_user_3="{\"uname\":\"c3\", \"addr\":\"c@c.com\" , \"pss\":\"pa3\" }"

        self.sjson_finalize_1="{\"schid\":\"1\", \"optid\":1 }"
        
    def sendCreateScheme(self, session= "7654321" , uid ="12345567", scheme="s1", options=[] ):
        data ={}
        data[self.SESSION_TAG_BACCT] = session
        data[self.UID_TAG_BACCT] = uid
        data[self.SCHEME_TAG_BACCT] = scheme
        data[self.OPTIONS_TAG_BACCT] = options
        jdata=json.dumps(data)
        urllib2.urlopen("http://localhost:8000/api/newscheme", jdata)
        
    def sendGetSchemeOptList(self, session= "7654321" , uid ="12345567"):
        data ={}
        data[self.SESSION_TAG_BACCT] = session
        data[self.UID_TAG_BACCT] = uid
        jdata=json.dumps(data)
        urllib2.urlopen("http://localhost:8000/api/schemes", jdata)
        
    def sendCreateBet(self, session= "7654321" , uid ="12345567", scheme="s1", optid="o1", points=100 ):
        data ={}
        data[self.SESSION_TAG_BACCT] = session
        data[self.UID_TAG_BACCT] = uid
        data[self.SCHEME_ID_TAG_BACCT] = scheme
        data[self.OPTION_ID_TAG_BACCT] = options
        
        jdata=json.dumps(data)
        urllib2.urlopen("http://localhost:8000/api/newbet", jdata)
                
    def sendCreateUser(self, username , passsec , addr ):
        optdata ={}
        optdata[self.OPTIONS_UNAME_BACCT] = username;
        optdata[self.OPTIONS_PASS_BACCT] = passsec; 
        optdata[self.OPTIONS_ADDR_BACCT] = addr ; 

        jdata=json.dumps(data)
        urllib2.urlopen("http://localhost:8000/api/newuser", jdata)
                
