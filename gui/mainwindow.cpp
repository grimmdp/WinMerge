#include <QList>
#include <QDebug>
#include "mainwindow.h"
#include "opendialog.h"
#include "aboutdialog.h"
#include "dircompare.h"
#include "resultitem.h"
#include "libxdiff_tools.h"

MainWindow::MainWindow()
{
    mUI.setupUi(this);
    libxdiff_tools_init();

    connect(mUI.mActionExit, SIGNAL(triggered()), this, SLOT(close()));
    connect(mUI.mActionOpenDirs, SIGNAL(triggered()), this, SLOT(OpenDirs()));
    connect(mUI.mActionAboutWinMerge, SIGNAL(triggered()), this, SLOT(AboutWinMerge()));
}

void MainWindow::OpenDirs()
{
    OpenDialog dlg;
    int retval = dlg.exec();
    if (retval == QDialog::Accepted)
    {
        QString left = dlg.GetLeftItem();
        QString right = dlg.GetRightItem();
        qDebug() << "Selected items: " << left << ", " << right;
        DoDirCompare(left, right);
    }
}

void MainWindow::DoDirCompare(const QString &left, const QString &right)
{
    DirCompare compare(left, right);
    compare.DoCompare();
    QList<ResultItem> results = compare.GetResults();

    QList<ResultItem>::const_iterator iter = results.constBegin();
    while (iter != results.constEnd())
    {
        QString resStr;
        if ((*iter).result == ResultItem::Different)
            resStr = "Different";
        else
            resStr = "Identical";
        qDebug() << "File: " << (*iter).name << " Result: " << resStr;
        ++iter;
    }
}

void MainWindow::AboutWinMerge()
{
    AboutDialog dlg(this);
    dlg.exec();
}
