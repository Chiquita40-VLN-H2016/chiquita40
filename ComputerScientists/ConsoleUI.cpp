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

        cout << "Enter command: ";
        cin >> command;

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
            cout << endl;
            cout << "! - Invalid command - !" << endl;
            cout << endl;
        }

    }while(true);
}

void ConsoleUI::commands()
{
    cout << "**********************************************************************" << endl;
    cout << "Please enter one of the following commands:" << endl
         << "add \t - Add new scientist to the list" << endl
         << "list \t - Show a list of all scientist" << endl
         << "find \t - Find scientist in list" << endl
         << "edit \t - Edit scientist in list" << endl
         << "delete \t - Delete scientist, write exact name of scientist to delete." << endl
         << "quit \t - Quit the program." << endl;
    cout << "**********************************************************************" << endl;
}

void ConsoleUI::add()
{
    string name;
    string bDate;
    string dDate;
    string gender;

    name = addName();
    bDate = addBirthDate();
    dDate = addDeathDate();
    gender = addGender();

    _scs.addScientist(name, bDate, dDate, gender);
    listName();
}

string ConsoleUI::addName()
{
    string name;
    cin.ignore();
    do
    {
        cout << "First and last name of scientist to add: ";

        getline(cin,name);

        if(name.size() == 0)
        {
            cout << endl;
            cout << "! - No name was entered. - !" << endl;
            cout << endl;
        }
        else if(name.size() > 23)
        {
            cout << endl;
            cout << "! - Name you entered is too long. - !" << endl << "! - Name can only be under 23 characters with space. - !" << endl;
            cout << endl;
        }
    }while(name.size() == 0 || name.size() > 23);

    return name;
}

string ConsoleUI::addBirthDate()
{
    string bDate;
    do
    {
        cout << "Year of Birth (YYYY): ";
        cin >> bDate;
        if(bDate.size() != 4 || isalpha(bDate[0]) || isalpha(bDate[1]) || isalpha(bDate[2]) || isalpha(bDate[3]))
        {
            cout << endl;
            cout << "! - Invalid year format - !" << endl;
            cout << endl;
        }
    }while(bDate.size() != 4 || isalpha(bDate[0]) || isalpha(bDate[1]) || isalpha(bDate[2]) || isalpha(bDate[3]));

    return bDate;
}

string ConsoleUI::addDeathDate()
{
    string dDate;
    do
    {
        cout << "Year of Death (YYYY, or if still alive, write 'alive'): ";
        cin >> dDate;
        if((isalpha(dDate[0]) && dDate != "alive") || (isalpha(dDate[1]) && dDate != "alive") || (isalpha(dDate[2])
            && dDate != "alive") || (isalpha(dDate[3]) && dDate != "alive") || (isdigit(dDate[0]) && dDate.size() != 4))
        {
            cout << endl;
            cout << "! - Invalid year format - !" << endl;
            cout << endl;
        }
     }while((isalpha(dDate[0]) && dDate != "alive") || (isalpha(dDate[1]) && dDate != "alive") || (isalpha(dDate[2])
        && dDate != "alive") || (isalpha(dDate[3]) && dDate != "alive") || (isdigit(dDate[0]) && dDate.size() != 4));

    return dDate;
}

string ConsoleUI::addGender()
{
    string gender;
    do
    {
        cout << "Gender (f/m): ";
        cin >> gender;
        if(gender != "f" && gender != "m")
        {
            cout << endl;
            cout << "! - This selection was invalid - !" << endl;
            cout << endl;
        }
    }while(gender != "f" && gender != "m");

    return gender;
}

void ConsoleUI::list()
{
    char in;

    cout    << "********************************************************" << endl;
    cout    << "Enter n - For a list of scientists ordered by name" << endl;
    cout    << "Enter b - For a list of scientists ordered by birth year" << endl;
    cout    << "Enter d - For a list of scientists ordered by death year" << endl;
    cout    << "Enter g - For a list of scientists ordered by gender" << endl;
    cout    << "********************************************************" << endl;

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
                cout << endl;
                cout << "! - Invalid command - !" << endl;
                cout << endl;
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
    Scientist sc = _scs.findScientistByName(findSc);
    if(sc.getName() == "")
    {
        cout << endl;
        cout << "! - Scientist was not found. - !" << endl;
        cout << endl;
    }
    else
    {
        printHeader();
        cout << sc;
    }
    cout << endl;
}

void ConsoleUI::printList(vector<Scientist> v)
{
   printHeader();
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
    int n = _scs.deleteScientist(deleteName);
    if(n == -1)
    {
        cout << endl;
        cout << "! - " << deleteName << " was not found in the list. - !" << endl;
        cout << endl;
    }
    else
    {
        listName();
    }
}

void ConsoleUI::editScientist()
{
    string editSC, name, dob, dod, gender;
    cout << "Enter first and last name of the scientist you want to edit: " << endl;
    cin.ignore();
    getline(cin,editSC);
    Scientist sc = _scs.findScientistByName(editSC);
    if(sc.getName() == "")
    {
        cout << endl;
        cout << "! - Scientist was not found. - !" << endl;
        cout << endl;
    }
    else
    {
        cout << "You want to edit: " << endl;
        printHeader();
        cout << sc << endl;
        name = editName(sc);
        dob = editBirthDate(sc);
        dod = editDeathDate(sc);
        gender = editGender(sc);

        _scs.editScientist(editSC, name, dob, dod, gender);
        sc = _scs.findScientistByName(name);

        cout << endl;
        cout << "Scientist has now been edited: " << endl;
        printHeader();
        cout << sc << endl;
        cout << endl;
    }
}

string ConsoleUI::editName(Scientist sc)
{
    string editSC, name;
    cout << "Would you like to edit the name? yes or no: ";
    cin >> editSC;

    if(editSC == "yes")
    {
        cin.ignore();
        do
        {
            cout    << "Enter new first and last name: ";
            getline(cin,name);
            if(name.size() == 0)
            {
                cout << endl;
                cout << "! - No name was entered. - !" << endl;
                cout << endl;
            }
            else if(name.size() > 23)
            {
                cout << endl;
                cout << "! - Name you entered is too long. - !" << endl << "! - Name can only be under 23 characters with space. - !" << endl;
                cout << endl;
            }

        }while(name.size() == 0 || name.size() > 23);
    }
    else if(editSC == "no")
    {
        name = sc.getName();
    }
    else
    {
        cout << endl;
        cout << "! - Invalid command, name will not be changed - !" << endl;
        name = sc.getName();
        cout << endl;
    }
    return name;
}

string ConsoleUI::editBirthDate(Scientist sc)
{
    string editSC, dob;
    cout << "Would you like to edit year of birth? yes or no: ";
    cin >> editSC;

    if(editSC == "yes")
    {
        do
        {
            cout << "Enter new year of Birth (YYYY): ";
            cin >> dob;
            if(dob.size() != 4 || isalpha(dob[0]) || isalpha(dob[1]) || isalpha(dob[2]) || isalpha(dob[3]))
            {
                cout << endl;
                cout << "! - Invalid year format - !" << endl;
                cout << endl;
            }
        }while(dob.size() != 4 || isalpha(dob[0]) || isalpha(dob[1]) || isalpha(dob[2]) || isalpha(dob[3]));
    }
    else if(editSC == "no")
    {
        dob = sc.getBirthDate();
    }
    else
    {
        cout << endl;
        cout << "! - Invalid command, year of birth will not be changed - !" << endl;
        dob = sc.getBirthDate();
        cout << endl;
    }
    return dob;
}

string ConsoleUI::editDeathDate(Scientist sc)
{
    string editSC, dDate;
    cout << "Would you like to edit year of death? yes or no: ";
    cin >> editSC;

    if(editSC == "yes")
    {
        do
        {
            cout << "Year of Death (YYYY, or if still alive, write 'alive'): ";
            cin >> dDate;
            if((isalpha(dDate[0]) && dDate != "alive") || (isalpha(dDate[1]) && dDate != "alive") || (isalpha(dDate[2])
                && dDate != "alive") || (isalpha(dDate[3]) && dDate != "alive") || (isdigit(dDate[0]) && dDate.size() != 4))
            {
                cout << endl;
                cout << "! - Invalid year format - !" << endl;
                cout << endl;
            }
         }while((isalpha(dDate[0]) && dDate != "alive") || (isalpha(dDate[1]) && dDate != "alive") || (isalpha(dDate[2])
            && dDate != "alive") || (isalpha(dDate[3]) && dDate != "alive") || (isdigit(dDate[0]) && dDate.size() != 4));
    }
    else if(editSC == "no")
    {
        dDate = sc.getDeathDate();
    }
    else
    {
        cout << endl;
        cout << "! - Invalid command, year of death will not be changed - !" << endl;
        dDate = sc.getDeathDate();
        cout << endl;
    }

    return dDate;
}

string ConsoleUI::editGender(Scientist sc)
{
    string editSC, gender;
    cout << "Would you like to edit gender? yes or no: ";
    cin >> editSC;

    if(editSC == "yes")
    {
        do
        {
            cout << "Enter new gender (f/m): ";
            cin >> gender;
            if(gender != "f" && gender != "m")
            {
                cout << endl;
                cout << "! - This selection was invalid - !" << endl;
                cout << endl;
            }
        }while(gender != "f" && gender != "m");
    }
    else if(editSC == "no")
    {
        gender = sc.getGender();
    }
    else
    {
        cout << endl;
        cout << "! - Invalid command, gender will not be changed - !" << endl;
        gender = sc.getGender();
        cout << endl;
    }

    return gender;
}

void ConsoleUI::printHeader()
{
    cout << endl;
    cout << "Scientist" << "\t" << "\t" << "\t" << "YoB" << "\t" << "YoD" << "\t" << "Gender" << endl;
    cout << "=======================================================" << endl;
}
