#include "DataAccess.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

DataAccess::DataAccess()
{

}

void DataAccess::addScientist(string sc)
{
    ofstream input;
    input.open("scientists.txt", ios::app);
    input << endl << sc;
    input.close();
}

void DataAccess::deleteScientist(string sNew)
{
    ofstream del;
    del.open("scientists.txt");
    del << endl << sNew;
    del.close();
}

vector<string> DataAccess::getData()
{
    vector<string> data;
    ifstream document;
    string word;

    document.open("scientists.txt");
    while(document >> word)
    {
        data.push_back(word);
    }

    document.close();

    return data;
}
