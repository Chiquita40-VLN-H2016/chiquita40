#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>

class Computer
{
public:
    Computer();
    Computer(string n, int b, string t, string wb);
    string getName() const;
    int getBuildYear() const;
    string getType() const;
    string getWasBuilt() const;
    void setName(string name);
    void setBuildYear(int by);
    void setType(string type);
    void setWasBuilt(string wasb);
    //??? Búa til friend ostream << fall til að prenta út computer?

private:
    string _name;
    int _buildYear;
    string _type;
    string _wasBuilt;
};

#endif // COMPUTER_H
