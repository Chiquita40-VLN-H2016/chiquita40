#include "ConsoleUI.h"


ConsoleUI::ConsoleUI()
{

}

void ConsoleUI::run()
{   
    string command;

    do
    {
        commands();

        cout    << "Enter command: ";
        cin     >> command;

        if(command == "add")
        {
            add();
        }
        else if(command == "list")
        {
            list();
        }
        else if(command == "find")
        {
            findScientist();
        }
        /*else if(command == "delete")
        {
            deleteScientist();
        }*/
        else
        {
            cout << "Invalid command" << endl;
        }

    }while(command != "quit");

}

void ConsoleUI::commands()
{
    cout    << "Welcome!" << endl
            << "This is a list that contains well known characters from Computer Science\n" << endl
            << "Please enter one of the following commands:" << endl
            << "add \t - Add new scientist to the list" << endl
            << "list \t - Show a list of all scientist" << endl
            << "find \t - Find scientist in list" << endl
 //           << "delete x - delete scientist, write exact name of scientist to delete where x is." << endl;
            << "Enter quit to quit the program." << endl;

}

void ConsoleUI::add()
{
    string name;
    int bDate;
    int dDate;
    char gender;

    cin.ignore();
    cout    << "Name of scientist to add: ";
    getline(cin,name);

    cout    << "Year of Birth: ";
    cin     >> bDate;

    cout    << "Year of Death (if still alive enter 9999): ";
    cin     >> dDate;

    cout    << "Gender: ";
    cin     >> gender;

    //ScientistService add;
    //add.addScientist(name, bDate, dDate, gender);
}

void ConsoleUI::list()
{
    char in;

    cout << "Enter n - For a list of scientists ordered by name" << endl;
    cout << "Enter b - For a list of scientists ordered by birth year" << endl;
    cout << "Enter d - For a list of scientists ordered by death year" << endl;
    cout << "Enter g - For a list of scientists ordered by gender" << endl;

    cout << "Please enter now: " << endl;
    cin >> in;

    switch(in)
    {
        case 'n':
                listName();
                break;
        case 'b':
                listDoB();
                break;
        case 'd':
                listDoD();
                break;
        case 'g':
                listGender();
                break;
        default:
                cout << "Invalid command" << endl;

    }

}
void ConsoleUI::listName()
{
    ScientistService name;
    name.getScientistsOrderByName();
    //hvernig á að prenta.
}

void ConsoleUI::listDoB()
{
    ScientistService dob;
    dob.getScientistsOrderByDoB();
    //hvernig á að prenta.
}

void ConsoleUI::listDoD()
{
    ScientistService dod;
    dod.getScientistsOrderByDoD();
    //hvernig á að prenta.
}

void ConsoleUI::listGender()
{
    ScientistService gender;
    gender.getScientistsOrderByGender();
    //hvernig á að prenta.
}

void ConsoleUI::findScientist()
{
    string findSc;

    cin.ignore();
    cout << "Enter the name of scientist: ";
    getline(cin,findSc);

    ScientistService scs;
    Scientist *sc = scs.findScientistByName(findSc);
    if(sc == nullptr)
    {
        cout << "Scientist was not found." << endl;
    }
    else
    {
        cout << *sc;
        //Þetta á að vera hægt út af overloading.
    }
}

void ConsoleUI::printList(vector<Scientist> v)
{
    cout << "Scientists" << endl;
    cout << "==============================================================" << endl;

       for(size_t i = 0; i < v.size(); i++)
       {
           cout << v.at(i);
       }
}
