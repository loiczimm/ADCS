#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "adcs.h"

#include "widget/core/ConnectDialog.h"





adcs* platform;





MainWindow::MainWindow(QWidget *parent) :    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->connectAction, SIGNAL(triggered()), this, SLOT(openConnectDialog()));


    // Construct an 'adcs' class object
    platform = new adcs;

    // Initialise quaternion values
    this->updateQuaternions();



    // Show fullscreen or maximized based on current settings
    //QSettings settings;
    //setFullScreen(settings.value("mainWindow/defaultFullScreen").toBool());
    //raise();
}







MainWindow::~MainWindow()
{
    delete ui;
}







void MainWindow::openConnectDialog()
{
    ConnectDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted){
        ui->Connect2->setText(dialog.connectionTarget());;

        //now open the socket connection
    }
        //    Station::station()->createRobot(dialog.connectionTarget(), dialog.configPath(), dialog.enableAdvancedFunctions());

}






// Start / run simulation button

void MainWindow::on_simulationButton_clicked()
{
    if( platform->getSimulationState() == STOPPED ){
        ui->simulationButton->setText("Stop Simulation");
        platform->setSimulationState(RUNNING);
    }
    else if( platform->getSimulationState() == RUNNING ){
        ui->simulationButton->setText("Start Simulation");
        platform->setSimulationState(STOPPED);
    }
}


// Update of roll / pitch / yaw after a change of value in the spinboxes

void MainWindow::on_roll_spinbox_valueChanged(double arg1)
{
    platform->setRoll(arg1);
    ui->roll_dial->setValue((int)100*platform->getRoll());
}

void MainWindow::on_pitch_spinbox_valueChanged(double arg1)
{
    platform->setPitch(arg1);
    ui->pitch_dial->setValue((int)100*platform->getPitch());
}

void MainWindow::on_yaw_spinbox_valueChanged(double arg1)
{
    platform->setYaw(arg1);
    ui->yaw_dial->setValue((int)100*platform->getYaw());
}



// Update of roll / pitch / yaw after a change of value in the dials

void MainWindow::on_roll_dial_valueChanged(int value)
{
    platform->setRoll((float)value/100);
    ui->roll_spinbox->setValue(platform->getRoll());
    this->updateQuaternions();
}

void MainWindow::on_pitch_dial_valueChanged(int value)
{
    platform->setPitch((float)value/100);
    ui->pitch_spinbox->setValue(platform->getPitch());
    this->updateQuaternions();
}

void MainWindow::on_yaw_dial_valueChanged(int value)
{
    platform->setYaw((float)value/100);
    ui->yaw_spinbox->setValue(platform->getYaw());
    this->updateQuaternions();
}




void MainWindow::updateQuaternions()
{
    ui->q0_spinbox->setValue(platform->getQuaternion(0));
    ui->q1_spinbox->setValue(platform->getQuaternion(1));
    ui->q2_spinbox->setValue(platform->getQuaternion(2));
    ui->q3_spinbox->setValue(platform->getQuaternion(3));
}





void MainWindow::on_coarseAlignment_radiobutton_released()
{
    platform->setSimulationState(COARSE);
    ui->fineAlignment_radiobutton->setChecked(false);
}




void MainWindow::on_fineAlignment_radiobutton_released()
{
    platform->setSimulationState(FINE);
    ui->coarseAlignment_radiobutton->setChecked(false);
}
