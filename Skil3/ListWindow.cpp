#include "ListWindow.h"
#include "ui_ListWindow.h"

ListWindow::ListWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListWindow)
{
    ui->setupUi(this);
    displayAllConnections();
    displayAllScientist();
    displayAllComputers();
}

ListWindow::~ListWindow()
{
    delete ui;
}


void ListWindow::displayScientistSearchResults(string search)
{
    ui->label_searchScientistsNoResults->setText("");
    ui->table_scientists->clearContents();
   _currentlyDisplayedScientists.clear();

   _currentlyDisplayedScientists = _scs.findScientistByName(search);
   if(_currentlyDisplayedScientists.size() != 0)
   {

       ui->table_scientists->setRowCount(_currentlyDisplayedScientists.size());

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
           QString l = QString::fromStdString(s.getLink());
           QString link = "<a href =\"" + l + "\">Link</a>";

           ui->table_scientists->setItem(row, 0, new Utilities::TableItemSC(s.getId()));
           ui->table_scientists->setItem(row, 1, new Utilities::TableItemSC(name));
           ui->table_scientists->setItem(row, 2, new Utilities::TableItemSC(birthYear));
           ui->table_scientists->setItem(row, 3, new Utilities::TableItemSC(deathYear));
           ui->table_scientists->setItem(row, 4, new Utilities::TableItemSC(gender));
           ui->table_scientists->setItem(row, 5, new Utilities::TableItemSC(link));

       }
   }
   if(search.size() != 0 && _currentlyDisplayedScientists.size() == 0)
   {
       ui->table_scientists->clearContents();
       ui->label_searchScientistsNoResults->setText("<p style=\"color:#f44242;\">Your search returned no results.</p>");
   }
}

void ListWindow::displayAllScientist()
{
    ui->input_listScientistSearch->setText("");
    ui->table_scientists->clearContents();
    _allScientists.clear();
    _scs.scientistsAscendingOrder(0);
    _allScientists = _scs.getScientists();

    ui->table_scientists->setRowCount(_allScientists.size());

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
        QString l = QString::fromStdString(s.getLink());
        QString link = "<a href =\"" + l + "\">Link</a>";

        ui->table_scientists->setItem(row, 0, new Utilities::TableItemSC(s.getId()));
        ui->table_scientists->setItem(row, 1, new Utilities::TableItemSC(name));
        ui->table_scientists->setItem(row, 2, new Utilities::TableItemSC(birthYear));
        ui->table_scientists->setItem(row, 3, new Utilities::TableItemSC(deathYear));
        ui->table_scientists->setItem(row, 4, new Utilities::TableItemSC(gender));
        ui->table_scientists->setItem(row, 5, new Utilities::TableItemSC(link));
    }
}

void ListWindow::displayConnectionsSearchResults(string search)
{
    ui->label_searchConnectionNoResult->setText("");
    ui->table_connections->clearContents();
    _currentlyDisplayedConnections.clear();

    _currentlyDisplayedConnections = _scs.findConnectionByName(search);

    //If not empty, display contents of vector.
    if(_currentlyDisplayedConnections.size() !=0)
    {
        ui->table_connections->setRowCount(_currentlyDisplayedConnections.size());

        for(unsigned int row = 0; row < _currentlyDisplayedConnections.size(); row++)
        {
            Invented in =_currentlyDisplayedConnections.at(row);
            QString sId = QString::number(in.getSId());
            QString sName = QString::fromStdString(in.getSName());
            QString cId = QString::number(in.getCId());
            QString cName = QString::fromStdString((in.getCName()));

            ui->table_connections->setItem(row, 0, new Utilities::TableItemConnect(sId));
            ui->table_connections->setItem(row, 1, new Utilities::TableItemConnect(sName));
            ui->table_connections->setItem(row, 2, new Utilities::TableItemConnect(cId));
            ui->table_connections->setItem(row, 3, new Utilities::TableItemConnect(cName));
        }
    }
    if(search.size() != 0 && _currentlyDisplayedConnections.size() == 0)
    {
        ui->table_connections->clearContents();
        ui->label_searchConnectionNoResult->setText("<p style=\"color:#f44242;\">Your search returned no results.</p>");
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
            QString l = QString::fromStdString(c.getLink());
            QString link = "<a href =\"" + l + "\">Link</a>";

            ui->table_Computers->setItem(row, 0, new Utilities::TableItemSC(id));
            ui->table_Computers->setItem(row, 1, new Utilities::TableItemSC(name));
            ui->table_Computers->setItem(row, 2, new Utilities::TableItemSC(buildyear));
            ui->table_Computers->setItem(row, 3, new Utilities::TableItemSC(type));
            ui->table_Computers->setItem(row, 4, new Utilities::TableItemSC(wasbuilt));
            ui->table_Computers->setItem(row, 5, new Utilities::TableItemSC(link));
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
        QString l = QString::fromStdString(c.getLink());
        QString link = "<a href =\"" + l + "\">Link</a>";

        ui->table_Computers->setItem(row, 0, new Utilities::TableItemSC(id));
        ui->table_Computers->setItem(row, 1, new Utilities::TableItemSC(name));
        ui->table_Computers->setItem(row, 2, new Utilities::TableItemSC(buildyear));
        ui->table_Computers->setItem(row, 3, new Utilities::TableItemSC(type));
        ui->table_Computers->setItem(row, 4, new Utilities::TableItemSC(wasbuilt));
        ui->table_Computers->setItem(row, 5, new Utilities::TableItemSC(link));
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

        ui->table_connections->setItem(row, 0, new Utilities::TableItemConnect(sId));
        ui->table_connections->setItem(row, 1, new Utilities::TableItemConnect(sName));
        ui->table_connections->setItem(row, 2, new Utilities::TableItemConnect(cId));
        ui->table_connections->setItem(row, 3, new Utilities::TableItemConnect(cName));
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

void ListWindow::on_input_listComputerSearch_textChanged(const QString &arg1)
{
    string search = arg1.toStdString();
    displayComputerSearchResults(search);
}

void ListWindow::on_input_searchConnections_textChanged(const QString &arg1)
{
    string search = arg1.toStdString();
    displayConnectionsSearchResults(search);
}
