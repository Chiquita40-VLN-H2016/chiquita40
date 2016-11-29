#ifndef SCIENTIST_H
#define SCIENTIST_H
#include <string>

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

};

#endif // SCIENTIST_H
