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
};

#endif // DATAACCESS_H
