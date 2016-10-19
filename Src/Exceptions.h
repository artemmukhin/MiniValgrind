#include <stdexcept>
#include <string>

class NotInitVarException : public std::runtime_error
{
public:
	NotInitVarException() : std::runtime_error("Not initialized variable") {}
	NotInitVarException(std::string s) : std::runtime_error("Not initialized variable: " + s) {}
};

class InvalidTypeException : public std::runtime_error
{
public:
	InvalidTypeException() : std::runtime_error("Invalid value's type") {}
	InvalidTypeException(std::string s) : std::runtime_error("Invalid value's type: " + s) {}
};

class EscapeFromBoundsException : public std::runtime_error
{
public:
	EscapeFromBoundsException() : std::runtime_error("Escape from the bounds of array") {}
	EscapeFromBoundsException(std::string s) : std::runtime_error("Escape from the bounds of array: " + s) {}
};