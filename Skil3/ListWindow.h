#ifndef LISTWINDOW_H
#define LISTWINDOW_H
#include "Scientist.h"
#include "Computer.h"
#include "SCService.h"
#include <string>
#include <vector>
#include <QDialog>

namespace Ui {
class ListWindow;
}

class ListWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ListWindow(QWidget *parent = 0);
    ~ListWindow();

private slots:
    void on_input_listPageSearch_textChanged(const QString &arg1);

    void on_button_listBack_clicked();

    void on_button_listQuit_clicked();

private:
    Ui::ListWindow *ui;
    vector<Scientist> _currentlyDisplayedScientists;
    vector<Computer> _currentlyDisplayedComputers;
    SCService _scs;

    void displaySearchResultsFromAll(string search);
};

#endif // LISTWINDOW_H
