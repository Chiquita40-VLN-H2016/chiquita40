#include "Scientist.h"

Scientist::Scientist()
{

}
Scientist::Scientist(string n, int bd, int dd, char g)
{
    _name = n;
    _birthDate = bd;
    _deathDate = dd;
    _gender = g;
}
string Scientist::getName() const
{
    return _name;
}
int Scientist::getBirthDate() const
{
    return _birthDate;
}
int Scientist::getDeathDate() const
{
    return _deathDate;
}
char Scientist::getGender() const
{
    return _gender;
}
