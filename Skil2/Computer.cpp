#include "Computer.h"

Computer::Computer()
{

}

Computer::Computer(int id, string n, int b, string t, bool wb)
{
    _id = id;
    _name = n;
    _buildYear = b;
    _type = t;
    _wasBuilt = wb;
}

string Computer::getName() const
{
    return _name;
}
int Computer::getBuildYear() const
{
    return _buildYear;
}
string Computer::getType() const
{
    return _type;
}
bool Computer::getWasBuilt() const
{
    return _wasBuilt;
}
void Computer::setName(string name)
{
    _name = name;
}

void Computer::setBuildYear(int by)
{
    _buildYear = by;
}

void Computer::setType(string type)
{
    _type = type;
}

void Computer::setWasBuilt(bool wasb)
{
    _wasBuilt = wasb;
}
