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
        string s2;
        constructString(s2, n, bd, dd, g);
       _data.addScientist(s2);
    }
}

void ScientistService::deleteScientist(string name)
{
    vector<Scientist> scientists = getScientistsOrderByName();
    int n = findScientistName(name);
    if(n != -1){
        scientists.erase(scientists.begin()+n);
        string s;
        for(size_t i = 0; i < scientists.size(); i++)
        {
            Scientist sc = scientists.at(i);
            string n = sc.getName();
            int bd = sc.getBirthDate();
            int dd = sc.getDeathDate();
            char g = sc.getGender();
            constructString(s, n, bd, dd, g);
            if(i != scientists.size()-1)
            {
               s.push_back('\n');
            }
        }
        _data.deleteScientist(s);
    }
}
//Private
int ScientistService::findScientistName(string name)
{
    Scientist s;
    vector<Scientist> scientists = getScientistsOrderByName();
    size_t size = scientists.size();

    for(unsigned int i = 0; i < size; i++){
        s = scientists.at(i);
        if(s.getName() == name){
            return i;
        }
    }
    return -1;
}

vector<Scientist> ScientistService::getScientists()
{
    vector<string> list = _data.getData();
    vector<Scientist> scientists;
    int count = 1, dob, dod;
    string name;
    char g;
    for(size_t i = 0; i < list.size(); i++){
        if(count == 1){
            name = list.at(i);
        }
        if(count == 2){
            name+= list.at(i);
        }
        if(count == 3){
            dob = stoi(list.at(i));
        }
        if(count == 4){
            dod = stoi(list.at(i));
        }
        if(count == 5){
            g = list.at(i).front();
            Scientist sc(name, dob, dod, g);
            scientists.push_back(sc);
            count = 0;
        }
        count++;
    }
    return scientists;
}

void ScientistService::constructString(string& s, string name, int dob, int dod, char g)
{
    s+=name;
    s.push_back('\t');
    s+=to_string(dob);
    s.push_back('\t');
    s+=to_string(dod);
    s.push_back('\t');
    s.push_back(g);
}
