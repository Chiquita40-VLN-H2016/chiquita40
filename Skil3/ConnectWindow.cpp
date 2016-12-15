#include "ConnectWindow.h"
#include "ui_ConnectWindow.h"

ConnectWindow::ConnectWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectWindow)
{
    ui->setupUi(this);
}

ConnectWindow::~ConnectWindow()
{
    delete ui;
}
void ConnectWindow::on_button_connectBack_clicked()
{
    close();
}

void ConnectWindow::on_button_connectQuit_clicked()
{
    close();
    qApp->quit();
}

void ConnectWindow::on_input_connectScientistSearch_textChanged(const QString &arg1)
{
    displayScientistSearchResult(arg1);
}

void ConnectWindow::displayScientistSearchResult(const QString &arg1)
{
    ui->list_connectScientistSearchResult->clear();
}
