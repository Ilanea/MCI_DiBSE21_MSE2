//
// Created by msyu on 03.05.2022.
//

#ifndef ROBOT_ROBOT_H
#define ROBOT_ROBOT_H

#include "sensor.h"
#include <map>
#include <memory>
#include "motor.h"

class Robot {
protected:
    std::map<const int, Sensor*> Sensors;
    int nextId = 0;
    Motor motor;

public:

    ~Robot(){
        Sensors.clear();
    }

    int addSensor(Sensor* sensor);
    Sensor *getSensor(int id);
    void deleteSensor(int id);
    void eventLoop(int iterations);

};


#endif //ROBOT_ROBOT_H
