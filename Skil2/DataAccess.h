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
    int addScientist(Scientist sc);
    void deleteScientist(Scientist sc);
    vector<Scientist> findScientist(string name);
    vector<Scientist> ScientistsAscendingOrder(int n);
    vector<Scientist> ScientistsDescendingOrder(int n);
    void editScientist(Scientist scNew);

    vector<Computer> getComputers();
    int addComputer(Computer c);
    void deleteComputer(Computer c);
    vector<Computer> findComputer(string name);
    vector<Computer> ComputersAscendingOrder(int n);
    vector<Computer> ComputersDescendingOrder(int n);
    void editComputer(Computer cNew);

    /*void addScientist(string sc);
    vector<string> getData();
    void deleteScientist(string sNew);*/

private:
    QSqlDatabase _db;
};

#endif // DATAACCESS_H
