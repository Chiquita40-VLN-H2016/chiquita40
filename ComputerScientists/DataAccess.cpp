#include "DataAccess.h"
#include "Scientist.h"
#include "ScientistService.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

DataAccess::DataAccess()
{

}

DataAccess::DataAccess(vector<Scientist> scientists)
{
    _scientists = scientists;
}

size_t DataAccess::size() const
{
    return _scientists.size();
}

void DataAccess::readScientist(Scientist& setScientist)
{
    ifstream document;
    string word;

    document.open("scientists.txt");
    while(document >> word)
    {
        setScientist.getName();
        setScientist.getGender();
        setScientist.getBirthDate();
        setScientist.getDeathDate();

        _scientists.push_back(word);
    }

    document.close();
}
