#ifndef SCIENTISTSERVICE_H
#define SCIENTISTSERVICE_H
#include "Scientist.h"
#include "DataAccess.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct NameComparison {
  bool operator() (Scientist i,Scientist j) { return (i.getName()<j.getName());}
};
struct DoBComparison {
  bool operator() (Scientist i,Scientist j) { return (i.getBirthDate()<j.getBirthDate());}
};
struct DoDComparison {
  bool operator() (Scientist i,Scientist j) { return (i.getDeathDate()<j.getDeathDate());}
};
struct GenderComparison {
  bool operator() (Scientist i,Scientist j) { return (i.getGender()<j.getGender());}
};


class ScientistService
{
private:
    DataAccess _data;
    vector<Scientist> _scientists;
    size_t size();
public:
    ScientistService();
    vector<Scientist> getScientists();
    void ScientistsOrderByName();
    void ScientistsOrderByDoB();
    void ScientistsOrderByDoD();
    void ScientistsOrderByGender();
    Scientist *findScientistByName(string name);
    void addScientist(string n, string bd, string dd, string g);
    void deleteScientist(string name);
private:
    int findScientistName(string name);
    void createScientists();
    void constructString(string& s, string name, string dob, string dod, string g);
};

#endif // SCIENTISTSERVICE_H
