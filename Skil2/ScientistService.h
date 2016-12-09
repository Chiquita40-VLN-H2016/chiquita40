#ifndef SCIENTISTSERVICE_H
#define SCIENTISTSERVICE_H
#include "Scientist.h"
#include "DataAccess.h"
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

//Struct to order by name.
struct NameComparisonScientist
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
    void ScientistsAscendingOrder(int n); //Ascending Order.
    void ScientistsDescendingOrder(int n); //Descending Order scientists by birth year.
    //void ScientistsOrderByDoD(); //Order scientists by death year.
    //void ScientistsOrderByGender(); //Order scientists by gender.
    vector<Scientist> findScientistByYear(int year);
    vector<Scientist> findScientistByName(string search);
    void addScientist(string n, int bd, int dd, char g);
    bool validYearCheck(int year);
    int deleteScientist(int id);
    void editScientist(int id, string name, int dob, int dod, char g);
    void closeDb();

private:
    DataAccess _data;
    vector<Scientist> _scientists;
    size_t size();
    //string constructStringForFile();
    int findScientistId(int id); //Helper function to find, add, edit and delete scientist.
    //void createScientists(); //Helper function that fills vector. Called by constructor.
    //Helper function that constructs the string that is written to file in DataAccess.
    void constructString(string& s, string name, int dob, int dod, char g);
};

#endif // SCIENTISTSERVICE_H
