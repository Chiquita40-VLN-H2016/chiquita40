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
        int birthYear = query.value("Birth_Year").toUInt();
        int deathYear = query.value("Death_Year").toUInt();
        string g = query.value("Gender").toString().toStdString();
        char gender = g.front();

        scientists.push_back(Scientist(id, name, birthYear, deathYear, gender));
    }

    return scientists;
}

int DataAccess::addScientist(Scientist sc)
{
    QSqlQuery query(_db);

    query.prepare("INSERT INTO Scientists(Name, Birth_Year, Death_Year, Gender) "
                  "VALUES (:name, :birthYear, :deathYear, :gender)");
    query.bindValue(":name", QString::fromStdString(sc.getName()));
    query.bindValue(":birthYear", sc.getBirthDate());
    query.bindValue(":deathYear", sc.getDeathDate());
    query.bindValue(":gender", QString::fromStdString(string(1,sc.getGender())));
    query.exec();
    int n = query.lastInsertId().toUInt();
    return n;
}

void DataAccess::deleteScientist(int id)
{
    QSqlQuery query(_db);

    query.prepare("DELETE FROM Scientists WHERE ID = (:id)");
    query.bindValue(":id", id);
    query.exec();
}

vector<Scientist> DataAccess::findScientistByName(string search)
{
    vector<Scientist> scientists;
    QSqlQuery query(_db);
    string s = "SELECT * FROM Scientists WHERE Name LIKE '%";
    s += search;
    s += "%'";
    //query.prepare("SELECT * FROM Scientists WHERE Name LIKE \"%(:search)%\"");
    QString qstr = QString::fromStdString(s);
    //query.bindValue(":search", qstr);
    query.exec(qstr);

    while(query.next())
    {
        int id = query.value("ID").toUInt();
        string name = query.value("Name").toString().toStdString();
        int birth_year = query.value("Birth_Year").toUInt();
        int death_year = query.value("Death_Year").toUInt();
        string g = query.value("Gender").toString().toStdString();
        char gender = g.front();
        scientists.push_back(Scientist(id, name, birth_year, death_year, gender));
    }

    return scientists;
}

vector<Scientist> DataAccess::findScientistByYear(int search)
{
    vector<Scientist> scientists;
    QSqlQuery query(_db);
    string s = "SELECT * FROM Scientists WHERE Birth_Year LIKE '%";
    s += to_string(search);
    s += "%' OR Death_Year LIKE '%";
    s += to_string(search);
    s += "%'";
    QString qstr = QString::fromStdString(s);
    //query.prepare("SELECT * FROM Scientists WHERE Birth_Year LIKE \"%(:search)%\" OR Death_Year LIKE \"%(:search)%\"");
    //query.bindValue(":search", search);
    query.exec(qstr);
    while(query.next())
    {
        int id = query.value("ID").toUInt();
        string name = query.value("Name").toString().toStdString();
        int birth_year = query.value("Birth_Year").toUInt();
        int death_year = query.value("Death_Year").toUInt();
        string g = query.value("Gender").toString().toStdString();
        char gender = g.front();
        scientists.push_back(Scientist(id, name, birth_year, death_year, gender));
    }

    return scientists;
}

vector<Scientist> DataAccess::ScientistsAscendingOrder(int n)
{
    vector<Scientist> scientists;
    QSqlQuery query(_db);
    switch(n)
    {
        case 0:
                query.exec("SELECT * FROM Scientists ORDER BY Name");
                break;
        case 1:
                query.exec("SELECT * FROM Scientists ORDER BY Birth_Year");
                break;
        case 2:
                query.exec("SELECT * FROM Scientists ORDER BY Death_Year");
                break;
        case 3:
                query.exec("SELECT * FROM Scientists ORDER BY Gender");
                break;
        default:
                query.exec("SELECT * FROM Scientists");
    }

    while(query.next())
    {
        int id = query.value("ID").toUInt();
        string name = query.value("Name").toString().toStdString();
        int birth_year = query.value("Birth_Year").toUInt();
        int death_year = query.value("Death_Year").toUInt();
        string g = query.value("Gender").toString().toStdString();
        char gender = g.front();
        scientists.push_back(Scientist(id, name, birth_year, death_year, gender));
    }

    return scientists;
}

vector<Scientist> DataAccess::ScientistsDescendingOrder(int n)
{
    vector<Scientist> scientists;
    QSqlQuery query(_db);
    switch(n)
    {
        case 0:
                query.exec("SELECT * FROM Scientists ORDER BY Name desc");
                break;
        case 1:
                query.exec("SELECT * FROM Scientists ORDER BY Birth_Year desc");
                break;
        case 2:
                query.exec("SELECT * FROM Scientists ORDER BY Death_Year desc");
                break;
        case 3:
                query.exec("SELECT * FROM Scientists ORDER BY Gender desc");
                break;
        default:
                query.exec("SELECT * FROM Scientists ORDER BY ID desc");
    }

    while(query.next())
    {
        int id = query.value("ID").toUInt();
        string name = query.value("Name").toString().toStdString();
        int birth_year = query.value("Birth_Year").toUInt();
        int death_year = query.value("Death_Year").toUInt();
        string g = query.value("Gender").toString().toStdString();
        char gender = g.front();
        scientists.push_back(Scientist(id, name, birth_year, death_year, gender));
    }

    return scientists;
}


void DataAccess::editScientist(Scientist scNew)
{
    QSqlQuery query(_db);
    query.prepare("UPDATE Scientists SET Name = (:name), Birth_Year = (:birthYear), "
                  "Death_Year = (:deathYear), Gender = (:gender) WHERE ID = (:id)");
    query.bindValue(":id", scNew.getId());
    query.bindValue(":name", QString::fromStdString(scNew.getName()));
    query.bindValue(":birthYear", scNew.getBirthDate());
    query.bindValue(":deathYear", scNew.getDeathDate());
    query.bindValue(":gender", QString::fromStdString(string(1,scNew.getGender())));
    query.exec();
}

//==================Computer functions======================================

vector<Computer> DataAccess::getComputers()
{
    vector<Computer> computers;
    _db.open();

    QSqlQuery query(_db);

    query.exec("SELECT * FROM Computers");

    while(query.next())
    {
        int id = query.value("ID").toUInt();
        string name = query.value("Name").toString().toStdString();
        int buildYear = query.value("Build_Year").toUInt();
        string type = query.value("Type").toString().toStdString();
        bool wasBuilt = query.value("Was_Built").toBool();

        computers.push_back(Computer(id, name, buildYear, type, wasBuilt));
    }

    return computers;
}

int DataAccess::addComputer(Computer c)
{
    QSqlQuery query(_db);

    query.prepare("INSERT INTO Computers(Name, Build_Year, Type, Was_Built) VALUES "
                  "(:name, :buildYear, :type, :wasBuilt)");
    query.bindValue(":name", QString::fromStdString(c.getName()));
    query.bindValue(":buildYear", c.getBuildYear());
    query.bindValue(":type", QString::fromStdString(c.getType()));
    query.bindValue(":wasBuilt", c.getWasBuilt());
    query.exec();
    int n = query.lastInsertId().toUInt();
    return n;
}

void DataAccess::deleteComputer(int id)
{
    QSqlQuery query(_db);
    query.prepare("DELETE FROM Computers WHERE ID = (:id)");
    query.bindValue(":id", id);
    query.exec();
}

vector<Computer> DataAccess::findComputerByName(string search)
{
    vector<Computer> computers;
    QSqlQuery query(_db);
    string s = "SELECT * FROM Computers WHERE Name LIKE '%";
    s += search;
    s += "%'";
    //query.prepare("SELECT * FROM Computers WHERE Name LIKE \"%(:search)%\"");
    QString qstr = QString::fromStdString(s);
    //query.bindValue(":search", qstr);
    query.exec(qstr);

    while(query.next())
    {
        int id = query.value("ID").toUInt();
        string name = query.value("Name").toString().toStdString();
        int buildYear = query.value("Build_Year").toUInt();
        string type = query.value("Type").toString().toStdString();
        bool wasBuilt = query.value("Was_Built").toBool();

        computers.push_back(Computer(id, name, buildYear, type, wasBuilt));
    }

    return computers;
}

vector<Computer> DataAccess::findComputerByYear(int search)
{
    vector<Computer> computers;
    QSqlQuery query(_db);
    string s = "SELECT * FROM Computers WHERE Build_Year LIKE '%";
    s += to_string(search);
    s += "%'";
    QString qstr = QString::fromStdString(s);
    //query.prepare("SELECT * FROM Scientists WHERE Build_Year LIKE \"%(:search)%\"");
    //query.bindValue(":search", search);
    query.exec(qstr);

    while(query.next())
    {
        int id = query.value("ID").toUInt();
        string name = query.value("Name").toString().toStdString();
        int buildYear = query.value("Build_Year").toUInt();
        string type = query.value("Type").toString().toStdString();
        bool wasBuilt = query.value("Was_Built").toBool();

        computers.push_back(Computer(id, name, buildYear, type, wasBuilt));
    }

    return computers;
}

vector<Computer> DataAccess::ComputersAscendingOrder(int n)
{
    vector<Computer> computers;
    QSqlQuery query(_db);
    switch(n)
    {
        case 0:
                query.exec("SELECT * FROM Computers ORDER BY Name");
                break;
        case 1:
                query.exec("SELECT * FROM Scientists ORDER BY Build_Year");
                break;
        case 2:
                query.exec("SELECT * FROM Scientists ORDER BY Type");
                break;
        case 3:
                query.exec("SELECT * FROM Scientists ORDER BY Was_Built");
                break;
        default:
                query.exec("SELECT * FROM Scientists");
    }

    while(query.next())
    {
        int id = query.value("ID").toUInt();
        string name = query.value("Name").toString().toStdString();
        int buildYear = query.value("Build_Year").toUInt();
        string type = query.value("Type").toString().toStdString();
        bool wasBuilt = query.value("Was_Built").toBool();

        computers.push_back(Computer(id, name, buildYear, type, wasBuilt));
    }

    return computers;
}

vector<Computer> DataAccess::ComputersDescendingOrder(int n)
{
    vector<Computer> computers;
    QSqlQuery query(_db);
    switch(n)
    {
        case 0:
                query.exec("SELECT * FROM Computers ORDER BY Name desc");
                break;
        case 1:
                query.exec("SELECT * FROM Scientists ORDER BY Build_Year desc");
                break;
        case 2:
                query.exec("SELECT * FROM Scientists ORDER BY Type desc");
                break;
        case 3:
                query.exec("SELECT * FROM Scientists ORDER BY Was_Built desc");
                break;
        default:
                query.exec("SELECT * FROM Scientists ORDER BY ID desc");
    }

    while(query.next())
    {
        int id = query.value("ID").toUInt();
        string name = query.value("Name").toString().toStdString();
        int buildYear = query.value("Build_Year").toUInt();
        string type = query.value("Type").toString().toStdString();
        bool wasBuilt = query.value("Was_Built").toBool();

        computers.push_back(Computer(id, name, buildYear, type, wasBuilt));
    }

    return computers;
}

void DataAccess::editComputer(Computer cNew)
{
    QSqlQuery query(_db);
    query.exec("UPDATE Computers SET Name = (:name), Build_Year = (:buildYear), "
               "Type = (:type), Was_Built = (:wasBuilt) WHERE ID = (:id)");
    query.bindValue(":name", QString::fromStdString(cNew.getName()));
    query.bindValue(":buildYear", cNew.getBuildYear());
    query.bindValue(":type", QString::fromStdString(cNew.getType()));
    query.bindValue(":wasBuilt", cNew.getWasBuilt());
    query.bindValue(":id", cNew.getId());
    query.exec();
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
