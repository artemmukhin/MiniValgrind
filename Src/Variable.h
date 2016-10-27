#pragma once

#include "Types.h"
#include "Exceptions.h"

enum VType;
enum EType;

class Var {
	VType type;
	int intVal;
	Var* ptrVal;
	int* arrVal;
	size_t arrSize;
	bool isInit;
	bool* isArrInit;
public:
	Var();
	Var(VType t);
	Var(VType t, unsigned size);
	Var(int int_val);
	Var(Var* ptr_val);
	Var(const int* arr, size_t s);
	~Var();
	Var(const Var& other);
	Var& operator=(const Var& other);
	VType getType();
	int getIntVal();
	Var* getPtrVal();
	int getArrAtVal(size_t i);
	size_t getArrSize();
	const int* getArr();
	void setIntVal(int newVal);
	void setPtrVal(Var* newVal);
	void setArrAtVal(int newVal, size_t i);
	void setArrVal(const int* arr, size_t s);
};
