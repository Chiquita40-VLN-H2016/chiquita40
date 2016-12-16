#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>
#include <string>

using namespace std;

class Computer
{
public:
    Computer();
    Computer(int id, string n, int b, string t, bool wb, string l);
    int getId() const;
    string getName() const;
    int getBuildYear() const;
    string getType() const;
    bool getWasBuilt() const;
    string getLink() const;
    void setId(int id);
    void setName(string name);
    void setBuildYear(int by);
    void setType(string type);
    void setWasBuilt(bool wasb);
    void setLink(string link);
    friend ostream& operator << (ostream& out, Computer c);//Overload of outstream operator to print out computer.
    string toString();
    string addTab(string s);
    string addTab(ostream& out, string name);//Add tabs to even out table spaces.

private:
    int _id;
    string _name;
    int _buildYear;
    string _type;
    bool _wasBuilt;
    string _link;
};

#endif // COMPUTER_H
