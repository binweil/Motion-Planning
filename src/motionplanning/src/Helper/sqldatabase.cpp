#include "sqldatabase.h"

SQLDataBase::SQLDataBase()
{

}

SQLDataBase::~SQLDataBase()
{

}

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int SQLDataBase::createDataBase(string filename) {

    char *zErrMsg = 0;
    int rc;

    rc = sqlite3_open(filename.c_str(),&db);
    if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
    }else {
      fprintf(stderr, "Opened database successfully\n");
    }
    sqlite3_close(db);
}

int SQLDataBase::openDataBase(string filename) {

    char *zErrMsg = 0;
    int rc;

    rc = sqlite3_open(filename.c_str(),&db);
    if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
    }else {
      fprintf(stderr, "Opened database successfully\n");
    }
//    sqlite3_close(db);
}

int SQLDataBase::createTable(string dabaseName, string tableName) {
    char *command;
    string sql;
    char *zErrMsg = 0;
//    openDataBase(dabaseName);
    sql = "CREATE TABLE IF NOT EXISTS "+ tableName + "("  \
          "ID INT PRIMARY KEY     NOT NULL," \
          "AlgorithmName           TEXT    NOT NULL," \
          "TestDate            INT     NOT NULL," \
          "MazeName        CHAR(50)," \
          "TimeUsed         REAL );";
    int rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Table created successfully\n");
    }
    return 0;
}

int SQLDataBase::insert2Table(string tableName, map<string,string> &Id2Values) {
    /*template
     * sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "
     */
    map<string,string>::iterator iter;
    char *zErrMsg = 0;
    string sql = "";
    for (iter = Id2Values.begin(); iter != Id2Values.end(); iter++) {
        sql += "INSERT INTO " + tableName + " VALUES ("
                + iter->first + " ," + iter->second + "); ";
    }
    int rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Records created successfully\n");
    }
    //sqlite3_close(db);
    return 0;
}

int SQLDataBase::close() {
    sqlite3_close(db);
}
