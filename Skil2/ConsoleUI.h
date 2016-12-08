#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include <iostream>
#include <string>
#include <vector>
#include "ScientistService.h"
#include "Scientist.h"
#include "ComputerService.h"
#include "Computer.h"

using namespace std;

class ConsoleUI
{
public:
    ConsoleUI();
    void run(); //Function to run ConsoleUI in main function.

private:
    ScientistService _scs;
    ComputerService _cs;

    void commands(); //Prints out the program's commands.

    void printListOfScientists(vector<Scientist> vs);
    void printHeaderScientists(); //Prints out Scientists table header.
    void printListOfComputers(vector<Computer> vc);
    void printHeaderComputers(); //Prints out Computers table header.

    void addScientist(); //Add new scientist.
    string addNameOfScientist();
    int addBirthDateOfScientist();
    int addDeathDateOfScientist(int bDate);
    char addGenderOfScientist();

    void addComputer(); //Add new computer.
    string addNameOfComputer();
    int addBuildYearOfComputer();
    string addTypeOfComputer();
    string addWasBuiltOfComputer();

    void list(); //Gets user input on how to sort the list.
    void listName(); //Gets a list of the scientists and prints it out ordered by name.
    void listDoB(); //Gets a list of the scientists and prints it out ordered by year of birth.
    void listDoD(); //Gets a list of the scientists and prints it out ordered by year of death.
    void listGender(); //Gets a list of the scientists and prints it out ordered by gender.

    void findScientist();
    void findComputer();
    void deleteScientist();
    void deleteComputer();

    void editScientist();
    string editNameOfScientist(Scientist sc);
    int editBirthDateOfScientist(Scientist sc);
    int editDeathDateOfScientist(Scientist sc, int bDate);
    char editGenderOfScientist(Scientist sc);
    void editComputer();
    string editNameOfComputer(Computer c);
    int editBuildYearOfComputer(Computer c);
    string editTypeOfComputer(Computer c);
    string editWasBuiltOfComputer(Computer c);
};

#endif // CONSOLEUI_H
