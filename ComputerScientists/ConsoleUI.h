#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include <iostream>
#include <string>
#include "ScientistService.h"

using namespace std;

class ConsoleUI
{
private:

    void printList(vector<Scientist> v);
    void commands();
    void add();
    void list();
    void listName();
    void listDoB();
    void listDoD();
    void listGender();
    void findScientist();
//    void deleteScientist(); *Hugsum í endann!

public:
    ConsoleUI();
    void run();
};

#endif // CONSOLEUI_H
