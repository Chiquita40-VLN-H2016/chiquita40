#include "ComputerService.h"

ComputerService::ComputerService()
{
    _computers = _data.getComputers();
}

vector<Computer> ComputerService::getComputers()
{
    return _computers;
}

void ComputerService::ComputersAscendingOrder(int n) //Ascending order.
{
    _computers = _data.ComputersAscendingOrder(n);
}

void ComputerService::ComputersDescendingOrder(int n) //Descending order.
{
    _computers = _data.ComputersDescendingOrder(n);
}

/*void ComputerService::ComputersOrderByName() //Order computers by name.
{
    NameComparisonComputer cmp;
    std::sort(_computers.begin(), _computers.end(), cmp);
}

void ComputerService::ComputersOrderByBuildYear() //Order computers by year built.
{
    BuildYearComparison cmp;
    std::sort(_computers.begin(), _computers.end(), cmp);
}

void ComputerService::ComputersOrderByType() //Order computers by type.
{
    TypeComparison cmp;
    std::sort(_computers.begin(), _computers.end(), cmp);
}

void ComputerService::ComputersOrderByWasBuilt() //Order computers by if computer was built or not.
{
    WasBuiltComparison cmp;
    std::sort(_computers.begin(), _computers.end(), cmp);
}*/

vector<Computer> ComputerService::findComputerByName(string name)
{
    vector<Computer> computers = _data.findComputerByName(name);

    return computers;
}

void ComputerService::addComputer(string n, int b, string t, string wb)
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

int ComputerService::deleteComputer(string name)
{
    int n = findComputerName(name);
    _data.deleteComputer(_computers.at(n));
    if(n != -1)
    {
        _computers.erase(_computers.begin()+n);
    }

    return n;
}

void ComputerService::editComputer(string originName, string name, int by, string type, string wasb)
{
    bool wasBuilt = false;

    if (wasb == "yes" || wasb == "Yes" || wasb == "YES")
    {
        wasBuilt = true;
    }

    int n = findComputerName(originName);
    if(n != -1)
    {
        _computers.at(n).setName(name);
        _computers.at(n).setBuildYear(by);
        _computers.at(n).setType(type);
        _computers.at(n).setWasBuilt(wasBuilt);

        _data.editComputer(_computers.at(n));
    }
}

/*void ComputerService::createComputers()
{
    //Erum ekki lengur að constructa string.. það þarf að útfæra annað í staðinn fyrir það.
}*/

int ComputerService::findComputerName(string name)
{
    Computer c;

    for(unsigned int i = 0; i < size(); i++)
    {
        c = _computers.at(i);
        if(c.getName() == name)
        {
            return i;
        }
    }

    return -1;
}

size_t ComputerService::size()
{
    return _computers.size();
}
