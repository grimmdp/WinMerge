#include "mainwindow.h"

MainWindow::MainWindow()
{
    mUI.setupUi(this);
    connect(mUI.mActionExit, SIGNAL(triggered()), this, SLOT(close()));
}
