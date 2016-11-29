#include "ScientistService.h"

ScientistService::ScientistService()
{
}

vector<Scientist> ScientistService::getScientistsOrderByName()
{
    //TODO: ná í upplýsingar úr dataAccess og búa til scientists vector;
    String list = _data.getData();
    vector<Scientist> scientists;
    NameComparison cmp;
    std::sort(scientists.begin(), scientists.end(), cmp);
    return scientists;
}

vector<Scientist> ScientistService::getScientistsOrderByDoB()
{
    //TODO: ná í upplýsingar úr dataAccess og búa til scientists vector;
    String list = _data.getData();
    vector<Scientist> scientists;
    DoBComparison cmp;
    std::sort(scientists.begin(), scientists.end(), cmp);
    return scientists;
}

vector<Scientist> ScientistService::getScientistsOrderByDoD()
{
    //TODO: ná í upplýsingar úr dataAccess og búa til scientists vector;
    String list = _data.getData();
    vector<Scientist> scientists;
    DoDComparison cmp;
    std::sort(scientists.begin(), scientists.end(), cmp);
    return scientists;
}

vector<Scientist> ScientistService::getScientistsOrderByGender()
{
    //TODO: ná í upplýsingar úr dataAccess og búa til scientists vector;
    String list = _data.getData();
    vector<Scientist> scientists;
    GenderComparison cmp;
    std::sort(scientists.begin(), scientists.end(), cmp);
    return scientists;
}

Scientist ScientistService::findScientistByName(string name)
{
    vector<Scientist> scientists = getScientistsOrderByName();
    int n = findScientistName(name);
    if(n != -1){
        return scientists.at(i);
    }
    return null;
}

void ScientistService::addScientist(string n, int bd, int dd, char g)
{
    Scientist s1 = findScientistByName(n);
    if(s1 == null){
        Scientist s2 = new Scientist(n, bd, dd, g);
        _data.addScientist(s2);
    }
}

void ScientistService::deleteScientist(string name)
{
    vector<Scientist> scientists = getScientistsOrderByName();
    int n = findScientistName(name);
    if(n != -1){
        scientists.erase(scientists.begin()+n);
        _data.deleteScientists(scientists);
    }
}
//Private
int ScientistService::findScientistName(string name)
{
    Scientist s;
    vector<Scientist> scientists = getScientistsOrderByName();
    int size = scientists.size();
    for(int i = 0; i < size; i++){
        s = scientists.at(i);
        if(s.getName() == name){
            return i;
        }
    }
    return -1;
}
