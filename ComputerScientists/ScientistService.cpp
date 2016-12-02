#include "ScientistService.h"

ScientistService::ScientistService()
{
    createScientists(); //Helper function that fills vector.
}

vector<Scientist> ScientistService::getScientists()
{
    return _scientists;
}

void ScientistService::ScientistsOrderByName() //Order scientists by name.
{
    NameComparison cmp;
    std::sort(_scientists.begin(), _scientists.end(), cmp);
}

void ScientistService::ScientistsOrderByDoB() //Order scientists by birth year.
{
    DoBComparison cmp;
    std::sort(_scientists.begin(), _scientists.end(), cmp);
}

void ScientistService::ScientistsOrderByDoD() //Order scientists by death year.
{
    DoDComparison cmp;
    std::sort(_scientists.begin(), _scientists.end(), cmp);
}

void ScientistService::ScientistsOrderByGender() //Order scientists by gender.
{
    GenderComparison cmp;
    std::sort(_scientists.begin(), _scientists.end(), cmp);
}

Scientist ScientistService::findScientistByName(string name)
{
    int n = findScientistName(name);

    if(n != -1)
    {
        return _scientists.at(n);
    }
    Scientist s("", "", "", "");

    return s;
}

//Checks whether scientist exists in list and only adds the new one if it doesn't.
void ScientistService::addScientist(string n, string bd, string dd, string g)
{
    int n1 = findScientistName(n);

    if(n1 == -1)
    {
        string s2;
        constructString(s2, n, bd, dd, g);
        _data.addScientist(s2);
        Scientist sc(n, bd, dd, g);
        _scientists.push_back(sc);
    }
}

int ScientistService::deleteScientist(string name)
{
    int n = findScientistName(name);

    if(n != -1)
    {
        _scientists.erase(_scientists.begin()+n);
        string s = constructStringForFile();
        _data.deleteScientist(s);
    }

    return n;
}

void ScientistService::editScientist(string originName, string name, string dob, string dod, string g)
{
    int n = findScientistName(originName);
    if(n != -1)
    {
        _scientists.at(n).setName(name);
        _scientists.at(n).setBirthDate(dob);
        _scientists.at(n).setDeathDate(dod);
        _scientists.at(n).setGender(g);
        string s = constructStringForFile();
        _data.deleteScientist(s);
    }
}

int ScientistService::findScientistName(string name)
{
    Scientist s;

    for(unsigned int i = 0; i < size(); i++)
    {
        s = _scientists.at(i);
        if(s.getName() == name)
        {
            return i;
        }
    }

    return -1;
}

string ScientistService::constructStringForFile() //Creates vector to print in file.
{
    string s;

    for(size_t i = 0; i < size(); i++)
    {
        Scientist sc = _scientists.at(i);
        string n = sc.getName();
        string bd = sc.getBirthDate();
        string dd = sc.getDeathDate();
        string g = sc.getGender();
        constructString(s, n, bd, dd, g); //Adds tabs to file where appropriate.
        if(i != size()-1)
        {
           s.push_back('\n');
        }
    }

    return s;
}

void ScientistService::createScientists() //Helper function that fills vector.
{
    vector<string> list = _data.getData();
    int count = 1;
    string name, dob, dod, g;

    for(size_t i = 0; i < list.size(); i++)
    {
        if(count == 1)
        {
            name = list.at(i);
            name.push_back(' ');
        }
        if(count == 2)
        {
            name+= list.at(i);
        }
        if(count == 3)
        {
            dob = list.at(i);
        }
        if(count == 4)
        {
            dod = list.at(i);
        }
        if(count == 5)
        {
            g = list.at(i);
            Scientist sc(name, dob, dod, g);
            _scientists.push_back(sc);
            count = 0;
        }
        count++;
    }
}

//Adds tabs to file where appropriate.
void ScientistService::constructString(string& s, string name, string dob, string dod, string g)
{
    s+=name;
    s.push_back('\t');
    s+=dob;
    s.push_back('\t');
    s+=dod;
    s.push_back('\t');
    s+=g;
}

size_t ScientistService::size()
{
    return _scientists.size();
}
