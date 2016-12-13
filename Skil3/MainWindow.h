#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Scientist.h"
#include "Computer.h"
#include "SCService.h"
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

    void on_button_frontPageSearch_clicked();

private:
    Ui::MainWindow *ui;
    vector<Scientist> _currentlyDisplayedScientists;
    vector<Computer> _currentlyDisplayedComputers;
    SCService _scs;

    void displaySearchResultsFromAll(string search);
};

#endif // MAINWINDOW_H
