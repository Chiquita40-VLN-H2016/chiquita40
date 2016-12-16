#include "ConnectWindow.h"
#include "ui_ConnectWindow.h"

ConnectWindow::ConnectWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectWindow)
{
    ui->setupUi(this);

    displayAllCurrentConnections();
}

ConnectWindow::~ConnectWindow()
{
    delete ui;
}

void ConnectWindow::on_button_connectBack_clicked()
{
    close();
}

void ConnectWindow::on_button_connectQuit_clicked()
{
    close();
    qApp->quit();
}

string ConnectWindow::scientistListHeader()
{
    string s = "Id\t|Name\t\t|Year Born\t|Year of Death\t|Gender\n";
    s+= "--------------------------------------------------------------------------------------------";
    return s;
}

string ConnectWindow::computerListHeader()
{
    string c = "Id\t|Name\t\t|Year Built\t|Type\t\t|Was Built\n";
    c+= "------------------------------------------------------------------------------------------------------------";
    return c;
}

string ConnectWindow::connectListHeader()
{
    string in = "Id\t|Scientist Name\t|Id\t|Computer Name\n";
    in+= "------------------------------------------------------------------------------------------------------------";
    return in;
}

void ConnectWindow::on_input_connectScientistSearch_textChanged(const QString &arg1)
{
    displayScientistSearchResult(arg1);
}

void ConnectWindow::displayScientistSearchResult(const QString &arg1)
{
    ui->table_connectScientistSearchResult->clearContents();
    ui->label_searchNoResultsScientist->clear();
    _currentlyDisplayedScientists.clear();

    string search = arg1.toStdString();

    _currentlyDisplayedScientists = _scs.findScientistByName(search);

    if(_currentlyDisplayedScientists.size() != 0)
    {
        ui->table_connectScientistSearchResult->setRowCount(_currentlyDisplayedScientists.size());

        for(unsigned int row = 0; row < _currentlyDisplayedScientists.size(); row++)
        {
            Scientist s = _currentlyDisplayedScientists.at(row);
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

            ui->table_connectScientistSearchResult->setItem(row, 0, new QTableWidgetItem(id));
            ui->table_connectScientistSearchResult->setItem(row, 1, new QTableWidgetItem(name));
            ui->table_connectScientistSearchResult->setItem(row, 2, new QTableWidgetItem(birthYear));
            ui->table_connectScientistSearchResult->setItem(row, 3, new QTableWidgetItem(deathYear));
            ui->table_connectScientistSearchResult->setItem(row, 4, new QTableWidgetItem(gender));

        }

        ui->table_connectScientistSearchResult->resizeColumnsToContents();

    }

    if(search.size() != 0 && _currentlyDisplayedScientists.size() == 0)
    {
        ui->table_connectScientistSearchResult->clearContents();
        ui->label_searchNoResultsScientist->setText("<p style=\"color:#f44242;\">Your search returned no results.</p>");
    }
}

void ConnectWindow::on_input_connectComputerSearch_textChanged(const QString &arg1)
{
    displayComputerSearchResult(arg1);
}

void ConnectWindow::displayComputerSearchResult(const QString &arg1)
{
    ui->table_connectComputerSearchResult->clearContents();
    ui->label_searchNoResultsComputer->clear();
    _currentlyDisplayedComputers.clear();

    string search = arg1.toStdString();

    _currentlyDisplayedComputers = _scs.findComputerByName(search);

    if(_currentlyDisplayedComputers.size() != 0)
    {
        ui->table_connectComputerSearchResult->setRowCount(_currentlyDisplayedComputers.size());

        for(unsigned int row = 0; row < _currentlyDisplayedComputers.size(); row++)
        {
            Computer c = _currentlyDisplayedComputers.at(row);
            QString id = QString::number(c.getId());
            QString name = QString::fromStdString(c.getName());
            QString type = QString::fromStdString(c.getType());
            QString builtYear;
            QString wasBuilt;

            if(c.getWasBuilt() == 1)
            {
                wasBuilt = QString::fromStdString("Yes");
                builtYear = QString::number(c.getBuildYear());
            }
            else
            {
                wasBuilt = QString::fromStdString("No");
            }

            ui->table_connectComputerSearchResult->setItem(row, 0, new QTableWidgetItem(id));
            ui->table_connectComputerSearchResult->setItem(row, 1, new QTableWidgetItem(name));
            ui->table_connectComputerSearchResult->setItem(row, 2, new QTableWidgetItem(type));
            ui->table_connectComputerSearchResult->setItem(row, 3, new QTableWidgetItem(builtYear));
            ui->table_connectComputerSearchResult->setItem(row, 4, new QTableWidgetItem(wasBuilt));

        }

        ui->table_connectComputerSearchResult->resizeColumnsToContents();

    }
    if(search.size() != 0 && _currentlyDisplayedComputers.size() == 0)
    {
        ui->table_connectComputerSearchResult->clearContents();
        ui->label_searchNoResultsComputer->setText("<p style=\"color:#f44242;\">Your search returned no results.</p>");
    }
}

void ConnectWindow::displayAllCurrentConnections()
{
    ui->table_connectCurrent->clearContents();
    _currentlyDisplayedConnections.clear();

    _currentlyDisplayedConnections = _scs.inventedAscendingOrder(0);

    ui->table_connectCurrent->setRowCount(_currentlyDisplayedConnections.size());

    for(unsigned int row = 0; row < _currentlyDisplayedConnections.size(); row++)
    {
        Invented i = _currentlyDisplayedConnections.at(row);
        QString sId = QString::number(i.getSId());
        QString sName = QString::fromStdString(i.getSName());
        QString cId = QString::number(i.getCId());
        QString cName = QString::fromStdString(i.getCName());

        ui->table_connectCurrent->setItem(row, 0, new QTableWidgetItem(sId));
        ui->table_connectCurrent->setItem(row, 1, new QTableWidgetItem(sName));
        ui->table_connectCurrent->setItem(row, 2, new QTableWidgetItem(cId));
        ui->table_connectCurrent->setItem(row, 3, new QTableWidgetItem(cName));
    }

    ui->table_connectCurrent->resizeColumnsToContents();
}


void ConnectWindow::on_button_connectScientistAndComputer_clicked()
{
    ui->label_connectErrorMessage->clear();

    int sId = ui->input_connectScientistID->text().toInt();
    int cId = ui->input_connectComputerID->text().toInt();

    Scientist s = _scs.scientistToEdit(sId);
    Computer c = _scs.computerToEdit(cId);

    if(s.getId() != -1 && c.getId() == -1)
    {
        ui->label_connectErrorMessage->setText("<p style=\"color:#f44242;\">Computer ID is not valid</p>");
    }
    else if(s.getId() == -1 && c.getId() != -1)
    {
        ui->label_connectErrorMessage->setText("<p style=\"color:#f44242;\">Scientist ID is not valid</p>");
    }
    else if(s.getId() == -1 && c.getId() == -1)
    {
        ui->label_connectErrorMessage->setText("<p style=\"color:#f44242;\">ID's are not valid</p>");
    }
    else if(s.getId() != -1 && c.getId() != -1)
    {
        bool notConnected = true;

        vector<Computer> computersConnected = _scs.findComputerByScientist(s.getId());

        for(unsigned int i = 0; i < computersConnected.size(); i++)
        {
            if(c.getId() == computersConnected.at(i).getId())
            {
                notConnected = false;
                ui->label_connectErrorMessage->setText("<p style=\"color:#f44242;\">Connection already exists</p>");
                break;
            }
        }

        if(notConnected)
        {
            _scs.joinSC(sId, cId);
            ui->input_connectComputerID->clear();
            ui->input_connectScientistID->clear();
            ui->table_connectCurrent->clearContents();

            displayAllCurrentConnections();

        }

    }
}

void ConnectWindow::on_table_connectScientistSearchResult_itemDoubleClicked(QTableWidgetItem *item)
{
    int rowID = item->row();
    QString scientistID = ui->table_connectScientistSearchResult->item(rowID, 0)->text();

    ui->input_connectScientistID->setText(scientistID);
}

void ConnectWindow::on_table_connectComputerSearchResult_itemDoubleClicked(QTableWidgetItem *item)
{
    int rowID = item->row();
    QString computerID = ui->table_connectComputerSearchResult->item(rowID, 0)->text();

    ui->input_connectComputerID->setText(computerID);
}
