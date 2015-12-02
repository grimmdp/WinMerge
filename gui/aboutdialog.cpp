#include "aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("About WinMerge");
    setGeometry(0,0,400,115);

    _mainHorizontalLayout->addLayout(_iconLayout);
    _mainHorizontalLayout->addLayout(_textLayout);

    _iconLayout->addWidget(_winmergeIcon);
    _winmergeIcon->setPixmap(QPixmap(QString::fromUtf8(":/res/icon.png"))); //QString::fromUtf8(":/res/icon.png")

    _iconLayout->addItem(_verticalSpacer);

    _textLayout->addWidget(_winmergeVertion);
    _winmergeVertion->setText("WinMerge 2.90.0");

    _textLayout->addWidget(_copyrightLabel);
    _copyrightLabel->setText("Copyright (c) 2010-2015 WinMerge developers");

    _textLayout->addWidget(_allRightsReserved);
    _allRightsReserved->setText("All rights reserved.");

    _textLayout->addWidget(_closeButton);
    _closeButton->setOrientation(Qt::Horizontal);
    _closeButton->setStandardButtons(QDialogButtonBox::Close);
    QObject::connect(_closeButton, SIGNAL(accepted()), this, SLOT(accept()));
    QObject::connect(_closeButton, SIGNAL(rejected()), this, SLOT(reject()));
}
