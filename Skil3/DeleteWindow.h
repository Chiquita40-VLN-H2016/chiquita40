#ifndef DELETEWINDOW_H
#define DELETEWINDOW_H

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

private:
    Ui::DeleteWindow *ui;
};

#endif // DELETEWINDOW_H
