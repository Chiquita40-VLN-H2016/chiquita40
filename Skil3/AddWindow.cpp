#include "AddWindow.h"
#include "ui_AddWindow.h"

AddWindow::AddWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddWindow)
{
    ui->setupUi(this);
}

AddWindow::~AddWindow()
{
    delete ui;
}

void AddWindow::on_button_addBack_clicked()
{
    close();
}

void AddWindow::on_button_addQuit_clicked()
{
    close();
    qApp->quit(); //Held að það krassi hér. Þarf að debugga líklega.//Mögulega lagað.
}

//
void AddWindow::on_input_addPageSearch_textChanged(const QString &arg1)
{
    string search = ui->input_addPageSearch->text().toStdString();
    if(search.size() != 0)
    {
        displaySearchResultsFromAll(search);
    }
    if(search.size()== 0)
    {
        ui->list_addPageSearchResult->clear();
    }
}

void AddWindow::on_button_addScientist_clicked()
{
    //TODO: villumeldingar ef eitthvað er tómt.
    string name = ui->input_addNameScientist->text().toStdString();
    int birthYear = ui->input_addYearBorn->text().toInt();
    string alive = ui->comboBox_addSAlive->currentText().toStdString();
    int deathYear = 9999;
    if (alive == "No")
    {
        deathYear = ui->input_addYearOfDeath->text().toInt();
    }
    string gender = ui->comboBox_addSGender->currentText().toStdString();
    char g = tolower(gender.front());
    _scs.addScientist(name, birthYear, deathYear, g);
    displayAllScientists();
    clearScientistForm();
}

void AddWindow::on_comboBox_addSAlive_currentIndexChanged(const QString &arg1)
{
    string alive = ui->comboBox_addSAlive->currentText().toStdString();
    if (alive == "No")
    {
        ui->input_addYearOfDeath->setEnabled(true);
    }
    else
    {
        ui->input_addYearOfDeath->setEnabled(false);
    }
}

void AddWindow::on_comboBox_addCBuilt_currentIndexChanged(const QString &arg1)
{
    string wasBuilt = ui->comboBox_addCBuilt->currentText().toStdString();
    if (wasBuilt == "Yes")
    {
        ui->input_addYearOfCompletion->setEnabled(true);
    }
    else
    {
        ui->input_addYearOfCompletion->setEnabled(false);
    }
}

void AddWindow::on_button_addComputer_clicked()
{
    //villumeldingar ef eitthvað er tómt sem á ekki að vera það.
    string name = ui->input_addNameComputer->text().toStdString();
    string type = ui->input_addType->text().toStdString();
    string wasBuilt = ui->comboBox_addCBuilt->currentText().toStdString();
    int buildYear = 0;
    if (wasBuilt == "Yes")
    {
        buildYear = ui->input_addYearOfCompletion->text().toInt();
    }
    _scs.addComputer(name, buildYear, type, wasBuilt);
    displayAllComputers();
    clearComputerForm();
}

void AddWindow::displaySearchResultsFromAll(string search)
{
     ui->list_addPageSearchResult->clear();
    _currentlyDisplayedComputers.clear();
    _currentlyDisplayedScientists.clear();

    _currentlyDisplayedComputers = _scs.findComputerByName(search);
    _currentlyDisplayedScientists = _scs.findScientistByName(search);
    if(_currentlyDisplayedScientists.size() != 0)
    {
        ui->list_addPageSearchResult->addItem(QString::fromStdString("Scientists that matched search:"));
        ui->list_addPageSearchResult->addItem(QString::fromStdString(scientistListHeader()));

        for(unsigned int i = 0; i < _currentlyDisplayedScientists.size(); i++)
        {
            Scientist s = _currentlyDisplayedScientists.at(i);
            ui->list_addPageSearchResult->addItem(QString::fromStdString(s.toString()));
        }

        ui->list_addPageSearchResult->addItem(" ");
    }

    if(_currentlyDisplayedComputers.size() != 0)
    {
        ui->list_addPageSearchResult->addItem(QString::fromStdString("Computers that matched search:"));
        ui->list_addPageSearchResult->addItem(QString::fromStdString(computerListHeader()));

        for(unsigned int i = 0; i < _currentlyDisplayedComputers.size(); i++)
        {
            Computer c = _currentlyDisplayedComputers.at(i);
            ui->list_addPageSearchResult->addItem(QString::fromStdString(c.toString()));
        }
    }
    if(_currentlyDisplayedComputers.size() == 0 && _currentlyDisplayedScientists.size() == 0)
    {
        ui->list_addPageSearchResult->addItem("Your search returned no results");
    }

}

void AddWindow::displayAllScientists()
{
    ui->input_addPageSearch->setText("");
    ui->list_addPageSearchResult->clear();
    _currentlyDisplayedScientists.clear();
    _scs.scientistsAscendingOrder(0);
    _currentlyDisplayedScientists = _scs.getScientists();

    ui->list_addPageSearchResult->addItem(QString::fromStdString("Updated list of Scientists:"));
    ui->list_addPageSearchResult->addItem(QString::fromStdString(scientistListHeader()));

    for(unsigned int i = 0; i < _currentlyDisplayedScientists.size(); i++)
    {
        Scientist s = _currentlyDisplayedScientists.at(i);
        ui->list_addPageSearchResult->addItem(QString::fromStdString(s.toString()));
    }

}

void AddWindow::displayAllComputers()
{
     ui->input_addPageSearch->setText("");
     ui->list_addPageSearchResult->clear();
    _currentlyDisplayedComputers.clear();
    _scs.computersAscendingOrder(0);
    _currentlyDisplayedComputers = _scs.getComputers();

    ui->list_addPageSearchResult->addItem(QString::fromStdString("Updated list of Computers:"));
    ui->list_addPageSearchResult->addItem(QString::fromStdString(computerListHeader()));

    for(unsigned int i = 0; i < _currentlyDisplayedComputers.size(); i++)
    {
        Computer c = _currentlyDisplayedComputers.at(i);
        ui->list_addPageSearchResult->addItem(QString::fromStdString(c.toString()));
    }
}

void AddWindow::clearScientistForm()
{
    ui->input_addNameScientist->setText("");
    ui->input_addYearBorn->setText("");
    ui->comboBox_addSAlive->setCurrentIndex(0);
    ui->input_addYearOfDeath->setText("");
    ui->comboBox_addSGender->setCurrentIndex(0);
    ui->input_addYearOfDeath->setEnabled(false);
}

void AddWindow::clearComputerForm()
{
    ui->input_addNameComputer->setText("");
    ui->input_addType->setText("");
    ui->comboBox_addCBuilt->setCurrentIndex(0);
    ui->input_addYearOfCompletion->setText("");
    ui->input_addYearOfCompletion->setEnabled(true);
}

string AddWindow::scientistListHeader()
{
    string s = "Id\t|Name\t\t|Year Born\t|Year of Death\t|Gender\n";
    s+= "--------------------------------------------------------------------------------------------";
    return s;
}

string AddWindow::computerListHeader()
{
    string c = "Id\t|Name\t\t|Year Built\t|Type\t\t|Was Built\n";
    c+= "------------------------------------------------------------------------------------------------------------";
    return c;
}

