#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_frontQuit_clicked()
{
    qApp->quit();
}

void MainWindow::on_button_frontPageSearch_clicked()
{
    string search = ui->input_frontPageSearch->text().toStdString();
    displaySearchResultsFromAll(search);
}

void MainWindow::displaySearchResultsFromAll(string search)
{
    ui->list_frontPageSearchResult->clear();
    _currentlyDisplayedComputers.clear();
    _currentlyDisplayedScientists.clear();

    _currentlyDisplayedComputers = _scs.findComputerByName(search);
    _currentlyDisplayedScientists = _scs.findScientistByName(search);

    ui->list_frontPageSearchResult->addItem(QString::fromStdString("Computers that matched search:"));

    for(unsigned int i = 0; i < _currentlyDisplayedComputers.size(); i++)
    {
        Computer c = _currentlyDisplayedComputers.at(i);
        ui->list_frontPageSearchResult->addItem(QString::fromStdString(c.toString()));
    }

    ui->list_frontPageSearchResult->addItem(QString::fromStdString("Scientists that matched search:"));

    for(unsigned int i = 0; i < _currentlyDisplayedScientists.size(); i++)
    {
        Scientist s = _currentlyDisplayedScientists.at(i);
        ui->list_frontPageSearchResult->addItem(QString::fromStdString(s.toString()));
    }
}


void MainWindow::on_button_frontEdit_clicked()
{
    EditWindow editWindow;
    editWindow.exec(); //Tekur/skilar int, hægt að stýra villuskilaboðum eftir því.
}

void MainWindow::on_button_frontDelete_clicked()
{
    DeleteWindow deleteWindow;
    deleteWindow.exec();
}

void MainWindow::on_button_frontSeeFullLists_clicked()
{
    ListWindow listWindow;
    listWindow.exec();
}
