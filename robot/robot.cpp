//
// Created by msyu on 03.05.2022.
//

#include <unistd.h>
#include <iostream>
#include "robot.h"
#include "exception.h"


int Robot::addSensor(Sensor* sensor){
    int id = nextId++;
    Sensors.insert({id,sensor});
    return nextId;
}

Sensor *Robot::getSensor(int id){
    if (Sensors.find(id) != Sensors.end()) {
        return Sensors[id];
    }
    return nullptr;
}

void Robot::deleteSensor(int id){
    Sensors.erase(id);
    std::cout << "Sensor #" << id << " geloescht!" << std::endl;
}

void Robot::eventLoop(int iterations){

    int Durchlauf=1;
    int NotfallCount = 0;
    bool Notstopp = false;
    bool SensorError = false;

    while(iterations >= 0){

        std::cout << "Durchlauf #" << Durchlauf  << std::endl;

        int GefahrenLevel = 0;


        if(!Notstopp){
            for(auto &sensor : Sensors){
                try{
                    int NeuesGefahrenLevel = sensor.second->checkSensor();
                    if(NeuesGefahrenLevel > GefahrenLevel){
                        GefahrenLevel = NeuesGefahrenLevel;
                        std::cout << "Neues Hoechstes Gefahrenlevel: " << GefahrenLevel << std::endl;
                    }
                }
                catch (CriticalDangerException &e) {
                    motor.emergencyBrake();
                    Notstopp = true;
                    if(NotfallCount == 0){
                        NotfallCount = 5;
                    }
                }
                catch (InternalErrorException &e){
                    std::cout << "Sensorfehler, setze minimale Geschwindigkeit!" << std::endl;
                    GefahrenLevel = 9;
                    if(!SensorError){
                        SensorError = true;
                        NotfallCount = 5;
                    }
                }
            }
        }

        if(NotfallCount != 0 && Notstopp){
            std::cout << "Wir sind im Notstopp fuer " << 6-NotfallCount << " von 5 Iterationen" << std::endl;
            NotfallCount--;
        }
        else{
            if(NotfallCount != 0 && SensorError) {
                std::cout << "Wir fahren im Notfallmodus fuer " << 6 - NotfallCount << " von 5 Iterationen" << std::endl;
                motor.setSpeed(1);
                NotfallCount--;
            }
            else{
                if(GefahrenLevel == 0){
                    std::cout << "Keine Gefahr, volle Geschwindigkeit!" << std::endl;
                    motor.setSpeed(10);
                }
                else{
                    int NewSpeed = 10 - GefahrenLevel;
                    motor.setSpeed(NewSpeed);
                }
            }
        }

        if(NotfallCount == 0){
            Notstopp = false;
            SensorError = false;
        }

        std::cout << "-------------------------------------------------------" << std::endl;

        if (iterations > 0) {
            iterations--;
            if (iterations <= 0) {
                break;
            }
        }
        sleep(1);
        Durchlauf++;

    }
}