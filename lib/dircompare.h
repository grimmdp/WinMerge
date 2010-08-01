#ifndef DIRCOMPARE_H
#define DIRCOMPARE_H

#include <QList>
#include "resultitem.h"

class QString;
class QDir;

class DirCompare
{
public:
    DirCompare(const QString &left, const QString &right);
    ~DirCompare();

    void DoCompare();
    QList<ResultItem> GetResults() const;

private:
    QDir *mLeftDir;
    QDir *mRightDir;
    QList<ResultItem> mResults;
};

#endif // DIRCOMPARE_H
