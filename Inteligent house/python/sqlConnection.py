import pyodbc

def configSql():
    cnxn = pyodbc.connect('DRIVER={MySQL ODBC 8.3 ANSI Driver};SERVER=127.0.0.1:3306;DATABASE=db_house;UID=root;PWD=')

    cnxn.setdecoding(pyodbc.SQL_CHAR, encoding='utf-8')
    cnxn.setdecoding(pyodbc.SQL_WCHAR, encoding='utf-8')
    cnxn.setencoding(encoding='utf-8')

    return cnxn

def createCursor(cnxn: pyodbc.Connection):
    cursor = cnxn.cursor()
    return cursor


class MySQL:
    cursor: pyodbc.Cursor

    def __init__(self, cursor) -> None:
        self.cursor = cursor


    def getAll(self, query):
        self.cursor.execute(query)
        return self.cursor.fetchall();