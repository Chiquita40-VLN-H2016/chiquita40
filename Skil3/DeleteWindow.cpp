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

void DeleteWindow::on_input_deletePageSearchScientist_textChanged(const QString &arg1)
{
    string search = ui->input_deletePageSearchScientist->text().toStdString();
    displayAllScientists(search);
}

void DeleteWindow::on_input_deletePageSearchComputer_textChanged(const QString &arg1)
{
    string search = ui->input_deletePageSearchComputer->text().toStdString();
    displayAllComputers(search);
}

void DeleteWindow::on_input_deletePageSearchConnect_textChanged(const QString &arg1)
{
    string search = ui->input_deletePageSearchConnect->text().toStdString();
    displayAllConnections(search);
}

void DeleteWindow::on_button_deleteBack_clicked()
{
    close();
}

void DeleteWindow::on_lineEdit_deleteScientistID_textChanged(const QString &arg1)
{
    ui->button_deleteScientist->setEnabled(true);
}

void DeleteWindow::on_lineEdit_deleteComputerID_textChanged(const QString &arg1)
{
    ui->button_deleteComputer->setEnabled(true);
}

void DeleteWindow::on_lineEdit_deleteConnectionScientistID_textChanged(const QString &arg1)
{
    if(!ui->lineEdit_deleteConnectionComputerID->text().isEmpty())
    {
        ui->button_deleteConnection->setEnabled(true);
    }
}

void DeleteWindow::on_lineEdit_deleteConnectionComputerID_textChanged(const QString &arg1)
{
    if(!ui->lineEdit_deleteConnectionScientistID->text().isEmpty())
    {
        ui->button_deleteConnection->setEnabled(true);
    }
}

int DeleteWindow::deleteWarningMessage()
{
    QMessageBox deleteMessage;
    deleteMessage.setText("You are about to delete.");
    deleteMessage.setInformativeText("Do you really want to delete?");
    deleteMessage.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    deleteMessage.setDefaultButton(QMessageBox::Yes);
    int ret = deleteMessage.exec();

    return ret;
}

void DeleteWindow::displayAllScientists(string search)
{
    ui->tableWidget_deletePageSearchResultScientist->clearContents();
    _currentlyDisplayedScientists.clear();

    _currentlyDisplayedScientists = _scs.findScientistByName(search);

    /*QStringList scientistHeader;
    ui->tableWidget_deletePageSearchResultScientist->setColumnCount(5);
    scientistHeader << "ID" << "Scientist Name" << "Birth Year" << "Death Year" << "Gender";
    ui->tableWidget_deletePageSearchResultScientist->setHorizontalHeaderLabels(scientistHeader);*/
    ui->tableWidget_deletePageSearchResultScientist->setRowCount(_currentlyDisplayedScientists.size());

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

        ui->tableWidget_deletePageSearchResultScientist->setItem(row, 0, new QTableWidgetItem(id));
        ui->tableWidget_deletePageSearchResultScientist->setItem(row, 1, new QTableWidgetItem(name));
        ui->tableWidget_deletePageSearchResultScientist->setItem(row, 2, new QTableWidgetItem(birthDate));
        ui->tableWidget_deletePageSearchResultScientist->setItem(row, 3, new QTableWidgetItem(deathYear));
        ui->tableWidget_deletePageSearchResultScientist->setItem(row, 4, new QTableWidgetItem(gender));
    }
}

void DeleteWindow::displayAllComputers(string search)
{
    ui->tableWidget_deletePageSearchResultComputer->clearContents();
    _currentlyDisplayedComputers.clear();

    _currentlyDisplayedComputers = _scs.findComputerByName(search);

    /*QStringList computerHeader;
    ui->tableWidget_deletePageSearchResultScientist->setColumnCount(5);
    computerHeader << "ID" << "Computer Name" << "Build Year" << "Type" << "Was Built?";
    ui->tableWidget_deletePageSearchResultComputer->setHorizontalHeaderLabels(computerHeader);*/
    ui->tableWidget_deletePageSearchResultComputer->setRowCount(_currentlyDisplayedComputers.size());

    for(unsigned int row = 0; row < _currentlyDisplayedComputers.size(); row++)
    {
        Computer c = _currentlyDisplayedComputers.at(row);

        QString id = QString::number(c.getId());
        QString name = QString::fromStdString(c.getName());
        QString buildYear = QString::number(c.getBuildYear());
        QString type = QString::fromStdString(c.getType());
        QString wasBuilt = QString::number(c.getWasBuilt());

        ui->tableWidget_deletePageSearchResultComputer->setItem(row, 0, new QTableWidgetItem(id));
        ui->tableWidget_deletePageSearchResultComputer->setItem(row, 1, new QTableWidgetItem(name));
        ui->tableWidget_deletePageSearchResultComputer->setItem(row, 2, new QTableWidgetItem(buildYear));
        ui->tableWidget_deletePageSearchResultComputer->setItem(row, 3, new QTableWidgetItem(type));
        ui->tableWidget_deletePageSearchResultComputer->setItem(row, 4, new QTableWidgetItem(wasBuilt));
    }
}

void DeleteWindow::displayAllConnections(string search)
{
    ui->tableWidget_deletePageSearchResultConnect->clearContents();
    _currentlyDisplayedConnections.clear();

    _currentlyDisplayedConnections = _scs.findConnectionByName(search);

    /*QStringList connectionHeader;
    ui->tableWidget_deletePageSearchResultConnect->setColumnCount(4);
    connectionHeader << "ID" << "Scientist Name" << "ID" << "Computer Name";
    ui->tableWidget_deletePageSearchResultConnect->setHorizontalHeaderLabels(connectionHeader);*/
    ui->tableWidget_deletePageSearchResultConnect->setRowCount(_currentlyDisplayedConnections.size());

    for(unsigned int row = 0; row < _currentlyDisplayedConnections.size(); row++)
    {
        Invented in = _currentlyDisplayedConnections.at(row);

        QString sId = QString::number(in.getSId());
        QString sName = QString::fromStdString(in.getSName());
        QString cId = QString::number(in.getCId());
        QString cName = QString::fromStdString(in.getCName());

        ui->tableWidget_deletePageSearchResultConnect->setItem(row, 0, new QTableWidgetItem(sId));
        ui->tableWidget_deletePageSearchResultConnect->setItem(row, 1, new QTableWidgetItem(sName));
        ui->tableWidget_deletePageSearchResultConnect->setItem(row, 2, new QTableWidgetItem(cId));
        ui->tableWidget_deletePageSearchResultConnect->setItem(row, 3, new QTableWidgetItem(cName));
    }
}

void DeleteWindow::displayScientistsAfterDelete()
{
    ui->tableWidget_deletePageSearchResultScientist->clearContents();
    _currentlyDisplayedScientists.clear();

    _scs.scientistsAscendingOrder(0);
    _currentlyDisplayedScientists = _scs.getScientists();

    /*QStringList scientistHeader;
    ui->tableWidget_deletePageSearchResultScientist->setColumnCount(5);
    scientistHeader << "ID" << "Scientist Name" << "Birth Year" << "Death Year" << "Gender";
    ui->tableWidget_deletePageSearchResultScientist->setHorizontalHeaderLabels(scientistHeader);*/
    ui->tableWidget_deletePageSearchResultScientist->setRowCount(_currentlyDisplayedScientists.size());

    for(unsigned int row = 0; row < _currentlyDisplayedScientists.size(); row++)
    {
        Scientist s = _currentlyDisplayedScientists.at(row);

        QString id = QString::number(s.getId());
        QString name = QString::fromStdString(s.getName());
        QString birthDate = QString::number(s.getBirthDate());
        QString deathDate = QString::number(s.getDeathDate());
        QString gender = QChar(toupper(s.getGender()));

        ui->tableWidget_deletePageSearchResultScientist->setItem(row, 0, new QTableWidgetItem(id));
        ui->tableWidget_deletePageSearchResultScientist->setItem(row, 1, new QTableWidgetItem(name));
        ui->tableWidget_deletePageSearchResultScientist->setItem(row, 2, new QTableWidgetItem(birthDate));
        ui->tableWidget_deletePageSearchResultScientist->setItem(row, 3, new QTableWidgetItem(deathDate));
        ui->tableWidget_deletePageSearchResultScientist->setItem(row, 4, new QTableWidgetItem(gender));
    }
}

void DeleteWindow::displayComputersAfterDelete()
{
    ui->tableWidget_deletePageSearchResultComputer->clearContents();
    _currentlyDisplayedComputers.clear();

    _scs.computersAscendingOrder(0);
    _currentlyDisplayedComputers = _scs.getComputers();

    /*QStringList computerHeader;
    ui->tableWidget_deletePageSearchResultScientist->setColumnCount(5);
    computerHeader << "ID" << "Computer Name" << "Build Year" << "Type" << "Was Built?";
    ui->tableWidget_deletePageSearchResultComputer->setHorizontalHeaderLabels(computerHeader);*/
    ui->tableWidget_deletePageSearchResultComputer->setRowCount(_currentlyDisplayedComputers.size());

    for(unsigned int row = 0; row < _currentlyDisplayedComputers.size(); row++)
    {
        Computer c = _currentlyDisplayedComputers.at(row);

        QString id = QString::number(c.getId());
        QString name = QString::fromStdString(c.getName());
        QString buildYear = QString::number(c.getBuildYear());
        QString type = QString::fromStdString(c.getType());
        QString wasBuilt = QString::number(c.getWasBuilt());

        ui->tableWidget_deletePageSearchResultComputer->setItem(row, 0, new QTableWidgetItem(id));
        ui->tableWidget_deletePageSearchResultComputer->setItem(row, 1, new QTableWidgetItem(name));
        ui->tableWidget_deletePageSearchResultComputer->setItem(row, 2, new QTableWidgetItem(buildYear));
        ui->tableWidget_deletePageSearchResultComputer->setItem(row, 3, new QTableWidgetItem(type));
        ui->tableWidget_deletePageSearchResultComputer->setItem(row, 4, new QTableWidgetItem(wasBuilt));
    }
}

void DeleteWindow::displayConnectionAfterDelete()
{
    ui->tableWidget_deletePageSearchResultConnect->clearContents();
    _currentlyDisplayedConnections.clear();

    //_scs.getListOfComputersAndScientistsAsc(0);
    _currentlyDisplayedConnections = _scs.inventedAscendingOrder(0);

    /*QStringList connectionHeader;
    ui->tableWidget_deletePageSearchResultConnect->setColumnCount(4);
    connectionHeader << "ID" << "Scientist Name" << "ID" << "Computer Name";
    ui->tableWidget_deletePageSearchResultConnect->setHorizontalHeaderLabels(connectionHeader);*/
    ui->tableWidget_deletePageSearchResultConnect->setRowCount(_currentlyDisplayedConnections.size());

    for(unsigned int row = 0; row < _currentlyDisplayedConnections.size(); row++)
    {
        Invented in = _currentlyDisplayedConnections.at(row);

        QString sId = QString::number(in.getSId());
        QString sName = QString::fromStdString(in.getSName());
        QString cId = QString::number(in.getCId());
        QString cName = QString::fromStdString(in.getCName());

        ui->tableWidget_deletePageSearchResultConnect->setItem(row, 0, new QTableWidgetItem(sId));
        ui->tableWidget_deletePageSearchResultConnect->setItem(row, 1, new QTableWidgetItem(sName));
        ui->tableWidget_deletePageSearchResultConnect->setItem(row, 2, new QTableWidgetItem(cId));
        ui->tableWidget_deletePageSearchResultConnect->setItem(row, 3, new QTableWidgetItem(cName));
    }
}

void DeleteWindow::on_button_deleteScientist_clicked()
{
    int success = -1;
    int ret = deleteWarningMessage();

    int id = ui->lineEdit_deleteScientistID->text().toInt();

    if(ret == 16384)
    {
        success = _scs.deleteScientist(id);
    }

    if(success != -1)
    {
        displayScientistsAfterDelete();
    }
    ui->button_deleteScientist->setEnabled(false);
    ui->input_deletePageSearchScientist->clear();
    ui->lineEdit_deleteScientistID->clear();
}

void DeleteWindow::on_button_deleteComputer_clicked()
{
    int success = -1;
    int ret = deleteWarningMessage();

    int id = ui->lineEdit_deleteComputerID->text().toInt();

    if(ret == 16384)
    {
        success = _scs.deleteComputer(id);
    }

    if(success != -1)
    {
        displayComputersAfterDelete();
    }
    ui->button_deleteComputer->setEnabled(false);
    ui->input_deletePageSearchComputer->clear();
    ui->lineEdit_deleteComputerID->clear();
}

void DeleteWindow::on_button_deleteConnection_clicked()
{
    bool success = false;
    int ret = deleteWarningMessage();

    int sId = ui->lineEdit_deleteConnectionScientistID->text().toInt();
    int cId = ui->lineEdit_deleteConnectionComputerID->text().toInt();

    if(ret == 16384)
    {
        success = _scs.deleteConnection(sId, cId);
    }

    if(success == true)
    {
        displayConnectionAfterDelete();
    }
    ui->button_deleteComputer->setEnabled(false);
    ui->input_deletePageSearchConnect->clear();
    ui->lineEdit_deleteConnectionScientistID->clear();
    ui->lineEdit_deleteConnectionComputerID->clear();
}

/*string DeleteWindow::scientistListHeader()
{
    string s = "Id\t|Name\t\t|Year Born\t|Year of Death\t|Gender\n";
    s+= "--------------------------------------------------------------------------------------------";
    return s;
}

string DeleteWindow::computerListHeader()
{
    string c = "Id\t|Name\t\t|Year Built\t|Type\t\t|Was Built\n";
    c+= "------------------------------------------------------------------------------------------------------------";
    return c;
}

string DeleteWindow::connectListHeader()
{
    string in = "Id\t|Scientist Name\t\t|Id\t|Computer Name\n";
    in+= "------------------------------------------------------------------------------------------------------------";
    return in;
}*/

/*void DeleteWindow::on_list_deletePageSearchResult_clicked(const QModelIndex &index)
{
    ui->button_deleteScientist->setEnabled(true);
}

void DeleteWindow::on_button_deleteScientist_clicked()
{
    QMessageBox deleteMEssage;
    deleteMEssage.setText("You are about to delete.");
    deleteMEssage.setInformativeText("Do you really want to delete?");
    deleteMEssage.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    deleteMEssage.setDefaultButton(QMessageBox::Yes);
    int ret = deleteMEssage.exec();

    int currentlySelectedScientistID = ui->list_deletePageSearchResult->currentIndex().row();
    Scientist currentlySelectedScientist = _currentlyDisplayedScientists.at(currentlySelectedScientistID -1);
    int success = _scs.deleteScientist(currentlySelectedScientist.getId());

    if(success != -1)
    {
        ui->list_deletePageSearchResult->clear();
        //_currentlyDisplayedScientists.clear();
        ui->list_deletePageSearchResult->addItem(QString::fromStdString("Scientists that have been deleted:"));

        for(unsigned int i = 0; i < _currentlyDisplayedScientists.size(); i++)
        {
            Scientist s = _currentlyDisplayedScientists.at(i);
            ui->list_deletePageSearchResult->addItem(QString::fromStdString(s.toString()));
        }
        ui->button_deleteScientist->setEnabled(false);
    }
}*/

