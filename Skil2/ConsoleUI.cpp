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
        commands(); //Prints out user input options.

        cout << "Enter command: ";
        cin >> command;

        if(command == "add")
        {
            int choice = 0;
            cout << "1 - To add new scientist" << endl;
            cout << "2 - To add new computer" << endl;
            cin >> choice;
            if(choice == 1)
            {
                addScientist();
            }
            else if(choice == 2)
            {
                addComputer();
            }
        }
        else if(command == "list")
        {
            int choice = 0;
            cout << "1 - Show and sort list of scientists" << endl;
            cout << "2 - Show and sort list of computers" << endl;
            cout << "3 - Show and sort list of scientists and computers" << endl;
            cin >> choice;
            if(choice == 1)
            {
                listScientists();
            }
            else if(choice == 2)
            {
                listComputers();
            }
            else if(choice == 3)
            {
                //print list of scientists and computers
            }
        }
        else if(command == "find")
        {
            int choice = 0;
            cout << "1 - Find scientist" << endl;
            cout << "2 - Find computer" << endl;
            cin >> choice;
            if(choice == 1)
            {
                findScientist();
            }
            else if(choice == 2)
            {
                findComputer();
            }
        }
        else if(command == "edit")
        {
            int choice = 0;
            cout << "1 - Edit scientist" << endl;
            cout << "2 - Edit computer" << endl;
            cin >> choice;
            if(choice == 1)
            {
                editScientist();
            }
            else if(choice == 2)
            {
                editComputer();
            }
        }
        else if(command == "delete")
        {
            int choice = 0;
            cout << "1 - Delete scientist" << endl;
            cout << "2 - Delete computer" << endl;
            cin >> choice;
            if(choice == 1)
            {
                deleteScientist();
            }
            else if(choice == 2)
            {
                deleteComputer();
            }
        }
        else if(command == "connect")
        {
            // connect scientist and computer
        }
        else if(command == "quit")
        {
            _scs.closeDb();

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
         << "add \t - Add new scientist or computer" << endl
         << "list \t - Show a list of all scientists and/or computers" << endl
         << "find \t - Find scientist or computer" << endl
         << "edit \t - Edit scientist or computer" << endl
         << "delete \t - Delete scientist or computer" << endl
         << "connect \t - Connect scientist with computer" << endl
         << "quit \t - Quit the program" << endl;
    cout << "**********************************************************************" << endl;
}

void ConsoleUI::printListOfScientists(vector<Scientist> vs)
{
   printHeaderScientists();
   for(size_t i = 0; i < vs.size(); i++)
   {
       cout << vs.at(i);
   }
   cout << endl;
}

void ConsoleUI::printHeaderScientists()
{
    cout << endl;
    cout << "ID" << "\t" << "Scientist" << "\t" << "\t" << "\t" << "YoB" << "\t" << "YoD" << "\t" << "Gender" << endl;
    cout << "=============================================================" << endl;
}

void ConsoleUI::printListOfComputers(vector<Computer> vc)
{
    printHeaderComputers();
    for(size_t i = 0; i < vc.size(); i++)
    {
        cout << vc.at(i);
    }
    cout << endl;
}

void ConsoleUI::printHeaderComputers()
{
    cout << endl;
    cout << "ID" << "\t" << "Computer" << "\t" << "\t" << "\t" << "Build year" << "\t" << "Type" << "\t" << "Was built" << endl;
    cout << "=============================================================" << endl;
}

void ConsoleUI::addScientist() //Adds scientist to the list.
{
    string sName;
    int bDate;
    int dDate;
    char gender;

    sName = addNameOfScientist();
    bDate = addBirthDateOfScientist();
    dDate = addDeathDateOfScientist(bDate);
    gender = addGenderOfScientist();

    _scs.addScientist(sName, bDate, dDate, gender);
    listScientistsByNameAsc();
}

string ConsoleUI::addNameOfScientist() //Gets a name of scientist from the user.
{
    string sName;
    cin.ignore();
    do
    {
        cout << "Enter name of scientist: ";

        getline(cin,sName);

        if(sName.size() == 0)
        {
            cout << endl;
            cout << "! - No scientist name was entered. - !" << endl;
            cout << endl;
        }
        else if(sName.size() > 23)
        {
            cout << endl;
            cout << "! - Scientist name you entered is too long. - !" << endl
                 << "! - Scientist name can be max 23 characters with space. - !" << endl;
            cout << endl;
        }
    }while(sName.size() == 0 || sName.size() > 23);

    return sName;
}

int ConsoleUI::addBirthDateOfScientist() //Gets a year of birth of scientist from user.
{
    int bDate;

    do
    {
        cout << "Enter year of Birth (YYYY): ";
        cin >> bDate;
        if(!_scs.validYearCheck(bDate))
        {
            cout << endl;
            cout << "! - Invalid year format - !" << endl;
            cout << endl;
        }

    }while(!_scs.validYearCheck(bDate));

    return bDate;
}

int ConsoleUI::addDeathDateOfScientist(int bDate) //Gets a year of death of scientist from user.
{

    int dDate;
    char deadOrAlive;

    do
    {
        cout << "Is scientist still alive? (y/n): ";
        cin >> deadOrAlive;

        if(deadOrAlive == tolower('n'))
        {
            do
            {
                cout << "Enter year of Death (YYYY): ";
                cin >> dDate;
                if(!_scs.validYearCheck(dDate) || dDate < bDate)
                {
                    cout << endl;
                    cout << "! - Invalid year format - !" << endl;
                    cout << endl;
                }
            }while(!_scs.validYearCheck(dDate) || dDate < bDate);
        }
        else if(deadOrAlive == tolower('y'))
        {
            dDate = 9999;
        }
        else
        {
            cout << endl;
            cout << "! - Invalid choice, please enter 'y' or 'n' - !" << endl;
        }
    }while(deadOrAlive != 'n' && deadOrAlive != 'y');

    return dDate;
}

char ConsoleUI::addGenderOfScientist() //Gets a gender of scientist from user.
{
    char gender;
    do
    {
        cout << "Gender (f/m): ";
        cin >> gender;
        if(gender != 'f' && gender != 'm')
        {
            cout << endl;
            cout << "! - This selection was invalid - !" << endl;
            cout << endl;
        }
    }while(gender != 'f' && gender != 'm');

    return gender;
}

void ConsoleUI::addComputer() //Adds computer to the list.
{
    string cName;
    int buildYear;
    string type;
    string wasBuilt;

    cName = addNameOfComputer();
    buildYear = addBuildYearOfComputer();
    type = addTypeOfComputer();
    wasBuilt = addWasBuiltOfComputer();

    _scs.addComputer(cName, buildYear, type, wasBuilt);
    //listName();
}

string ConsoleUI::addNameOfComputer()
{
    string cName;
    cin.ignore();
    do
    {
        cout << "Name of Computer to add: ";

        getline(cin,cName);

        if(cName.size() == 0)
        {
            cout << endl;
            cout << "! - No computer name was entered. - !" << endl;
            cout << endl;
        }
        else if(cName.size() > 23)
        {
            cout << endl;
            cout << "! - Computer name you entered is too long. - !" << endl
                 << "! - Computer name can be max 23 characters with space. - !" << endl;
            cout << endl;
        }
    }while(cName.size() == 0 || cName.size() > 23);

    return cName;
}

int ConsoleUI::addBuildYearOfComputer()
{
    int buildYear;

    do
    {
        cout << "Enter build year (YYYY): ";
        cin >> buildYear;
        if(!_scs.validYearCheck(buildYear))
        {
            cout << endl;
            cout << "! - Invalid year format - !" << endl;
            cout << endl;
        }

    }while(!_scs.validYearCheck(buildYear));

    return buildYear;
}

string ConsoleUI::addTypeOfComputer()
{
    string cType;
    cin.ignore(); //To empty cin in order to use getline();
    do
    {
        cout << "Type to add: ";

        getline(cin,cType);

        if(cType.size() == 0)
        {
            cout << endl;
            cout << "! - No type was entered. - !" << endl;
            cout << endl;
        }
        else if(cType.size() > 7)
        {
            cout << endl;
            cout << "! - Computer name you entered is too long. - !" << endl
                 << "! - Computer name can be max 7 characters with space. - !" << endl;
            cout << endl;
        }
    }while(cType.size() == 0 || cType.size() > 7);

    return cType;
}

char ConsoleUI::addWasBuiltOfComputer()
{
    char wasBuilt;
    do
    {
        cout << "Has the computer been built, y/n: ";

        cin >> wasBuilt;

        if(wasBuilt != tolower('y') || wasBuilt != tolower('n'))
        {
            cout << endl;
            cout << "! - Invalid choice, please enter 'y' or 'n' - !" << endl;
            cout << endl;
        }
    }while(wasBuilt != tolower('y') || wasBuilt != tolower('n'));

    return wasBuilt;
}

char ConsoleUI::chooseSortingMethod()
{
    char sort;
    do
    {
        cout    << "**********************************" << endl;
        cout << "1 - Print in ascending order." << endl;
        cout << "2 - Print in descending order." << endl;
        cout    << "**********************************" << endl;

        cin >> sort;

        if(sort != tolower('1') || sort != tolower('2'))
        {
            cout << endl;
            cout << "! - Invalid choice, please enter '1' or '2' - !" << endl;
            cout << endl;
        }
    }while(sort != tolower('1') || sort != tolower('2'));

    return sort;
}

void ConsoleUI::listScientists()
{
    char in;
    char sort;

    cout    << "********************************************************" << endl;
    cout    << "1 - For a list of scientists ordered by name" << endl;
    cout    << "2 - For a list of scientists ordered by birth year" << endl;
    cout    << "3 - For a list of scientists ordered by death year" << endl;
    cout    << "4 - For a list of scientists ordered by gender" << endl;
    cout    << "********************************************************" << endl;

    cout << "Please enter now: " << endl;
    cin >> in;

    switch(in)
    {
        case '1':
                sort = chooseSortingMethod();
                if(sort == '1')
                {
                    listScientistsByNameAsc();
                }
                else if(sort == '2')
                {
                    listScientistsByNameDesc();
                }
                break;
        case '2':
                sort = chooseSortingMethod();
                if(sort == '1')
                {
                    listScientistsByBirthYearAsc();
                }
                else if(sort == '2')
                {
                    listScientistsByBirthYearDesc();
                }
                break;
        case '3':
                sort = chooseSortingMethod();
                if(sort == '1')
                {
                    listScientistsByDeathYearAsc();
                }
                else if(sort == '2')
                {
                    listScientistsByDeathYearDesc();
                }
                break;
        case '4':
                sort = chooseSortingMethod();
                if(sort == '1')
                {
                    listScientistsByGenderAsc();
                }
                else if(sort == '2')
                {
                    listScientistsByGenderDesc();
                }
                break;
        default:
                cout << endl;
                cout << "! - Invalid command - !" << endl;
                cout << endl;
    }
}

void ConsoleUI::listScientistsByNameAsc()
{
    vector<Scientist> sc = _scs.getScientists();
    printListOfScientists(sc);
}

void ConsoleUI::listScientistsByNameDesc()
{
    vector<Scientist> sc = _scs.getScientists();
    printListOfScientists(sc);
}

void ConsoleUI::listScientistsByBirthYearAsc()
{
    vector<Scientist> sc = _scs.getScientists();
    printListOfScientists(sc);
}

void ConsoleUI::listScientistsByBirthYearDesc()
{
    vector<Scientist> sc = _scs.getScientists();
    printListOfScientists(sc);
}

void ConsoleUI::listScientistsByDeathYearAsc()
{
    vector<Scientist> sc = _scs.getScientists();
    printListOfScientists(sc);
}

void ConsoleUI::listScientistsByDeathYearDesc()
{
    vector<Scientist> sc = _scs.getScientists();
    printListOfScientists(sc);
}

void ConsoleUI::listScientistsByGenderAsc()
{
    vector<Scientist> sc = _scs.getScientists();
    printListOfScientists(sc);
}

void ConsoleUI::listScientistsByGenderDesc()
{
    vector<Scientist> sc = _scs.getScientists();
    printListOfScientists(sc);
}

void ConsoleUI::listComputers()
{
    char in;
    char sort;

    cout    << "********************************************************" << endl;
    cout    << "1 - For a list of computers ordered by name" << endl;
    cout    << "2 - For a list of computers ordered by build year" << endl;
    cout    << "3 - For a list of computers ordered by type" << endl;
    cout    << "4 - For a list of computers ordered by if was built or not" << endl;
    cout    << "********************************************************" << endl;

    cout << "Please enter now: " << endl;
    cin >> in;

    switch(in)
    {
        case '1':
                sort = chooseSortingMethod();
                if(sort == '1')
                {
                    listComputersIfWasBuiltAsc();
                }
                else if(sort == '2')
                {
                    listComputersIfWasBuiltDesc();
                }
                break;
        case '2':
                sort = chooseSortingMethod();
                if(sort == '1')
                {
                    listComputersByBuildYearAsc();
                }
                else if(sort == '2')
                {
                    listComputersByBuildYearDesc();
                }
                break;
        case '3':
                sort = chooseSortingMethod();
                if(sort == '1')
                {
                    listComputersByTypeAsc();
                }
                else if(sort == '2')
                {
                    listComputersByTypeDesc();
                }
                break;
        case '4':
                sort = chooseSortingMethod();
                if(sort == '1')
                {
                    listComputersIfWasBuiltAsc();
                }
                else if(sort == '2')
                {
                    listComputersIfWasBuiltDesc();
                }
                break;
        default:
                cout << endl;
                cout << "! - Invalid command - !" << endl;
                cout << endl;
    }
}

void ConsoleUI::listComputersByNameAsc()
{
    vector<Computer> c = _scs.getComputers();
    printListOfComputers(c);
}

void ConsoleUI::listComputersByNameDesc()
{
    vector<Computer> c = _scs.getComputers();
    printListOfComputers(c);
}

void ConsoleUI::listComputersByBuildYearAsc()
{
    vector<Computer> c = _scs.getComputers();
    printListOfComputers(c);
}

void ConsoleUI::listComputersByBuildYearDesc()
{
    vector<Computer> c = _scs.getComputers();
    printListOfComputers(c);
}

void ConsoleUI::listComputersByTypeAsc()
{
    vector<Computer> c = _scs.getComputers();
    printListOfComputers(c);
}

void ConsoleUI::listComputersByTypeDesc()
{
    vector<Computer> c = _scs.getComputers();
    printListOfComputers(c);
}

void ConsoleUI::listComputersIfWasBuiltAsc()
{
    vector<Computer> c = _scs.getComputers();
    printListOfComputers(c);
}

void ConsoleUI::listComputersIfWasBuiltDesc()
{
    vector<Computer> c = _scs.getComputers();
    printListOfComputers(c);
}

void ConsoleUI::findScientist()
{
    string findSc;

    cin.ignore();
    cout << "Enter the name of scientist: ";
    getline(cin,findSc);
    vector<Scientist> sc = _scs.findScientistByName(findSc);

}

void ConsoleUI::findComputer()
{
    string findC;

    cin.ignore();
    cout << "Enter the name of computer: ";
    getline(cin,findC);
    vector<Computer> c = _scs.findComputerByName(findC);
}

void ConsoleUI::deleteScientist()
{
    string deleteScientistName;
    cout << "Enter name of the scientist you want to delete: " << endl;
    cin.ignore();
    getline(cin,deleteScientistName);
    int id = 0; //Preliminary svo það buildist. Þarf að breyta.
    int n = _scs.deleteScientist(id);
    if(n == -1)
    {
        cout << endl;
        cout << "! - " << deleteScientistName << " was not found in the list. - !" << endl;
        cout << endl;
    }
    else
    {
        listScientistsByNameAsc();
    }
}

void ConsoleUI::deleteComputer()
{
    string deleteComputerName;
    cout << "Enter the name of the computer you want to delete: " << endl;
    cin.ignore();
    getline(cin,deleteComputerName);
    int id = 0; //Preliminary placeholder. Þarf að breyta.
    int n = _scs.deleteComputer(id);
    if(n == -1)
    {
        cout << endl;
        cout << "! - " << deleteComputerName << " was not found in the list. - !" << endl;
        cout << endl;
    }
    else
    {
        //listName();
    }
}

void ConsoleUI::editScientist()
{
    string editSC, sName;
    int bDate, dDate;
    char gender;
    cout << "Enter name of the scientist you want to edit: " << endl;
    cin.ignore();
    getline(cin,editSC);
    vector<Scientist> sc = _scs.findScientistByName(editSC);

}

string ConsoleUI::editNameOfScientist(Scientist sc)
{
    char editSC;
    string sName;
    cout << "Would you like to edit the name? y/n: ";
    cin >> editSC;

    if(editSC == tolower('y'))
    {
        cin.ignore();
        do
        {
            cout    << "Enter new name: ";
            getline(cin,sName);
            if(sName.size() == 0)
            {
                cout << endl;
                cout << "! - No name was entered. - !" << endl;
                cout << endl;
            }
            else if(sName.size() > 23)
            {
                cout << endl;
                cout << "! - Name you entered is too long. - !" << endl << "! - Name can only be under 23 characters with space. - !" << endl;
                cout << endl;
            }

        }while(sName.size() == 0 || sName.size() > 23);
    }
    else if(editSC == tolower('n'))
    {
        sName = sc.getName();
    }
    else
    {
        cout << endl;
        cout << "! - Invalid command, name will not be changed - !" << endl;
        sName = sc.getName();
        cout << endl;
    }
    return sName;
}

int ConsoleUI::editBirthDateOfScientist(Scientist sc)
{
    char editSC;
    int bDate;
    cout << "Would you like to edit year of birth? y/n: ";
    cin >> editSC;

    if(editSC == tolower('y'))
    {
        do
        {
            cout << "Enter new year of Birth (YYYY): ";
            cin >> bDate;
            if(!_scs.validYearCheck(bDate))
            {
                cout << endl;
                cout << "! - Invalid year format - !" << endl;
                cout << endl;
            }

        }while(!_scs.validYearCheck(bDate));

    }
    else if(editSC == tolower('n'))
    {
        bDate = sc.getBirthDate();
    }
    else
    {
        cout << endl;
        cout << "! - Invalid command, year of birth will not be changed - !" << endl;
        bDate = sc.getBirthDate();
        cout << endl;
    }
    return bDate;
}

int ConsoleUI::editDeathDateOfScientist(Scientist sc, int bDate)
{
    char editSC;
    char deadOrAlive;
    int dDate;

    cout << "Would you like to edit year of death? y/n: ";
    cin >> editSC;

    if(editSC == tolower('y'))
    {
        do
        {
            cout << "Is scientist still alive? y/n: ";
            cin >> deadOrAlive;

            if(deadOrAlive == tolower('n'))
            {
                do
                {
                    cout << "Year of Death (YYYY): ";
                    cin >> dDate;
                    if(!_scs.validYearCheck(dDate) || dDate < bDate)
                    {
                        cout << endl;
                        cout << "! - Invalid year format - !" << endl;
                        cout << endl;
                    }
                }while(!_scs.validYearCheck(dDate) || dDate < bDate);
            }
            else if(deadOrAlive == tolower('y'))
            {
                dDate = 9999;
            }
            else
            {
                cout << endl;
                cout << "! - Invalid choice, please enter 'y' or 'n' - !" << endl;
            }
        }while(deadOrAlive != tolower('n') && deadOrAlive != tolower('y'));
    }
    else if(editSC == tolower('n'))
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

char ConsoleUI::editGenderOfScientist(Scientist sc)
{
    char editSC;
    char gender;
    cout << "Would you like to edit gender? yes or no: ";
    cin >> editSC;

    if(editSC == tolower('y'))
    {
        do
        {
            cout << "Enter new gender (f/m): ";
            cin >> gender;
            if(gender != 'f' && gender != 'm')
            {
                cout << endl;
                cout << "! - This selection was invalid - !" << endl;
                cout << endl;
            }
        }while(gender != 'f' && gender != 'm');
    }
    else if(editSC == tolower('n'))
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

void ConsoleUI::editComputer()
{
    string editC, cName;
    int by;
    string t, wb;
    cout << "Enter name of the computer you want to edit: " << endl;
    cin.ignore();
    getline(cin,editC);
    vector<Computer> c = _scs.findComputerByName(editC);

    // Vantar föll hér til að kalla í editNameOfComputer osfrv.
}

string ConsoleUI::editNameOfComputer(Computer c)
{
    char editC;
    string cName;
    cout << "Would you like to edit the name? y/n: ";
    cin >> editC;

    if(editC == tolower('y'))
    {
        cin.ignore();
        do
        {
            cout    << "Enter new name: ";
            getline(cin,cName);
            if(cName.size() == 0)
            {
                cout << endl;
                cout << "! - No name was entered. - !" << endl;
                cout << endl;
            }
            else if(cName.size() > 23)
            {
                cout << endl;
                cout << "! - Name you entered is too long. - !" << endl << "! - Name can only be under 23 characters with space. - !" << endl;
                cout << endl;
            }

        }while(cName.size() == 0 || cName.size() > 23);
    }
    else if(editC == tolower('n'))
    {
        cName = c.getName();
    }
    else
    {
        cout << endl;
        cout << "! - Invalid command, name will not be changed - !" << endl;
        cName = c.getName();
        cout << endl;
    }
    return cName;
}

int ConsoleUI::editBuildYearOfComputer(Computer c)
{
    char editC;
    int buildYear;

    cout << "Would you like to edit the build year? y/n: ";
    cin >> editC;

    if(editC == tolower('y'))
    {
        do
        {
            cout << "Enter build year (YYYY): ";
            cin >> buildYear;
            if(!_scs.validYearCheck(buildYear))
            {
                cout << endl;
                cout << "! - Invalid year format - !" << endl;
                cout << endl;
            }

        }while(!_scs.validYearCheck(buildYear));
    }
    else if(editC == tolower('n'))
    {
        buildYear = c.getBuildYear();
    }
    else
    {
        cout << endl;
        cout << "! - Invalid command, build year will not be changed - !" << endl;
        buildYear = c.getBuildYear();
        cout << endl;
    }
    return buildYear;
}

string ConsoleUI::editTypeOfComputer(Computer c)
{
    char editC;
    string cType;
    cout << "Would you like to edit the type? y/n: ";
    cin >> editC;

    if(editC == tolower('y'))
    {
        cin.ignore();
        do
        {
            cout    << "Enter new type: ";
            getline(cin,cType);
            if(cType.size() == 0)
            {
                cout << endl;
                cout << "! - No type was entered. - !" << endl;
                cout << endl;
            }
            else if(cType.size() > 7)
            {
                cout << endl;
                cout << "! - Type you entered is too long. - !" << endl << "! - Type can only be under 7 characters with space. - !" << endl;
                cout << endl;
            }

        }while(cType.size() == 0 || cType.size() > 7);
    }
    else if(editC == tolower('n'))
    {
        cType = c.getType();
    }
    else
    {
        cout << endl;
        cout << "! - Invalid command, type will not be changed - !" << endl;
        cType = c.getType();
        cout << endl;
    }
    return cType;
}

char ConsoleUI::editWasBuiltOfComputer(Computer c)
{
    char editC;
    char wasBuilt;
    cout << "Would you like to edit if the computer has been built? y/n: ";
    cin >> editC;

    if(editC == tolower('y'))
    {
        do
        {
            cout    << "Has the computer been built? y/n: ";
            cin >> wasBuilt;
            if(wasBuilt != tolower('y') || wasBuilt != tolower('n'))
            {
                cout << endl;
                cout << "! - Invalid choice, please enter 'y' or 'n' - !" << endl;
                cout << endl;
            }
        }while(wasBuilt != tolower('y') || wasBuilt != tolower('n'));
    }
    else if(editC == tolower('n'))
    {
        wasBuilt = c.getWasBuilt();
    }
    else
    {
        cout << endl;
        cout << "! - Invalid command, type will not be changed - !" << endl;
        wasBuilt = c.getWasBuilt();
        cout << endl;
    }
    return wasBuilt;
}
