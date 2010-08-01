
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>

#include "ui_mainwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

protected slots:
    void OpenDirs();

private:
    Ui::mMainWindow mUI;
};

#endif // MAINWINDOW_H
