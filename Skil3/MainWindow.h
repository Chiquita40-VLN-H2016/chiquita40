#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Scientist.h"
#include "Computer.h"
#include "SCService.h"
#include "EditWindow.h"
#include "DeleteWindow.h"
#include "ListWindow.h"
#include "AddWindow.h"
#include "ConnectWindow.h"
#include <string>
#include <vector>

#include <QMainWindow>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_button_frontQuit_clicked();

    void on_button_frontEdit_clicked();

    void on_button_frontDelete_clicked();

    void on_button_frontSeeFullLists_clicked();

    void on_button_frontAdd_clicked();

    void on_input_frontPageSearch_textChanged(const QString &arg1);

    void on_button_frontConnect_clicked();

private:
    Ui::MainWindow *ui;
    vector<Scientist> _currentlyDisplayedScientists;
    vector<Computer> _currentlyDisplayedComputers;
    SCService _scs;

    void displaySearchResultsFromAll(string search);
    string scientistListHeader();
    string computerListHeader();
};

#endif // MAINWINDOW_H
