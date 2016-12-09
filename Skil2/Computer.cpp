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

int Computer::getId() const
{
    return _id;
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
void Computer::setId(int id)
{
    _id = id;
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
//Overload of outstream operator to print out computer.
ostream& operator << (ostream& out, Computer c)
{
    out << c.getId() << '\t';
    out << c.addTab(out, c.getName());
    if(c.getBuildYear() == 0)
    {
        out << " " << '\t';
    }
    else
    {
         out << c.getBuildYear() << '\t';
    }
    out << c.getType() << '\t';
    if(c.getWasBuilt())
    {
        out << "Yes" << endl;
    }
    else
    {
        out << "No" << endl;
    }

    return out;
}

//If name is shorter than 24 characters, even out table spaces.
string Computer::addTab(ostream& out, string name)
{
    string tab = "\t";

    if(name.size() < 24 && name.size() > 15)
    {
        out << name << tab;
    }
    else if(name.size() < 16 && name.size() > 7)
    {
        out << name << tab << tab;
    }
    else if(name.size() < 8)
    {
        out << name << tab << tab << tab;
    }
    else
    {
        out << name;
    }

    return tab;
}
