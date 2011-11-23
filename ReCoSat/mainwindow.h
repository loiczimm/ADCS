#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBasicTimer>
#include <QTimerEvent>
#include <QTimer>


namespace Ui {
    class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    // Opens a dialog for a new connection
    void openConnectDialog();

    void on_simulationButton_clicked();

    void on_roll_spinbox_valueChanged(double arg1);
    void on_pitch_spinbox_valueChanged(double arg1);
    void on_yaw_spinbox_valueChanged(double arg1);

    void on_roll_dial_valueChanged(int value);
    void on_pitch_dial_valueChanged(int value);
    void on_yaw_dial_valueChanged(int value);

    void updateQuaternions();

    void on_coarseAlignment_radiobutton_released();

    void on_fineAlignment_radiobutton_released();

    void updateCaption();



private:
    Ui::MainWindow *ui;
    QBasicTimer * timer_; //TEMP


protected:
    void timerEvent(QTimerEvent *);



};

#endif // MAINWINDOW_H
