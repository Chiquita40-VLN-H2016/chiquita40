#ifndef SCIENTIST_H
#define SCIENTIST_H
#include <string>
#include <iostream>

using namespace std;


class Scientist
{
private:
    string _name;
    int _birthDate;
    int _deathDate;
    char _gender;
public:
    Scientist();
    Scientist(string n, int bd, int dd, char g);
    string getName() const;
    int getBirthDate() const;
    int getDeathDate() const;
    char getGender() const;
    friend ostream& operator << (ostream& out, const Scientist s);

};

#endif // SCIENTIST_H
