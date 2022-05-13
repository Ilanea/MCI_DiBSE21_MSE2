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
    std::map<const int, std::shared_ptr<Sensor>> Sensors;
    int nextId = 0;
    Motor motor;

public:

    ~Robot(){}

    int addSensor(std::shared_ptr<Sensor> sensor);
    std::shared_ptr<Sensor> getSensor(int id);
    void deleteSensor(int id);
    void eventLoop(int iterations);

};


#endif //ROBOT_ROBOT_H
