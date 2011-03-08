#include <QDir>
#include <QFileInfo>
#include <QString>
#include <QList>
#include <QStringList>
#include <QtDebug>
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
    const QFileInfoList left = mLeftDir->entryInfoList(QDir::NoFilter,
                               QDir::Name | QDir::DirsFirst);
    const QFileInfoList right = mRightDir->entryInfoList(QDir::NoFilter,
                                QDir::Name | QDir::DirsFirst);

    mResults.clear();

    QFileInfoList::const_iterator iter = left.constBegin();
    QFileInfoList::const_iterator iter2 = right.constBegin();
    while (iter != left.constEnd() && iter2 != right.constEnd())
    {
        const QFileInfo inf1 = *iter;
        const bool leftIsFile = inf1.isFile();
        const QFileInfo inf2 = *iter2;
        const bool rightIsFile = inf2.isFile();

        if (leftIsFile && rightIsFile)
        {
            if (inf1.fileName() == inf2.fileName())
            {
                qDebug() << "Comparing: " << inf1.fileName() << " and " << inf2.fileName();
                FileCompare compare(inf1.absoluteFilePath(), inf2.absoluteFilePath());
                ResultItem item = compare.Compare();
                mResults << item;
                ++iter;
                ++iter2;
            }
            else
            {
                qDebug() << "Skipping one-side item: " << inf1.fileName();
                ++iter;
            }
        }
        else
        {
            if (!leftIsFile)
            {
                qDebug() << "Skipping left-side dir: " << inf1.baseName();
                ++iter;
            }
            if (!rightIsFile)
            {
                qDebug() << "Skipping right-side dir: " << inf2.baseName();
                ++iter2;
            }
        }
    }
}

QList<ResultItem> DirCompare::GetResults() const
{
    return mResults;
}
