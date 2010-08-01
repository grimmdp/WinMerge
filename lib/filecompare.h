#ifndef FILECOMPARE_H
#define FILECOMPARE_H

#include <QString>
#include "resultitem.h"

class FileCompare
{
public:
    FileCompare(const QString &left, const QString &right);
    ResultItem Compare();

private:
    QString mLeft;
    QString mRight;
};

#endif // FILECOMPARE_H
