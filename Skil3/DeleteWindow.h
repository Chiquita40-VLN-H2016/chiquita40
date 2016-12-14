#ifndef DELETEWINDOW_H
#define DELETEWINDOW_H
#include "Scientist.h"
#include "Computer.h"
#include "SCService.h"
#include <string>
#include <vector>

#include <QDialog>

namespace Ui {
class DeleteWindow;
}

class DeleteWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteWindow(QWidget *parent = 0);
    ~DeleteWindow();

private slots:
    void on_button_deleteQuit_clicked();

    void on_button_deletePageSearch_clicked();

private:
    Ui::DeleteWindow *ui;
    vector<Scientist> _currentlyDisplayedScientists;
    vector<Computer> _currentlyDisplayedComputers;
    SCService _scs;

    void displaySearchResultsFromAll(string search);
};

#endif // DELETEWINDOW_H
