//
// Created by msyu on 21.05.2022.
//

#ifndef FACTORY_EXCEPTION_H
#define FACTORY_EXCEPTION_H

#include <stdexcept>

class FactoryException : public std::runtime_error
{
public:
    using std::runtime_error::runtime_error;
};

class MachineFailureException : public FactoryException
{
public:
    using FactoryException::FactoryException;
};

class MachineExplosionException : public FactoryException
{
public:
    using FactoryException::FactoryException;
};

class MachineOutOfRangeException : public FactoryException
{
public:
    using FactoryException::FactoryException;
};

#endif //FACTORY_EXCEPTION_H
