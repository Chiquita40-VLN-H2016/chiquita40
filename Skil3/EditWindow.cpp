#include "EditWindow.h"
#include "ui_EditWindow.h"

EditWindow::EditWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditWindow)
{
    ui->setupUi(this);

    hideScientistFields();
    hideComputerFields();
}

EditWindow::~EditWindow()
{
    delete ui;
}

void EditWindow::on_button_editBack_clicked()
{
    close();
}

void EditWindow::on_button_editQuit_clicked()
{
    close();
    qApp->quit();
}

// Scientists - All functions regarding scientists in EditWindow.

void EditWindow::on_input_editPageScientistsSearch_textChanged()
{
    string search = ui->input_editPageScientistsSearch->text().toStdString();
    displayScientistSearchResultsFromAll(search);
}

void EditWindow::displayScientistSearchResultsFromAll(string search)
{
    ui->table_editPageScientistsSearchResult->clearContents();
    _currentlyDisplayedScientists.clear();

    _currentlyDisplayedScientists = _scs.findScientistByName(search);

    if(_currentlyDisplayedScientists.size() != 0)
    {
        ui->table_editPageScientistsSearchResult->setRowCount(_currentlyDisplayedScientists.size());

        for(unsigned int row = 0; row < _currentlyDisplayedScientists.size(); row++)
        {
            Scientist s = _currentlyDisplayedScientists.at(row);
            QString id = QString::number(s.getId());
            QString name = QString::fromStdString(s.getName());
            QString birthYear = QString::number(s.getBirthDate());
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

            ui->table_editPageScientistsSearchResult->setItem(row, 0, new QTableWidgetItem(id));
            ui->table_editPageScientistsSearchResult->setItem(row, 1, new QTableWidgetItem(name));
            ui->table_editPageScientistsSearchResult->setItem(row, 2, new QTableWidgetItem(birthYear));
            ui->table_editPageScientistsSearchResult->setItem(row, 3, new QTableWidgetItem(deathYear));
            ui->table_editPageScientistsSearchResult->setItem(row, 4, new QTableWidgetItem(gender));

        }

    }
    if(search.size() != 0 && _currentlyDisplayedScientists.size() == 0)
    {
        ui->table_editPageScientistsSearchResult->clearContents();
    //    ui->label_searchNoResults->setText("<p style=\"color:#f44242;\">Your search returned no results.</p>");
    }

}

void EditWindow::displayEditedScientist(int id)
{
    ui->input_editPageScientistsSearch->clear();
    ui->table_editPageScientistsSearchResult->clearContents();
    int row = 0;

    Scientist s = _scs.scientistToEdit(id);

    ui->table_editPageScientistsSearchResult->setRowCount(row + 1);

    QString sId = QString::number(s.getId());
    QString name = QString::fromStdString(s.getName());
    QString birthYear = QString::number(s.getBirthDate());
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

    ui->table_editPageScientistsSearchResult->setItem(row, 0, new QTableWidgetItem(sId));
    ui->table_editPageScientistsSearchResult->setItem(row, 1, new QTableWidgetItem(name));
    ui->table_editPageScientistsSearchResult->setItem(row, 2, new QTableWidgetItem(birthYear));
    ui->table_editPageScientistsSearchResult->setItem(row, 3, new QTableWidgetItem(deathYear));
    ui->table_editPageScientistsSearchResult->setItem(row, 4, new QTableWidgetItem(gender));
}

void EditWindow::on_button_editScientist_clicked()
{
    ui->input_editNameScientist->clear();   // Clear all input fields.
    ui->input_editYearBorn->clear();
    ui->input_editYearOfDeath->clear();
    ui->label_editScientistErrorMessage->clear();

    int sId = ui->input_editIdScientist->text().toInt();

    Scientist s = _scs.scientistToEdit(sId);
    if(s.getId() != -1)
    {
        ui->input_editIdScientist->setEnabled(false);   // Lock ID field for editing.

        string name = s.getName();
        string yearBorn = to_string(s.getBirthDate());
        string yearDeath = to_string(s.getDeathDate());
        char gender = s.getGender();

        ui->input_editNameScientist->show();    // Show all fields when button is clicked
        ui->input_editYearBorn->show();         // and ID has been validated.
        ui->comboBox_editScientistAlive->show();
        ui->comboBox_editGender->show();
        ui->label_ScientistAlive->show();
        ui->button_saveEditScientist->show();
        ui->label_gender->show();
        ui->label_editBirthYearScientist->show();
        ui->label_editNameScientist->show();

        ui->input_editNameScientist->setText(QString::fromStdString(name));
        ui->input_editYearBorn->setText(QString::fromStdString(yearBorn));

        if(yearDeath != "9999")
        {
            ui->comboBox_editScientistAlive->setCurrentText(QString::fromStdString("No"));
            ui->label_editDeathYearScientist->show();
            ui->input_editYearOfDeath->show();
            ui->input_editYearOfDeath->setText(QString::fromStdString(yearDeath));
        }
        else if (yearDeath == "9999")
        {
            ui->comboBox_editScientistAlive->setCurrentText(QString::fromStdString("Yes"));
            ui->input_editYearOfDeath->setText(QString::fromStdString(yearDeath));

        }

        if(gender == 'f' || gender == 'F')
        {
            ui->comboBox_editGender->setCurrentIndex(0);    // Set gender index to "Female"

        }
        else if(gender == 'm' || gender == 'M')
        {
            ui->comboBox_editGender->setCurrentIndex(1);    // Set gender index to "Male"
        }
    }
    else
    {
        ui->input_editIdScientist->clear();
    }

}

void EditWindow::on_comboBox_editScientistAlive_currentIndexChanged()
{
    string alive = "9999";

    if(ui->comboBox_editScientistAlive->currentText() == "No")
    {
        ui->input_editYearOfDeath->clear();
        ui->label_editDeathYearScientist->show();
        ui->input_editYearOfDeath->show();
    }
    else
    {
        ui->input_editYearOfDeath->hide();
        ui->label_editDeathYearScientist->hide();
        ui->input_editYearOfDeath->setText(QString::fromStdString(alive));
    }
}

void EditWindow::on_button_saveEditScientist_clicked()
{
    int id = ui->input_editIdScientist->text().toInt();
    string name = ui->input_editNameScientist->text().toStdString();
    string bY = ui->input_editYearBorn->text().toStdString();
    int birthYear = ui->input_editYearBorn->text().toInt();
    bool birthYearIsValid = Utilities::validYearCheck(bY);
    bool deathYearIsValid = false;
    string alive = ui->comboBox_editScientistAlive->currentText().toStdString();
    int deathYear = 9999;
    string gender = ui->comboBox_editGender->currentText().toStdString();
    char g = tolower(gender.front());

    if(alive == "Yes")
    {
        deathYearIsValid = true;
    }
    else if (alive == "No")
    {
        string dY = ui->input_editYearOfDeath->text().toStdString();
        deathYear = ui->input_editYearOfDeath->text().toInt();
        deathYearIsValid = Utilities::validYearCheck(dY);

        if(deathYearIsValid && deathYear < birthYear)
        {
            deathYearIsValid = false;
        }

    }

    if(!birthYearIsValid && deathYearIsValid)
    {
        ui->label_editScientistErrorMessage->setText("<p style=\"color:#f44242;\">Invalid Birth Year</p>");
    }
    else if(!deathYearIsValid && birthYearIsValid)
    {
        ui->label_editScientistErrorMessage->setText("<p style=\"color:#f44242;\">Invalid Year of Death</p>");
    }
    else if(!birthYearIsValid && !deathYearIsValid)
    {
        ui->label_editScientistErrorMessage->setText("<p style=\"color:#f44242;\">Invalid Year Format</p>");
    }
    else
    {
        _scs.editScientist(id, name, birthYear, deathYear, g);

        ui->input_editIdScientist->setEnabled(true);
        ui->input_editIdScientist->clear();

        hideScientistFields();
        displayEditedScientist(id);
    }

}

void EditWindow::on_input_editNameScientist_textChanged(const QString &arg1)
{
    if(arg1.isEmpty())
    {
        ui->button_saveEditScientist->setEnabled(false);
    }
    else
    {
        ui->button_saveEditScientist->setEnabled(true);
    }
}

void EditWindow::hideScientistFields()
{
    ui->input_editNameScientist->hide();
    ui->input_editYearBorn->hide();
    ui->comboBox_editScientistAlive->hide();
    ui->input_editYearOfDeath->hide();
    ui->comboBox_editGender->hide();
    ui->label_ScientistAlive->hide();
    ui->button_saveEditScientist->hide();
    ui->label_gender->hide();
    ui->label_editBirthYearScientist->hide();
    ui->label_editDeathYearScientist->hide();
    ui->label_editNameScientist->hide();
}

// Computers - All functions regarding computers in EditWindow.

void EditWindow::on_input_editPageComputersSearch_textChanged()
{
    string search = ui->input_editPageComputersSearch->text().toStdString();
    displayComputerSearchResultsFromAll(search);
}

void EditWindow::displayComputerSearchResultsFromAll(string search)
{
    ui->table_editPageComputersSearchResult->clearContents();
    _currentlyDisplayedComputers.clear();

    _currentlyDisplayedComputers = _scs.findComputerByName(search);

    if(_currentlyDisplayedComputers.size() != 0)
    {
        ui->table_editPageComputersSearchResult->setRowCount(_currentlyDisplayedComputers.size());

        for(unsigned int row = 0; row < _currentlyDisplayedComputers.size(); row++)
        {
            Computer c = _currentlyDisplayedComputers.at(row);
            QString id = QString::number(c.getId());
            QString name = QString::fromStdString(c.getName());
            QString type = QString::fromStdString(c.getType());
            QString builtYear;
            QString wasBuilt;

            if(c.getWasBuilt() == 1)
            {
                wasBuilt = QString::fromStdString("Yes");
                builtYear = QString::number(c.getBuildYear());
            }
            else
            {
                wasBuilt = QString::fromStdString("No");
            }

            ui->table_editPageComputersSearchResult->setItem(row, 0, new QTableWidgetItem(id));
            ui->table_editPageComputersSearchResult->setItem(row, 1, new QTableWidgetItem(name));
            ui->table_editPageComputersSearchResult->setItem(row, 2, new QTableWidgetItem(type));
            ui->table_editPageComputersSearchResult->setItem(row, 3, new QTableWidgetItem(builtYear));
            ui->table_editPageComputersSearchResult->setItem(row, 4, new QTableWidgetItem(wasBuilt));

        }

    }
    if(search.size() != 0 && _currentlyDisplayedComputers.size() == 0)
    {
        ui->table_editPageComputersSearchResult->clearContents();
    //    ui->label_searchNoResults->setText("<p style=\"color:#f44242;\">Your search returned no results.</p>");
    }

}

void EditWindow::displayEditedComputer(int id)
{
    ui->table_editPageComputersSearchResult->clearContents();
    _currentlyDisplayedComputers.clear();
    int row = 0;

    Computer c = _scs.computerToEdit(id);

    ui->table_editPageComputersSearchResult->setRowCount(row + 1);

    QString cId = QString::number(c.getId());
    QString name = QString::fromStdString(c.getName());
    QString type = QString::fromStdString(c.getType());
    QString builtYear;
    QString wasBuilt;

    if(c.getWasBuilt() == 1)
    {
        wasBuilt = QString::fromStdString("Yes");
        builtYear = QString::number(c.getBuildYear());
    }
    else
    {
        wasBuilt = QString::fromStdString("No");
    }

    ui->table_editPageComputersSearchResult->setItem(row, 0, new QTableWidgetItem(cId));
    ui->table_editPageComputersSearchResult->setItem(row, 1, new QTableWidgetItem(name));
    ui->table_editPageComputersSearchResult->setItem(row, 2, new QTableWidgetItem(type));
    ui->table_editPageComputersSearchResult->setItem(row, 3, new QTableWidgetItem(builtYear));
    ui->table_editPageComputersSearchResult->setItem(row, 4, new QTableWidgetItem(wasBuilt));
}

void EditWindow::on_button_editComputer_clicked()
{
    ui->input_editNameComputer->clear();        // Clear all input fields.
    ui->input_editYearOfCompletion->clear();
    ui->input_editType->clear();

    int cId = ui->input_editIdComputer->text().toInt();

    Computer c = _scs.computerToEdit(cId);
    if(c.getId() != -1)
    {
        ui->input_editIdComputer->setEnabled(false);        // Lock ID field for editing.

        string name = c.getName();
        string yearBuilt = to_string(c.getBuildYear());
        string type = c.getType();
        bool wasBuilt = c.getWasBuilt();

        ui->input_editNameComputer->show();
        ui->input_editType->show();
        ui->comboBox_editComputerBuilt->show();
        ui->label_computerBuilt->show();
        ui->button_saveEditComputer->show();
        ui->label_editNameComputer->show();
        ui->label_editTypeComputer->show();

        ui->input_editNameComputer->setText(QString::fromStdString(name));
        ui->input_editType->setText(QString::fromStdString(type));

        if(wasBuilt)
        {
            ui->comboBox_editComputerBuilt->setCurrentText(QString::fromStdString("Yes"));
            ui->label_editYearOfCompletionComputer->show();
            ui->input_editYearOfCompletion->show();
            ui->input_editYearOfCompletion->setText(QString::fromStdString(yearBuilt));
        }
        else
        {
            ui->comboBox_editComputerBuilt->setCurrentText(QString::fromStdString("No"));
        }
    }
    else
    {
        ui->input_editIdComputer->clear();
    }
}

void EditWindow::on_comboBox_editComputerBuilt_currentIndexChanged()
{
    if(ui->comboBox_editComputerBuilt->currentText() == "Yes")
    {
        ui->input_editYearOfCompletion->clear();
        ui->label_editYearOfCompletionComputer->show();
        ui->input_editYearOfCompletion->show();
    }
    else
    {
        ui->input_editYearOfCompletion->setText(QString::fromStdString("0"));
        ui->label_editYearOfCompletionComputer->hide();
        ui->input_editYearOfCompletion->hide();
    }

}

void EditWindow::on_button_saveEditComputer_clicked()
{
    int id = ui->input_editIdComputer->text().toInt();
    string name = ui->input_editNameComputer->text().toStdString();
    string type = ui->input_editType->text().toStdString();
    string wasBuilt = ui->comboBox_editComputerBuilt->currentText().toStdString();
    bool buildYearIsValid = true;
    int yearBuilt = 0;

    if(wasBuilt == "Yes")
    {
        yearBuilt = ui->input_editYearOfCompletion->text().toInt();
        string buY = ui->input_editYearOfCompletion->text().toStdString();
        buildYearIsValid = Utilities::validYearCheck(buY);
        buildYearIsValid = _scs.validYearCheck(yearBuilt);
    }
    if(buildYearIsValid)
    {
        _scs.editComputer(id,name,yearBuilt, type, wasBuilt);

        ui->input_editIdComputer->setEnabled(true);
        ui->input_editIdComputer->clear();

        hideComputerFields();
        displayEditedComputer(id);
    }
    else
    {
        ui->label_editComputerErrorMessage->setText("<p style=\"color:#f44242;\">Invalid Build Year</p>");
    }

}

void EditWindow::on_input_editNameComputer_textChanged(const QString &arg1)
{
    if(arg1.isEmpty())
    {
        ui->button_saveEditComputer->setEnabled(false);
    }
    else
    {
        if(!ui->input_editType->text().isEmpty())
        {
            ui->button_saveEditComputer->setEnabled(true);
        }
    }
}

void EditWindow::on_input_editType_textChanged(const QString &arg1)
{
    if(arg1.isEmpty())
    {
        ui->button_saveEditComputer->setEnabled(false);
    }
    else
    {
        if(!ui->input_editNameComputer->text().isEmpty())
        {
            ui->button_saveEditComputer->setEnabled(true);
        }
    }
}

void EditWindow::hideComputerFields()
{
    ui->input_editNameComputer->hide();
    ui->input_editYearOfCompletion->hide();
    ui->comboBox_editComputerBuilt->hide();
    ui->label_computerBuilt->hide();
    ui->input_editType->hide();
    ui->button_saveEditComputer->hide();
    ui->label_editNameComputer->hide();
    ui->label_editTypeComputer->hide();
    ui->label_editYearOfCompletionComputer->hide();
}
