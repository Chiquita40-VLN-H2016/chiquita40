#include "Invented.h"

Invented::Invented()
{

}

Invented::Invented(string s, string c, int sId, int cId)
{
    _sName = s;
    _cName = c;
    _sId = sId;
    _cId = cId;
}

string Invented::getSName()
{
    return _sName;
}

string Invented::getCName()
{
    return _cName;
}

int Invented::getSId()
{
    return _sId;
}

int Invented::getCId()
{
    return _cId;
}

//Overload of outstream operator to print out Invented list.
ostream& operator << (ostream& out, Invented i)
{
    out << i.addTab(out, i.getSName());
    out << i.getCName() << endl;

    return out;
}

string Invented::toString()
{
    string i = "";
    i+= to_string(_sId);
    i+= '\t';
    i+= _sName + addTab(_sName);
    i+= to_string(_cId);
    i+= '\t';
    i+= _cName + addTab(_cName);

    return i;
}

string Invented::addTab(string i)
{
    string tab = "";
    if(i.size() < 24 && i.size() > 13)
    {
        tab = "\t";
    }
    else if(i.size() <= 13)
    {
        tab = "\t\t";
    }

    return tab;
}

//If name is shorter than 24 characters, even out table spaces.
string Invented::addTab(ostream& out, string name)
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
