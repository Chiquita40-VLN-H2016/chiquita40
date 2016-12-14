#include "Scientist.h"

Scientist::Scientist()
{

}
Scientist::Scientist(int id, string n, int bd, int dd, char g)
{
    _id = id;
    _name = n;
    _birthDate = bd;
    _deathDate = dd;
    _gender = g;
}

int Scientist::getId() const
{
    return _id;
}

string Scientist::getName() const
{
    return _name;
}

int Scientist::getBirthDate() const
{
    return _birthDate;
}

int Scientist::getDeathDate() const
{
    return _deathDate;
}

char Scientist::getGender() const
{
    return _gender;
}

void Scientist::setId(int id)
{
    _id = id;
}

void Scientist::setName(string name)
{
    _name = name;
}

void Scientist::setBirthDate(int bd)
{
    _birthDate = bd;
}

void Scientist::setDeathDate(int dd)
{
    _deathDate = dd;
}

void Scientist::setGender(char g)
{
    _gender = g;
}

string Scientist::toString()
{
    string s = "";
    s+= to_string(_id);
    s+= '\t';
    s+= _name + addTab();
    s+= to_string(_birthDate);
    s+= '\t';
    if(_deathDate == 9999)
    {
        s+= "Alive";
        s+= '\t';
    }
    else
    {
        s+= to_string(_deathDate);
        s+= '\t';
    }
    if(_gender == 'f' || _gender == 'F')
    {
        s+= "F";
    }
    else
    {
        s+= "M";
    }

    return s;
}

string Scientist::addTab()
{
    string tab = "";
    if(_name.size() < 24 && _name.size() > 13)
    {
        tab = "\t";
    }
    else if(_name.size() <=13)
    {
        tab = "\t\t";
    }
    return tab;
}

//Overload of outstream operator to print out scientist.
ostream& operator << (ostream& out, Scientist s)
{
    out << s.getId() << '\t';
    out << s.addTab(out, s.getName());
    out << s.getBirthDate() << '\t';
    if(s.getDeathDate() == 9999)
    {
        out << "Alive" << '\t';
    }
    else
    {
        out << s.getDeathDate() << '\t';
    }
    if(s.getGender() == 'f' || s.getGender() == 'F')
    {
        out << "F" << endl;
    }
    else
    {
        out << "M" << endl;
    }

    return out;
}

//If name is shorter than 24 characters, even out table spaces.
string Scientist::addTab(ostream& out, string name)
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
