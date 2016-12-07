#ifndef COMPUTERSERVICE_H
#define COMPUTERSERVICE_H
#include "Computer.h"
#include "DataAccess.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//Struct to order by name.
struct NameComparison
{
  bool operator() (Computer i, Computer j) { return (i.getName()<j.getName());}
};

//Struct to order by year computer was built.
struct BuildYearComparison
{
  bool operator() (Computer i, Computer j) { return (i.getBuildYear()<j.getBuildYear());}
};

//Struct to order by type of computer.
struct TypeComparison
{
  bool operator() (Computer i, Computer j) { return (i.getType()<j.getType());}
};

//Struct to order by if computer was built or not.
struct WasBuiltComparison
{
  bool operator() (Computer i, Computer j) { return (i.getWasBuilt()<j.getWasBuilt());}
};

class ComputerService
{
public:
    ComputerService();
    vector<Computer> getComputers(); //Returns member variable _computers.
    void ComputersAscendingOrder(int n); //Ascending order.
    void ComputersDescendingOrder(int n); //Descending order.
    //void ComputersOrderByType(); //Order computers by type.
    //void ComputersOrderByWasBuilt(); //Order computers by if computer was built or not.
    vector<Computer> findComputerByName(string name);
    void addComputer(string n, int b, string t, string wb);
    int deleteComputer(string name);
    void editComputer(string originName, string name, int by, string type, string wasb);

private:
    DataAccess _data;
    vector<Computer> _computers;
    size_t size();
    int findComputerName(string name); //Helper function to find, add, edit and delete computer.
//    void createComputer(); // Það þarf að útfæra þetta uppá nýtt

};

#endif // COMPUTERSERVICE_H
