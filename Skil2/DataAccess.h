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
    void deleteScientist(int id);
    vector<Scientist> findScientistByName(string search);
    vector<Scientist> findScientistByYear(int search);
    vector<Scientist> ScientistsAscendingOrder(int n);
    vector<Scientist> ScientistsDescendingOrder(int n);
    void editScientist(Scientist scNew);

    vector<Computer> getComputers();
    int addComputer(Computer c);
    void deleteComputer(int id);
    vector<Computer> findComputerByName(string search);
    vector<Computer> findComputerByYear(int search);
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
