#ifndef EDITWINDOW_H
#define EDITWINDOW_H
#include "Scientist.h"
#include "Computer.h"
#include "SCService.h"
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

 //   void on_input_editIdScientist_editingFinished(int sId);

    void on_button_editScientist_clicked();

    void on_comboBox_editScientistAlive_currentIndexChanged(const QString &arg1);

private:
    Ui::EditWindow *ui;
    vector<Scientist> _currentlyDisplayedScientists;
    vector<Computer> _currentlyDisplayedComputers;
    SCService _scs;

    void displaySearchResultsFromAll(string search);
};

#endif // EDITWINDOW_H
