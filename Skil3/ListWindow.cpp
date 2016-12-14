#include "ListWindow.h"
#include "ui_ListWindow.h"

ListWindow::ListWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListWindow)
{
    ui->setupUi(this);
}

ListWindow::~ListWindow()
{
    delete ui;
}

void ListWindow::on_input_listPageSearch_textChanged(const QString &arg1)
{
    string search = ui->input_listPageSearch->text().toStdString();
    displaySearchResultsFromAll(search);
}

void ListWindow::displaySearchResultsFromAll(string search)
{
    ui->list_listPageSearchResult->clear();
    _currentlyDisplayedComputers.clear();
    _currentlyDisplayedScientists.clear();

    _currentlyDisplayedComputers = _scs.findComputerByName(search);
    _currentlyDisplayedScientists = _scs.findScientistByName(search);

    ui->list_listPageSearchResult->addItem(QString::fromStdString("Computers that matched search:"));

    for(unsigned int i = 0; i < _currentlyDisplayedComputers.size(); i++)
    {
        Computer c = _currentlyDisplayedComputers.at(i);
        ui->list_listPageSearchResult->addItem(QString::fromStdString(c.toString()));
    }

    ui->list_listPageSearchResult->addItem(QString::fromStdString("Scientists that matched search:"));

    for(unsigned int i = 0; i < _currentlyDisplayedScientists.size(); i++)
    {
        Scientist s = _currentlyDisplayedScientists.at(i);
        ui->list_listPageSearchResult->addItem(QString::fromStdString(s.toString()));
    }
}

