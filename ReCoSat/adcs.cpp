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






