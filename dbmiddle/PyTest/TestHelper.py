import psycopg2
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

