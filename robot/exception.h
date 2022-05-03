//
// Created by msyu on 03.05.2022.
//

#ifndef ROBOT_EXCEPTION_H
#define ROBOT_EXCEPTION_H

#include <stdexcept>

class RobotException : public std::runtime_error
{
public:
    using std::runtime_error::runtime_error;
};

class CriticalDangerException : public RobotException
{
public:
    using RobotException::RobotException;
};

class InternalErrorException : public RobotException
{
public:
    using RobotException::RobotException;
};

class SpeedOutOfRangeException : public RobotException
{
public:
    using RobotException::RobotException;
};

#endif //ROBOT_EXCEPTION_H
