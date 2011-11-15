/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue 15. Nov 14:25:58 2011
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
#include <QtGui/QDial>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMdiArea>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *connectAction;
    QWidget *centralWidget;
    QMdiArea *mdiArea;
    QLineEdit *AccXLineEdit;
    QLabel *AccLabel;
    QLineEdit *Connect2;
    QLabel *Connect2Label;
    QLabel *MagLabel;
    QLineEdit *MagXLineEdit;
    QLabel *GyrLabel;
    QLineEdit *GyrXLineEdit;
    QLineEdit *AccYLineEdit;
    QLineEdit *MagYLineEdit;
    QLineEdit *GyrYLineEdit;
    QLineEdit *AccZLineEdit;
    QLineEdit *MagZLineEdit;
    QLineEdit *GyrZLineEdit;
    QDial *dial;
    QDial *dial_2;
    QDial *dial_3;
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QLabel *rollLabel;
    QLabel *pitchLabel;
    QLabel *yawLabel;
    QMenuBar *menuBar;
    QMenu *menuConnection;
    QMenu *menuAbout;
    QMenu *menuWindow;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/graphics/resources/logoSC.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAnimated(false);
        connectAction = new QAction(MainWindow);
        connectAction->setObjectName(QString::fromUtf8("connectAction"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        mdiArea->setGeometry(QRect(0, 90, 800, 491));
        AccXLineEdit = new QLineEdit(centralWidget);
        AccXLineEdit->setObjectName(QString::fromUtf8("AccXLineEdit"));
        AccXLineEdit->setGeometry(QRect(90, 20, 71, 20));
        AccXLineEdit->setAcceptDrops(true);
        AccXLineEdit->setReadOnly(true);
        AccLabel = new QLabel(centralWidget);
        AccLabel->setObjectName(QString::fromUtf8("AccLabel"));
        AccLabel->setGeometry(QRect(10, 20, 81, 16));
        Connect2 = new QLineEdit(centralWidget);
        Connect2->setObjectName(QString::fromUtf8("Connect2"));
        Connect2->setGeometry(QRect(680, 8, 113, 20));
        Connect2->setReadOnly(true);
        Connect2Label = new QLabel(centralWidget);
        Connect2Label->setObjectName(QString::fromUtf8("Connect2Label"));
        Connect2Label->setGeometry(QRect(580, 9, 100, 20));
        MagLabel = new QLabel(centralWidget);
        MagLabel->setObjectName(QString::fromUtf8("MagLabel"));
        MagLabel->setGeometry(QRect(10, 40, 81, 16));
        MagXLineEdit = new QLineEdit(centralWidget);
        MagXLineEdit->setObjectName(QString::fromUtf8("MagXLineEdit"));
        MagXLineEdit->setGeometry(QRect(90, 40, 71, 20));
        MagXLineEdit->setReadOnly(true);
        GyrLabel = new QLabel(centralWidget);
        GyrLabel->setObjectName(QString::fromUtf8("GyrLabel"));
        GyrLabel->setGeometry(QRect(10, 60, 81, 16));
        GyrXLineEdit = new QLineEdit(centralWidget);
        GyrXLineEdit->setObjectName(QString::fromUtf8("GyrXLineEdit"));
        GyrXLineEdit->setGeometry(QRect(90, 60, 71, 20));
        GyrXLineEdit->setReadOnly(true);
        AccYLineEdit = new QLineEdit(centralWidget);
        AccYLineEdit->setObjectName(QString::fromUtf8("AccYLineEdit"));
        AccYLineEdit->setGeometry(QRect(170, 20, 71, 20));
        AccYLineEdit->setReadOnly(true);
        MagYLineEdit = new QLineEdit(centralWidget);
        MagYLineEdit->setObjectName(QString::fromUtf8("MagYLineEdit"));
        MagYLineEdit->setGeometry(QRect(170, 40, 71, 20));
        MagYLineEdit->setReadOnly(true);
        GyrYLineEdit = new QLineEdit(centralWidget);
        GyrYLineEdit->setObjectName(QString::fromUtf8("GyrYLineEdit"));
        GyrYLineEdit->setGeometry(QRect(170, 60, 71, 20));
        GyrYLineEdit->setReadOnly(true);
        AccZLineEdit = new QLineEdit(centralWidget);
        AccZLineEdit->setObjectName(QString::fromUtf8("AccZLineEdit"));
        AccZLineEdit->setGeometry(QRect(250, 20, 71, 20));
        AccZLineEdit->setReadOnly(true);
        MagZLineEdit = new QLineEdit(centralWidget);
        MagZLineEdit->setObjectName(QString::fromUtf8("MagZLineEdit"));
        MagZLineEdit->setGeometry(QRect(250, 40, 71, 20));
        MagZLineEdit->setReadOnly(true);
        GyrZLineEdit = new QLineEdit(centralWidget);
        GyrZLineEdit->setObjectName(QString::fromUtf8("GyrZLineEdit"));
        GyrZLineEdit->setGeometry(QRect(250, 60, 71, 20));
        GyrZLineEdit->setReadOnly(true);
        dial = new QDial(centralWidget);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setGeometry(QRect(356, 20, 50, 64));
        dial_2 = new QDial(centralWidget);
        dial_2->setObjectName(QString::fromUtf8("dial_2"));
        dial_2->setGeometry(QRect(416, 20, 50, 64));
        dial_3 = new QDial(centralWidget);
        dial_3->setObjectName(QString::fromUtf8("dial_3"));
        dial_3->setGeometry(QRect(476, 20, 50, 64));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(580, 33, 160, 19));
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider_2 = new QSlider(centralWidget);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(580, 53, 160, 19));
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        rollLabel = new QLabel(centralWidget);
        rollLabel->setObjectName(QString::fromUtf8("rollLabel"));
        rollLabel->setGeometry(QRect(371, 10, 30, 20));
        pitchLabel = new QLabel(centralWidget);
        pitchLabel->setObjectName(QString::fromUtf8("pitchLabel"));
        pitchLabel->setGeometry(QRect(429, 10, 30, 20));
        yawLabel = new QLabel(centralWidget);
        yawLabel->setObjectName(QString::fromUtf8("yawLabel"));
        yawLabel->setGeometry(QRect(490, 10, 30, 20));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ReCoSatV1", 0, QApplication::UnicodeUTF8));
        connectAction->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        AccLabel->setText(QApplication::translate("MainWindow", "Accelerometers", 0, QApplication::UnicodeUTF8));
        Connect2->setText(QString());
        Connect2Label->setText(QApplication::translate("MainWindow", "Connection string", 0, QApplication::UnicodeUTF8));
        MagLabel->setText(QApplication::translate("MainWindow", "Magnetometers", 0, QApplication::UnicodeUTF8));
        GyrLabel->setText(QApplication::translate("MainWindow", "Gyroscopes", 0, QApplication::UnicodeUTF8));
        rollLabel->setText(QApplication::translate("MainWindow", "Roll", 0, QApplication::UnicodeUTF8));
        pitchLabel->setText(QApplication::translate("MainWindow", "Pitch", 0, QApplication::UnicodeUTF8));
        yawLabel->setText(QApplication::translate("MainWindow", "Yaw", 0, QApplication::UnicodeUTF8));
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
