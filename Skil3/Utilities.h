#ifndef UTILITIES_H
#define UTILITIES_H

#include <QtSql>
#include <string>
#include <QTableWidgetItem>

namespace Utilities {
    QSqlDatabase getDatabaseConnection();
    std::string stringToLower(std::string original);
    bool validYearCheck(std::string year);

    //Class to be able to sort integers in table widget.
    //Slightly ajusted code from: http://stackoverflow.com/questions/20706819/qt-qtablewidget-adding-integers-to-table
    class TableItemSC : public QTableWidgetItem
    {
    public:
        TableItemSC(const QString & text)
            :
                QTableWidgetItem(text)
        {}

        TableItemSC(int num)
            :
                QTableWidgetItem(QString::number(num))
        {}

        bool operator< (const QTableWidgetItem &other) const
        {
            if (other.column() == 0) {
                // Compare cell data as integers id column.
                return text().toInt() < other.text().toInt();
            }
            return other.text() < text();
        }
    };

    //For connection tables.
    class TableItemConnect : public QTableWidgetItem
    {
    public:
        TableItemConnect(const QString & text)
            :
                QTableWidgetItem(text)
        {}

        TableItemConnect(int num)
            :
                QTableWidgetItem(QString::number(num))
        {}

        bool operator< (const QTableWidgetItem &other) const
        {
            if (other.column() == 0 || other.column() == 2) {
                // Compare cell data as integers for id columns.
                return text().toInt() < other.text().toInt();
            }
            return other.text() < text();
        }
    };
}

#endif // UTILITIES_H
