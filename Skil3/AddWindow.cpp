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
    string search = arg1.toStdString();
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
    string bY = ui->input_addYearBorn->text().toStdString();
    int birthYear = ui->input_addYearBorn->text().toInt();
    bool birthYearIsValid = Utilities::validYearCheck(bY);
    birthYearIsValid = _scs.validYearCheck(birthYear);
    bool deathYearIsValid = false;
    string alive = ui->comboBox_addSAlive->currentText().toStdString();
    int deathYear = 9999;
    if(alive == "Yes")
    {
        deathYearIsValid = true;
    }
    else if (alive == "No")
    {
        string dY = ui->input_addYearOfDeath->text().toStdString();
        deathYear = ui->input_addYearOfDeath->text().toInt();
        deathYearIsValid = Utilities::validYearCheck(dY);
        deathYearIsValid = _scs.validYearCheck(deathYear);
        if(deathYearIsValid && deathYear < birthYear)
        {
            deathYearIsValid = false;
        }
    }
    string gender = ui->comboBox_addSGender->currentText().toStdString();
    char g = tolower(gender.front());
    if(!birthYearIsValid && deathYearIsValid)
    {
        ui->label_addScientistErrorMessage->setText("<p style=\"color:#f44242;\">Invalid Birth Year</p>");
    }
    else if(!deathYearIsValid && birthYearIsValid)
    {
        ui->label_addScientistErrorMessage->setText("<p style=\"color:#f44242;\">Invalid Year of Death</p>");
    }
    else if(!birthYearIsValid && !deathYearIsValid)
    {
        ui->label_addScientistErrorMessage->setText("<p style=\"color:#f44242;\">Invalid Year Format</p>");
    }
    else
    {
        _scs.addScientist(name, birthYear, deathYear, g);
        displayAllScientists();
        clearScientistForm();
    }
}

void AddWindow::on_comboBox_addSAlive_currentIndexChanged(const QString &arg1)
{
    string alive = arg1.toStdString();
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
    string wasBuilt = arg1.toStdString();
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
    bool buildYearIsValid = true;
    int buildYear = 0;
    if (wasBuilt == "Yes")
    {
        buildYear = ui->input_addYearOfCompletion->text().toInt();
        string buY = ui->input_addYearOfCompletion->text().toStdString();
        buildYearIsValid = Utilities::validYearCheck(buY);
        buildYearIsValid = _scs.validYearCheck(buildYear);
    }
    if(buildYearIsValid)
    {
        _scs.addComputer(name, buildYear, type, wasBuilt);
        displayAllComputers();
        clearComputerForm();
    }
    else
    {
        ui->label_addComputerErrorMessage->setText("<p style=\"color:#f44242;\">Invalid Build Year</p>");
    }
}

//Add scientist button enabled if name is not empty.
void AddWindow::on_input_addNameScientist_textChanged(const QString &arg1)
{
    if(arg1.isEmpty())
    {
        ui->button_addScientist->setEnabled(false);
    }
    else
    {
        ui->button_addScientist->setEnabled(true);
    }
}

//Add computer button enabled if name is not empty.
void AddWindow::on_input_addNameComputer_textChanged(const QString &arg1)
{
    if(arg1.isEmpty())
    {
        ui->button_addComputer->setEnabled(false);
    }
    else
    {
        if(!ui->input_addType->text().isEmpty())
        {
            ui->button_addComputer->setEnabled(true);
        }
    }
}

void AddWindow::on_input_addType_textChanged(const QString &arg1)
{
    if(arg1.isEmpty())
    {
        ui->button_addComputer->setEnabled(false);
    }
    else
    {
        if(!ui->input_addNameComputer->text().isEmpty())
        {
            ui->button_addComputer->setEnabled(true);
        }
    }
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
    ui->button_addScientist->setEnabled(false);
    ui->label_addScientistErrorMessage->setText("");
}

void AddWindow::clearComputerForm()
{
    ui->input_addNameComputer->setText("");
    ui->input_addType->setText("");
    ui->comboBox_addCBuilt->setCurrentIndex(0);
    ui->input_addYearOfCompletion->setText("");
    ui->input_addYearOfCompletion->setEnabled(true);
    ui->button_addComputer->setEnabled(false);
    ui->label_addComputerErrorMessage->setText("");
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


