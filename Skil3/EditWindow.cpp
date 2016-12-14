#include "EditWindow.h"
#include "ui_EditWindow.h"

EditWindow::EditWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditWindow)
{
    ui->setupUi(this);

    ui->input_editNameScientist->hide();
    ui->input_editYearBorn->hide();
    ui->comboBox_editScientistAlive->hide();
    ui->input_editYearOfDeath->hide();
    ui->comboBox_editGender->hide();
    ui->label_ScientistAlive->hide();
    ui->button_saveEditScientist->hide();
    ui->label_gender->hide();

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

/*void EditWindow::on_input_editIdScientist_editingFinished(int sId)
{
    Scientist s = _scs.scientistToEdit(sId);
    string name = s.getName();
    ui->input_editNameScientist->setInputMask(QString::fromStdString(name));
}*/

void EditWindow::on_button_editScientist_clicked()
{

    ui->input_editNameScientist->clear();   // Clear all input fields.
    ui->input_editYearBorn->clear();
    ui->input_editYearOfDeath->clear();

    int sId = ui->input_editIdScientist->text().toInt();

    Scientist s = _scs.scientistToEdit(sId);
    if(s.getId() != -1)
    {
        string name = s.getName();
        string yearBorn = to_string(s.getBirthDate());
        string yearDeath = to_string(s.getDeathDate());
        char gender = s.getGender();

        ui->input_editNameScientist->show();    // Show all fields when button is clicked.
        ui->input_editYearBorn->show();
        ui->comboBox_editScientistAlive->show();
        ui->comboBox_editGender->show();
        ui->label_ScientistAlive->show();
        ui->button_saveEditScientist->show();
        ui->label_gender->show();

        ui->input_editNameScientist->setText(QString::fromStdString(name));
        ui->input_editYearBorn->setText(QString::fromStdString(yearBorn));
        if(yearDeath != "9999")
        {
            ui->comboBox_editScientistAlive->setCurrentText(QString::fromStdString("No"));
            ui->input_editYearOfDeath->show();
            ui->input_editYearOfDeath->setText(QString::fromStdString(yearDeath));
        }
        else if (yearDeath == "9999")
        {
            ui->comboBox_editScientistAlive->setCurrentText(QString::fromStdString("Yes"));
     //       ui->input_editYearOfDeath->hide();
        }
        if(gender == 'f' || gender == 'F')
        {
            ui->comboBox_editGender->setCurrentText(QChar::fromLatin1('F'));
        }
        else if(gender == 'm' || gender == 'M')
        {
            ui->comboBox_editGender->setCurrentText(QChar::fromLatin1('M'));
        }
    }
    else
    {
        ui->input_editIdScientist->clear();
    }

}

void EditWindow::on_comboBox_editScientistAlive_currentIndexChanged(const QString &arg1)
{
    string alive = "9999";

    if(ui->comboBox_editScientistAlive->currentText() == "No")
    {
        ui->input_editYearOfDeath->clear();
        ui->input_editYearOfDeath->show();
    }
    else if(ui->comboBox_editScientistAlive->currentText() == "Yes")
    {
        ui->input_editYearOfDeath->hide();
        ui->input_editYearOfDeath->setText(QString::fromStdString(alive));
    }
    else
    {
        ui->input_editYearOfDeath->hide();
        ui->input_editYearOfDeath->setText(QString::fromStdString(""));
    }
}
