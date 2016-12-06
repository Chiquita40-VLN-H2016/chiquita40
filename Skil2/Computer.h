#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>

using namespace std;

class Computer
{
public:
    Computer();
    Computer(int id, string n, int b, string t, bool wb);
    string getName() const;
    int getBuildYear() const;
    string getType() const;
    bool getWasBuilt() const;
    void setName(string name);
    void setBuildYear(int by);
    void setType(string type);
    void setWasBuilt(bool wasb);
    //??? Búa til friend ostream << fall til að prenta út computer?

private:
    int _id;
    string _name;
    int _buildYear;
    string _type;
    bool _wasBuilt;
};

#endif // COMPUTER_H
