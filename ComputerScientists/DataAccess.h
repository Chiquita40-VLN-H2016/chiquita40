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
    void addScientist();
    vector<string> getData();
    void deleteScientist();

private:
    vector<string> _data;
};

#endif // DATAACCESS_H
