#ifndef DATAACCESS_H
#define DATAACCESS_H
#include "Scientist.h"
#include "Computer.h"

#include <iostream>
#include <vector>
#include <string>
#include <QtSql>

using namespace std;

//Class to get data from data base and to add data to the same data base.
class DataAccess
{
public:
    DataAccess();

    vector<Scientist> getScientists();
    void addScientist(Scientist sc);
    void deleteScientist(Scientist sc);
    vector<Scientist> findScientist(string name);
    void editScientist(Scientist scNew);

    vector<Computer> getComputers();
    void addComputer(Computer c);
    void deleteComputer(Computer c);
    Computer findComputer(string name);
    void editComputer(Computer cNew);

    /*void addScientist(string sc);
    vector<string> getData();
    void deleteScientist(string sNew);*/

private:
    QSqlDatabase _db;
};

#endif // DATAACCESS_H
