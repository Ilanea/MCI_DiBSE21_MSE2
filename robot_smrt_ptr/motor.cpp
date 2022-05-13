//
// Created by msyu on 03.05.2022.
//

#include <iostream>
#include "motor.h"
#include "exception.h"

void Motor::setSpeed(int speed){
    if(speed >= 0 && speed <= 10){
        this->Geschwindigkeit = speed;
        std::cout << "Wir fahren nun " << speed << " km/h" << std::endl;
    }
    else {
        throw SpeedOutOfRangeException("Motor::setSpeed: Ungueltige Geschwindigkeit!");
    }

}

int Motor::getSpeed(){
    return this->Geschwindigkeit;
}

void Motor::emergencyBrake(){
    this->Geschwindigkeit = 0;
    std::cout << "Kritisches Gefahrenlevel, Notbremsung!" << std::endl;
}