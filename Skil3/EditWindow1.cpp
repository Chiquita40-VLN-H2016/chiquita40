#include "EditWindow.h"
#include "ui_EditWindow.h"


EditWindow::EditWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditWindow)
{
    ui->setupUi(this);
}

EditWindow::~EditWindow()
{
    delete ui;
}

void EditWindow::on_input_editPageSearch_textChanged(const QString &arg1)
{
    string search = ui->input_editPageSearch->text().toStdString();
    displaySearchResultsFromAll(search);
}

void EditWindow::displaySearchResultsFromAll(string search)
{
    ui->list_editPageSearchResult->clear();
    _currentlyDisplayedComputers.clear();
    _currentlyDisplayedScientists.clear();

    _currentlyDisplayedComputers = _scs.findComputerByName(search);
    _currentlyDisplayedScientists = _scs.findScientistByName(search);

    ui->list_editPageSearchResult->addItem(QString::fromStdString("Computers that matched search:"));

    for(unsigned int i = 0; i < _currentlyDisplayedComputers.size(); i++)
    {
        Computer c = _currentlyDisplayedComputers.at(i);
        ui->list_editPageSearchResult->addItem(QString::fromStdString(c.toString()));
    }

    ui->list_editPageSearchResult->addItem(QString::fromStdString("Scientists that matched search:"));

    for(unsigned int i = 0; i < _currentlyDisplayedScientists.size(); i++)
    {
        Scientist s = _currentlyDisplayedScientists.at(i);
        ui->list_editPageSearchResult->addItem(QString::fromStdString(s.toString()));
    }
}
