#ifndef INVENTED_H
#define INVENTED_H
#include <string>
#include <iostream>

using namespace std;

class Invented
{
public:
    Invented();
    Invented(string s, string c);
    string getSName();
    string getCName();
    friend ostream& operator << (ostream& out, Invented i);

private:
    string _sName;
    string _cName;
    string addTab(ostream& out, string name);
};

#endif // INVENTED_H
