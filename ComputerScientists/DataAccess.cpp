#include "DataAccess.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

DataAccess::DataAccess()
{

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
