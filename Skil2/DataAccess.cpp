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

vector<Scientist> DataAccess::getScientists()
{
    vector<Scientist> scientists;
    _db.open();

    QSqlQuery query(_db);

    query.exec("SELECT * FROM Scientists");

    while(query.next())
    {
        int id = query.value("ID").toUInt();
        string name = query.value("Name").toString().toStdString();
        int birth_year = query.value("Birth_Year").toUInt();
        int death_year = query.value("Death_Year").toUInt();
        char gender = query.value("Gender").toUChar();

        scientists.push_back(Scientist(id, name, birth_year, death_year, gender));
    }

    return scientists;
}

void DataAccess::addScientist(Scientist sc)
{
    QSqlQuery query(_db);

    query.exec("INSERT INTO Scientists(Name, Birth_Year, Death_Year, Gender) VALUES (:sc.name, :sc.birth_year, :sc.death_year, :sc.gender)");
}

void DataAccess::deleteScientist(Scientist sc)
{
    QSqlQuery query(_db);

    query.exec("DELETE FROM Scientists WHERE Name = (:sc.name) AND Birth_Year = (:sc.birth_year) AND Death_Year = (:sc.death_year) AND Gender = (:sc.gender)");
    //query.bindValue(":sc.name", name);
}

vector<Scientist> DataAccess::findScientist(string name)
{
    vector<Scientist> scientists;
    QSqlQuery query(_db);
    query.exec("SELECT * FROM Scientists WHERE Name = (:name)");

    while(query.next())
    {
        int id = query.value("ID").toUInt();
        string name = query.value("Name").toString().toStdString();
        int birth_year = query.value("Birth_Year").toUInt();
        int death_year = query.value("Death_Year").toUInt();
        char gender = query.value("Gender").toUChar();

        scientists.push_back(Scientist(id, name, birth_year, death_year, gender));
    }

    return scientists;
}

void DataAccess::editScientist(Scientist scNew)
{
    QSqlQuery query(_db);
    query.exec("UPDATE Scientists SET Name = (:scNew.name) AND Birth_Year = (:scNew.birth_year) AND Death_Year = (:scNew.death_year) AND Gender = (:scNew.gender)");
}

/*void DataAccess::addScientist(string sc) //Writes a single addition to the file.
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
}*/
