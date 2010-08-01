#include <QDir>
#include <QString>
#include <QList>
#include <QStringList>
#include "dircompare.h"
#include "filecompare.h"
#include "resultitem.h"

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

    mResults.clear();

    QStringList::const_iterator iter = left.constBegin();
    while (iter != left.constEnd())
    {
        int index = right.indexOf(*iter);
        if (index != -1)
        {
            FileCompare compare(*iter, right.at(index));
            ResultItem item = compare.Compare();
            mResults << item;
        }
        ++iter;
    }
}

QList<ResultItem> DirCompare::GetResults() const
{
    return mResults;
}
