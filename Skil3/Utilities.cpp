#include "Utilities.h"

namespace Utilities {
    //Using code from Bæring's lecture (Cars-Template).
    QSqlDatabase getDatabaseConnection()
    {
        QString connectionName = "CSDConnection";

        QSqlDatabase db;

        if(QSqlDatabase::contains(connectionName))
        {
            db = QSqlDatabase::database(connectionName);
        }
        else
        {
            db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
            db.setDatabaseName("C:/ComputerScienceDatabase.sqlite");

            db.open();

            //Own addition.
            QSqlQuery query(db);
            query.exec("PRAGMA foreign_keys = ON");  //Activate foreign key constriction in database.
        }

        return db;
    }

    bool validYearCheck(std::string year)
    {
        if(year.size() != 4)
        {
            return false;
        }
        for(unsigned int i = 0; i < year.size(); i++)
        {
            if(!isdigit(year.at(i)))
            {
                return false;
            }
        }
        return true;
    }


}
