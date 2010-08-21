
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
    void OpenFiles();
    void ToggleMainToolBar();
    void ToggleStatusBar();
    void AboutWinMerge();

protected:
    void DoDirCompare(const QString &left, const QString &right);

private:
    Ui::mMainWindow mUI;
};

#endif // MAINWINDOW_H
