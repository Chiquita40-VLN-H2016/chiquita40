#include "ListWindow.h"
#include "ui_ListWindow.h"

ListWindow::ListWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListWindow)
{
    ui->setupUi(this);
}

ListWindow::~ListWindow()
{
    delete ui;
}

void ListWindow::on_input_listPageSearch_textChanged(const QString &arg1)
{
    string search = ui->input_listPageSearch->text().toStdString();
}
