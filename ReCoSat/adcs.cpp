#include "adcs.h"
#include <math.h>


#define deg_to_rad(x)   ((x)*M_PI/180)




adcs::adcs()
{
    this->roll = 0;
    this->pitch = 0;
    this->yaw = 0;

    this->simulationState = STOPPED;
    this->controllerMode = COARSE;

    this->computeQuaternions();

    return;
}











void adcs::computeQuaternions()
{
    this->quaternions[0] = cos(deg_to_rad(roll)/2)*cos(deg_to_rad(pitch)/2)*cos(deg_to_rad(yaw)/2)+sin(deg_to_rad(roll)/2)*sin(deg_to_rad(pitch)/2)*sin(deg_to_rad(yaw)/2);
    this->quaternions[1] = sin(deg_to_rad(roll)/2)*cos(deg_to_rad(pitch)/2)*cos(deg_to_rad(yaw)/2)-cos(deg_to_rad(roll)/2)*sin(deg_to_rad(pitch)/2)*sin(deg_to_rad(yaw)/2);
    this->quaternions[2] = cos(deg_to_rad(roll)/2)*sin(deg_to_rad(pitch)/2)*cos(deg_to_rad(yaw)/2)+sin(deg_to_rad(roll)/2)*cos(deg_to_rad(pitch)/2)*sin(deg_to_rad(yaw)/2);
    this->quaternions[3] = cos(deg_to_rad(roll)/2)*cos(deg_to_rad(pitch)/2)*sin(deg_to_rad(yaw)/2)-sin(deg_to_rad(roll)/2)*sin(deg_to_rad(pitch)/2)*cos(deg_to_rad(yaw)/2);
}















/************* SET FUNCTIONS *************/

// Set Roll
void adcs::setRoll(double roll)
{
    this->roll = roll;
    this->computeQuaternions();
}

// Set Pitch
void adcs::setPitch(double pitch)
{
    this->pitch = pitch;
    this->computeQuaternions();
}

// Set Yaw
void adcs::setYaw(double yaw)
{
    this->yaw = yaw;
    this->computeQuaternions();
}

// Set Simulation State
void adcs::setSimulationState(short state)
{
    this->simulationState = state;
}

// Set Controller Mode
void adcs::setControllerMode(short mode)
{
    this->controllerMode = mode;
}

// Set Current Quaternions
void adcs::setCurrentQuaternions(double q0, double q1, double q2, double q3)
{
    this->currentQuaternions[0] = q0;
    this->currentQuaternions[1] = q1;
    this->currentQuaternions[2] = q2;
    this->currentQuaternions[3] = q3;
}

// Set Magnetometer Values
void adcs::setMagnetometer(double arg1, double arg2, double arg3)
{
    this->magnetometer[0] = arg1;
    this->magnetometer[1] = arg2;
    this->magnetometer[2] = arg3;
}

// Set Gyroscope Values
void adcs::setGyroscope(double arg1, double arg2, double arg3)
{
    this->gyroscope[0] = arg1;
    this->gyroscope[1] = arg2;
    this->gyroscope[2] = arg3;
}

// Set Accelerometer Values
void adcs::setAccelerometer(double arg1, double arg2, double arg3)
{
    this->accelerometer[0] = arg1/16384;
    this->accelerometer[1] = arg2/16384;
    this->accelerometer[2] = arg3/16384;
}





/************* GET FUNCTIONS *************/

// Get Pitch
double adcs::getRoll()
{
    return this->roll;
}

// Get Roll
double adcs::getPitch()
{
    return this->pitch;
}

// Get Yaw
double adcs::getYaw()
{
    return this->yaw;
}

// Get Quaternion n
double adcs::getQuaternion(int n)
{
    return this->quaternions[n];
}

// Get Current Quaternion n
double adcs::getCurrentQuaternion(int n)
{
    return this->currentQuaternions[n];
}

// Get Magnetometer Value along the n-axis
double adcs::getMagnetometer(int n)
{
    return this->magnetometer[n];
}

// Get Gyroscope Value along the n-axis
double adcs::getGyroscope(int n)
{
    return this->gyroscope[n];
}

// Get Accelerometer Value along the n-axis
double adcs::getAccelerometer(int n)
{
    return this->accelerometer[n];
}

// Get Simulation State
short adcs::getSimulationState()
{
     return this->simulationState;
}

// Get Controller Mode
short adcs::getControllerMode()
{
    return this->controllerMode;
}






