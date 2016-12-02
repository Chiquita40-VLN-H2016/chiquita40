#ifndef SCIENTIST_H
#define SCIENTIST_H
#include <iostream>
#include <string>

using namespace std;

class Scientist
{
public:
    Scientist();
    Scientist(string n, string bd, string dd, string g);
    string getName() const;
    string getBirthDate() const;
    string getDeathDate() const;
    string getGender() const;
    void setName(string name);
    void setBirthDate(string bd);
    void setDeathDate(string dd);
    void setGender(string g);
    friend ostream& operator << (ostream& out, Scientist s); //Overload of outstream operator to print out scientist.
    string addTab(ostream& out, string name); //Add tabs to even out table spaces.

private:
    string _name;
    string _birthDate;
    string _deathDate;
    string _gender;
};

#endif // SCIENTIST_H
