#include "DataAccess.h"

using namespace std;

DataAccess::DataAccess()
{

    _db = QSqlDatabase::addDatabase("QSQLITE");
    _db.setDatabaseName("C:/CSHistory.sqlite");

    _db.open();

    /*if (!_db.open())
    {
        qDebug() << "Error: connection with database failed";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }*/
}

DataAccess::~DataAccess()                    // Destructor
{
    QString connection;
    connection = _db.connectionName();
    _db.close();
    _db = QSqlDatabase();
    QSqlDatabase::removeDatabase(connection);
    //QSqlDatabase::removeDatabase("CSdatabase");
}

vector<Scientist> DataAccess::getScientists()
{
    vector<Scientist> scientists;

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
    query.prepare("DELETE FROM Invented WHERE SID = (:id)");
    query.bindValue(":id", id);
    query.exec();

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

vector<Scientist> DataAccess::scientistsAscendingOrder(int n)
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

vector<Scientist> DataAccess::scientistsDescendingOrder(int n)
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

    query.prepare("DELETE FROM Invented WHERE CID = (:id)");
    query.bindValue(":id", id);
    query.exec();

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

vector<Computer> DataAccess::computersAscendingOrder(int n)
{
    vector<Computer> computers;
    QSqlQuery query(_db);
    switch(n)
    {
        case 0:
                query.exec("SELECT * FROM Computers ORDER BY Name desc");
                break;
        case 1:
                query.exec("SELECT * FROM Computers ORDER BY Build_Year desc");
                break;
        case 2:
                query.exec("SELECT * FROM Computers ORDER BY Type desc");
                break;
        case 3:
                query.exec("SELECT * FROM Computers ORDER BY Was_Built desc");
                break;
        default:
                query.exec("SELECT * FROM Computers ORDER BY ID desc");
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

vector<Computer> DataAccess::computersDescendingOrder(int n)
{
    vector<Computer> computers;
    QSqlQuery query(_db);
    switch(n)
    {
        case 0:
                query.exec("SELECT * FROM Computers ORDER BY Name desc");
                break;
        case 1:
                query.exec("SELECT * FROM Computers ORDER BY Build_Year desc");
                break;
        case 2:
                query.exec("SELECT * FROM Computers ORDER BY Type desc");
                break;
        case 3:
                query.exec("SELECT * FROM Computers ORDER BY Was_Built desc");
                break;
        default:
                query.exec("SELECT * FROM Computers ORDER BY ID desc");
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

//============================ Join functions =================================

void DataAccess::joinScientistAndComputer(int scientistId, int computerId)
{
    QSqlQuery query(_db);
    query.exec("PRAGMA foreign_keys = ON");
    query.prepare("INSERT INTO Invented(SID, CID) "
                  "VALUES (:scId, :cId)");
    query.bindValue(":scId", scientistId);
    query.bindValue(":cId", computerId);
    query.exec();
}

void DataAccess::deleteConnection(int scientistId, int computerId)
{
    QSqlQuery query(_db);

    query.prepare("DELETE FROM Invented WHERE SID = (:scId) AND CID = (:cId);");
    query.bindValue(":scId", scientistId);
    query.bindValue(":cId", computerId);
    query.exec();
}

vector<Scientist> DataAccess::getScientistsByComputer(int id)
{
    vector<Scientist> scientists;
    QSqlQuery query(_db);
    query.prepare("SELECT S.ID, S.Name, S.Birth_Year, S.Death_Year, S.Gender "
                  "FROM Scientists S "
                  "JOIN Invented I ON S.ID = I.SID "
                  "WHERE I.CID = (:id);");
    query.bindValue(":id", id);
    query.exec();

    while(query.next())
    {
        int id = query.value("S.ID").toUInt();
        string name = query.value("S.Name").toString().toStdString();
        int birth_year = query.value("S.Birth_Year").toUInt();
        int death_year = query.value("S.Death_Year").toUInt();
        string g = query.value("S.Gender").toString().toStdString();
        char gender = g.front();
        scientists.push_back(Scientist(id, name, birth_year, death_year, gender));
    }

    return scientists;
}

vector<Computer> DataAccess::getComputersByScientist(int id)
{
    vector<Computer> computers;
    QSqlQuery query(_db);

    query.prepare("SELECT C.ID, C.Name, C.Build_Year, C.Type, C.Was_Built "
                  "FROM Computers C "
                  "JOIN Invented I ON C.ID = I.CID "
                  "WHERE I.SID = (:id);");
    query.bindValue(":id", id);
    query.exec();

    while(query.next())
    {
        int id = query.value("C.ID").toUInt();
        string name = query.value("C.Name").toString().toStdString();
        int buildYear = query.value("C.Build_Year").toUInt();
        string type = query.value("C.Type").toString().toStdString();
        bool wasBuilt = query.value("C.Was_Built").toBool();

        computers.push_back(Computer(id, name, buildYear, type, wasBuilt));
    }

    return computers;
}

vector<Invented> DataAccess::getListOfComputersAndScientistsAsc(int n)
{
    vector<Invented> connections;
    QSqlQuery query(_db);
    switch(n)
    {
        case 0:
                query.exec("SELECT S.Name as s_name, C.Name as c_name "
                           "FROM Scientists S "
                           "JOIN Invented I ON S.ID = I.SID "
                           "JOIN Computers C ON C.ID = I.CID "
                           "ORDER BY S.Name;");
                break;
        case 1:
                query.exec("SELECT S.Name as s_name, C.Name as c_name "
                           "FROM Scientists S "
                           "JOIN Invented I ON S.ID = I.SID "
                           "JOIN Computers C ON C.ID = I.CID "
                           "ORDER BY C.Name;");
                break;
        default:
                 query.exec("SELECT S.Name as s_name, C.Name as c_name "
                            "FROM Scientists S "
                            "JOIN Invented I ON S.ID = I.SID "
                            "JOIN Computers C ON C.ID = I.CID "
                            "ORDER BY S.Name;");
    }
    /*query.exec("SELECT S.Name as s_name, C.Name as c_name "
               "FROM Scientists S "
               "JOIN Invented I ON S.ID = I.SID "
               "JOIN Computers C ON C.ID = I.CID;");*/

    while(query.next())
    {
        string sName = query.value("s_name").toString().toStdString();
        string cName = query.value("c_name").toString().toStdString();
        connections.push_back(Invented(sName, cName));
    }

    return connections;
}

vector<Invented> DataAccess::getListOfComputersAndScientistsDesc(int n)
{
    vector<Invented> connections;
    QSqlQuery query(_db);
    switch(n)
    {
        case 0:
                query.exec("SELECT S.Name as s_name, C.Name as c_name "
                           "FROM Scientists S "
                           "JOIN Invented I ON S.ID = I.SID "
                           "JOIN Computers C ON C.ID = I.CID "
                           "ORDER BY S.Name DESC;");
                break;
        case 1:
                query.exec("SELECT S.Name as s_name, C.Name as c_name "
                           "FROM Scientists S "
                           "JOIN Invented I ON S.ID = I.SID "
                           "JOIN Computers C ON C.ID = I.CID "
                           "ORDER BY C.Name DESC;");
                break;
        default:
                 query.exec("SELECT S.Name as s_name, C.Name as c_name "
                            "FROM Scientists S "
                            "JOIN Invented I ON S.ID = I.SID "
                            "JOIN Computers C ON C.ID = I.CID "
                            "ORDER BY S.Name DESC;");
    }
    /*query.exec("SELECT S.Name as s_name, C.Name as c_name "
               "FROM Scientists S "
               "JOIN Invented I ON S.ID = I.SID "
               "JOIN Computers C ON C.ID = I.CID;");*/

    while(query.next())
    {
        string sName = query.value("s_name").toString().toStdString();
        string cName = query.value("c_name").toString().toStdString();
        connections.push_back(Invented(sName, cName));
    }

    return connections;
}
