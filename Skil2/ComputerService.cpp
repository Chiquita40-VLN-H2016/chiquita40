#include "ComputerService.h"

ComputerService::ComputerService()
{
    //Það þarf að útfæra createComputer fall.
    //createComputers();
}

vector<Computer> ComputerService::getComputers()
{
    return _computers;
}

void ComputerService::ComputersOrderByName() //Order computers by name.
{
    NameComparison cmp;
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
}

Computer ComputerService::findComputerByName(string name)
{
    int n = findScientistName(name);

    if(n != -1)
    {
        return _computers.at(n);
    }
    Computer c("", 0, "", ""); //If computer is not found in list an empty computer is returned.

    return c;
}

void ComputerService::addComputer(string n, int b, string t, string wb)
{
    //Erum ekki lengur að constructa string.. það þarf að útfæra annað í staðinn fyrir það.
}

int ComputerService::deleteComputer(string name)
{
    //Erum ekki lengur að constructa string.. það þarf að útfæra annað í staðinn fyrir það.
}

void ComputerService::editComputer(string originName, string name, int by, string type, string wasb)
{
    //Erum ekki lengur að constructa string.. það þarf að útfæra annað í staðinn fyrir það.
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
