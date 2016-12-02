#ifndef SCIENTISTSERVICE_H
#define SCIENTISTSERVICE_H
#include "Scientist.h"
#include "DataAccess.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//Struct to order by name.
struct NameComparison
{
  bool operator() (Scientist i,Scientist j) { return (i.getName()<j.getName());}
};

//Struct to order by date of birth.
struct DoBComparison
{
  bool operator() (Scientist i,Scientist j) { return (i.getBirthDate()<j.getBirthDate());}
};

//Struct to order by date of death.
struct DoDComparison
{
  bool operator() (Scientist i,Scientist j) { return (i.getDeathDate()<j.getDeathDate());}
};

//Struct to order by gender.
struct GenderComparison
{
  bool operator() (Scientist i,Scientist j) { return (i.getGender()<j.getGender());}
};

class ScientistService
{
public:
    ScientistService();
    vector<Scientist> getScientists(); //Returns member variable _scientists.
    void ScientistsOrderByName(); //Order scientists by name.
    void ScientistsOrderByDoB(); //Order scientists by birth year.
    void ScientistsOrderByDoD(); //Order scientists by death year.
    void ScientistsOrderByGender(); //Order scientists by gender.
    Scientist findScientistByName(string name);
    void addScientist(string n, string bd, string dd, string g);
    int deleteScientist(string name);
    void editScientist(string originName, string name, string dob, string dod, string g);

private:
    DataAccess _data;
    vector<Scientist> _scientists;
    size_t size();
    string constructStringForFile();
    int findScientistName(string name); //Helper function to find, add and delete scientist.
    void createScientists(); //Helper function that fills vector. Called by constructor.
    //Helper function that constructs the string that is written to file in DataAccess.
    void constructString(string& s, string name, string dob, string dod, string g);
};

#endif // SCIENTISTSERVICE_H
