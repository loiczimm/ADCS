/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed 23. Nov 21:29:23 2011
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
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *connectAction;
    QWidget *centralWidget;
    QLineEdit *Connect2;
    QLabel *AccLabel_2;
    QPushButton *simulationButton;
    QTabWidget *tabWidget;
    QWidget *attitudeControlTab;
    QGroupBox *currentQuaternionBox;
    QLabel *cur_q0_label;
    QLabel *cur_q1_label;
    QLabel *cur_q2_label;
    QLabel *cur_q3_label;
    QDoubleSpinBox *cur_q0_spinbox;
    QDoubleSpinBox *cur_q1_spinbox;
    QDoubleSpinBox *cur_q2_spinbox;
    QDoubleSpinBox *cur_q3_spinbox;
    QGroupBox *setupQuaternionBox;
    QDial *roll_dial;
    QDial *pitch_dial;
    QDial *yaw_dial;
    QLabel *roll_label;
    QLabel *yaw_label;
    QLabel *pitch_label;
    QLabel *q0_label;
    QLabel *q1_label;
    QLabel *q2_label;
    QLabel *q3_label;
    QFrame *horizontalSeparation;
    QDoubleSpinBox *roll_spinbox;
    QDoubleSpinBox *pitch_spinbox;
    QDoubleSpinBox *yaw_spinbox;
    QDoubleSpinBox *q3_spinbox;
    QDoubleSpinBox *q2_spinbox;
    QDoubleSpinBox *q1_spinbox;
    QDoubleSpinBox *q0_spinbox;
    QRadioButton *coarseAlignment_radiobutton;
    QRadioButton *fineAlignment_radiobutton;
    QFrame *line;
    QLabel *label_5;
    QWidget *sensorReadingsTab;
    QGroupBox *accelerometerBox;
    QLabel *accelX_label;
    QLabel *accelY_label;
    QLabel *accelZ_label;
    QDoubleSpinBox *accelX_spinbox;
    QDoubleSpinBox *accelY_spinbox;
    QDoubleSpinBox *accelZ_spinbox;
    QProgressBar *progressBarAccX;
    QProgressBar *progressBarAccY;
    QProgressBar *progressBarAccZ;
    QGroupBox *gyroscopeBox;
    QLabel *gyroX_label;
    QLabel *gyroY_label;
    QLabel *gyroZ_label;
    QDoubleSpinBox *gyroX_spinbox;
    QDoubleSpinBox *gyroY_spinbox;
    QDoubleSpinBox *gyroZ_spinbox;
    QGroupBox *magnetoBox;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QDoubleSpinBox *magX_spinbox;
    QDoubleSpinBox *magY_spinbox;
    QDoubleSpinBox *magZ_spinbox;
    QGroupBox *groupBox;
    QProgressBar *progressBar;
    QProgressBar *progressBar_2;
    QProgressBar *progressBar_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QGraphicsView *graphicsView;
    QLCDNumber *lcdNumber;
    QLabel *state_label;
    QMenuBar *menuBar;
    QMenu *menuConnection;
    QMenu *menuAbout;
    QMenu *menuWindow;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 539);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/graphic/logoSC.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setToolButtonStyle(Qt::ToolButtonFollowStyle);
        connectAction = new QAction(MainWindow);
        connectAction->setObjectName(QString::fromUtf8("connectAction"));
        connectAction->setShortcutContext(Qt::WidgetShortcut);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Connect2 = new QLineEdit(centralWidget);
        Connect2->setObjectName(QString::fromUtf8("Connect2"));
        Connect2->setGeometry(QRect(540, 10, 241, 20));
        AccLabel_2 = new QLabel(centralWidget);
        AccLabel_2->setObjectName(QString::fromUtf8("AccLabel_2"));
        AccLabel_2->setGeometry(QRect(420, 10, 121, 20));
        simulationButton = new QPushButton(centralWidget);
        simulationButton->setObjectName(QString::fromUtf8("simulationButton"));
        simulationButton->setGeometry(QRect(10, 10, 191, 32));
        simulationButton->setCheckable(false);
        simulationButton->setChecked(false);
        simulationButton->setAutoExclusive(false);
        simulationButton->setAutoDefault(false);
        simulationButton->setDefault(false);
        simulationButton->setFlat(false);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 50, 761, 441));
        attitudeControlTab = new QWidget();
        attitudeControlTab->setObjectName(QString::fromUtf8("attitudeControlTab"));
        currentQuaternionBox = new QGroupBox(attitudeControlTab);
        currentQuaternionBox->setObjectName(QString::fromUtf8("currentQuaternionBox"));
        currentQuaternionBox->setGeometry(QRect(290, 250, 431, 141));
        cur_q0_label = new QLabel(currentQuaternionBox);
        cur_q0_label->setObjectName(QString::fromUtf8("cur_q0_label"));
        cur_q0_label->setGeometry(QRect(30, 30, 71, 16));
        cur_q0_label->setAlignment(Qt::AlignCenter);
        cur_q1_label = new QLabel(currentQuaternionBox);
        cur_q1_label->setObjectName(QString::fromUtf8("cur_q1_label"));
        cur_q1_label->setGeometry(QRect(130, 30, 71, 16));
        cur_q1_label->setAlignment(Qt::AlignCenter);
        cur_q2_label = new QLabel(currentQuaternionBox);
        cur_q2_label->setObjectName(QString::fromUtf8("cur_q2_label"));
        cur_q2_label->setGeometry(QRect(230, 30, 71, 16));
        cur_q2_label->setAlignment(Qt::AlignCenter);
        cur_q3_label = new QLabel(currentQuaternionBox);
        cur_q3_label->setObjectName(QString::fromUtf8("cur_q3_label"));
        cur_q3_label->setGeometry(QRect(330, 30, 71, 16));
        cur_q3_label->setAlignment(Qt::AlignCenter);
        cur_q0_spinbox = new QDoubleSpinBox(currentQuaternionBox);
        cur_q0_spinbox->setObjectName(QString::fromUtf8("cur_q0_spinbox"));
        cur_q0_spinbox->setGeometry(QRect(30, 50, 71, 25));
        cur_q0_spinbox->setReadOnly(true);
        cur_q1_spinbox = new QDoubleSpinBox(currentQuaternionBox);
        cur_q1_spinbox->setObjectName(QString::fromUtf8("cur_q1_spinbox"));
        cur_q1_spinbox->setGeometry(QRect(130, 50, 71, 25));
        cur_q1_spinbox->setReadOnly(true);
        cur_q2_spinbox = new QDoubleSpinBox(currentQuaternionBox);
        cur_q2_spinbox->setObjectName(QString::fromUtf8("cur_q2_spinbox"));
        cur_q2_spinbox->setGeometry(QRect(230, 50, 71, 25));
        cur_q2_spinbox->setReadOnly(true);
        cur_q3_spinbox = new QDoubleSpinBox(currentQuaternionBox);
        cur_q3_spinbox->setObjectName(QString::fromUtf8("cur_q3_spinbox"));
        cur_q3_spinbox->setGeometry(QRect(330, 50, 71, 25));
        cur_q3_spinbox->setReadOnly(true);
        setupQuaternionBox = new QGroupBox(attitudeControlTab);
        setupQuaternionBox->setObjectName(QString::fromUtf8("setupQuaternionBox"));
        setupQuaternionBox->setGeometry(QRect(290, 10, 431, 231));
        roll_dial = new QDial(setupQuaternionBox);
        roll_dial->setObjectName(QString::fromUtf8("roll_dial"));
        roll_dial->setGeometry(QRect(40, 30, 71, 91));
        roll_dial->setMinimum(-4500);
        roll_dial->setMaximum(4500);
        roll_dial->setPageStep(10);
        roll_dial->setValue(0);
        roll_dial->setOrientation(Qt::Horizontal);
        pitch_dial = new QDial(setupQuaternionBox);
        pitch_dial->setObjectName(QString::fromUtf8("pitch_dial"));
        pitch_dial->setGeometry(QRect(180, 30, 71, 91));
        pitch_dial->setAutoFillBackground(false);
        pitch_dial->setMinimum(-4500);
        pitch_dial->setMaximum(4500);
        pitch_dial->setSingleStep(1);
        pitch_dial->setPageStep(10);
        pitch_dial->setInvertedAppearance(false);
        pitch_dial->setInvertedControls(false);
        pitch_dial->setWrapping(false);
        pitch_dial->setNotchTarget(3.7);
        pitch_dial->setNotchesVisible(false);
        yaw_dial = new QDial(setupQuaternionBox);
        yaw_dial->setObjectName(QString::fromUtf8("yaw_dial"));
        yaw_dial->setGeometry(QRect(320, 30, 71, 91));
        yaw_dial->setMinimum(-18000);
        yaw_dial->setMaximum(18000);
        yaw_dial->setWrapping(true);
        yaw_dial->setNotchesVisible(false);
        roll_label = new QLabel(setupQuaternionBox);
        roll_label->setObjectName(QString::fromUtf8("roll_label"));
        roll_label->setGeometry(QRect(50, 30, 51, 16));
        roll_label->setAlignment(Qt::AlignCenter);
        yaw_label = new QLabel(setupQuaternionBox);
        yaw_label->setObjectName(QString::fromUtf8("yaw_label"));
        yaw_label->setGeometry(QRect(330, 30, 51, 16));
        yaw_label->setAlignment(Qt::AlignCenter);
        pitch_label = new QLabel(setupQuaternionBox);
        pitch_label->setObjectName(QString::fromUtf8("pitch_label"));
        pitch_label->setGeometry(QRect(190, 30, 51, 16));
        pitch_label->setAlignment(Qt::AlignCenter);
        q0_label = new QLabel(setupQuaternionBox);
        q0_label->setObjectName(QString::fromUtf8("q0_label"));
        q0_label->setGeometry(QRect(30, 170, 71, 16));
        q0_label->setAlignment(Qt::AlignCenter);
        q1_label = new QLabel(setupQuaternionBox);
        q1_label->setObjectName(QString::fromUtf8("q1_label"));
        q1_label->setGeometry(QRect(130, 170, 71, 16));
        q1_label->setAlignment(Qt::AlignCenter);
        q2_label = new QLabel(setupQuaternionBox);
        q2_label->setObjectName(QString::fromUtf8("q2_label"));
        q2_label->setGeometry(QRect(230, 170, 71, 16));
        q2_label->setAlignment(Qt::AlignCenter);
        q3_label = new QLabel(setupQuaternionBox);
        q3_label->setObjectName(QString::fromUtf8("q3_label"));
        q3_label->setGeometry(QRect(330, 170, 71, 16));
        q3_label->setAlignment(Qt::AlignCenter);
        horizontalSeparation = new QFrame(setupQuaternionBox);
        horizontalSeparation->setObjectName(QString::fromUtf8("horizontalSeparation"));
        horizontalSeparation->setGeometry(QRect(27, 150, 381, 20));
        horizontalSeparation->setFrameShape(QFrame::HLine);
        horizontalSeparation->setFrameShadow(QFrame::Sunken);
        roll_spinbox = new QDoubleSpinBox(setupQuaternionBox);
        roll_spinbox->setObjectName(QString::fromUtf8("roll_spinbox"));
        roll_spinbox->setGeometry(QRect(30, 120, 91, 25));
        roll_spinbox->setMinimum(-45);
        roll_spinbox->setMaximum(45);
        roll_spinbox->setValue(0);
        pitch_spinbox = new QDoubleSpinBox(setupQuaternionBox);
        pitch_spinbox->setObjectName(QString::fromUtf8("pitch_spinbox"));
        pitch_spinbox->setGeometry(QRect(170, 120, 91, 25));
        pitch_spinbox->setDecimals(2);
        pitch_spinbox->setMinimum(-45);
        pitch_spinbox->setMaximum(45);
        yaw_spinbox = new QDoubleSpinBox(setupQuaternionBox);
        yaw_spinbox->setObjectName(QString::fromUtf8("yaw_spinbox"));
        yaw_spinbox->setGeometry(QRect(310, 120, 91, 25));
        yaw_spinbox->setMinimum(-180);
        yaw_spinbox->setMaximum(180);
        q3_spinbox = new QDoubleSpinBox(setupQuaternionBox);
        q3_spinbox->setObjectName(QString::fromUtf8("q3_spinbox"));
        q3_spinbox->setGeometry(QRect(330, 190, 71, 25));
        q3_spinbox->setReadOnly(true);
        q3_spinbox->setDecimals(3);
        q3_spinbox->setMinimum(-1);
        q3_spinbox->setMaximum(1);
        q2_spinbox = new QDoubleSpinBox(setupQuaternionBox);
        q2_spinbox->setObjectName(QString::fromUtf8("q2_spinbox"));
        q2_spinbox->setGeometry(QRect(230, 190, 71, 25));
        q2_spinbox->setReadOnly(true);
        q2_spinbox->setDecimals(3);
        q2_spinbox->setMinimum(-1);
        q2_spinbox->setMaximum(1);
        q1_spinbox = new QDoubleSpinBox(setupQuaternionBox);
        q1_spinbox->setObjectName(QString::fromUtf8("q1_spinbox"));
        q1_spinbox->setGeometry(QRect(130, 190, 71, 25));
        q1_spinbox->setReadOnly(true);
        q1_spinbox->setDecimals(3);
        q1_spinbox->setMinimum(-1);
        q1_spinbox->setMaximum(1);
        q0_spinbox = new QDoubleSpinBox(setupQuaternionBox);
        q0_spinbox->setObjectName(QString::fromUtf8("q0_spinbox"));
        q0_spinbox->setGeometry(QRect(30, 190, 71, 25));
        q0_spinbox->setReadOnly(true);
        q0_spinbox->setDecimals(3);
        q0_spinbox->setMinimum(-1);
        q0_spinbox->setMaximum(1);
        coarseAlignment_radiobutton = new QRadioButton(attitudeControlTab);
        coarseAlignment_radiobutton->setObjectName(QString::fromUtf8("coarseAlignment_radiobutton"));
        coarseAlignment_radiobutton->setGeometry(QRect(30, 20, 131, 20));
        coarseAlignment_radiobutton->setChecked(true);
        fineAlignment_radiobutton = new QRadioButton(attitudeControlTab);
        fineAlignment_radiobutton->setObjectName(QString::fromUtf8("fineAlignment_radiobutton"));
        fineAlignment_radiobutton->setGeometry(QRect(30, 50, 131, 20));
        line = new QFrame(attitudeControlTab);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(250, 20, 20, 381));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label_5 = new QLabel(attitudeControlTab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(80, 240, 81, 16));
        QFont font;
        font.setItalic(true);
        label_5->setFont(font);
        tabWidget->addTab(attitudeControlTab, QString());
        sensorReadingsTab = new QWidget();
        sensorReadingsTab->setObjectName(QString::fromUtf8("sensorReadingsTab"));
        accelerometerBox = new QGroupBox(sensorReadingsTab);
        accelerometerBox->setObjectName(QString::fromUtf8("accelerometerBox"));
        accelerometerBox->setGeometry(QRect(380, 10, 161, 191));
        accelX_label = new QLabel(accelerometerBox);
        accelX_label->setObjectName(QString::fromUtf8("accelX_label"));
        accelX_label->setGeometry(QRect(0, 40, 41, 21));
        accelX_label->setAlignment(Qt::AlignCenter);
        accelY_label = new QLabel(accelerometerBox);
        accelY_label->setObjectName(QString::fromUtf8("accelY_label"));
        accelY_label->setGeometry(QRect(0, 90, 41, 21));
        accelY_label->setAlignment(Qt::AlignCenter);
        accelZ_label = new QLabel(accelerometerBox);
        accelZ_label->setObjectName(QString::fromUtf8("accelZ_label"));
        accelZ_label->setGeometry(QRect(0, 140, 41, 21));
        accelZ_label->setAlignment(Qt::AlignCenter);
        accelX_spinbox = new QDoubleSpinBox(accelerometerBox);
        accelX_spinbox->setObjectName(QString::fromUtf8("accelX_spinbox"));
        accelX_spinbox->setGeometry(QRect(40, 40, 101, 25));
        accelX_spinbox->setReadOnly(true);
        accelX_spinbox->setDecimals(4);
        accelX_spinbox->setMinimum(-2);
        accelX_spinbox->setMaximum(2);
        accelY_spinbox = new QDoubleSpinBox(accelerometerBox);
        accelY_spinbox->setObjectName(QString::fromUtf8("accelY_spinbox"));
        accelY_spinbox->setGeometry(QRect(40, 90, 101, 25));
        accelY_spinbox->setReadOnly(true);
        accelY_spinbox->setDecimals(4);
        accelY_spinbox->setMinimum(-2);
        accelY_spinbox->setMaximum(2);
        accelZ_spinbox = new QDoubleSpinBox(accelerometerBox);
        accelZ_spinbox->setObjectName(QString::fromUtf8("accelZ_spinbox"));
        accelZ_spinbox->setGeometry(QRect(40, 140, 101, 25));
        accelZ_spinbox->setReadOnly(true);
        accelZ_spinbox->setDecimals(4);
        accelZ_spinbox->setMinimum(-2);
        accelZ_spinbox->setMaximum(2);
        progressBarAccX = new QProgressBar(accelerometerBox);
        progressBarAccX->setObjectName(QString::fromUtf8("progressBarAccX"));
        progressBarAccX->setGeometry(QRect(40, 70, 101, 16));
        progressBarAccX->setMaximum(1000);
        progressBarAccX->setValue(0);
        progressBarAccX->setTextVisible(false);
        progressBarAccX->setOrientation(Qt::Horizontal);
        progressBarAccX->setInvertedAppearance(false);
        progressBarAccY = new QProgressBar(accelerometerBox);
        progressBarAccY->setObjectName(QString::fromUtf8("progressBarAccY"));
        progressBarAccY->setGeometry(QRect(40, 120, 101, 16));
        progressBarAccY->setMaximum(1000);
        progressBarAccY->setValue(0);
        progressBarAccY->setTextVisible(false);
        progressBarAccY->setOrientation(Qt::Horizontal);
        progressBarAccY->setInvertedAppearance(false);
        progressBarAccZ = new QProgressBar(accelerometerBox);
        progressBarAccZ->setObjectName(QString::fromUtf8("progressBarAccZ"));
        progressBarAccZ->setGeometry(QRect(40, 170, 101, 16));
        progressBarAccZ->setMaximum(1000);
        progressBarAccZ->setValue(0);
        progressBarAccZ->setTextVisible(false);
        progressBarAccZ->setOrientation(Qt::Horizontal);
        progressBarAccZ->setInvertedAppearance(false);
        gyroscopeBox = new QGroupBox(sensorReadingsTab);
        gyroscopeBox->setObjectName(QString::fromUtf8("gyroscopeBox"));
        gyroscopeBox->setGeometry(QRect(380, 210, 161, 191));
        gyroX_label = new QLabel(gyroscopeBox);
        gyroX_label->setObjectName(QString::fromUtf8("gyroX_label"));
        gyroX_label->setGeometry(QRect(0, 40, 41, 21));
        gyroX_label->setAlignment(Qt::AlignCenter);
        gyroY_label = new QLabel(gyroscopeBox);
        gyroY_label->setObjectName(QString::fromUtf8("gyroY_label"));
        gyroY_label->setGeometry(QRect(0, 90, 41, 21));
        gyroY_label->setAlignment(Qt::AlignCenter);
        gyroZ_label = new QLabel(gyroscopeBox);
        gyroZ_label->setObjectName(QString::fromUtf8("gyroZ_label"));
        gyroZ_label->setGeometry(QRect(0, 140, 41, 21));
        gyroZ_label->setAlignment(Qt::AlignCenter);
        gyroX_spinbox = new QDoubleSpinBox(gyroscopeBox);
        gyroX_spinbox->setObjectName(QString::fromUtf8("gyroX_spinbox"));
        gyroX_spinbox->setGeometry(QRect(40, 40, 101, 25));
        gyroX_spinbox->setReadOnly(true);
        gyroY_spinbox = new QDoubleSpinBox(gyroscopeBox);
        gyroY_spinbox->setObjectName(QString::fromUtf8("gyroY_spinbox"));
        gyroY_spinbox->setGeometry(QRect(40, 90, 101, 25));
        gyroY_spinbox->setReadOnly(true);
        gyroZ_spinbox = new QDoubleSpinBox(gyroscopeBox);
        gyroZ_spinbox->setObjectName(QString::fromUtf8("gyroZ_spinbox"));
        gyroZ_spinbox->setGeometry(QRect(40, 140, 101, 25));
        gyroZ_spinbox->setReadOnly(true);
        magnetoBox = new QGroupBox(sensorReadingsTab);
        magnetoBox->setObjectName(QString::fromUtf8("magnetoBox"));
        magnetoBox->setGeometry(QRect(560, 210, 161, 191));
        label_7 = new QLabel(magnetoBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(0, 40, 41, 21));
        label_7->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(magnetoBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(0, 90, 41, 21));
        label_8->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(magnetoBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(0, 140, 41, 21));
        label_9->setAlignment(Qt::AlignCenter);
        magX_spinbox = new QDoubleSpinBox(magnetoBox);
        magX_spinbox->setObjectName(QString::fromUtf8("magX_spinbox"));
        magX_spinbox->setGeometry(QRect(40, 40, 101, 25));
        magX_spinbox->setReadOnly(true);
        magY_spinbox = new QDoubleSpinBox(magnetoBox);
        magY_spinbox->setObjectName(QString::fromUtf8("magY_spinbox"));
        magY_spinbox->setGeometry(QRect(40, 90, 101, 25));
        magY_spinbox->setReadOnly(true);
        magZ_spinbox = new QDoubleSpinBox(magnetoBox);
        magZ_spinbox->setObjectName(QString::fromUtf8("magZ_spinbox"));
        magZ_spinbox->setGeometry(QRect(40, 140, 101, 25));
        magZ_spinbox->setReadOnly(true);
        groupBox = new QGroupBox(sensorReadingsTab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(560, 10, 161, 191));
        progressBar = new QProgressBar(groupBox);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(20, 40, 21, 111));
        progressBar->setContextMenuPolicy(Qt::DefaultContextMenu);
        progressBar->setLayoutDirection(Qt::LeftToRight);
        progressBar->setAutoFillBackground(false);
        progressBar->setValue(24);
        progressBar->setOrientation(Qt::Vertical);
        progressBar->setInvertedAppearance(false);
        progressBar_2 = new QProgressBar(groupBox);
        progressBar_2->setObjectName(QString::fromUtf8("progressBar_2"));
        progressBar_2->setGeometry(QRect(70, 40, 21, 111));
        progressBar_2->setValue(61);
        progressBar_2->setOrientation(Qt::Vertical);
        progressBar_3 = new QProgressBar(groupBox);
        progressBar_3->setObjectName(QString::fromUtf8("progressBar_3"));
        progressBar_3->setGeometry(QRect(120, 40, 21, 111));
        progressBar_3->setValue(43);
        progressBar_3->setOrientation(Qt::Vertical);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 150, 41, 21));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 150, 41, 21));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(110, 150, 41, 21));
        label_3->setAlignment(Qt::AlignCenter);
        graphicsView = new QGraphicsView(sensorReadingsTab);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(30, 30, 321, 211));
        lcdNumber = new QLCDNumber(sensorReadingsTab);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(80, 340, 64, 23));
        tabWidget->addTab(sensorReadingsTab, QString());
        state_label = new QLabel(centralWidget);
        state_label->setObjectName(QString::fromUtf8("state_label"));
        state_label->setGeometry(QRect(230, 20, 141, 16));
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

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        connectAction->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        Connect2->setText(QString());
        AccLabel_2->setText(QApplication::translate("MainWindow", "Connection string", 0, QApplication::UnicodeUTF8));
        simulationButton->setText(QApplication::translate("MainWindow", "Start Simulation", 0, QApplication::UnicodeUTF8));
        currentQuaternionBox->setTitle(QApplication::translate("MainWindow", "Current Quaternions", 0, QApplication::UnicodeUTF8));
        cur_q0_label->setText(QApplication::translate("MainWindow", "q0", 0, QApplication::UnicodeUTF8));
        cur_q1_label->setText(QApplication::translate("MainWindow", "q1", 0, QApplication::UnicodeUTF8));
        cur_q2_label->setText(QApplication::translate("MainWindow", "q2", 0, QApplication::UnicodeUTF8));
        cur_q3_label->setText(QApplication::translate("MainWindow", "q3", 0, QApplication::UnicodeUTF8));
        setupQuaternionBox->setTitle(QApplication::translate("MainWindow", "Quaternion Setup", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        roll_dial->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_ACCESSIBILITY
        pitch_dial->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        pitch_dial->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        roll_label->setText(QApplication::translate("MainWindow", "Roll", 0, QApplication::UnicodeUTF8));
        yaw_label->setText(QApplication::translate("MainWindow", "Yaw", 0, QApplication::UnicodeUTF8));
        pitch_label->setText(QApplication::translate("MainWindow", "Pitch", 0, QApplication::UnicodeUTF8));
        q0_label->setText(QApplication::translate("MainWindow", "q0", 0, QApplication::UnicodeUTF8));
        q1_label->setText(QApplication::translate("MainWindow", "q1", 0, QApplication::UnicodeUTF8));
        q2_label->setText(QApplication::translate("MainWindow", "q2", 0, QApplication::UnicodeUTF8));
        q3_label->setText(QApplication::translate("MainWindow", "q3", 0, QApplication::UnicodeUTF8));
        coarseAlignment_radiobutton->setText(QApplication::translate("MainWindow", "Coarse alignment", 0, QApplication::UnicodeUTF8));
        fineAlignment_radiobutton->setText(QApplication::translate("MainWindow", "Fine alignment", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "More later...", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(attitudeControlTab), QApplication::translate("MainWindow", "Attitude Control", 0, QApplication::UnicodeUTF8));
        accelerometerBox->setTitle(QApplication::translate("MainWindow", "Accelerometers", 0, QApplication::UnicodeUTF8));
        accelX_label->setText(QApplication::translate("MainWindow", "x", 0, QApplication::UnicodeUTF8));
        accelY_label->setText(QApplication::translate("MainWindow", "y", 0, QApplication::UnicodeUTF8));
        accelZ_label->setText(QApplication::translate("MainWindow", "z", 0, QApplication::UnicodeUTF8));
        progressBarAccX->setFormat(QApplication::translate("MainWindow", "%p%", 0, QApplication::UnicodeUTF8));
        progressBarAccY->setFormat(QApplication::translate("MainWindow", "%p%", 0, QApplication::UnicodeUTF8));
        progressBarAccZ->setFormat(QApplication::translate("MainWindow", "%p%", 0, QApplication::UnicodeUTF8));
        gyroscopeBox->setTitle(QApplication::translate("MainWindow", "Gyroscopes", 0, QApplication::UnicodeUTF8));
        gyroX_label->setText(QApplication::translate("MainWindow", "x", 0, QApplication::UnicodeUTF8));
        gyroY_label->setText(QApplication::translate("MainWindow", "y", 0, QApplication::UnicodeUTF8));
        gyroZ_label->setText(QApplication::translate("MainWindow", "z", 0, QApplication::UnicodeUTF8));
        magnetoBox->setTitle(QApplication::translate("MainWindow", "Magnetometers", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "x", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "y", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "z", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Wheel speeds", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        progressBar->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        progressBar->setFormat(QApplication::translate("MainWindow", "%p%", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "w1", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "w2", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "w3", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(sensorReadingsTab), QApplication::translate("MainWindow", "Sensor Readings", 0, QApplication::UnicodeUTF8));
        state_label->setText(QApplication::translate("MainWindow", "STATE: Not connected", 0, QApplication::UnicodeUTF8));
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
