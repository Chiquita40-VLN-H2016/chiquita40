#include "ListWindow.h"
#include "ui_ListWindow.h"

ListWindow::ListWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListWindow)
{
    ui->setupUi(this);
    displayAllScientist(0, 0);
}

ListWindow::~ListWindow()
{
    delete ui;
}

/*void ListWindow::displaySearchResultsFromAll(string search)
{
    ui->list_listPageSearchResult->clear();
    _currentlyDisplayedComputers.clear();
    _currentlyDisplayedScientists.clear();

    _currentlyDisplayedComputers = _scs.findComputerByName(search);
    _currentlyDisplayedScientists = _scs.findScientistByName(search);

    ui->list_listPageSearchResult->addItem(QString::fromStdString("Computers that matched search:"));

    for(unsigned int i = 0; i < _currentlyDisplayedComputers.size(); i++)
    {
        Computer c = _currentlyDisplayedComputers.at(i);
        ui->list_listPageSearchResult->addItem(QString::fromStdString(c.toString()));
    }

    ui->list_listPageSearchResult->addItem(QString::fromStdString("Scientists that matched search:"));

    for(unsigned int i = 0; i < _currentlyDisplayedScientists.size(); i++)
    {
        Scientist s = _currentlyDisplayedScientists.at(i);
        ui->list_listPageSearchResult->addItem(QString::fromStdString(s.toString()));
    }
}*/

void ListWindow::displayAllScientist(int type, int ascdesc)
{
    ui->input_listScientistSearch->setText("");
    ui->table_Scientists->clearContents();
    _allScientists.clear();
    scientistsWhichOrder(type, ascdesc);
    _allScientists = _scs.getScientists();

    ui->table_Scientists->setRowCount(_allScientists.size());

    for(unsigned int row = 0; row < _allScientists.size(); row++)
    {
        Scientist s = _allScientists.at(row);
        QString id = QString::number(s.getId());
        QString name = QString::fromStdString(s.getName());
        QString birthYear = QString::number(s.getBirthDate());
        QString deathYear;
        if(s.getDeathDate() == 9999)
        {
            deathYear = "Alive";
        }
        else
        {
            deathYear = QString::number(s.getDeathDate());
        }
        QString gender = QChar(toupper(s.getGender()));

        ui->table_Scientists->setItem(row, 0, new QTableWidgetItem(id));
        ui->table_Scientists->setItem(row, 1, new QTableWidgetItem(name));
        ui->table_Scientists->setItem(row, 2, new QTableWidgetItem(birthYear));
        ui->table_Scientists->setItem(row, 3, new QTableWidgetItem(deathYear));
        ui->table_Scientists->setItem(row, 4, new QTableWidgetItem(gender));
    }
}

//Order scientists in desired order.
void ListWindow::scientistsWhichOrder(int type, int ascdesc)
{
    if(ascdesc == 0) //Ascending order.
    {
        switch(type)
        {

            case 0:  //Order by name.
                    _scs.scientistsAscendingOrder(0);
                    break;
            case 1: //Order by Birth year.
                    _scs.scientistsAscendingOrder(1);
                    break;
            case 2: //Order by Year of death.
                    _scs.scientistsAscendingOrder(2);
                    break;
            case 3: //Order by gender.
                    _scs.scientistsAscendingOrder(3);
                    break;
            default: //Order by id.
                    _scs.scientistsAscendingOrder(4);
        }
    }
    else //Descending order.
    {
        switch(type)
        {

            case 0:  //Order by name.
                    _scs.scientistsDescendingOrder(0);
                    break;
            case 1: //Order by Birth year.
                    _scs.scientistsDescendingOrder(1);
                    break;
            case 2: //Order by Year of death.
                    _scs.scientistsDescendingOrder(2);
                    break;
            case 3: //Order by gender.
                    _scs.scientistsDescendingOrder(3);
                    break;
            default: //Order by id.
                    _scs.scientistsDescendingOrder(4);
        }
    }
}

void ListWindow::on_button_listBack_clicked()
{
    close();
}

void ListWindow::on_button_listQuit_clicked()
{
    close();
    qApp->quit();
}

void ListWindow::on_input_listScientistSearch_textChanged(const QString &arg1)
{
    string search = arg1.toStdString();
    if(search.size() != 0)
    {
        //displaySearchResultsFromAll(search);
    }
    if(search.size()== 0)
    {
        ui->table_Scientists->clearContents();
    }
}
