/********************************************************************************
** Form generated from reading UI file 'ConnectDlg.ui'
**
** Created: Mon 7. Nov 14:28:41 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UI_CONNECTDLG_H
#define UI_UI_CONNECTDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_ConnectDlg
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ConnectDlg)
    {
        if (ConnectDlg->objectName().isEmpty())
            ConnectDlg->setObjectName(QString::fromUtf8("ConnectDlg"));
        ConnectDlg->resize(187, 117);
        buttonBox = new QDialogButtonBox(ConnectDlg);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(0, 60, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(ConnectDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConnectDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConnectDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConnectDlg);
    } // setupUi

    void retranslateUi(QDialog *ConnectDlg)
    {
        ConnectDlg->setWindowTitle(QApplication::translate("ConnectDlg", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConnectDlg: public Ui_ConnectDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UI_CONNECTDLG_H
