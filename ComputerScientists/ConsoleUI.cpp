#include "ConsoleUI.h"


ConsoleUI::ConsoleUI()
{

}

void ConsoleUI::run()
{   
    string command;

    cout    << "Welcome!" << endl
            << "This is a list that contains well known characters from Computer Science\n" << endl;

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
        else if(command == "edit")
        {
            editScientist();
        }
        else if(command == "delete")
        {
            deleteScientist();
        }
        else if(command == "quit")
        {
            break;
        }
        else
        {
            cout << "Invalid command" << endl;
        }

    }while(true);
}

void ConsoleUI::commands()
{
     cout   << "Please enter one of the following commands:" << endl
            << "add \t - Add new scientist to the list" << endl
            << "list \t - Show a list of all scientist" << endl
            << "find \t - Find scientist in list" << endl
            << "edit \t - Edit scientist in list" << endl
            << "delete \t - Delete scientist, write exact name of scientist to delete." << endl
            << "quit \t - Quit the program." << endl;
}

void ConsoleUI::add()
{
    string name;
    string bDate;
    string dDate;
    string gender;

    cin.ignore();
    do
    {
        cout    << "First and last name of scientist to add: ";
        getline(cin,name);
        if(name.size() == 0)
        {
            cout << "No name was entered." << endl;
        }
    }while(name.size() == 0);

    do
    {
        cout    << "Year of Birth (YYYY): ";
        cin     >> bDate;
        if(bDate.size() != 4)
        {
            cout << "Invalid date format!" << endl;
        }
    }while(bDate.size() != 4);

    do
    {
        cout    << "Year of Death (YYYY, or if still alive, write 'alive'): ";
        cin     >> dDate;
        if(dDate.size() != 4 && dDate != "alive")
        {
            cout << "Invalid date format!" << endl;
        }
    }while(dDate.size() != 4 && dDate != "alive");

    do
    {
        cout    << "Gender (f/m): ";
        cin     >> gender;
        if(gender != "f" && gender != "m")
        {
            cout << "This selection was invalid" << endl;
        }
    }while(gender != "f" && gender != "m");

    _scs.addScientist(name, bDate, dDate, gender);
    listName();
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
    _scs.ScientistsOrderByName();
    vector<Scientist> sc = _scs.getScientists();
    printList(sc);
}

void ConsoleUI::listDoB()
{
    _scs.ScientistsOrderByDoB();
    vector<Scientist> sc = _scs.getScientists();
    printList(sc);
}

void ConsoleUI::listDoD()
{
    _scs.ScientistsOrderByDoD();
    vector<Scientist> sc = _scs.getScientists();
    printList(sc);
}

void ConsoleUI::listGender()
{
    _scs.ScientistsOrderByGender();
    vector<Scientist> sc = _scs.getScientists();
    printList(sc);
}

void ConsoleUI::findScientist()
{
    string findSc;

    cin.ignore();
    cout << "Enter the name of scientist: ";
    getline(cin,findSc);
    cout << endl;
    Scientist sc = _scs.findScientistByName(findSc);
    if(sc.getName() == "")
    {
        cout << "Scientist was not found." << endl;
    }
    else
    {
        cout << "Scientist \t DoB \t DoD \t Gender" << endl;
        cout << "==================================================" << endl;
        cout << sc;
        //Þetta á að vera hægt út af overloading.
    }

    cout << endl;
}

void ConsoleUI::printList(vector<Scientist> v)
{
    cout << endl;
    cout << "Scientist \t DoB \t DoD \t Gender" << endl;
    cout << "==================================================" << endl;

       for(size_t i = 0; i < v.size(); i++)
       {
           cout << v.at(i);
       }
   cout << endl;
}

void ConsoleUI::deleteScientist()
{
    string deleteName;
    cout << "Enter first and last name of the scientist you want to delete: " << endl;
    cin.ignore();
    getline(cin,deleteName);
    _scs.deleteScientist(deleteName);
    listName();
}

void ConsoleUI::editScientist()
{
    string editSC, name, dob, dod, gender;
    cout << "Enter first and last name of the scientist you want to edit: " << endl;
    cin.ignore();
    getline(cin,editSC);
    Scientist sc = _scs.findScientistByName(editSC);
    _scs.deleteScientist(editSC);
    cout << "You want to edit: " << endl;
    cout << sc << endl;
    cout << "Would you like to edit the name?: yes or no" << endl;
    cin >> editSC;

    if(editSC == "yes")
    {
        cout << "Enter new name: ";
        getline(cin,name);
    }
    else
    {
        name = sc.getName();
    }

    cout << "Would you like to edit date of birth?: yes or no" << endl;
    cin >> editSC;

    if(editSC == "yes")
    {
        cout << "Enter new date of birth: ";
        cin >> dob;
    }
    else
    {
        dob = sc.getBirthDate();
    }

    cout << "Would you like to edit date of death?: yes or no" << endl;
    cin >> editSC;

    if(editSC == "yes")
    {
        cout << "Enter new date of death: ";
        cin >> dod;
    }
    else
    {
        dod = sc.getDeathDate();
    }
    cout << "Would you like to edit gender?: yes or no" << endl;
    cin >> editSC;

    if(editSC == "yes")
    {
        cout << "Enter new gender: ";
        cin >> gender;
    }
    else
    {
        gender = sc.getGender();
    }
    _scs.addScientist(name, dob, dod, gender);
    sc = _scs.findScientistByName(name);

    cout << "Scientist has now been edited: " << endl;
    cout << sc << endl;
}