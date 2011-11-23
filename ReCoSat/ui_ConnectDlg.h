/********************************************************************************
** Form generated from reading UI file 'ConnectDlg.ui'
**
** Created: Wed 23. Nov 18:27:54 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTDLG_H
#define UI_CONNECTDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnectDlg
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *tcpAddressLabel;
    QLineEdit *tcpAddressEdit;
    QLabel *tcpPortLabel;
    QLineEdit *tcpPortEdit;
    QWidget *configFileWidget;
    QHBoxLayout *horizontalLayout;
    QCheckBox *enabledAdvancedFunctionCheck;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ConnectDlg)
    {
        if (ConnectDlg->objectName().isEmpty())
            ConnectDlg->setObjectName(QString::fromUtf8("ConnectDlg"));
        ConnectDlg->setWindowModality(Qt::ApplicationModal);
        ConnectDlg->resize(329, 150);
        ConnectDlg->setModal(true);
        verticalLayout = new QVBoxLayout(ConnectDlg);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetMinimumSize);
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        formLayout->setFormAlignment(Qt::AlignCenter);
        formLayout->setHorizontalSpacing(6);
        formLayout->setVerticalSpacing(6);
        formLayout->setContentsMargins(-1, 0, -1, -1);
        tcpAddressLabel = new QLabel(ConnectDlg);
        tcpAddressLabel->setObjectName(QString::fromUtf8("tcpAddressLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, tcpAddressLabel);

        tcpAddressEdit = new QLineEdit(ConnectDlg);
        tcpAddressEdit->setObjectName(QString::fromUtf8("tcpAddressEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, tcpAddressEdit);

        tcpPortLabel = new QLabel(ConnectDlg);
        tcpPortLabel->setObjectName(QString::fromUtf8("tcpPortLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, tcpPortLabel);

        tcpPortEdit = new QLineEdit(ConnectDlg);
        tcpPortEdit->setObjectName(QString::fromUtf8("tcpPortEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, tcpPortEdit);

        configFileWidget = new QWidget(ConnectDlg);
        configFileWidget->setObjectName(QString::fromUtf8("configFileWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(configFileWidget->sizePolicy().hasHeightForWidth());
        configFileWidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(configFileWidget);
#ifndef Q_OS_MAC
        horizontalLayout->setSpacing(6);
#endif
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        formLayout->setWidget(2, QFormLayout::FieldRole, configFileWidget);

        enabledAdvancedFunctionCheck = new QCheckBox(ConnectDlg);
        enabledAdvancedFunctionCheck->setObjectName(QString::fromUtf8("enabledAdvancedFunctionCheck"));

        formLayout->setWidget(3, QFormLayout::FieldRole, enabledAdvancedFunctionCheck);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        buttonBox = new QDialogButtonBox(ConnectDlg);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(ConnectDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConnectDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConnectDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConnectDlg);
    } // setupUi

    void retranslateUi(QDialog *ConnectDlg)
    {
        ConnectDlg->setWindowTitle(QApplication::translate("ConnectDlg", "Connection", 0, QApplication::UnicodeUTF8));
        tcpAddressLabel->setText(QApplication::translate("ConnectDlg", "Server address:", 0, QApplication::UnicodeUTF8));
        tcpPortLabel->setText(QApplication::translate("ConnectDlg", "Port number:", 0, QApplication::UnicodeUTF8));
        enabledAdvancedFunctionCheck->setText(QApplication::translate("ConnectDlg", "Enable advanced functions", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConnectDlg: public Ui_ConnectDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTDLG_H
