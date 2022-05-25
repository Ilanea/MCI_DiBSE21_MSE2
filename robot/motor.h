//
// Created by msyu on 03.05.2022.
//

#ifndef ROBOT_MOTOR_H
#define ROBOT_MOTOR_H


class Motor {
protected:
    int Geschwindigkeit;

public:

    ~Motor(){}

    void setSpeed(int speed);
    int getSpeed();
    void emergencyBrake();
};


#endif //ROBOT_MOTOR_H
