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
    ui->list_connectScientistSearchResult->clear();
    _currentlyDisplayedScientists.clear();

    string search = arg1.toStdString();

    _currentlyDisplayedScientists = _scs.findScientistByName(search);

    if(_currentlyDisplayedScientists.size() != 0)
    {
        ui->list_connectScientistSearchResult->addItem(QString::fromStdString("Scientists that matched search:"));
        ui->list_connectScientistSearchResult->addItem(QString::fromStdString(scientistListHeader()));

        for(unsigned int i = 0; i < _currentlyDisplayedScientists.size(); i++)
        {
            Scientist s = _currentlyDisplayedScientists.at(i);
            ui->list_connectScientistSearchResult->addItem(QString::fromStdString(s.toString()));
        }

        ui->list_connectScientistSearchResult->addItem(" ");

    }
}

void ConnectWindow::on_input_connectComputerSearch_textChanged(const QString &arg1)
{
    displayComputerSearchResult(arg1);
}

void ConnectWindow::displayComputerSearchResult(const QString &arg1)
{
    ui->list_connectComputerSearchResult->clear();
    _currentlyDisplayedComputers.clear();

    string search = arg1.toStdString();

    _currentlyDisplayedComputers = _scs.findComputerByName(search);

    if(_currentlyDisplayedComputers.size() != 0)
    {
        ui->list_connectComputerSearchResult->addItem(QString::fromStdString("Computers that matched search:"));
        ui->list_connectComputerSearchResult->addItem(QString::fromStdString(computerListHeader()));

        for(unsigned int i = 0; i < _currentlyDisplayedComputers.size(); i++)
        {
            Computer c = _currentlyDisplayedComputers.at(i);
            ui->list_connectComputerSearchResult->addItem(QString::fromStdString(c.toString()));
        }

        ui->list_connectComputerSearchResult->addItem(" ");
    }
}

void ConnectWindow::displayAllCurrentConnections()
{
    ui->list_connectCurrent->clear();
    _currentlyDisplayedConnections.clear();

    _currentlyDisplayedConnections = _scs.inventedAscendingOrder(0);

    ui->list_connectCurrent->addItem(QString::fromStdString("Scientists and connected Computers:"));
    ui->list_connectCurrent->addItem(QString::fromStdString(connectListHeader()));

    for(unsigned int i = 0; i < _currentlyDisplayedConnections.size(); i++)
    {
        Invented in = _currentlyDisplayedConnections.at(i);
        ui->list_connectCurrent->addItem(QString::fromStdString(in.toString()));
    }
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
        _scs.joinSC(sId, cId);
        ui->input_connectComputerID->clear();
        ui->input_connectScientistID->clear();
        ui->list_connectCurrent->clear();

        displayAllCurrentConnections();
    }
}
