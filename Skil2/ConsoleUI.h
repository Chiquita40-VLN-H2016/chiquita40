#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include <iostream>
#include <string>
#include <vector>
#include "Scientist.h"
#include "Computer.h"
#include "SCService.h"
#include "Invented.h"

using namespace std;

class ConsoleUI
{
public:
    ConsoleUI();
    void run(); //Function to run ConsoleUI in main function.

private:
    SCService _scs;

    void commands(); //Prints out the program's commands.

    void printListOfScientists(vector<Scientist> vs);
    void printHeaderScientists(); //Prints out Scientists table header.
    void printListOfScientistsWithComputer(vector<Scientist> vs);
    void printListOfComputerWithScientist(vector<Computer> vs);
    void printListOfComputers(vector<Computer> vc);
    void printHeaderComputers(); //Prints out Computers table header.
    void printJoinedList(vector<Invented> vi);
    void printJoinedHeader(); //Prints out joined list table header.
    void printListOfConnectionsForDeletion();

    void commandAdd();
    void commandList();
    void commandFind();
    void commandEdit();
    void commandDelete();
    void commandJoin();

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

    int chooseSortingMethod();
    void listScientists(); //Gets user input on how to sort the list of Scientists.
    void listScientistsByNameAsc();
    void listScientistsByNameDesc();
    void listScientistsByBirthYearAsc();
    void listScientistsByBirthYearDesc();
    void listScientistsByDeathYearAsc();
    void listScientistsByDeathYearDesc();
    void listScientistsByGenderAsc();
    void listScientistsByGenderDesc();
    void listComputers(); //Gets user input on how to sort the list of Computers.
    void listComputersByNameAsc();
    void listComputersByNameDesc();
    void listComputersByBuildYearAsc();
    void listComputersByBuildYearDesc();
    void listComputersByTypeAsc();
    void listComputersByTypeDesc();
    void listComputersIfWasBuiltAsc();
    void listComputersIfWasBuiltDesc();
    void listJoined(); //Gets user input on how to sort the joined list of Scientists and Computers.
    void listJoinedByScientistsNameAsc();
    void listJoinedByScientistsNameDesc();
    void listJoinedByComputersNameAsc();
    void listJoinedByComputersNameAscDesc();

    void findScientist();
    void findComputer();
    void deleteScientist();
    void deleteConnection();
    void deleteComputer();
    void joinSC();

    void editScientist();
    string editNameOfScientist(Scientist sc);
    int editBirthDateOfScientist(Scientist sc);
    int editDeathDateOfScientist(Scientist sc, int bDate);
    char editGenderOfScientist(Scientist sc);
    void editComputer();
    string editNameOfComputer(Computer c);
    int editBuildYearOfComputer(Computer c);
    string editTypeOfComputer(Computer c);
    char editWasBuiltOfComputer(Computer c);

};

#endif // CONSOLEUI_H
