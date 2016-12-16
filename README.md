# Computer Scientists Readme

Program which lists known computers and characters from computer science.

## I. Description
We have developed a program that holds a list over computer scientists and computers.

When working with the list of computer scientists:

* You can add a new computer scientist to the list. 
* You can view a list of computer scientists on screen ordered by id, name, birth year, death year and gender.
* You can search for a name of a computer scientist.
* You can edit an entry of a computer scientist by double clicking the table.
* You can delete an entry of a computer scientist.
* You can join a computer scientist and a computer together.

When working with the list of computers:

* You can add a new computer to the list.
* You can view a list of computers on screen ordered by id, name, build year, type and if it was built or not.
* You can search for a name of a computer.
* You can edit an entry of a computer by double clicking the table.
* You can delete an entry of a computer.
* You can join a computer scientist and a computer together.

When working with the list of connections:

* You can add a new connection between a computer and a computer scientist.
* You can view a list of connections on screen ordered by scientist's id, scientist's name, computer's id and computer's name.
* You can search for a connection between a computer and a computer scientist.
* You can delete a connection between a computer and a computer scientist.

You can do these commands as often as you wish. To quit program, click on 'quick' button. To go to previous window, click on back.

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
+ Scientist.cpp
+ Scientist.h
+ SCService.cpp
+ SCService.h
+ Utilities.cpp
+ Utilities.h
+ main.cpp
+ resources.qrc
+ ComputerScienceDatabase.sqlite - Database that holds lists of scientists, computers, their id's, a joined list and links to known       scientists and computers.
+ Insert_queries.txt - SQL queries to fill database.


## III. Using Qt and SQLite Manager
1. Clone the repository
2. Save the .sqlite file in C:\ drive.
3. Run SQLite Manager as administrator.
4. Run Qt as administrator.
5. Open ComputerScientists.pro from folder Skil3 in Qt
6. Change working directory to where the chiquita40\Skil3 folder is saved on your computer
7. Build and run the program

## IV. Instructions 
When you run the program, a welcome window with quick search and buttons for all program features appears on the screen.

**Add**

You can add a new scientist and/or a computer to the database.

**Edit**

You can edit a scientist and/or a computer.

**See full lists**

You can choose from a list of scientists, computers or scientists connected to computers. Each list item can be ordered ascending or descending by clicking on the adequate table header.

**Delete**

Search for a scientist or computer and delete it from the list. You can also disconnect a computer from a scientist.

**Connect**

Connect a scientist with a computer. The Invented table in the SQLite Manager will be updated.

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
