#include "DeleteWindow.h"
#include "ui_DeleteWindow.h"

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
