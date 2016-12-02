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
    //Returns member variable _scientists.
    vector<Scientist> getScientists();
    //Four functions that order _scientists by different variables.
    void ScientistsOrderByName();
    void ScientistsOrderByDoB();
    void ScientistsOrderByDoD();
    void ScientistsOrderByGender();
    Scientist findScientistByName(string name);
    void addScientist(string n, string bd, string dd, string g);
    int deleteScientist(string name);
    void editScientist(string originName, string name, string dob, string dod, string g);

private:
    DataAccess _data;
    vector<Scientist> _scientists;
    //Helper function for find, add and delete.
    int findScientistName(string name);
    //Helper function that fills vector. Called by constructor
    void createScientists();
    //Helper function that constructs the string that is written to file in DataAccess.
    void constructString(string& s, string name, string dob, string dod, string g);
    string constructStringForFile();
    size_t size();
};

#endif // SCIENTISTSERVICE_H
