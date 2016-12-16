#include "AddWindow.h"
#include "ui_AddWindow.h"

AddWindow::AddWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddWindow)
{
    ui->setupUi(this);
}

AddWindow::~AddWindow()
{
    delete ui;
}

void AddWindow::on_button_addBack_clicked()
{
    close();
}

void AddWindow::on_button_addQuit_clicked()
{
    close();
    qApp->quit();
}

//Search on text changed.
void AddWindow::on_input_addScientistSearch_textChanged(const QString &arg1)
{
    string search = arg1.toStdString();
    if(search.size() != 0)
    {
        displayScientistSearchResults(search);
    }
    if(search.size()== 0)
    {
        ui->table_addScientist->clearContents();
    }
}

void AddWindow::on_button_addScientist_clicked()
{
    string name = ui->input_addNameScientist->text().toStdString();
    string bY = ui->input_addYearBorn->text().toStdString();
    int birthYear = ui->input_addYearBorn->text().toInt();

    //Two validity checks for birthYear.
    bool birthYearIsValid = Utilities::validYearCheck(bY);
    birthYearIsValid = _scs.validYearCheck(birthYear);
    bool deathYearIsValid = false;
    string alive = ui->comboBox_addSAlive->currentText().toStdString();
    int deathYear = 9999;
    if(alive == "Yes")
    {
        deathYearIsValid = true;
    }
    else if (alive == "No")
    {
        string dY = ui->input_addYearOfDeath->text().toStdString();
        deathYear = ui->input_addYearOfDeath->text().toInt();

        //Two validity checks for deathYear.
        deathYearIsValid = Utilities::validYearCheck(dY);
        deathYearIsValid = _scs.validYearCheck(deathYear);
        if(deathYearIsValid && deathYear < birthYear)
        {
            deathYearIsValid = false;
        }
    }
    string gender = ui->comboBox_addSGender->currentText().toStdString();
    char g = tolower(gender.front());
    string link = ui->input_addLink->text().toStdString();

    //Scientist only added if both years are valid.
    if(!birthYearIsValid && deathYearIsValid)
    {
        ui->label_addScientistErrorMessage->setText("<p style=\"color:#f44242;\">Invalid Birth Year</p>");
    }
    else if(!deathYearIsValid && birthYearIsValid)
    {
        ui->label_addScientistErrorMessage->setText("<p style=\"color:#f44242;\">Invalid Year of Death</p>");
    }
    else if(!birthYearIsValid && !deathYearIsValid)
    {
        ui->label_addScientistErrorMessage->setText("<p style=\"color:#f44242;\">Invalid Year Format</p>");
    }
    else
    {
        _scs.addScientist(name, birthYear, deathYear, g, link);
        displayAllScientists();
        clearScientistForm();
    }
}

//Enables adding death year if "No" is chosen.
void AddWindow::on_comboBox_addSAlive_currentIndexChanged(const QString &arg1)
{
    string alive = arg1.toStdString();
    if (alive == "No")
    {
        ui->input_addYearOfDeath->setEnabled(true);
    }
    else
    {
        ui->input_addYearOfDeath->setEnabled(false);
    }
}

//Enables adding build year if "Yes" is chosen.
void AddWindow::on_comboBox_addCBuilt_currentIndexChanged(const QString &arg1)
{
    string wasBuilt = arg1.toStdString();
    if (wasBuilt == "Yes")
    {
        ui->input_addYearOfCompletion->setEnabled(true);
    }
    else
    {
        ui->input_addYearOfCompletion->setEnabled(false);
    }
}

void AddWindow::on_button_addComputer_clicked()
{
    string name = ui->input_addNameComputer->text().toStdString();
    string type = ui->input_addType->text().toStdString();
    string wasBuilt = ui->comboBox_addCBuilt->currentText().toStdString();
    bool buildYearIsValid = true;
    string link = ui->input_ComputerLink->text().toStdString();
    int buildYear = 0;
    if (wasBuilt == "Yes")
    {
        buildYear = ui->input_addYearOfCompletion->text().toInt();
        string buY = ui->input_addYearOfCompletion->text().toStdString();
        //Two validity checks.
        buildYearIsValid = Utilities::validYearCheck(buY);
        buildYearIsValid = _scs.validYearCheck(buildYear);
    }
    //Computer only added if build year is valid.
    if(buildYearIsValid)
    {
        _scs.addComputer(name, buildYear, type, wasBuilt, link);
        displayAllComputers();
        clearComputerForm();
    }
    else
    {
        ui->label_addComputerErrorMessage->setText("<p style=\"color:#f44242;\">Invalid Build Year</p>");
    }
}

//Add scientist button enabled if name is not empty.
void AddWindow::on_input_addNameScientist_textChanged(const QString &arg1)
{
    if(arg1.isEmpty())
    {
        ui->button_addScientist->setEnabled(false);
    }
    else
    {
        ui->button_addScientist->setEnabled(true);
    }
}

//Add computer button enabled if name is not empty.
void AddWindow::on_input_addNameComputer_textChanged(const QString &arg1)
{
    if(arg1.isEmpty())
    {
        ui->button_addComputer->setEnabled(false);
    }
    else
    {
        if(!ui->input_addType->text().isEmpty())
        {
            ui->button_addComputer->setEnabled(true);
        }
    }
}

//Computer cannot be added if type field is empty.
void AddWindow::on_input_addType_textChanged(const QString &arg1)
{
    if(arg1.isEmpty())
    {
        ui->button_addComputer->setEnabled(false);
    }
    else
    {
        if(!ui->input_addNameComputer->text().isEmpty())
        {
            ui->button_addComputer->setEnabled(true);
        }
    }
}

void AddWindow::on_input_searchComputer_textChanged(const QString &arg1)
{
    string search = arg1.toStdString();
    if(search.size() != 0)
    {
        displayComputerSearchResult(search);
    }
    if(search.size()== 0)
    {
        ui->table_addComputer->clearContents();
    }
}

void AddWindow::displayScientistSearchResults(string search)
{
    ui->label_searchScientistsNoResults->setText("");
    ui->table_addScientist->clearContents();
   _currentlyDisplayedScientists.clear();

   _currentlyDisplayedScientists = _scs.findScientistByName(search);

   //If search returned results, the results are shown.
   if(_currentlyDisplayedScientists.size() != 0)
   {

       ui->table_addScientist->setRowCount(_currentlyDisplayedScientists.size());

       for(unsigned int row = 0; row < _currentlyDisplayedScientists.size(); row++)
       {
           Scientist s = _currentlyDisplayedScientists.at(row);
           QString name = QString::fromStdString(s.getName());
           QString birthYear = QString::number(s.getBirthDate());
           QString deathYear;
           if(s.getDeathDate() == 9999)
           {
               deathYear = "Alive";
           }
           else
           {
               deathYear = QString::number(s.getDeathDate());
           }
           QString gender = QChar(toupper(s.getGender()));

           //TableItemSC class inherits from QTableWidgetClass and overloads sorting
           //to sort the Id's as numbers rather than strings.
           ui->table_addScientist->setItem(row, 0, new Utilities::TableItemSC(s.getId()));
           ui->table_addScientist->setItem(row, 1, new Utilities::TableItemSC(name));
           ui->table_addScientist->setItem(row, 2, new Utilities::TableItemSC(birthYear));
           ui->table_addScientist->setItem(row, 3, new Utilities::TableItemSC(deathYear));
           ui->table_addScientist->setItem(row, 4, new Utilities::TableItemSC(gender));
       }

       ui->table_addScientist->resizeColumnsToContents();
   }
   //If vector is empty and search is not, a message is sent to user.
   if(search.size() != 0 && _currentlyDisplayedScientists.size() == 0)
   {
       ui->table_addScientist->clearContents();
       ui->label_searchScientistsNoResults->setText("<p style=\"color:#f44242;\">Your search returned no results.</p>");
   }
}

void AddWindow::displayComputerSearchResult(string search)
{
    ui->label_searchComputerNoResults->setText("");
    ui->table_addComputer->clearContents();
   _currentlyDisplayedComputers.clear();

   _currentlyDisplayedComputers = _scs.findComputerByName(search);
   if(_currentlyDisplayedComputers.size() != 0)
   {

       ui->table_addComputer->setRowCount(_currentlyDisplayedComputers.size());

       for(unsigned int row = 0; row < _currentlyDisplayedComputers.size(); row++)
       {
           Computer c = _currentlyDisplayedComputers.at(row);
           QString name = QString::fromStdString(c.getName());
           QString buildYear = QString::number(c.getBuildYear());
           if(c.getBuildYear() == 0)
           {
               buildYear = "";
           }
           QString type = QString::fromStdString(c.getType());
           QString wasBuilt;
           if(c.getWasBuilt())
           {
               wasBuilt = "Yes";
           }
           else
           {
               wasBuilt = "No";
           }

           ui->table_addComputer->setItem(row, 0, new Utilities::TableItemSC(c.getId()));
           ui->table_addComputer->setItem(row, 1, new Utilities::TableItemSC(name));
           ui->table_addComputer->setItem(row, 2, new Utilities::TableItemSC(buildYear));
           ui->table_addComputer->setItem(row, 3, new Utilities::TableItemSC(type));
           ui->table_addComputer->setItem(row, 4, new Utilities::TableItemSC(wasBuilt));
       }

       ui->table_addComputer->resizeColumnsToContents();
   }
   if(search.size() != 0 && _currentlyDisplayedComputers.size() == 0)
   {
       ui->table_addComputer->clearContents();
       ui->label_searchComputerNoResults->setText("<p style=\"color:#f44242;\">Your search returned no results.</p>");
   }
}

void AddWindow::displayAllScientists()
{
    ui->input_addScientistSearch->setText("");
    ui->table_addScientist->clearContents();
    _allScientists.clear();
    _scs.scientistsAscendingOrder(0);
    _allScientists = _scs.getScientists();

    ui->table_addScientist->setRowCount(_allScientists.size());

    for(unsigned int row = 0; row < _allScientists.size(); row++)
    {
        Scientist s = _allScientists.at(row);
        QString name = QString::fromStdString(s.getName());
        QString birthYear = QString::number(s.getBirthDate());
        QString deathYear;
        if(s.getDeathDate() == 9999)
        {
            deathYear = "Alive";
        }
        else
        {
            deathYear = QString::number(s.getDeathDate());
        }

        QString gender = QChar(toupper(s.getGender()));

        ui->table_addScientist->setItem(row, 0, new Utilities::TableItemSC(s.getId()));
        ui->table_addScientist->setItem(row, 1, new Utilities::TableItemSC(name));
        ui->table_addScientist->setItem(row, 2, new Utilities::TableItemSC(birthYear));
        ui->table_addScientist->setItem(row, 3, new Utilities::TableItemSC(deathYear));
        ui->table_addScientist->setItem(row, 4, new Utilities::TableItemSC(gender));
    }

    ui->table_addScientist->resizeColumnsToContents();

}

void AddWindow::displayAllComputers()
{
    ui->input_searchComputer->setText("");
    ui->table_addComputer->clearContents();
    _allComputers.clear();

    _scs.computersAscendingOrder(0);
    _allComputers = _scs.getComputers();

    ui->table_addComputer->setRowCount(_allComputers.size());

    for(unsigned int row = 0; row < _allComputers.size(); row++)
    {
        Computer c = _allComputers.at(row);
        QString name = QString::fromStdString(c.getName());
        QString buildYear = QString::number(c.getBuildYear());
        if(c.getBuildYear() == 0)
        {
            buildYear = "";
        }
        QString type = QString::fromStdString(c.getType());
        QString wasBuilt;
        if(c.getWasBuilt())
        {
            wasBuilt = "Yes";
        }
        else
        {
            wasBuilt = "No";
        }

        ui->table_addComputer->setItem(row, 0, new Utilities::TableItemSC(c.getId()));
        ui->table_addComputer->setItem(row, 1, new Utilities::TableItemSC(name));
        ui->table_addComputer->setItem(row, 2, new Utilities::TableItemSC(buildYear));
        ui->table_addComputer->setItem(row, 3, new Utilities::TableItemSC(type));
        ui->table_addComputer->setItem(row, 4, new Utilities::TableItemSC(wasBuilt));
    }

    ui->table_addComputer->resizeColumnsToContents();
}

void AddWindow::clearScientistForm()
{
    ui->input_addNameScientist->setText("");
    ui->input_addYearBorn->setText("");
    ui->comboBox_addSAlive->setCurrentIndex(0);
    ui->input_addYearOfDeath->setText("");
    ui->comboBox_addSGender->setCurrentIndex(0);
    ui->input_addLink->setText("");
    ui->input_addYearOfDeath->setEnabled(false);
    ui->button_addScientist->setEnabled(false);
    ui->label_addScientistErrorMessage->setText("");
}

void AddWindow::clearComputerForm()
{
    ui->input_addNameComputer->setText("");
    ui->input_addType->setText("");
    ui->comboBox_addCBuilt->setCurrentIndex(0);
    ui->input_addYearOfCompletion->setText("");
    ui->input_ComputerLink->setText("");
    ui->input_addYearOfCompletion->setEnabled(true);
    ui->button_addComputer->setEnabled(false);
    ui->label_addComputerErrorMessage->setText("");
}


