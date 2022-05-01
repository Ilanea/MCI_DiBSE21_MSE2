//
// Created by msyu on 14.04.2022.
//

#ifndef PROTOTYP5_EXCEPTION_H
#define PROTOTYP5_EXCEPTION_H

#include <stdexcept>

class GameException : public std::runtime_error
{
public:
    using std::runtime_error::runtime_error;
};

class InvalidConstructorException : public GameException
{
public:
    using GameException::GameException;
};

class InvalidGoldException : public GameException
{
public:
    using GameException::GameException;
};

class InvalidNameException : public GameException
{
public:
    using GameException::GameException;
};

class InvalidItemException : public GameException
{
public:
    using GameException::GameException;
};

class InventoryOutOfRange : public GameException
{
public:
    using GameException::GameException;
};

class InventoryFull : public GameException
{
public:
    using GameException::GameException;
};

class CharacterAlreadyExists : public GameException
{
public:
    using GameException::GameException;
};

class CharacterDoesNotExists : public GameException
{
public:
    using GameException::GameException;
};

class ItemAlreadyExists : public GameException
{
public:
    using GameException::GameException;
};

#endif //PROTOTYP5_EXCEPTION_H
