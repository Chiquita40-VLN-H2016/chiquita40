#include "Scientist.h"

Scientist::Scientist()
{

}
Scientist::Scientist(string n, string bd, string dd, string g)
{
    _name = n;
    _birthDate = bd;
    _deathDate = dd;
    _gender = g;
}

string Scientist::getName() const
{
    return _name;
}

string Scientist::getBirthDate() const
{
    return _birthDate;
}

string Scientist::getDeathDate() const
{
    return _deathDate;
}

string Scientist::getGender() const
{
    return _gender;
}

void Scientist::setName(string name)
{
    _name = name;
}

void Scientist::setBirthDate(string bd)
{
    _birthDate = bd;
}

void Scientist::setDeathDate(string dd)
{
    _deathDate = dd;
}

void Scientist::setGender(string g)
{
    _gender = g;
}

ostream& operator << (ostream& out, Scientist s)
{
    out << s.addTab(out, s.getName());
    out << s.getBirthDate() << '\t';
    out << s.getDeathDate() << '\t';
    out << s.getGender() << endl;

    return out;
}

// If name is shorter than 16 characters, print 2 tabs
string Scientist::addTab(ostream& out, string name)
{
    string tab = "\t";

    if(name.size() < 16 && name.size() > 7)
    {
        out << name << tab << tab;
    }
    else if(name.size() < 8)
    {
        out << name << tab << tab << tab;
    }
    else
    {
        out << name << tab;
    }

    return tab;
}
