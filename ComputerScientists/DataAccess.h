#ifndef DATAACCESS_H
#define DATAACCESS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class DataAccess
{
public:
    DataAccess();
    void addScientist(string sc); //function to write in file
    vector<string> getData();
    void deleteScientist(string sNew);
    //void addScientist(string n, string bd, string dd, string g);
    //void deleteScientist(string name);

private:
    vector<string> _data;
};

#endif // DATAACCESS_H
