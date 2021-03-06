#ifndef DATAACCESS_H
#define DATAACCESS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

//Class to get data from file and to add data to the same file.
class DataAccess
{
public:
    DataAccess();
    void addScientist(string sc);
    vector<string> getData();
    void deleteScientist(string sNew);
};

#endif // DATAACCESS_H
