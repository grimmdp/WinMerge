#include <QDebug>
#include "mainwindow.h"
#include "opendialog.h"

MainWindow::MainWindow()
{
    mUI.setupUi(this);
    connect(mUI.mActionExit, SIGNAL(triggered()), this, SLOT(close()));
    connect(mUI.mActionOpenDirs, SIGNAL(triggered()), this, SLOT(OpenDirs()));
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
    }
}
