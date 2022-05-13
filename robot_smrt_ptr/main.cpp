#include <iostream>
#include "motor.h"
#include "robot.h"

int main() {

    try{

        Robot robot;

        robot.addSensor(std::shared_ptr<Sensor> (new camerasensor));
        robot.addSensor(std::shared_ptr<Sensor> (new distancesensor));
        robot.addSensor(std::shared_ptr<Sensor> (new cliffsensor));

        robot.eventLoop(10);

        robot.deleteSensor(1);
        robot.deleteSensor(2);
        robot.deleteSensor(3);

    }  catch (std::exception &error){
        std::cerr << "Exception in Main: " << error.what() << std::endl;
    }

}
