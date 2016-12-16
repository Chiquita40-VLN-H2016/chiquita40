#include "ListWindow.h"
#include "ui_ListWindow.h"

ListWindow::ListWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListWindow)
{
    ui->setupUi(this);
    displayAllConnections();
    displayAllScientist(0, 0);
    displayAllComputers();
}

ListWindow::~ListWindow()
{
    delete ui;
}


void ListWindow::displayScientistSearchResults(string search)
{
    ui->label_searchScientistsNoResults->setText("");
    ui->table_Scientists->clearContents();
   _currentlyDisplayedScientists.clear();

   _currentlyDisplayedScientists = _scs.findScientistByName(search);
   if(_currentlyDisplayedScientists.size() != 0)
   {

       ui->table_Scientists->setRowCount(_currentlyDisplayedScientists.size());

       for(unsigned int row = 0; row < _currentlyDisplayedScientists.size(); row++)
       {
           Scientist s = _currentlyDisplayedScientists.at(row);
           //QTableWidgetItem *id = new QTableWidgetItem(s.getId());
           QString id = QString::number(s.getId());
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

           ui->table_Scientists->setItem(row, 0, new QTableWidgetItem(id));
           ui->table_Scientists->setItem(row, 1, new QTableWidgetItem(name));
           ui->table_Scientists->setItem(row, 2, new QTableWidgetItem(birthYear));
           ui->table_Scientists->setItem(row, 3, new QTableWidgetItem(deathYear));
           ui->table_Scientists->setItem(row, 4, new QTableWidgetItem(gender));
       }
   }
   if(search.size() != 0 && _currentlyDisplayedScientists.size() == 0)
   {
       ui->table_Scientists->clearContents();
       ui->label_searchScientistsNoResults->setText("<p style=\"color:#f44242;\">Your search returned no results.</p>");
   }
}

void ListWindow::displayAllScientist(int type, int ascdesc)
{
    ui->input_listScientistSearch->setText("");
    ui->table_Scientists->clearContents();
    _allScientists.clear();
    scientistsWhichOrder(type, ascdesc);
    _allScientists = _scs.getScientists();

    ui->table_Scientists->setRowCount(_allScientists.size());

    for(unsigned int row = 0; row < _allScientists.size(); row++)
    {
        Scientist s = _allScientists.at(row);
        //QTableWidgetItem *id = new QTableWidgetItem(s.getId());
        QString id = QString::number(s.getId());
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

        ui->table_Scientists->setItem(row, 0, new QTableWidgetItem(id));
        ui->table_Scientists->setItem(row, 1, new QTableWidgetItem(name));
        ui->table_Scientists->setItem(row, 2, new QTableWidgetItem(birthYear));
        ui->table_Scientists->setItem(row, 3, new QTableWidgetItem(deathYear));
        ui->table_Scientists->setItem(row, 4, new QTableWidgetItem(gender));
    }
}

void ListWindow::displayComputerSearchResults(string search)
{
    ui->label_searchComputersNoResults->setText("");
    ui->table_Computers->clearContents();
    _currentlyDisplayedComputers.clear();

    _currentlyDisplayedComputers = _scs.findComputerByName(search);
    if(_currentlyDisplayedComputers.size() !=0)
    {
        ui->table_Computers->setRowCount(_currentlyDisplayedComputers.size());

        for(unsigned int row = 0; row < _currentlyDisplayedComputers.size(); row++)
        {
            Computer c =_currentlyDisplayedComputers.at(row);
            QString id = QString::number(c.getId());
            QString name = QString::fromStdString(c.getName());
            QString type = QString::fromStdString(c.getType());
            QString buildyear = QString::number(c.getBuildYear());
            if(c.getBuildYear() == 0)
            {
                buildyear = " ";
            }
            else
            {
                QString::number(c.getBuildYear());
            }
            QString wasbuilt = QString::number(c.getWasBuilt());
            if(c.getWasBuilt() == 1)
            {
                wasbuilt = "Yes";
            }
            else if(c.getWasBuilt() == 0)
            {
                wasbuilt = "No";
            }

            ui->table_Computers->setItem(row, 0, new QTableWidgetItem(id));
            ui->table_Computers->setItem(row, 1, new QTableWidgetItem(name));
            ui->table_Computers->setItem(row, 2, new QTableWidgetItem(buildyear));
            ui->table_Computers->setItem(row, 3, new QTableWidgetItem(type));
            ui->table_Computers->setItem(row, 4, new QTableWidgetItem(wasbuilt));

        }
    }
    if(search.size() != 0 && _currentlyDisplayedComputers.size() == 0)
    {
        ui->table_Computers->clearContents();
        ui->label_searchComputersNoResults->setText("<p style=\"color:#f44242;\">Your search returned no results.</p>");
    }
}

void ListWindow::displayAllComputers()
{
    ui->input_listComputerSearch->setText("");
    ui->table_Computers->clearContents();
    _allComputers.clear();
    _allComputers = _scs.getComputers();


    ui->table_Computers->setRowCount(_allComputers.size());

    for(unsigned int row = 0; row < _allComputers.size(); row++)
    {
        Computer c = _allComputers.at(row);
        QString id = QString::number(c.getId());
        QString name = QString::fromStdString(c.getName());
        QString type = QString::fromStdString(c.getType());
        QString buildyear = QString::number(c.getBuildYear());
        if(c.getBuildYear() == 0)
        {
            buildyear = " ";
        }
        else
        {
            QString::number(c.getBuildYear());
        }
        QString wasbuilt = QString::number(c.getWasBuilt());
        if(c.getWasBuilt() == 1)
        {
            wasbuilt = "Yes";
        }
        else if(c.getWasBuilt() == 0)
        {
            wasbuilt = "No";
        }


        ui->table_Computers->setItem(row, 0, new QTableWidgetItem(id));
        ui->table_Computers->setItem(row, 1, new QTableWidgetItem(name));
        ui->table_Computers->setItem(row, 2, new QTableWidgetItem(buildyear));
        ui->table_Computers->setItem(row, 3, new QTableWidgetItem(type));
        ui->table_Computers->setItem(row, 4, new QTableWidgetItem(wasbuilt));


    }
}


void ListWindow::displayAllConnections()
{
    ui->input_searchConnections->setText("");
    ui->table_connections->clearContents();
    _allConnections.clear();
    _allConnections = _scs.inventedAscendingOrder(0);

    ui->table_connections->setRowCount(_allConnections.size());

    for(unsigned int row = 0; row < _allConnections.size(); row++)
    {
        Invented in = _allConnections.at(row);
        QString sId = QString::number(in.getSId());
        QString sName = QString::fromStdString(in.getSName());
        QString cId = QString::number(in.getCId());
        QString cName = QString::fromStdString((in.getCName()));

        ui->table_connections->setItem(row, 0, new QTableWidgetItem(sId));
        ui->table_connections->setItem(row, 1, new QTableWidgetItem(sName));
        ui->table_connections->setItem(row, 2, new QTableWidgetItem(cId));
        ui->table_connections->setItem(row, 3, new QTableWidgetItem(cName));
    }
}

//Order scientists in desired order.
void ListWindow::scientistsWhichOrder(int type, int ascdesc)
{
    if(ascdesc == 0) //Ascending order.
    {
        switch(type)
        {

            case 0:  //Order by name.
                    _scs.scientistsAscendingOrder(0);
                    break;
            case 1: //Order by Birth year.
                    _scs.scientistsAscendingOrder(1);
                    break;
            case 2: //Order by Year of death.
                    _scs.scientistsAscendingOrder(2);
                    break;
            case 3: //Order by gender.
                    _scs.scientistsAscendingOrder(3);
                    break;
            default: //Order by id.
                    _scs.scientistsAscendingOrder(4);
        }
    }
    else //Descending order.
    {
        switch(type)
        {

            case 0:  //Order by name.
                    _scs.scientistsDescendingOrder(0);
                    break;
            case 1: //Order by Birth year.
                    _scs.scientistsDescendingOrder(1);
                    break;
            case 2: //Order by Year of death.
                    _scs.scientistsDescendingOrder(2);
                    break;
            case 3: //Order by gender.
                    _scs.scientistsDescendingOrder(3);
                    break;
            default: //Order by id.
                    _scs.scientistsDescendingOrder(4);
        }
    }
}

void ListWindow::on_button_listBack_clicked()
{
    close();
}

void ListWindow::on_button_listQuit_clicked()
{
    close();
    qApp->quit();
}

void ListWindow::on_input_listScientistSearch_textChanged(const QString &arg1)
{
    string search = arg1.toStdString();
    displayScientistSearchResults(search);
}

void ListWindow::on_lineEdit_textChanged(const QString &arg1)
{
    string search = arg1.toStdString();
    //displayConnectionSearchResults(search);
}

void ListWindow::on_input_listComputerSearch_textChanged(const QString &arg1)
{
    string search = arg1.toStdString();
    displayComputerSearchResults(search);
}
