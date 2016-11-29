#ifndef SCIENTIST_H
#define SCIENTIST_H
#include <string>


class Scientist
{
private:
    string name;
    int birthDate;
    int deathDate;
    char gender;
public:
    Scientist();
    Scientist(string n, int bd, int dd, char g);
};

#endif // SCIENTIST_H
