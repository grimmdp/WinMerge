#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
#include "ui_aboutdialog.h"

class QWidget;

class AboutDialog : public  QDialog
{
    Q_OBJECT

public:
    AboutDialog(QWidget * parent = NULL);

private:
    Ui::mAboutDialog mUI;
};

#endif // ABOUTDIALOG_H
