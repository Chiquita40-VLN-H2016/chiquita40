#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include <iostream>
#include <string>
#include "ScientistService.h"
#include "Scientist.h"

using namespace std;

class ConsoleUI
{
public:
    ConsoleUI();
    void run(); //Function to run ConsoleUI in main function.

private:
    ScientistService _scs;

    void printList(vector<Scientist> v);
    void printHeader(); //Prints out table header.
    void commands(); //Prints out the program's commands.
    void add(); //Add new scientist.
    string addName();
    string addBirthDate();
    string addDeathDate();
    string addGender();
    void list(); //Gets user input on how to sort the list.
    void listName(); //Gets a list of the scientists and prints it out ordered by name.
    void listDoB(); //Gets a list of the scientists and prints it out ordered by year of birth.
    void listDoD(); //Gets a list of the scientists and prints it out ordered by year of death.
    void listGender(); //Gets a list of the scientists and prints it out ordered by gender.
    void findScientist();
    void deleteScientist();
    void editScientist();
    string editName(Scientist sc);
    string editBirthDate(Scientist sc);
    string editDeathDate(Scientist sc);
    string editGender(Scientist sc);
};

#endif // CONSOLEUI_H
