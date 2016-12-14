#ifndef UTILITIES_H
#define UTILITIES_H

#include <QtSql>
#include <string>

namespace Utilities {
    QSqlDatabase getDatabaseConnection();
    std::string stringToLower(std::string original);
}

#endif // UTILITIES_H
