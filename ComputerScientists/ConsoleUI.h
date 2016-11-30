#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include <iostream>
#include "ScientistService.h"

using namespace std;

class ConsoleUI
{
private:
    string _command, _name;
    int _bDate, _dDate;
    char _gender;

public:
    ConsoleUI();
    void run();
};

#endif // CONSOLEUI_H
