#include <QDir>
#include <QString>
#include <QStringList>
#include "dircompare.h"

DirCompare::DirCompare(const QString &left, const QString &right)
{
    mLeftDir = new QDir(left);
    mRightDir = new QDir(right);
}

DirCompare::~DirCompare()
{
    delete mLeftDir;
    delete mRightDir;
}

void DirCompare::DoCompare()
{
    QStringList left = mLeftDir->entryList();
    QStringList right = mRightDir->entryList();
}
