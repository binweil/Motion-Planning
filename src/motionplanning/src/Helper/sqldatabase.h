#ifndef SQLDATABASE_H
#define SQLDATABASE_H

#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
#include <fstream>

#include "sqlite3.h"

using namespace std;

class SQLDataBase
{
public:
    SQLDataBase();
    ~SQLDataBase();
    int createDataBase(string filename);
    int openDataBase(string filename);
    int createTable(string dabaseName,string tableName);
    int insert2Table(string tableName, map<string,string> &Id2Values);
    int close();
private:
    sqlite3 *db;
};

#endif // SQLDATABASE_H
