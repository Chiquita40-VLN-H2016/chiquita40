#include "DataAccess.h"

using namespace std;

DataAccess::DataAccess()
{
    _db = QSqlDatabase::addDatabase("QSQLITE");
    _db.setDatabaseName("C:/CSHistory.sqlite");

/*    if (!_db.open())
    {
        qDebug() << "Error: connection with database failed";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }*/
}

void DataAccess::addScientist(string sc) //Writes a single addition to the file.
{
    ofstream input;
    input.open("scientists.txt", ios::app);
    input << endl << sc;
    input.close();
}

void DataAccess::deleteScientist(string sNew) //Overwrites whole file with new string.
{
    ofstream del;

    del.open("scientists.txt");
    del << sNew;
    del.close();
}

vector<string> DataAccess::getData() //Returns a vector of strings with data from file to next layer.
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
