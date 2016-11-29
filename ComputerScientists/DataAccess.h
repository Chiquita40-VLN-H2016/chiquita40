#ifndef DATAACCESS_H
#define DATAACCESS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Scientist.h"

using namespace std;

class DataAccess
{
public:
    DataAccess();
    DataAccess(vector<Scientist> scientists);
    size_t size() const;
    void readScientist(Scientist& setScientist);

private:
    vector<Scientist> _scientists;
};

#endif // DATAACCESS_H
