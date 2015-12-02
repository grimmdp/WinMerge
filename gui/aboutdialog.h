#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QDialogButtonBox>
#include <QSpacerItem>
#include "ui_aboutdialog.h"

class QWidget;

class AboutDialog : public  QDialog
{
    Q_OBJECT

public:
    AboutDialog(QWidget * parent = NULL);

private:
    QHBoxLayout* _mainHorizontalLayout = new QHBoxLayout(this);
    QVBoxLayout* _iconLayout = new QVBoxLayout(this);
    QLabel* _winmergeIcon = new QLabel(this);
    QSpacerItem* _verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    QVBoxLayout* _textLayout = new QVBoxLayout(this);
    QLabel* _winmergeVertion = new QLabel(this);
    QLabel* _copyrightLabel = new QLabel(this);
    QLabel* _allRightsReserved = new QLabel(this);
    QDialogButtonBox* _closeButton = new QDialogButtonBox(this);
};

#endif // ABOUTDIALOG_H
