/**
    Mini Valgrind
    Exceptions.h

    @author Artem Mukhin
*/

#pragma once

#include <stdexcept>
#include <string>

class NotInitVarException: public std::runtime_error
{
public:
    NotInitVarException()
        : std::runtime_error("Not initialized variable")
    {}
    NotInitVarException(std::string s)
        : std::runtime_error("Not initialized variable: " + s)
    {}
};

class InvalidTypeException: public std::runtime_error
{
public:
    InvalidTypeException()
        : std::runtime_error("Invalid value's type")
    {}
    InvalidTypeException(std::string s)
        : std::runtime_error("Invalid value's type: " + s)
    {}
};

class EscapeFromBoundsException: public std::runtime_error
{
public:
    EscapeFromBoundsException()
        : std::runtime_error("Escape from the bounds of array")
    {}
    EscapeFromBoundsException(std::string s)
        : std::runtime_error("Escape from the bounds of array: " + s)
    {}
};

class UndefinedVarException: public std::runtime_error
{
public:
    UndefinedVarException()
        : std::runtime_error("Undefined variable")
    {}
    UndefinedVarException(std::string s)
        : std::runtime_error("Undefined variable: " + s)
    {}
};

class UndefinedFunctionException: public std::runtime_error
{
public:
    UndefinedFunctionException()
        : std::runtime_error("Undefined function")
    {}
    UndefinedFunctionException(std::string s)
        : std::runtime_error("Undefined function: " + s)
    {}
};

class InvalidFunctionCall: public std::runtime_error
{
public:
    InvalidFunctionCall()
        : std::runtime_error("Invalid function call")
    {}
    InvalidFunctionCall(std::string s)
        : std::runtime_error("Invalid function call" + s)
    {}
};