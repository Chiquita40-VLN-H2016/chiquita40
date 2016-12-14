#include "Utilities.h"

namespace Utilities {
    //Using code from Bæring's lecture (Cars-Template).
    QSqlDatabase getDatabaseConnection()
    {
        QString connectionName = "SCConnection";

        QSqlDatabase db;

        if(QSqlDatabase::contains(connectionName))
        {
            db = QSqlDatabase::database(connectionName);
        }
        else
        {
            db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
            db.setDatabaseName("C:/CSHistory.sqlite");

            db.open();

            //Own addition.
            QSqlQuery query(db);
            query.exec("PRAGMA foreign_keys = ON");  //Activate foreign key constriction in database.
        }

        return db;
    }


}
