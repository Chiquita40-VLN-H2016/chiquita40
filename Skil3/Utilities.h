#ifndef UTILITIES_H
#define UTILITIES_H

#include <QtSql>
#include <string>

namespace Utilities {
    QSqlDatabase getDatabaseConnection();
    std::string stringToLower(std::string original);
    bool validYearCheck(std::string year);
}

#endif // UTILITIES_H
