#ifndef SCSERVICE_H
#define SCSERVICE_H
#include "Scientist.h"
#include "Computer.h"
#include "DataAccess.h"
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

class SCService
{
public:
    SCService();
    vector<Scientist> getScientists(); //Returns member variable _scientists.
    vector<Computer> getComputers(); //Returns member variable _computers.
    void scientistsAscendingOrder(int n); //Ascending Order.
    void scientistsDescendingOrder(int n); //Descending Order scientists by birth year.
    void computersAscendingOrder(int n); //Ascending order.
    void computersDescendingOrder(int n); //Descending order.
    vector<Scientist> findScientistByYear(int year);
    vector<Scientist> findScientistByName(string search);
    vector<Computer> findComputerByYear(int year);
    vector<Computer> findComputerByName(string search);
    vector<Scientist> findComputerByScientist(int id);
    void addScientist(string n, int bd, int dd, char g);
    void addComputer(string n, int b, string t, string wb);
    bool validYearCheck(int year);
    int deleteScientist(int id);
    int deleteComputer(int id);
    void editScientist(int id, string name, int dob, int dod, char g);
    void editComputer(int id, string name, int by, string type, string wasb);

private:
    DataAccess _data;
    vector<Scientist> _scientists;
    vector<Computer> _computers;
    size_t size();
    int findScientistId(int id); //Helper function to find, add, edit and delete scientist.
    int findComputerId(int id); //Helper function to find, add, edit and delete computer.
    void constructString(string& s, string name, int dob, int dod, char g);
};

#endif // SCSERVICE_H
