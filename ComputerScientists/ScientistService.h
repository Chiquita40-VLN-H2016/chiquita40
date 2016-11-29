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
public:
    ScientistService();
    vector<Scientist> getScientistsOrderByName();
    vector<Scientist> getScientistsOrderByDoB();
    vector<Scientist> getScientistsOrderByDoD();
    vector<Scientist> getScientistsOrderByGender();
    Scientist findScientistByName(string name);
    void addScientist(string n, int bd, int dd, char g);
    void deleteScientist(string name);
private:
    int findScientistName(string name);
};

#endif // SCIENTISTSERVICE_H
