//
// Created by msyu on 03.05.2022.
//

#include "sensor.h"
#include <iostream>
#include <ctime>
#include <algorithm>
#include "exception.h"

int camerasensor::checkSensor() {

    int randomnumber = rand() % 100 + 1;

    if(randomnumber <= 15){
        throw CriticalDangerException("camerasensor::checkSensor: Zu wenig Abstand!");
    }else if(randomnumber >= 16 && randomnumber <= 20){
        throw InternalErrorException("camerasensor::checkSensor: Internal Error im Abstandsensor.");
    }
    else{
        int Gefahrenlevel = rand() % 7;
        return Gefahrenlevel;
    }

}

int distancesensor::checkSensor() {

    int randomnumber = rand() % 100 + 1;

    if(randomnumber <= 10){
        throw CriticalDangerException("camerasensor::checkSensor: Zu wenig Abstand!");
    }else if(randomnumber >= 11 && randomnumber <= 15){
        throw InternalErrorException("camerasensor::checkSensor: Internal Error im Abstandsensor.");
    }
    else{
        int Gefahrenlevel = rand() % 5;
        return Gefahrenlevel;
    }

}

int cliffsensor::checkSensor() {

    int randomnumber = rand() % 100 + 1;

    if(randomnumber <= 20){
        throw CriticalDangerException("camerasensor::checkSensor: Zu wenig Abstand!");
    }else if(randomnumber >= 21 && randomnumber <= 35){
        throw InternalErrorException("camerasensor::checkSensor: Internal Error im Abstandsensor.");
    }
    else{
        int Gefahrenlevel = rand() % 10;
        return Gefahrenlevel;
    }

}