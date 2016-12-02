#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include <iostream>
#include <string>
#include "ScientistService.h"
#include "Scientist.h"

using namespace std;

class ConsoleUI
{
private:

    ScientistService _scs;

    void printList(vector<Scientist> v);
    void printHeader();
    void commands();
    void add();
    string addName();
    string addBirthDate();
    string addDeathDate();
    string addGender();
    void list();
    void listName();
    void listDoB();
    void listDoD();
    void listGender();
    void findScientist();
    void deleteScientist();
    void editScientist();
    string editName(Scientist sc);
    string editBirthDate(Scientist sc);
    string editDeathDate(Scientist sc);
    string editGender(Scientist sc);

public:
    ConsoleUI();
    void run();
};

#endif // CONSOLEUI_H
