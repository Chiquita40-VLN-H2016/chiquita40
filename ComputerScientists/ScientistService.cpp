#include "ScientistService.h"

ScientistService::ScientistService()
{
}

vector<Scientist> ScientistService::getScientistsOrderByName()
{
    vector<Scientist> scientists = getScientists();
    NameComparison cmp;
    std::sort(scientists.begin(), scientists.end(), cmp);
    return scientists;
}

vector<Scientist> ScientistService::getScientistsOrderByDoB()
{
    vector<Scientist> scientists = getScientists();
    DoBComparison cmp;
    std::sort(scientists.begin(), scientists.end(), cmp);
    return scientists;
}

vector<Scientist> ScientistService::getScientistsOrderByDoD()
{
    vector<Scientist> scientists = getScientists();
    DoDComparison cmp;
    std::sort(scientists.begin(), scientists.end(), cmp);
    return scientists;
}

vector<Scientist> ScientistService::getScientistsOrderByGender()
{
    vector<Scientist> scientists = getScientists();
    GenderComparison cmp;
    std::sort(scientists.begin(), scientists.end(), cmp);
    return scientists;
}

Scientist *ScientistService::findScientistByName(string name)
{
    vector<Scientist> scientists = getScientistsOrderByName();
    int n = findScientistName(name);
    if(n != -1){
        return &scientists.at(n);
    }
    return nullptr;
}

void ScientistService::addScientist(string n, int bd, int dd, char g)
{
    Scientist *s1 = findScientistByName(n);
    if(s1 == nullptr){
        Scientist s2(n, bd, dd, g);
       // _data.addScientist(s2);
    }
}

void ScientistService::deleteScientist(string name)
{
    vector<Scientist> scientists = getScientistsOrderByName();
    int n = findScientistName(name);
    if(n != -1){
        scientists.erase(scientists.begin()+n);
        //_data.deleteScientist(scientists);
    }
}
//Private
int ScientistService::findScientistName(string name)
{
    Scientist s;
    vector<Scientist> scientists = getScientistsOrderByName();
    size_t size = scientists.size();
    for(size_t i = 0; i < size; i++){
        s = scientists.at(i);
        if(s.getName() == name){
            return i;
        }
    }
    return -1;
}

vector<Scientist> ScientistService::getScientists()
{
    //string list = _data.getData();
    vector<Scientist> scientists;
    //TODO: split list by some feature.
    //Fill scientists vector in a forloop.
    return scientists;
}
