#ifndef ADCS_H
#define ADCS_H


// SIMULATION STATE DEFINES
#define STOPPED 0
#define RUNNING 1


// CONTROLLER MODE DEFINES
#define FINE    0
#define COARSE  1





class adcs
{



public:
    adcs();

    void setRoll(double roll);
    void setPitch(double pitch);
    void setYaw(double yaw);
    void setSimulationState(short state);
    void setControllerMode(short mode);

    double getRoll();
    double getPitch();
    double getYaw();
    double getQuaternion(int n);
    short getSimulationState();
    short getControllerMode();



    void computeQuaternions();


//private:
    double roll, pitch, yaw;
    short simulationState;
    short controllerMode;
    double quaternions[4];



};

#endif // ADCS_H
