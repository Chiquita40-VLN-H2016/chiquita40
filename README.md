# Computer Scientists Readme

Program which lists known characters from Computer Science

## I. Description
We have developed a program that holds a list over Computer Scientists.

* You can add a new Computer Scientist to the list. 
* You can print out a list of Computer Scientists on screen ordered by name, birth year, death year and gender.
* You can search for a name of a Computer Scientist.
* You can edit an entry of a Computer Scientist.
* You can delete an entry of a Computer Scientist.

You can do these commands as often as you whish. To stop type in 'quit'.

## II. File list
+ ConsoleUI.cpp
+ ConsoleUI.h
+ Scientist.cpp
+ Scientist.h
+ ScientistService.cpp
+ ScientistService.h
+ DataAccess.cpp
+ DataAccess.h
+ main.cpp
+ scientists.txt        -   This is a data file which holds a list of Computer Scientists.
+ scientists_backup.txt        -   This is a backup of the data file above.

## III. Using Qt
1. Clone the Repository
2. Open ComputerScientists.pro in Qt
3. Change working directory to where the chiquita40\ComputerScientists folder is saved on your computer
4. Build the program

## IV. Instructions 
When you run the program a list of commands appear on the screen.

**Add/Edit**

Name of new Scientist cannot be longer than 23 characters (with spaces). He/She has to have a first and a last name; middle name is not possible. It is not possible to add the same Scientist more than once.

Edit works only with the exact first and last name entered.

**List**

The different lists represent the same list ordered by different information about the scientists. The lists you can choose from are all in ascending order.

**Find**

Find works only with the exact first and last name, it does not give you results if you only enter first or last name or if you enter the name incorrectly.

**Delete**

Delete works only with the exact first and last name.

**Quit**

If you get a compile time error when you have entered "quit", please rebuild (choose "Rebuild All") the program.

## V. Coding conventions
* Member variables start with an _underscore.
* Other variables start with a lower case letter (theVariable).
* Class names start with an upper case letter (TheClass).
* Curly brackets are always used even when code in statements is one line.
* Curly brackets are always placed beneath the statement they refer to.
* Code is indented with a single tab.

Example:
```c++
if(n == 0)
{
  return n;
}
```
