import unittest
import os
import psycopg2
import json
#import RedisConn
import TestHelper

class TestDB(unittest.TestCase):
    def setUp(self):
        #if TestDB.isConn==False:
        self.dbinit()
        if isOneTime==False:
            TestDB.isConn=True
            
    def createConn(self):
        conn = psycopg2.connect("dbname='%s' user='%s'  password='%s'" % (self.dbname, self.user, self.password))
        return conn

    def dbinit(self, dbname='accountdb', user='anandrathi', password='guru123'):
        self.dbname=dbname
        self.user=user
        self.password=password
        self.conn = self.createConn()

    def tearDown(self):
        pass

    def test_01_CreateInitialScheme(self):
        TestHelper.initdb()
        self.assertTrue(TestHelper.checkTableExists(conn=self.conn, sch_str='public', table_str='bet' ), "Error: Table bet not found" )
        self.assertTrue(TestHelper.checkTableExists(conn=self.conn, sch_str='public', table_str='scheme' ), "Error: Table scheme not found" )
        self.assertTrue(TestHelper.checkTableExists(conn=self.conn, sch_str='public', table_str='options' ), "Error: Table options not found" )
        self.assertTrue(TestHelper.checkTableExists(conn=self.conn, sch_str='public', table_str='scheme_option_summary' ), "Error: Table scheme_option_summary not found" )
        self.assertTrue(TestHelper.checkTableExists(conn=self.conn, sch_str='public', table_str='bonus' ), "Error: Table bonus not found" )
        self.assertTrue(TestHelper.checkTableExists(conn=self.conn, sch_str='public', table_str='bet_archive' ), "Error: Table bet_archive not found" )
        self.assertTrue(TestHelper.checkTableExists(conn=self.conn, sch_str='public', table_str='options_archive' ), "Error: Table options_archive not found" )
        self.assertTrue(TestHelper.checkTableExists(conn=self.conn, sch_str='public', table_str='schemearchive' ), "Error: Table schemearchive not found" )
        self.assertTrue(TestHelper.checkTableExists(conn=self.conn, sch_str='public', table_str='finalizebet' ), "Error: Table finalizebet not found" )

    def test_02_checkSchemeTable(self):
        TestHelper.initdb()
        rows = TestHelper.checkSchemeTable(conn=self.conn, scheme_name='s3', options=2, total=0)
        self.assertTrue(len(rows)==1, "Error: no rows not found" )
        

if __name__ == '__main__':
    unittest.main()