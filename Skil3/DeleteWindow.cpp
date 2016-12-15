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
    qApp->quit();
}

void DeleteWindow::on_button_deletePageSearch_clicked()
{
    string search = ui->input_deletePageSearch->text().toStdString();
    displaySearchResultsFromAll(search);
}

void DeleteWindow::displaySearchResultsFromAll(string search)
{
    ui->list_deletePageSearchResult->clear();
    _currentlyDisplayedComputers.clear();
    _currentlyDisplayedScientists.clear();

    _currentlyDisplayedComputers = _scs.findComputerByName(search);
    _currentlyDisplayedScientists = _scs.findScientistByName(search);

    ui->list_deletePageSearchResult->addItem(QString::fromStdString("Computers that matched search:"));

    for(unsigned int i = 0; i < _currentlyDisplayedComputers.size(); i++)
    {
        Computer c = _currentlyDisplayedComputers.at(i);
        ui->list_deletePageSearchResult->addItem(QString::fromStdString(c.toString()));
    }

    ui->list_deletePageSearchResult->addItem(QString::fromStdString("Scientists that matched search:"));

    for(unsigned int i = 0; i < _currentlyDisplayedScientists.size(); i++)
    {
        Scientist s = _currentlyDisplayedScientists.at(i);
        ui->list_deletePageSearchResult->addItem(QString::fromStdString(s.toString()));
    }
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
    ui->button_deleteConnection->setEnabled(true);
}

void DeleteWindow::on_lineEdit_deleteConnectionComputerID_textChanged(const QString &arg1)
{
    ui->button_deleteConnection->setEnabled(true);
}

int DeleteWindow::deleteWarningMessage()
{
    QMessageBox deleteMessage;
    deleteMessage.setText("You are about to delete.");
    deleteMessage.setInformativeText("Do you really want to delete?");
    deleteMessage.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    deleteMessage.setDefaultButton(QMessageBox::Yes);
    int ret = deleteMessage.exec(); // Diemut gúgla int ret

    return ret;
}

void DeleteWindow::displayDeletePageSearchResultsForScientists()
{
    ui->list_deletePageSearchResult->clear();
    _currentlyDisplayedScientists.clear();

    _scs.scientistsAscendingOrder(0);
    _currentlyDisplayedScientists = _scs.getScientists();

    ui->list_deletePageSearchResult->addItem(QString::fromStdString("Updated list of Scientists:"));

    for(unsigned int i = 0; i < _currentlyDisplayedScientists.size(); i++)
    {
        Scientist s = _currentlyDisplayedScientists.at(i);
        ui->list_deletePageSearchResult->addItem(QString::fromStdString(s.toString()));
    }
}

void DeleteWindow::displayDeletePageSearchResultsForComputers()
{
    ui->list_deletePageSearchResult->clear();
    _currentlyDisplayedComputers.clear();

    _scs.computersAscendingOrder(0);
    _currentlyDisplayedComputers = _scs.getComputers();

    ui->list_deletePageSearchResult->addItem(QString::fromStdString("Updated list of Computers:"));

    for(unsigned int i = 0; i < _currentlyDisplayedComputers.size(); i++)
    {
        Computer c = _currentlyDisplayedComputers.at(i);
        ui->list_deletePageSearchResult->addItem(QString::fromStdString(c.toString()));
    }
}

void DeleteWindow::on_button_deleteScientist_clicked()
{
    int success = -1;
    int ret = deleteWarningMessage();

    int id = ui->lineEdit_deleteScientistID->text().toInt();

    if(ret == 16384) //ATH með töluna
    {
        success = _scs.deleteScientist(id);
    }

    if(success != -1)
    {
        displayDeletePageSearchResultsForScientists();
    }
    ui->button_deleteScientist->setEnabled(false);
}

void DeleteWindow::on_button_deleteComputer_clicked()
{
    int success = -1;
    int ret = deleteWarningMessage();

    int id = ui->lineEdit_deleteComputerID->text().toInt();

    if(ret == 16384) //ATH með töluna
    {
        success = _scs.deleteComputer(id);
    }

    if(success != -1)
    {
        displayDeletePageSearchResultsForComputers();
    }
    ui->button_deleteComputer->setEnabled(false);
}

void DeleteWindow::on_button_deleteConnection_clicked()
{
    int success = -1;
    int ret = deleteWarningMessage();

    int sId = ui->lineEdit_deleteConnectionScientistID->text().toInt();
    int cId = ui->lineEdit_deleteConnectionComputerID->text().toInt();

    if(ret == 16384) //ATH með töluna
    {
        success = _scs.deleteConnection(sId, cId);
    }

    if(success != -1)
    {
        displayDeletePageSearchResultsForConnection();
    }
    ui->button_deleteComputer->setEnabled(false);
}

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

