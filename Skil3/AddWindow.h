#ifndef ADDWINDOW_H
#define ADDWINDOW_H
#include "Scientist.h"
#include "Computer.h"
#include "SCService.h"
#include "EditWindow1.h"
#include "DeleteWindow.h"
#include "AddWindow.h"
#include "Utilities.h"
#include <string>
#include <vector>

#include <QDialog>

namespace Ui {
class AddWindow;
}

class AddWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddWindow(QWidget *parent = 0);
    ~AddWindow();

private slots:
    void on_button_addBack_clicked();

    void on_button_addQuit_clicked();

    void on_input_addScientistSearch_textChanged(const QString &arg1);

    void on_button_addScientist_clicked();

    void on_comboBox_addSAlive_currentIndexChanged(const QString &arg1);

    void on_comboBox_addCBuilt_currentIndexChanged(const QString &arg1);

    void on_button_addComputer_clicked();

    void on_input_addNameScientist_textChanged(const QString &arg1);

    void on_input_addNameComputer_textChanged(const QString &arg1);

    void on_input_addType_textChanged(const QString &arg1);

    void on_input_searchComputer_textChanged(const QString &arg1);

private:
    Ui::AddWindow *ui;
    vector<Scientist> _currentlyDisplayedScientists;
    vector<Computer> _currentlyDisplayedComputers;
    vector<Scientist> _allScientists;
    vector<Computer> _allComputers;
    SCService _scs;

    void displaySearchResultsFromAll(string search);
    void displayScientistSearchResults(string search);
    void displayComputerSearchResult(string search);
    void displayAllScientists();
    void displayAllComputers();
    void clearScientistForm();
    void clearComputerForm();
    string scientistListHeader();
    string computerListHeader();
};

#endif // ADDWINDOW_H

