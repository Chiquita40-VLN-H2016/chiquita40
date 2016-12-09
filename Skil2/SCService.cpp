#include "SCService.h"

SCService::SCService()
{
    _scientists = _data.getScientists();
    _computers = _data.getComputers();
}

vector<Scientist> SCService::getScientists()
{
    return _scientists;
}

vector<Computer> SCService::getComputers()
{
    return _computers;
}

void SCService::scientistsAscendingOrder(int n) //Ascending order.
{
    _scientists = _data.scientistsAscendingOrder(n);
}

void SCService::computersAscendingOrder(int n) //Ascending order.
{
    _computers = _data.computersAscendingOrder(n);
}

vector<Invented> SCService::inventedAscendingOrder(int n)
{
    vector<Invented> connections = _data.getListOfComputersAndScientistsAsc(n);
    return connections;
}

void SCService::scientistsDescendingOrder(int n) //Descending order.
{
    _scientists = _data.scientistsDescendingOrder(n);
}

void SCService::computersDescendingOrder(int n) //Descending order.
{
    _computers = _data.computersDescendingOrder(n);
}

vector<Invented> SCService::inventedDescendingOrder(int n)
{
    vector<Invented> connections = _data.getListOfComputersAndScientistsDesc(n);
    return connections;
}

vector<Scientist> SCService::findScientistByYear(int year)
{
    vector<Scientist> scientists = _data.findScientistByYear(year);
    return scientists;
}

vector<Computer> SCService::findComputerByYear(int year)
{
    vector<Computer> computers = _data.findComputerByYear(year);
    return computers;
}

vector<Scientist> SCService::findScientistByName(string search)
{
    vector<Scientist> scientists = _data.findScientistByName(search);

    return scientists;
}

vector<Scientist> SCService::findScientistByComputer(int id)
{
    vector<Scientist> sc;

    sc = _data.getScientistsByComputer(id);

    return sc;
}


vector<Computer> SCService::findComputerByName(string search)
{
    vector<Computer> computers = _data.findComputerByName(search);

    return computers;
}

vector<Computer> SCService::findComputerByScientist(int id)
{
    vector<Computer> c;

    c = _data.getComputersByScientist(id);

    return c;
}

//Checks whether scientist exists in list and only adds the new one if it doesn't.
void SCService::addScientist(string n, int bd, int dd, char g)
{
    Scientist sc(-1, n, bd, dd, g);
    int i = _data.addScientist(sc);
    sc.setId(i); //sc.id now has the right value from the database.
    _scientists.push_back(sc);
}

void SCService::addComputer(string n, int b, string t, string wb)
{
    bool wasBuilt = false;

    if (wb == "yes" || wb == "Yes" || wb == "YES")
    {
        wasBuilt = true;
    }

    Computer c(-1, n, b, t, wasBuilt);
    int i = _data.addComputer(c);
    c.setId(i);

    _computers.push_back(c);
}
int SCService::deleteScientist(int id)
{

    int n = findScientistId(id);
    if(n != -1)
    {
        _data.deleteScientist(id);
        _scientists.erase(_scientists.begin()+n);
    }

    return n;
}

int SCService::deleteComputer(int id)
{
    int n = findComputerId(id);
    if(n != -1)
    {
        _data.deleteComputer(id);
        _computers.erase(_computers.begin()+n);
    }

    return n;
}

void SCService::editScientist(int id, string name, int dob, int dod, char g)
{
    int n = findScientistId(id);
    if(n != -1)
    { //Information on scientist updated using set functions.
        _scientists.at(n).setName(name);
        _scientists.at(n).setBirthDate(dob);
        _scientists.at(n).setDeathDate(dod);
        _scientists.at(n).setGender(g);
        _data.editScientist(_scientists.at(n));
    }
}

Scientist SCService::scientistToEdit(int id)
{
    int n = findScientistId(id);
    if(n != -1)
    {
        return _scientists.at(n);
    }
    Scientist s(-1, "", -1, -1, ' ');
    return s;
}

void SCService::editComputer(int id, string name, int by, string type, string wasb)
{
    bool wasBuilt = false;

    if (wasb == "yes" || wasb == "Yes" || wasb == "YES")
    {
        wasBuilt = true;
    }

    int n = findComputerId(id);
    if(n != -1)
    {
        _computers.at(n).setName(name);
        _computers.at(n).setBuildYear(by);
        _computers.at(n).setType(type);
        _computers.at(n).setWasBuilt(wasBuilt);

        _data.editComputer(_computers.at(n));
    }
}

Computer SCService::computerToEdit(int id)
{
    int n = findComputerId(id);
    if(n != -1)
    {
        return _computers.at(n);
    }
    Computer c(-1, "", -1, "", false);
    return c;
}

int SCService::findScientistId(int id)
{
    Scientist s;

    for(unsigned int i = 0; i < sSize(); i++)
    {
        s = _scientists.at(i);
        if(s.getId() == id)
        {
            return i;
        }
    }

    return -1;
}

int SCService::findComputerId(int id)
{
    Computer c;

    for(unsigned int i = 0; i < cSize(); i++)
    {
        c = _computers.at(i);
        if(c.getId() == id)
        {
            return i;
        }
    }

    return -1;
}

bool SCService::validYearCheck(int year)
{
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);

    if(year >= 1000 && year <= timePtr->tm_year + 1900)
    {
        return true;
    }

    return false;

}

bool SCService::checkIfContainsNumber(string s)
{
    for(size_t i = 0; i < s.length(); i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            return true;
        }
    }
    return false;
}

size_t SCService::cSize()
{
    return _computers.size();
}

size_t SCService::sSize()
{
    return _scientists.size();
}

void SCService::joinSC(int sid, int cid)
{
    _data.joinScientistAndComputer(sid, cid);
}
