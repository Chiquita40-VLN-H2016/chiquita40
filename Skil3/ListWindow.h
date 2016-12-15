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

    void on_button_listBack_clicked();

    void on_button_listQuit_clicked();

    void on_input_listScientistSearch_textChanged(const QString &arg1);

private:
    Ui::ListWindow *ui;
    vector<Scientist> _currentlyDisplayedScientists;
    vector<Computer> _currentlyDisplayedComputers;
    vector<Invented> _currentlyDisplayedConnections;
    vector<Scientist> _allScientists;
    vector<Computer> _allComputers;
    vector<Invented> _allConnections;
    SCService _scs;

    //void displaySearchResultsFromAll(string search);
    void displayAllScientist(int type, int ascdesc);
    void scientistsWhichOrder(int type, int ascdesc);
};

#endif // LISTWINDOW_H
