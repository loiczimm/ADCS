/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon 7. Nov 14:44:10 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMdiArea>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *connectAction;
    QWidget *centralWidget;
    QMdiArea *mdiArea;
    QLineEdit *AccLineEdit;
    QLabel *AccLabel;
    QLineEdit *Connect2;
    QLabel *AccLabel_2;
    QMenuBar *menuBar;
    QMenu *menuConnection;
    QMenu *menuAbout;
    QMenu *menuWindow;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        connectAction = new QAction(MainWindow);
        connectAction->setObjectName(QString::fromUtf8("connectAction"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        mdiArea->setGeometry(QRect(0, 90, 800, 491));
        AccLineEdit = new QLineEdit(centralWidget);
        AccLineEdit->setObjectName(QString::fromUtf8("AccLineEdit"));
        AccLineEdit->setGeometry(QRect(90, 40, 113, 20));
        AccLabel = new QLabel(centralWidget);
        AccLabel->setObjectName(QString::fromUtf8("AccLabel"));
        AccLabel->setGeometry(QRect(10, 40, 81, 16));
        Connect2 = new QLineEdit(centralWidget);
        Connect2->setObjectName(QString::fromUtf8("Connect2"));
        Connect2->setGeometry(QRect(680, 8, 113, 20));
        AccLabel_2 = new QLabel(centralWidget);
        AccLabel_2->setObjectName(QString::fromUtf8("AccLabel_2"));
        AccLabel_2->setGeometry(QRect(580, 9, 100, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        menuConnection = new QMenu(menuBar);
        menuConnection->setObjectName(QString::fromUtf8("menuConnection"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        menuWindow = new QMenu(menuBar);
        menuWindow->setObjectName(QString::fromUtf8("menuWindow"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuConnection->menuAction());
        menuBar->addAction(menuWindow->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuConnection->addAction(connectAction);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        connectAction->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        AccLabel->setText(QApplication::translate("MainWindow", "Accelerometers", 0, QApplication::UnicodeUTF8));
        Connect2->setText(QString());
        AccLabel_2->setText(QApplication::translate("MainWindow", "Connection string", 0, QApplication::UnicodeUTF8));
        menuConnection->setTitle(QApplication::translate("MainWindow", "Connection", 0, QApplication::UnicodeUTF8));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        menuWindow->setTitle(QApplication::translate("MainWindow", "Window", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
