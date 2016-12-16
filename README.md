# Computer Scientists Readme

Program which lists known computers and characters from Computer Science.

## I. Description
We have developed a program that holds a list over Computer Scientists and Computers.

When working with the list of Computer Scientists:

* You can add a new Computer Scientist to the list. 
* You can print out a list of Computer Scientists on screen ordered by name, birth year, death year and gender.
* You can search for a name of a Computer Scientist.
* You can edit an entry of a Computer Scientist.
* You can delete an entry of a Computer Scientist.
* You can join a Computer Scientist and a Computer together.

When working with the list of Computers:

* You can add a new Computer to the list.
* You can print out a list of Computers on screen ordered by name, build year, type and if it was built or not.
* You can search for a name of a Computer.
* You can edit an entry of a Computer.
* You can delete an entry of a Computer.
* You can join a Computer Scientist and a Computer together.

You can do these commands as often as you wish. To stop type in 'quit'.

## II. File list
+ AddWindow.cpp
+ AddWindow.h
+ AddWindow.ui
+ Computer.cpp
+ Computer.h
+ ConnectWindow.cpp
+ ConnectWindow.h
+ ConnectWindow.ui
+ DataAccess.cpp
+ DataAccess.h
+ DeleteWindow.cpp
+ DeleteWindow.h
+ DeleteWindow.ui
+ EditWindow.cpp
+ EditWindow.h
+ EditWindow.ui
+ Invented.cpp
+ Invented.h
+ ListWindow.cpp
+ ListWindow.h
+ ListWindow.ui
+ MainWindow.cpp
+ MainWindow.h
+ MainWindow.ui
+ resources.qrc
+ Scientist.cpp
+ Scientist.h
+ SCService.cpp
+ SCService.h
+ main.cpp
+ CSHistory.sqlite           - Database that holds lists of Scientists, Computers and a joined list.
+ Insert_queries.txt - SQL queries to fill database.

## III. Using Qt and SQLite Manager
1. Clone the Repository
2. Save the .sqlite file in C:\ drive.
3. Run SQLite Manager as administrator.
4. Run Qt as administrator.
5. Open ComputerScientists.pro from folder Skil3 in Qt
6. Change working directory to where the chiquita40\Skil3 folder is saved on your computer
7. Build and run the program

## IV. Instructions 
When you run the program, a welcome window with quick search and buttons for all program features appears on the screen.

**Add/Edit**

Name of a new Scientist and/ or a Computer cannot be longer than 31 characters (with spaces).

**See full lists**

You can choose from a list of Scientists, Computers or Scientists connected to Computers. Each list item can be ordered ascending or descending by clicking on the adequate table header.

**Delete**

Search for a Scientist or Computer and delete it from the list. You can also disconnect a Computer from a Scientist.

**Connect**

Connect a Scientist with a Computer. The Invented table in the SQLite Manager will be updated.

**Quit**

Each window contains a button to quit the programm.

## V. Coding conventions
* Member variables start with an _underscore.
* Other variables start with a lower case letter (theVariable)(Camel case).
* Class names start with an upper case letter (TheClass)(Pascal case).
* Curly braces are always used even when code in statements is one line.
* Curly braces are always placed beneath the statement they refer to.
* Code is indented with a single tab.

Example:
```c++
if(n == 0)
{
  return n;
}
```
