//
// Created by msyu on 03.05.2022.
//

#ifndef ROBOT_SENSOR_H
#define ROBOT_SENSOR_H

#include <iostream>

class Sensor {
public:
    Sensor(){}

    virtual ~Sensor(){
        std::cout << "Sensor Destructor!" << std::endl;
    }

    virtual int checkSensor() = 0;
};

class camerasensor : public Sensor {
public:
    int checkSensor() override;
};

class distancesensor : public Sensor {
public:
    int checkSensor() override;
};

class cliffsensor : public Sensor {
public:
    int checkSensor() override;
};


#endif //ROBOT_SENSOR_H
