#include "ConsoleUI.h"

int const TAB_NAME = 31;
int const TAB_TYPE = 15;

ConsoleUI::ConsoleUI()
{

}

void ConsoleUI::run()
{
    string command;

    cout    << "Welcome!" << endl
            << "This is a list that contains well known characters" << endl
            << "and computers from Computer Science\n" << endl;

    do
    {

        commands(); //Prints out user input options.

        cout << "Enter command: ";

        if(!cin)
        {
            cin.clear();
            string ignoreLine;
            getline(cin, ignoreLine);
        }

        cin >> command;

        if(command == "add")
        {
            commandAdd();
        }
        else if(command == "list")
        {
            commandList();
        }
        else if(command == "find")
        {
            commandFind();
        }
        else if(command == "edit")
        {
            commandEdit();
        }
        else if(command == "delete")
        {
            commandDelete();
        }
        else if(command == "join")
        {
            commandJoin(); // connect scientist and computer
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
    cout << endl;
    cout << "************************************************************************" << endl;
    cout << "Please enter one of the following commands:" << endl
         << "add \t - Add new scientist or computer" << endl
         << "list \t - Show a list of all scientists and/or computers" << endl
         << "find \t - Find scientist or computer" << endl
         << "edit \t - Edit scientist or computer" << endl
         << "delete \t - Delete scientist or computer" << endl
         << "join \t - Connect scientist with computer" << endl
         << "quit \t - Quit the program" << endl;
    cout << "************************************************************************" << endl;
}

void ConsoleUI::commandAdd()
{
    int choice = 0;

    cout << "-------------------------------------------------------------------------" << endl;
    cout << "1 - To add new scientist" << endl;
    cout << "2 - To add new computer" << endl;
    cout << "-------------------------------------------------------------------------" << endl;

    cout << "Please enter now: ";
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

void ConsoleUI::commandList()
{
    int choice = 0;

    cout << "-------------------------------------------------------------------------" << endl;
    cout << "1 - Show and sort list of scientists" << endl;
    cout << "2 - Show and sort list of computers" << endl;
    cout << "3 - Show and sort list of scientists and computers" << endl;
    cout << "-------------------------------------------------------------------------" << endl;

    cout << "Please enter now: ";
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

void ConsoleUI::commandFind()
{
    int choice = 0;

    cout << "-------------------------------------------------------------------------" << endl;
    cout << "1 - Find scientist" << endl;
    cout << "2 - Find computer" << endl;
    cout << "-------------------------------------------------------------------------" << endl;

    cout << "Please enter now: ";
    cin >> choice;

    if(choice == 1)
    {
        findScientist();
    }
    else if(choice == 2)
    {
        findComputer();
    }
    else
    {
        cout << endl;
        cout << "! - This selection was invalid - !" << endl;
        cout << endl;
    }
}

void ConsoleUI::commandEdit()
{
    int choice = 0;

    cout << "-------------------------------------------------------------------------" << endl;
    cout << "1 - Edit scientist" << endl;
    cout << "2 - Edit computer" << endl;
    cout << "-------------------------------------------------------------------------" << endl;

    cout << "Please enter now: ";
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

void ConsoleUI::commandDelete()
{
    int choice = 0;

    cout << "-------------------------------------------------------------------------" << endl;
    cout << "1 - Delete scientist" << endl;
    cout << "2 - Delete computer" << endl;
    cout << "-------------------------------------------------------------------------" << endl;

    cout << "Please enter now: ";
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

void ConsoleUI::commandJoin()
{
    int sid, cid;
    vector<Scientist> sc;
    vector<Computer> c;

    _scs.scientistsAscendingOrder(0);
    sc = _scs.getScientists();
    printListOfScientists(sc);

    cout << "Please enter the ID of the scientist you want to connect." << endl
         << "You can see the id in the table above." << endl;
    cin >> sid;

    _scs.computersAscendingOrder(0);
    c = _scs.getComputers();
    printListOfComputers(c);

    cout << "Please enter the ID of the computer you want to connect." << endl
         << "You can see the id in the table above." << endl;
    cin >> cid;

    _scs.joinSC(sid, cid);
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
    cout << "ID" << "\t" << "Scientist" << "\t" << "\t" << "\t" << "Born" << "\t" << "Died" << "\t" << "Gender" << endl;
    cout << "=========================================================================" << endl;
}

void ConsoleUI::printListOfScientistsWithComputer(vector<Scientist> vs)
{
   int id;
   vector<Computer> c;

   printHeaderScientists();

   for(size_t i = 0; i < vs.size(); i++)
   {
       id = vs.at(i).getId();
       c = _scs.findComputerByScientist(id);

       if(c.size() > 0)
       {
            for(size_t j = 0; j < c.size(); j++)
            {
                cout << vs.at(i) << '\t' << "Computer invented: " << c.at(j).getName();
            }

            cout << endl;
       }
       else
       {
           cout << vs.at(i);
       }

       cout << endl;
   }
 //  cout << endl;
}

void ConsoleUI::printHeaderScientistsWithComputer()
{
    cout << endl;
    cout << "ID" << "\t" << "Scientist" << "\t" << "\t" << "\t" << "Born" << "\t" << "Died" << "\t" << "Gender" << "Computers" << endl;
    cout << "=========================================================================" << endl;
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
    cout << "ID" << "\t" << "Computer" << "\t" << "\t" << "\t" << "Build" << "\t" << "Type" << "\t" << "\t" << "Was built" << endl;
    cout << "=========================================================================" << endl;
}

void ConsoleUI::printJoinedList(vector<Invented> vi)
{
    printJoinedHeader();
    for(size_t i = 0; i < vi.size(); i++)
    {
        cout << vi.at(i);
    }
    cout << endl;
}

void ConsoleUI::printJoinedHeader()
{
    cout << endl;
    cout << "Scientist Name" << "\t" << "\t" << "\t" << "Computer Name" << "\t" << "\t" << "\t" << endl;
    cout << "=========================================================================" << endl;
}

void ConsoleUI::addScientist() //Adds scientist to the list.
{
    string sName;
    int bDate;
    int dDate;
    char gender;

    cin.ignore();
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
        else if(sName.size() > TAB_NAME)
        {
            cout << endl;
            cout << "! - Name you entered is too long. - !" << endl
                 << "! - Name can be max " << TAB_NAME << " characters with space. - !" << endl;
            cout << endl;
        }
    }while(sName.size() == 0 || sName.size() > TAB_NAME);

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

    cin.ignore();
    return bDate;
}

int ConsoleUI::addDeathDateOfScientist(int bDate) //Gets a year of death of scientist from user.
{

    int dDate;
    string deadOrAlive;
    do
    {
        cout << "Is scientist still alive? (yes/no): ";
        getline(cin,deadOrAlive);

        if(deadOrAlive == "no" || deadOrAlive == "No" || deadOrAlive == "NO")
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
        else if(deadOrAlive == "yes" || deadOrAlive == "Yes" || deadOrAlive == "YES")
        {
            dDate = 9999;
        }
        else
        {
            cout << endl;
            cout << "! - Invalid choice, please enter 'yes' or 'no' - !" << endl;
        }
    }while(deadOrAlive != "no" && deadOrAlive != "No" && deadOrAlive != "NO" && deadOrAlive != "yes" && deadOrAlive != "Yes" && deadOrAlive != "YES");

    return dDate;
}

char ConsoleUI::addGenderOfScientist() //Gets a gender of scientist from user.
{
    string gender;
    cin.ignore();
    do
    {
        cout << "Gender (f/m): ";
        getline(cin,gender);

        if(gender != "f" && gender != "m")
        {
            cout << endl;
            cout << "! - This selection was invalid - !" << endl;
            cout << endl;
        }
    }while(gender != "f" && gender != "m");

    return gender.front();
}

void ConsoleUI::addComputer() //Adds computer to the list.
{
    string cName;
    int buildYear;
    string type;
    string wasBuilt;

    cin.ignore();
    cName = addNameOfComputer();
    wasBuilt = addWasBuiltOfComputer();
    if(wasBuilt == "yes" || wasBuilt == "Yes" || wasBuilt == "YES")
    {
        buildYear = addBuildYearOfComputer();
        cin.ignore();
    }
    else
    {
        buildYear = 0;
    }
    type = addTypeOfComputer();

    _scs.addComputer(cName, buildYear, type, wasBuilt);
    //listName();
}

string ConsoleUI::addNameOfComputer()
{
    string cName;

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
        else if(cName.size() > TAB_NAME)
        {
            cout << endl;
            cout << "! - Name you entered is too long. - !" << endl
                 << "! - Name can be max " << TAB_NAME << " characters with space. - !" << endl;
            cout << endl;
        }
    }while(cName.size() == 0 || cName.size() > TAB_NAME);

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
        else if(cType.size() > TAB_TYPE)
        {
            cout << endl;
            cout << "! - Type you entered is too long. - !" << endl
                 << "! - Type can be max " << TAB_TYPE << " characters with space. - !" << endl;
            cout << endl;
        }
    }while(cType.size() == 0 || cType.size() > TAB_TYPE);

    return cType;
}

string ConsoleUI::addWasBuiltOfComputer()
{
    string wasBuilt;

    do
    {
        cout << "Has the computer been built, yes/no: ";
        getline(cin,wasBuilt);

        if(wasBuilt != "no" && wasBuilt != "No" && wasBuilt != "NO" && wasBuilt != "yes" && wasBuilt != "Yes" && wasBuilt != "YES")
        {
            cout << endl;
            cout << "! - Invalid choice, please enter 'yes' or 'no' - !" << endl;
            cout << endl;
        }
    }while(wasBuilt != "no" && wasBuilt != "No" && wasBuilt != "NO" && wasBuilt != "yes" && wasBuilt != "Yes" && wasBuilt != "YES");

    return wasBuilt;
}

int ConsoleUI::chooseSortingMethod()
{
    int sort;

    do
    {
        cout    << "-------------------------------------------------------------------------" << endl;
        cout    << "1 - Print in ascending order." << endl;
        cout    << "2 - Print in descending order." << endl;
        cout    << "-------------------------------------------------------------------------" << endl;

        cout << "Please enter now: ";
        cin >> sort;

        if(sort != 1 && sort != 2)
        {
            cout    << endl;
            cout    << "! - Invalid choice, please enter '1' or '2' - !" << endl;
            cout    << endl;
        }
    }while(sort != 1 && sort != 2);

    return sort;
}

void ConsoleUI::listScientists()
{
    int in;
    int sort;

    cout    << "-------------------------------------------------------------------------" << endl;
    cout    << "1 - For a list of scientists ordered by name" << endl;
    cout    << "2 - For a list of scientists ordered by birth year" << endl;
    cout    << "3 - For a list of scientists ordered by death year" << endl;
    cout    << "4 - For a list of scientists ordered by gender" << endl;
    cout    << "-------------------------------------------------------------------------" << endl;

    cout << "Please enter now: ";
    cin >> in;

    switch(in)
    {
        case 1:
                sort = chooseSortingMethod();
                if(sort == 1)
                {
                    listScientistsByNameAsc();
                }
                else if(sort == 2)
                {
                    listScientistsByNameDesc();
                }
                break;
        case 2:
                sort = chooseSortingMethod();
                if(sort == 1)
                {
                    listScientistsByBirthYearAsc();
                }
                else if(sort == 2)
                {
                    listScientistsByBirthYearDesc();
                }
                break;
        case 3:
                sort = chooseSortingMethod();
                if(sort == 1)
                {
                    listScientistsByDeathYearAsc();
                }
                else if(sort == 2)
                {
                    listScientistsByDeathYearDesc();
                }
                break;
        case 4:
                sort = chooseSortingMethod();
                if(sort == 1)
                {
                    listScientistsByGenderAsc();
                }
                else if(sort == 2)
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
    _scs.scientistsAscendingOrder(0);
    vector<Scientist> sc = _scs.getScientists();
    printListOfScientists(sc);
}

void ConsoleUI::listScientistsByNameDesc()
{
    _scs.scientistsDescendingOrder(0);
    vector<Scientist> sc = _scs.getScientists();
    printListOfScientists(sc);
}

void ConsoleUI::listScientistsByBirthYearAsc()
{
    _scs.scientistsAscendingOrder(1);
    vector<Scientist> sc = _scs.getScientists();
    printListOfScientists(sc);
}

void ConsoleUI::listScientistsByBirthYearDesc()
{
    _scs.scientistsDescendingOrder(1);
    vector<Scientist> sc = _scs.getScientists();
    printListOfScientists(sc);
}

void ConsoleUI::listScientistsByDeathYearAsc()
{
    _scs.scientistsAscendingOrder(2);
    vector<Scientist> sc = _scs.getScientists();
    printListOfScientists(sc);
}

void ConsoleUI::listScientistsByDeathYearDesc()
{
    _scs.scientistsDescendingOrder(2);
    vector<Scientist> sc = _scs.getScientists();
    printListOfScientists(sc);
}

void ConsoleUI::listScientistsByGenderAsc()
{
    _scs.scientistsAscendingOrder(3);
    vector<Scientist> sc = _scs.getScientists();
    printListOfScientists(sc);
}

void ConsoleUI::listScientistsByGenderDesc()
{
    _scs.scientistsDescendingOrder(3);
    vector<Scientist> sc = _scs.getScientists();
    printListOfScientists(sc);
}

void ConsoleUI::listComputers()
{
    int in;
    int sort;

    cout    << "-------------------------------------------------------------------------" << endl;
    cout    << "1 - For a list of computers ordered by name" << endl;
    cout    << "2 - For a list of computers ordered by build year" << endl;
    cout    << "3 - For a list of computers ordered by type" << endl;
    cout    << "4 - For a list of computers ordered by if was built or not" << endl;
    cout    << "-------------------------------------------------------------------------" << endl;

    cout << "Please enter now: ";
    cin >> in;

    switch(in)
    {
        case 1:
                sort = chooseSortingMethod();
                if(sort == 1)
                {
                    listComputersByNameAsc();
                }
                else if(sort == 2)
                {
                    listComputersByNameDesc();
                }
                break;
        case 2:
                sort = chooseSortingMethod();
                if(sort == 1)
                {
                    listComputersByBuildYearAsc();
                }
                else if(sort == 2)
                {
                    listComputersByBuildYearDesc();
                }
                break;
        case 3:
                sort = chooseSortingMethod();
                if(sort == 1)
                {
                    listComputersByTypeAsc();
                }
                else if(sort == 2)
                {
                    listComputersByTypeDesc();
                }
                break;
        case 4:
                sort = chooseSortingMethod();
                if(sort == 1)
                {
                    listComputersIfWasBuiltAsc();
                }
                else if(sort == 2)
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
    _scs.computersAscendingOrder(0);
    vector<Computer> c = _scs.getComputers();
    printListOfComputers(c);
}

void ConsoleUI::listComputersByNameDesc()
{
    _scs.computersDescendingOrder(0);
    vector<Computer> c = _scs.getComputers();
    printListOfComputers(c);
}

void ConsoleUI::listComputersByBuildYearAsc()
{
    _scs.computersAscendingOrder(1);
    vector<Computer> c = _scs.getComputers();
    printListOfComputers(c);
}

void ConsoleUI::listComputersByBuildYearDesc()
{
    _scs.computersDescendingOrder(1);
    vector<Computer> c = _scs.getComputers();
    printListOfComputers(c);
}

void ConsoleUI::listComputersByTypeAsc()
{
    _scs.computersAscendingOrder(2);
    vector<Computer> c = _scs.getComputers();
    printListOfComputers(c);
}

void ConsoleUI::listComputersByTypeDesc()
{
    _scs.computersDescendingOrder(3);
    vector<Computer> c = _scs.getComputers();
    printListOfComputers(c);
}

void ConsoleUI::listComputersIfWasBuiltAsc()
{
    _scs.computersAscendingOrder(3);
    vector<Computer> c = _scs.getComputers();
    printListOfComputers(c);
}

void ConsoleUI::listComputersIfWasBuiltDesc()
{
    _scs.computersDescendingOrder(3);
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
 //   printListOfScientists(sc); // Nýtt print, sem sækir líka ID af computer.
    printListOfScientistsWithComputer(sc);
}

void ConsoleUI::findComputer()
{
    string findC;

    cin.ignore();
    cout << "Enter the name of computer: ";
    getline(cin,findC);
    vector<Computer> c = _scs.findComputerByName(findC);
    printListOfComputers(c); // Nýtt print sem sækir líka ID af scientist
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
    string editSC, sName, yesOrNo;
    int bDate, dDate, id;
    char gender;
    Scientist s;

    cout << "Enter name of the scientist you want to edit: " << endl;
    cin.ignore();
    getline(cin,editSC);
    vector<Scientist> sc = _scs.findScientistByName(editSC);
    cout << "These Scientists matched your search:" << endl;
    printListOfScientists(sc);

    while(yesOrNo != "yes" && yesOrNo != "Yes" && yesOrNo != "YES")
    {
        cout << "Select the id of the scientist you want to edit: ";
        cin >> id;
        s = _scs.scientistToEdit(id);
        if(s.getId() == -1)
        {
            cout << endl;
            cout << "! - Invalid id chosen - !" << endl;
            cout << endl;
            continue;
        }
        printHeaderScientists();
        cout << s << endl;
        cout << endl;
        cout << "Would you like to edit this scientist, yes or no?: ";
        cin.ignore();
        getline(cin,yesOrNo);
    }

    sName = editNameOfScientist(s);
    bDate = editBirthDateOfScientist(s);
    dDate = editDeathDateOfScientist(s,bDate);
    gender = editGenderOfScientist(s);
    _scs.editScientist(id, sName, bDate, dDate, gender);

    s = _scs.scientistToEdit(id);
    cout << "The scientist has been edited: " << endl;
    printHeaderScientists();
    cout << s << endl;
}

string ConsoleUI::editNameOfScientist(Scientist sc)
{
    string editSC;
    string sName;

    //cin.ignore();
    cout << "Would you like to edit the name? yes/no: ";
    getline(cin,editSC);

    if(editSC == "yes" || editSC == "Yes" || editSC == "YES")
    {
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
            else if(sName.size() > TAB_NAME)
            {
                cout << endl;
                cout << "! - Name you entered is too long. - !" << endl
                     << "! - Name can be max " << TAB_NAME << " characters with space. - !" << endl;
                cout << endl;
            }

        }while(sName.size() == 0 || sName.size() > TAB_NAME);
    }
    else if(editSC == "no" || editSC == "No" || editSC == "NO")
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
    string editSC;
    int bDate;

    //cin.ignore();
    cout << "Would you like to edit year of birth? yes/no: ";
    getline(cin,editSC);

    if(editSC == "yes" || editSC == "Yes" || editSC == "YES")
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
        cin.ignore();

    }
    else if(editSC == "no" || editSC == "No" || editSC == "NO")
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
    string editSC;
    string deadOrAlive;
    int dDate;

    //cin.ignore();
    cout << "Would you like to edit year of death? yes/no: ";
    getline(cin,editSC);

    if(editSC == "yes" || editSC == "Yes" || editSC == "YES")
    {
        do
        {
            cout << "Is scientist still alive? yes/no: ";
            getline(cin,deadOrAlive);

            if(deadOrAlive == "no" || deadOrAlive == "No" || deadOrAlive == "NO")
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
                cin.ignore();
            }
            else if(deadOrAlive == "yes" || deadOrAlive == "Yes" || deadOrAlive == "YES")
            {
                dDate = 9999;
            }
            else
            {
                cout << endl;
                cout << "! - Invalid choice, please enter 'yes' or 'nno' - !" << endl;
            }
        }while(deadOrAlive != "no" && deadOrAlive != "No" && deadOrAlive != "NO" && deadOrAlive != "yes" && deadOrAlive != "Yes" && deadOrAlive != "YES");
    }
    else if(editSC == "no" || editSC == "No" || editSC == "NO")
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
    string editSC;
    string gender;

    //cin.ignore();
    cout << "Would you like to edit gender? yes or no: ";
    getline(cin,editSC);

    if(editSC == "yes" || editSC == "Yes" || editSC == "YES")
    {
        do
        {
            cout << "Enter new gender (f/m): ";
            //cin.ignore();
            getline(cin,gender);
            if(gender != "f" && gender != "m")
            {
                cout << endl;
                cout << "! - This selection was invalid - !" << endl;
                cout << endl;
            }
        }while(gender != "f" && gender != "m");
    }
    else if(editSC == "no" || editSC == "No" || editSC == "NO")
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

    return gender.front();
}

void ConsoleUI::editComputer()
{
    string editC, cName, yesOrNo;
    int buildYear, id;
    string type, wasBuilt;
    Computer co;
    cout << "Enter name of the computer you want to edit: " << endl;
    cin.ignore();
    getline(cin,editC);
    vector<Computer> c = _scs.findComputerByName(editC);
    cout << "These computers matched your search:" << endl;
    printListOfComputers(c);
    while(yesOrNo != "yes" && yesOrNo != "Yes" && yesOrNo != "YES")
    {
        cout << "Select the id of the computer you want to edit: ";
        cin >> id;
        co = _scs.computerToEdit(id);
        if(co.getId() == -1)
        {
            cout << endl;
            cout << "! - Invalid id chosen - !" << endl;
            cout << endl;
            continue;
        }
        printHeaderComputers();
        cout << co << endl;
        cout << endl;
        cout << "Would you like to edit this computer, yes or no?: ";
        cin.ignore();
        getline(cin,yesOrNo);
    }
    cName = editNameOfComputer(co);
    wasBuilt = editWasBuiltOfComputer(co);
    if(wasBuilt == "yes" || wasBuilt == "Yes" || wasBuilt == "YES")
    {
        buildYear = editBuildYearOfComputer(co);
        cin.ignore();
    }
    else
    {
        buildYear = 0;
    }
    buildYear = editBuildYearOfComputer(co);
    type = editTypeOfComputer(co);
    _scs.editComputer(id, cName, buildYear, type, wasBuilt);

    co = _scs.computerToEdit(id);
    cout << "The computer has been edited: " << endl;
    printHeaderComputers();
    cout << co << endl;
}

string ConsoleUI::editNameOfComputer(Computer c)
{
    string editC;
    string cName;

    //cin.ignore();
    cout << "Would you like to edit the name? yes/no: ";
    getline(cin,editC);

    if(editC == "yes" || editC == "Yes" || editC == "YES")
    {
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
            else if(cName.size() > TAB_NAME)
            {
                cout << endl;
                cout << "! - Name you entered is too long. - !" << endl
                     << "! - Name can be max " << TAB_NAME << " characters with space. - !" << endl;
                cout << endl;
            }

        }while(cName.size() == 0 || cName.size() > TAB_NAME);
    }
    else if(editC == "no" || editC == "No" || editC == "NO")
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
    string editC;
    int buildYear;

    //cin.ignore();
    cout << "Would you like to edit the build year? yes/no: ";
    getline(cin,editC);

    if(editC == "yes" || editC == "Yes" || editC == "YES")
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
        cin.ignore();
    }
    else if(editC == "no" || editC == "No" || editC == "NO")
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
    string editC;
    string cType;

    //cin.ignore();
    cout << "Would you like to edit the type? yes/no: ";
    getline(cin,editC);

    if(editC == "yes" || editC == "Yes" || editC == "YES")
    {
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
            else if(cType.size() > TAB_TYPE)
            {
                cout << endl;
                cout << "! - Type you entered is too long. - !" << endl
                     << "! - Type can only be under " << TAB_TYPE << " characters with space. - !" << endl;
                cout << endl;
            }

        }while(cType.size() == 0 || cType.size() > TAB_TYPE);
    }
    else if(editC == "no" || editC == "No" || editC == "NO")
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
    string editC;
    string wasBuilt;

    //cin.ignore();
    cout << "Would you like to edit if the computer has been built? yes/no: ";
    getline(cin,editC);

    if(editC == "yes" || editC == "Yes" || editC == "YES")
    {
        do
        {
            cout    << "Has the computer been built? yes/no: ";
            getline(cin,wasBuilt);
            if(wasBuilt != "no" && wasBuilt != "No" && wasBuilt != "NO" && wasBuilt != "yes" && wasBuilt != "Yes" && wasBuilt != "YES")
            {
                cout << endl;
                cout << "! - Invalid choice, please enter 'yes' or 'no' - !" << endl;
                cout << endl;
            }
        }while(wasBuilt != "no" && wasBuilt != "No" && wasBuilt != "NO" && wasBuilt != "yes" && wasBuilt != "Yes" && wasBuilt != "YES");
    }
    else if(editC == "no" || editC == "No" || editC == "NO")
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

    return wasBuilt.front();
}
