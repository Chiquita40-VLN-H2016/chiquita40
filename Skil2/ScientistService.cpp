#include "ScientistService.h"

ScientistService::ScientistService()
{
    _scientists = _data.getScientists();
}

vector<Scientist> ScientistService::getScientists()
{
    return _scientists;
}

void ScientistService::ScientistsAscendingOrder(int n) //Ascending order.
{
    _scientists = _data.ScientistsAscendingOrder(n);
    //NameComparison cmp;
    //std::sort(_scientists.begin(), _scientists.end(), cmp);
}

void ScientistService::ScientistsDescendingOrder(int n) //Descending order.
{
    _scientists = _data.ScientistsDescendingOrder(n);
    //DoBComparison cmp;
    //std::sort(_scientists.begin(), _scientists.end(), cmp);
}

/*void ScientistService::ScientistsOrderByDoD() //Order scientists by death year.
{
    DoDComparison cmp;
    std::sort(_scientists.begin(), _scientists.end(), cmp);
}

void ScientistService::ScientistsOrderByGender() //Order scientists by gender.
{
    GenderComparison cmp;
    std::sort(_scientists.begin(), _scientists.end(), cmp);
}*/

vector<Scientist> ScientistService::findScientistByYear(int year)
{
    vector<Scientist> scientists = _data.findScientistByYear(year);
    return scientists;
}

vector<Scientist> ScientistService::findScientistByName(string search)
{
    vector<Scientist> scientists = _data.findScientistByName(search);
    /*int n = findScientistName(name);

    if(n != -1)
    {
        return _scientists.at(n);
    }
    Scientist s("", 0, 0,' '); //If Scientist is not found in list an empty scientist is returned.

    return s;*/
    return scientists;
}

//Checks whether scientist exists in list and only adds the new one if it doesn't.
void ScientistService::addScientist(string n, int bd, int dd, char g)
{
    //int n1 = findScientistName(n);

    Scientist sc(-1, n, bd, dd, g);
    int i = _data.addScientist(sc);
    sc.setId(i); //sc.id now has the right value from the database.
    _scientists.push_back(sc);
    /*if(n1 == -1)
    {
        string s2;
        constructString(s2, n, bd, dd, g);
        _data.addScientist(s2);
        Scientist sc(n, bd, dd, g);
        _scientists.push_back(sc);
    }*/
}

int ScientistService::deleteScientist(int id)
{

    int n = findScientistId(id);
    if(n != -1)
    {
        _data.deleteScientist(id);
        _scientists.erase(_scientists.begin()+n);
        //string s = constructStringForFile();
        //_data.deleteScientist(s);
    }

    return n;
}

void ScientistService::editScientist(int id, string name, int dob, int dod, char g)
{
    int n = findScientistId(id);
    if(n != -1)
    { //Information on scientist updated using set functions.
        _scientists.at(n).setName(name);
        _scientists.at(n).setBirthDate(dob);
        _scientists.at(n).setDeathDate(dod);
        _scientists.at(n).setGender(g);
        //string s = constructStringForFile();
        _data.editScientist(_scientists.at(n));
        //_data.deleteScientist(s); //delete function in data used to overwrite file with updated version.
    }
}

void ScientistService::closeDb()
{
    _data.dbClose();
}

int ScientistService::findScientistId(int id)
{
    Scientist s;

    for(unsigned int i = 0; i < size(); i++)
    {
        s = _scientists.at(i);
        if(s.getId() == id)
        {
            return i;
        }
    }

    return -1;
}

bool ScientistService::validYearCheck(int year)
{
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);

    if(year >= 1000 && year <= timePtr->tm_year + 1900)
    {
        return true;
    }

    return false;

}

/*string ScientistService::constructStringForFile() //Creates vector to print in file.
{
    string s;

    for(size_t i = 0; i < size(); i++)
    {
        Scientist sc = _scientists.at(i);
        string n = sc.getName();
        int bd = sc.getBirthDate();
        int dd = sc.getDeathDate();
        char g = sc.getGender();
        constructString(s, n, bd, dd, g); //Adds tabs to file where appropriate for correct setup in file.
        if(i != size()-1)
        {
           s.push_back('\n');
        }
    }

    return s;
}*/

/*void ScientistService::createScientists() //Helper function that fills vector.
{
    vector<string> list = _data.getData();
    int count = 1;
    string name;
    int dob, dod;
    char g;

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
        if(count == 5) //All information on scientists have been gathered so this round is finished by
        {              //adding the scientist to the vector and a new circle begins.
            g = list.at(i);
            Scientist sc(name, dob, dod, g);
            _scientists.push_back(sc);
            count = 0;
        }
        count++;
    }
}*/

//Adds tabs to file where appropriate.
/*void ScientistService::constructString(string& s, string name, int dob, int dod, char g)
{
    s+=name;
    s.push_back('\t');
    s+=dob;
    s.push_back('\t');
    s+=dod;
    s.push_back('\t');
    s+=g;
}*/

size_t ScientistService::size()
{
    return _scientists.size();
}