#ifndef DATAACCESS_H
#define DATAACCESS_H
#include "Scientist.h"
#include "Computer.h"
#include "Invented.h"

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
    //~DataAccess();

    vector<Scientist> getScientists();
    int addScientist(Scientist sc);
    void deleteScientist(int id);
    vector<Scientist> findScientistByName(string search);
    vector<Scientist> findScientistByYear(int search);
    vector<Scientist> scientistsAscendingOrder(int n);
    vector<Scientist> scientistsDescendingOrder(int n);
    void editScientist(Scientist scNew);

    vector<Computer> getComputers();
    int addComputer(Computer c);
    void deleteComputer(int id);
    vector<Computer> findComputerByName(string search);
    vector<Computer> findComputerByYear(int search);
    vector<Computer> computersAscendingOrder(int n);
    vector<Computer> computersDescendingOrder(int n);
    void editComputer(Computer cNew);

    void joinScientistAndComputer(int scientistId, int computerId);
    bool deleteConnection(int scientistId, int computerId);
    vector<Scientist> getScientistsByComputer(int id);
    vector<Computer> getComputersByScientist(int id);
    vector<Invented> getListOfComputersAndScientistsAsc(int n);
    vector<Invented> getListOfComputersAndScientistsDesc(int n);



private:
    QSqlDatabase _db;
};

#endif // DATAACCESS_H
