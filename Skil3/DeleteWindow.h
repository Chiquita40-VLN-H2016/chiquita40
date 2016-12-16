#ifndef DELETEWINDOW_H
#define DELETEWINDOW_H
#include "Scientist.h"
#include "Computer.h"
#include "Invented.h"
#include "SCService.h"
#include <string>
#include <vector>

#include <QDialog>
#include <QTableWidget>

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

    void on_button_deleteBack_clicked();

    void on_input_deleteScientistSearch_textChanged(const QString &arg1);

    void on_input_deleteComputerSearch_textChanged(const QString &arg1);

    void on_input_deleteConnectSearch_textChanged(const QString &arg1);

    void on_lineEdit_deleteScientistID_textChanged(const QString &arg1);

    void on_button_deleteScientist_clicked();

    void on_lineEdit_deleteComputerID_textChanged(const QString &arg1);

    void on_button_deleteComputer_clicked();

    void on_lineEdit_deleteConnectionScientistID_textChanged(const QString &arg1);

    void on_lineEdit_deleteConnectionComputerID_textChanged(const QString &arg1);

    void on_button_deleteConnection_clicked();

private:
    Ui::DeleteWindow *ui;
    vector<Scientist> _currentlyDisplayedScientists;
    vector<Computer> _currentlyDisplayedComputers;
    vector<Invented> _currentlyDisplayedConnections;
    SCService _scs;

    int deleteWarningMessage();

    void displayAllScientists(string search);
    void displayAllComputers(string search);
    void displayAllConnections(string search);
    void displayScientistsAfterDelete();
    void displayComputersAfterDelete();
    void displayConnectionAfterDelete();
};

#endif // DELETEWINDOW_H
