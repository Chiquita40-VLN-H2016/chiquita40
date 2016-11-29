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
    void getData();
    void deleteScientist();

private:
    vector<Scientist> _scientists;
};

#endif // DATAACCESS_H
