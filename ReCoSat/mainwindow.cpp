#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "widget/core/ConnectDialog.h"


MainWindow::MainWindow(QWidget *parent) :    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->connectAction, SIGNAL(triggered()), this, SLOT(openConnectDialog()));


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
