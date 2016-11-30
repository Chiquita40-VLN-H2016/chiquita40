#include "ConsoleUI.h"

ConsoleUI::ConsoleUI()
{

}

void ConsoleUI::run()
{

    cout    << "Welcome!" << endl
            << "This is a list that contains well known characters from Computer Science\n" << endl
            << "Please enter one of the following commands:" << endl
            << "add \t - Add new scientist to the list" << endl
            << "list \t - Show a list of all scientist by name in ASC order" << endl
            << "list b \t - list of all scientists in order of birth-year in ASC order" << endl
            << "list d \t - list of all scientist in order of death-year in ASC order" << endl
            << "list g \t - list of all scientist in order of gender in ASC order" << endl
            << "delete x - delete scientist, write exact name of scientist to delete where x is." << endl;

    cout    << "Enter command: ";
    cin     >> _command;

    if(_command == "add")
    {
        cout    << "Name of scientist to add: ";
        cin     >> _name;

        cout    << endl << "Year of Birth: ";
        cin     >> _bDate;

        cout    << endl << "Year of Death (if still alive enter 9999): ";
        cin     >> _dDate;

        cout    << endl << "Gender: ";
        cin     >> _gender;

        ScientistService add;
        add.addScientist(_name, _bDate, _dDate, _gender);

    }

}
