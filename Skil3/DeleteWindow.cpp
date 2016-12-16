#include "DeleteWindow.h"
#include "ui_DeleteWindow.h"
#include <QMessageBox>

DeleteWindow::DeleteWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteWindow)
{
    ui->setupUi(this);
}

DeleteWindow::~DeleteWindow()
{
    delete ui;
}

void DeleteWindow::on_button_deleteQuit_clicked()
{
    close();
    qApp->quit();
}

void DeleteWindow::on_input_deleteScientistSearch_textChanged()
{
    string search = ui->input_deleteScientistSearch->text().toStdString();
    displayAllScientists(search);
}

void DeleteWindow::on_input_deleteComputerSearch_textChanged()
{
    string search = ui->input_deleteComputerSearch->text().toStdString();
    displayAllComputers(search);
}

void DeleteWindow::on_input_deleteConnectSearch_textChanged()
{
    string search = ui->input_deleteConnectSearch->text().toStdString();
    displayAllConnections(search);
}

void DeleteWindow::on_button_deleteBack_clicked()
{
    close();
}

void DeleteWindow::on_lineEdit_deleteScientistID_textChanged()
{
    ui->button_deleteScientist->setEnabled(true);
}

void DeleteWindow::on_lineEdit_deleteComputerID_textChanged()
{
    ui->button_deleteComputer->setEnabled(true);
}

void DeleteWindow::on_lineEdit_deleteConnectionScientistID_textChanged()
{
    if(!ui->lineEdit_deleteConnectionComputerID->text().isEmpty())
    {
        ui->button_deleteConnection->setEnabled(true);
    }
}

void DeleteWindow::on_lineEdit_deleteConnectionComputerID_textChanged()
{
    if(!ui->lineEdit_deleteConnectionScientistID->text().isEmpty())
    {
        ui->button_deleteConnection->setEnabled(true);
    }
}

int DeleteWindow::deleteWarningMessage()
{
    QMessageBox deleteMessage;
    deleteMessage.setWindowTitle("Warning");
    deleteMessage.setText("You are about to delete.");
    deleteMessage.setInformativeText("Do you really want to delete?");
    deleteMessage.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    deleteMessage.setDefaultButton(QMessageBox::Yes);
    int ret = deleteMessage.exec();

    return ret;
}

void DeleteWindow::displayAllScientists(string search)
{
    ui->table_Scientists->clearContents();
    _currentlyDisplayedScientists.clear();
    _currentlyDisplayedScientists = _scs.getScientists();
    _currentlyDisplayedScientists = _scs.findScientistByName(search);

    ui->table_Scientists->setRowCount(_currentlyDisplayedScientists.size());

    for(unsigned int row = 0; row < _currentlyDisplayedScientists.size(); row++)
    {
        Scientist s = _currentlyDisplayedScientists.at(row);

        QString id = QString::number(s.getId());
        QString name = QString::fromStdString(s.getName());
        QString birthDate = QString::number(s.getBirthDate());
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
        ui->table_Scientists->setItem(row, 2, new QTableWidgetItem(birthDate));
        ui->table_Scientists->setItem(row, 3, new QTableWidgetItem(deathYear));
        ui->table_Scientists->setItem(row, 4, new QTableWidgetItem(gender));
    }
}

void DeleteWindow::displayAllComputers(string search)
{
    ui->table_Computers->clearContents();
    _currentlyDisplayedComputers.clear();

    _currentlyDisplayedComputers = _scs.findComputerByName(search);

    ui->table_Computers->setRowCount(_currentlyDisplayedComputers.size());

    for(unsigned int row = 0; row < _currentlyDisplayedComputers.size(); row++)
    {
        Computer c = _currentlyDisplayedComputers.at(row);

        QString id = QString::number(c.getId());
        QString name = QString::fromStdString(c.getName());
        QString buildYear;
        if(c.getBuildYear() == 0)
        {
            buildYear = "";
        }
        else
        {
            buildYear = QString::number(c.getBuildYear());
        }
        QString type = QString::fromStdString(c.getType());
        QString wasBuilt;
        if(c.getWasBuilt() == 1)
        {
            wasBuilt = "Yes";
        }
        else
        {
            wasBuilt = "No";
        }

        ui->table_Computers->setItem(row, 0, new QTableWidgetItem(id));
        ui->table_Computers->setItem(row, 1, new QTableWidgetItem(name));
        ui->table_Computers->setItem(row, 2, new QTableWidgetItem(buildYear));
        ui->table_Computers->setItem(row, 3, new QTableWidgetItem(type));
        ui->table_Computers->setItem(row, 4, new QTableWidgetItem(wasBuilt));
    }
    ui->table_Computers->resizeColumnToContents(1);
}

void DeleteWindow::displayAllConnections(string search)
{
    ui->table_Connections->clearContents();
    _currentlyDisplayedConnections.clear();

    _currentlyDisplayedConnections = _scs.findConnectionByName(search);

    ui->table_Connections->setRowCount(_currentlyDisplayedConnections.size());

    for(unsigned int row = 0; row < _currentlyDisplayedConnections.size(); row++)
    {
        Invented in = _currentlyDisplayedConnections.at(row);

        QString sId = QString::number(in.getSId());
        QString sName = QString::fromStdString(in.getSName());
        QString cId = QString::number(in.getCId());
        QString cName = QString::fromStdString(in.getCName());

        ui->table_Connections->setItem(row, 0, new QTableWidgetItem(sId));
        ui->table_Connections->setItem(row, 1, new QTableWidgetItem(sName));
        ui->table_Connections->setItem(row, 2, new QTableWidgetItem(cId));
        ui->table_Connections->setItem(row, 3, new QTableWidgetItem(cName));
    }
}

void DeleteWindow::displayScientistsAfterDelete()
{
    ui->table_Scientists->clearContents();
    _currentlyDisplayedScientists.clear();

    _scs.scientistsAscendingOrder(0);
    _currentlyDisplayedScientists = _scs.getScientists();

    ui->table_Scientists->setRowCount(_currentlyDisplayedScientists.size());

    for(unsigned int row = 0; row < _currentlyDisplayedScientists.size(); row++)
    {
        Scientist s = _currentlyDisplayedScientists.at(row);

        QString id = QString::number(s.getId());
        QString name = QString::fromStdString(s.getName());
        QString birthDate = QString::number(s.getBirthDate());
        QString deathDate = QString::number(s.getDeathDate());
        QString gender = QChar(toupper(s.getGender()));

        ui->table_Scientists->setItem(row, 0, new QTableWidgetItem(id));
        ui->table_Scientists->setItem(row, 1, new QTableWidgetItem(name));
        ui->table_Scientists->setItem(row, 2, new QTableWidgetItem(birthDate));
        ui->table_Scientists->setItem(row, 3, new QTableWidgetItem(deathDate));
        ui->table_Scientists->setItem(row, 4, new QTableWidgetItem(gender));
    }
}

void DeleteWindow::displayComputersAfterDelete()
{
    ui->table_Computers->clearContents();
    _currentlyDisplayedComputers.clear();

    _scs.computersAscendingOrder(0);
    _currentlyDisplayedComputers = _scs.getComputers();

    ui->table_Computers->setRowCount(_currentlyDisplayedComputers.size());

    for(unsigned int row = 0; row < _currentlyDisplayedComputers.size(); row++)
    {
        Computer c = _currentlyDisplayedComputers.at(row);

        QString id = QString::number(c.getId());
        QString name = QString::fromStdString(c.getName());
        QString buildYear = QString::number(c.getBuildYear());
        QString type = QString::fromStdString(c.getType());
        QString wasBuilt = QString::number(c.getWasBuilt());

        ui->table_Computers->setItem(row, 0, new QTableWidgetItem(id));
        ui->table_Computers->setItem(row, 1, new QTableWidgetItem(name));
        ui->table_Computers->setItem(row, 2, new QTableWidgetItem(buildYear));
        ui->table_Computers->setItem(row, 3, new QTableWidgetItem(type));
        ui->table_Computers->setItem(row, 4, new QTableWidgetItem(wasBuilt));
    }
}

void DeleteWindow::displayConnectionAfterDelete()
{
    ui->table_Connections->clearContents();
    _currentlyDisplayedConnections.clear();

    _currentlyDisplayedConnections = _scs.inventedAscendingOrder(0);

    ui->table_Connections->setRowCount(_currentlyDisplayedConnections.size());

    for(unsigned int row = 0; row < _currentlyDisplayedConnections.size(); row++)
    {
        Invented in = _currentlyDisplayedConnections.at(row);

        QString sId = QString::number(in.getSId());
        QString sName = QString::fromStdString(in.getSName());
        QString cId = QString::number(in.getCId());
        QString cName = QString::fromStdString(in.getCName());

        ui->table_Connections->setItem(row, 0, new QTableWidgetItem(sId));
        ui->table_Connections->setItem(row, 1, new QTableWidgetItem(sName));
        ui->table_Connections->setItem(row, 2, new QTableWidgetItem(cId));
        ui->table_Connections->setItem(row, 3, new QTableWidgetItem(cName));
    }
}

void DeleteWindow::on_button_deleteScientist_clicked()
{
    ui->label_warningScId1->clear();

    int success = -1;
    int ret = 0;

    int id = ui->lineEdit_deleteScientistID->text().toInt();

    Scientist s = _scs.scientistToEdit(id);
    if(s.getId() < 0)
    {
        ui->label_warningScId1->setText("<p style=\"color:#f44242;\">Invalid ID</p>");
    }
    else
    {
        ret = deleteWarningMessage();
    }

    if(ret == 16384)
    {
        success = _scs.deleteScientist(id);
    }
    else
    {
        ui->button_deleteScientist->setEnabled(false);
        ui->input_deleteScientistSearch->clear();
        ui->lineEdit_deleteScientistID->clear();
    }

    if(success != -1)
    {
        displayScientistsAfterDelete();

        ui->button_deleteScientist->setEnabled(false);
        ui->input_deleteScientistSearch->clear();
        ui->lineEdit_deleteScientistID->clear();
    }
}

void DeleteWindow::on_button_deleteComputer_clicked()
{
    ui->label_warningCId1->clear();

    int success = -1;
    int ret = 0;

    int id = ui->lineEdit_deleteComputerID->text().toInt();

    Computer c = _scs.computerToEdit(id);
    if(c.getId() < 0)
    {
        ui->label_warningCId1->setText("<p style=\"color:#f44242;\">Invalid ID</p>");
    }
    else
    {
        ret = deleteWarningMessage();
    }

    if(ret == 16384)
    {
        success = _scs.deleteComputer(id);
    }
    else
    {
        ui->button_deleteComputer->setEnabled(false);
        ui->input_deleteComputerSearch->clear();
        ui->lineEdit_deleteComputerID->clear();
    }

    if(success != -1)
    {
        displayComputersAfterDelete();

        ui->button_deleteComputer->setEnabled(false);
        ui->input_deleteComputerSearch->clear();
        ui->lineEdit_deleteComputerID->clear();
    }
}

void DeleteWindow::on_button_deleteConnection_clicked()
{
    ui->label_warningScId2->clear();
    ui->label_warningCId2->clear();

    bool success = false;
    int ret = 0;

    int sId = ui->lineEdit_deleteConnectionScientistID->text().toInt();
    int cId = ui->lineEdit_deleteConnectionComputerID->text().toInt();

    Scientist s = _scs.scientistToEdit(sId);
    Computer c = _scs.computerToEdit(cId);

    if(s.getId() < 0)
    {
        ui->label_warningScId2->setText("<p style=\"color:#f44242;\">Invalid Scientist ID</p>");
    }
    else if(c.getId() < 0)
    {
        ui->label_warningCId2->setText("<p style=\"color:#f44242;\">Invalid Computer ID</p>");
    }
    else
    {
        ret = deleteWarningMessage();
    }

    if(ret == 16384)
    {
        success = _scs.deleteConnection(sId, cId);
    }
    else
    {
        ui->button_deleteComputer->setEnabled(false);
        ui->input_deleteConnectSearch->clear();
        ui->lineEdit_deleteConnectionScientistID->clear();
        ui->lineEdit_deleteConnectionComputerID->clear();
    }

    if(success == true)
    {
        displayConnectionAfterDelete();

        ui->button_deleteComputer->setEnabled(false);
        ui->input_deleteConnectSearch->clear();
        ui->lineEdit_deleteConnectionScientistID->clear();
        ui->lineEdit_deleteConnectionComputerID->clear();
    }
}
