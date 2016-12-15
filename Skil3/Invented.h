#ifndef INVENTED_H
#define INVENTED_H
#include <string>
#include <iostream>

using namespace std;

class Invented
{
public:
    Invented();
    Invented(string s, string c, int sId, int cId);
    string getSName();
    string getCName();
    int getSId();
    int getCId();
    friend ostream& operator << (ostream& out, Invented i);
    string toString();
    string addTab(string i);

private:
    string _sName;
    string _cName;
    int _sId;
    int _cId;
    string addTab(ostream& out, string name);
};

#endif // INVENTED_H
