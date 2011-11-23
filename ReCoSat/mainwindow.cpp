#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adcs.h"
#include "widget/core/ConnectDialog.h"


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


// Define libraries for communication protocol (sockets, etc.)
#ifdef MINGW32
   //#include <winsock.h>
   #include <winsock2.h>
#else
  #include <netinet/in.h>
   #include <sys/socket.h>
   #include <arpa/inet.h>
#endif


// Platform class pointer
adcs* platform;
QTimer* timer;




//******************************************
// TEMPORARY

pthread_t thread_c;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* streamClient(void* arg);
void  quit();

int       is_data_ready = 0;
int       sock;
char*     server_ip = "10.0.0.133";
int       server_port = 8888;


int twoComplement(uint8_t low, int8_t high);

//int num = 0;


// tcp:10.0.0.133;port=8888


//******************************************







MainWindow::MainWindow(QWidget *parent) :    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->connectAction, SIGNAL(triggered()), this, SLOT(openConnectDialog()));


    // Construct an 'adcs' class object
    platform = new adcs;

    // Initialise display of quaternion values
    this->updateQuaternions();



    //timer_ = new QBasicTimer();
    //timer_->start(500,this);
    timer = new QTimer(this);

    timer->setSingleShot(false);
    timer->start(50);

    connect(timer, SIGNAL(timeout()), this, SLOT(updateCaption()));

    // Show fullscreen or maximized based on current settings
    //QSettings settings;
    //setFullScreen(settings.value("mainWindow/defaultFullScreen").toBool());
    //raise();
}




MainWindow::~MainWindow()
{
    delete ui;
    quit();
}




void MainWindow::updateCaption()
{
    //ui->cur_q0_spinbox->setValue(platform->getCurrentQuaternion(0));
    //ui->cur_q1_spinbox->setValue(platform->getCurrentQuaternion(1));
    //ui->cur_q2_spinbox->setValue(platform->getCurrentQuaternion(2));
    //ui->cur_q3_spinbox->setValue(platform->getCurrentQuaternion(3));

    ui->accelX_spinbox->setValue(platform->getAccelerometer(0));
    ui->accelY_spinbox->setValue(platform->getAccelerometer(1));
    ui->accelZ_spinbox->setValue(platform->getAccelerometer(2));

    //ui->gyroX_spinbox->setValue(platform->getGyroscope(0));
    //ui->gyroY_spinbox->setValue(platform->getGyroscope(1));
    //ui->gyroZ_spinbox->setValue(platform->getGyroscope(2));

    //ui->magX_spinbox->setValue(platform->getMagnetometer(0));
    //ui->magY_spinbox->setValue(platform->getMagnetometer(1));
    //ui->magZ_spinbox->setValue(platform->getMagnetometer(2));
}




void MainWindow::timerEvent(QTimerEvent * e)
{
    if(e->timerId() == timer_->timerId())
    {
        //ui->doubleSpinBox1->setValue(platform->getCurrentQuaternion(0));
       // ui->doubleSpinBox2->setValue(platform->getCurrentQuaternion(1));
        //ui->doubleSpinBox3->setValue(platform->getCurrentQuaternion(2));
        //ui->doubleSpinBox4->setValue(platform->getCurrentQuaternion(3));
        ;
    }
}





void MainWindow::openConnectDialog()
{
    ConnectDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted){
        ui->Connect2->setText(dialog.connectionTarget());;


        // tcp:10.0.0.133;port=8888
        //char buffer[100];

       // for(i=0)



        //now open the socket connection

        // run the streaming client as a separate thread
        if (pthread_create(&thread_c, NULL, streamClient, NULL)) {
            quit();
        }

        /*fprintf(stdout, "Press 'q' to quit.\n\n");
        while(key != 'q') {

             * Display the received image, make it thread safe
             * by enclosing it using pthread_mutex_lock

            pthread_mutex_lock(&mutex);
            if (is_data_ready) {
                num++;
                printf("pitch: %d, roll: %d, yaw: %d \n",pitch, roll,yaw);
                printf("number: %d\n\n",num);
                is_data_ready = 0;
            }
            pthread_mutex_unlock(&mutex);

            key = cvWaitKey(10);
        }*/



        // Station::station()->createRobot(dialog.connectionTarget(), dialog.configPath(), dialog.enableAdvancedFunctions());
    }
}





void* streamClient(void* arg)
{
    struct  sockaddr_in server;

    platform->setPitch(100);

    // make this thread cancellable using pthread_cancel()
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);

    /*#ifdef MINGW32
    WSADATA wsadata;
    if (WSAStartup(MAKEWORD(1,1), &wsadata) == SOCKET_ERROR) {
    printf("Error creating socket.");
    return;
    }
    #endif*/

    // create socket
    if ((sock = socket(PF_INET,SOCK_STREAM, 0)) < 0) {
        quit();
    }

    // setup server parameters
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(server_ip);
    server.sin_port = htons(server_port);

    // connect to server
    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        quit();
    }

    char buffer[6];


    double  i, j, k;
    int bytes;

    // start receiving images
    while(1)
    {
       /* // get raw data
       // for (i = 0; i < imgsize; i += bytes) {
            if ((bytes = recv(sock, attitude, sizeof(attitude) , 0)) == -1) {
                quit("recv failed", 1);
            }

            //now send back the values to server


        //}
        //extract the target coordinate

            pitch = attitude[0];
            roll = attitude[1];
            yaw = attitude[2];


            bytes = send(sock,attitude, sizeof(attitude), 0);
        //printf("\n\nbytes: %d\n\n",bytes);
        pthread_mutex_lock(&mutex);

       // is_data_ready = 1;
        if(bytes == sizeof(attitude))
              is_data_ready = 1;
        pthread_mutex_unlock(&mutex);

        // have we terminated yet?
        pthread_testcancel();

        // no, take a rest for a while //
        //usleep(1000);*/




        if ((bytes = recv(sock, buffer, sizeof(buffer) , 0)) == -1) {
            quit();
        }

        i = (double) twoComplement(buffer[0],buffer[1]);
        j = (double) twoComplement(buffer[2],buffer[3]);
        k = (double) twoComplement(buffer[4],buffer[5]);

        platform->setAccelerometer(i,j,k);

        //platform->setCurrentQuaternions((double)i,(double)j,(double)k,0.0);

        //bytes = send(sock, buffer, sizeof(buffer), 0);

        //pthread_mutex_lock(&mutex);

       // is_data_ready = 1;
       // if(bytes == sizeof(buffer))
       //       is_data_ready = 1;
       //pthread_mutex_unlock(&mutex);



    }
}



int twoComplement(uint8_t low, int8_t high)
{
    return low+(high << 8);
}


/**
 * This function provides a way to exit nicely from the system
 */
void quit()
{
    /*if (retval == 0) {
        fprintf(stdout, (msg == NULL ? "" : msg));
        fprintf(stdout, "\n");
    } else {
        fprintf(stderr, (msg == NULL ? "" : msg));
        fprintf(stderr, "\n");
    }*/

    if (sock) close(sock);


    pthread_mutex_destroy(&mutex);

    //exit(retval);
    exit(0);
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
