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
    dlg.exec();
}
