#ifndef EDITWINDOW_H
#define EDITWINDOW_H
#include "Scientist.h"
#include "Computer.h"
#include "SCService.h"
#include "Utilities.h"
#include <string>
#include <vector>

#include <QDialog>

namespace Ui {
class EditWindow;
}

class EditWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditWindow(QWidget *parent = 0);
    ~EditWindow();

private slots:
    void on_input_editPageSearch_textChanged(const QString &arg1);

    void on_button_editScientist_clicked();

    void on_comboBox_editScientistAlive_currentIndexChanged(const QString &arg1);

    void on_button_saveEditScientist_clicked();

    void on_button_editComputer_clicked();

    void on_comboBox_editComputerBuilt_currentIndexChanged(const QString &arg1);

    void on_button_editBack_clicked();

    void on_button_editQuit_clicked();

    void on_button_saveEditComputer_clicked();

    void on_list_editPageSearchResult_doubleClicked(const QModelIndex &index);

    void on_input_editNameScientist_textChanged(const QString &arg1);

    void on_input_editNameComputer_textChanged(const QString &arg1);

    void on_input_editType_textChanged(const QString &arg1);

private:
    Ui::EditWindow *ui;
    vector<Scientist> _currentlyDisplayedScientists;
    vector<Computer> _currentlyDisplayedComputers;
    SCService _scs;

    void displaySearchResultsFromAll(string search);
    void hideScientistFields();
    void hideComputerFields();
    void displayEditedScientist(int id);
    void displayEditedComputer(int id);

    string scientistListHeader();
    string computerListHeader();
};

#endif // EDITWINDOW_H
