#ifndef SCIENTIST_H
#define SCIENTIST_H
#include <iostream>
#include <string>

using namespace std;

class Scientist
{
public:
    Scientist();
    Scientist(string n, int bd, int dd, char g);
    string getName() const;
    int getBirthDate() const;
    int getDeathDate() const;
    char getGender() const;
    void setName(string name);
    void setBirthDate(int bd);
    void setDeathDate(int dd);
    void setGender(char gender);
    friend ostream& operator << (ostream& out, Scientist s); //Overload of outstream operator to print out scientist.
    string addTab(ostream& out, string name); //Add tabs to even out table spaces.

private:
    string _name;
    int _birthDate;
    int _deathDate;
    char _gender;
};

#endif // SCIENTIST_H
