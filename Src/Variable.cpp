#include "Variable.h"

Var::Var() {
	type = T_INT;
	intVal = 0;
	ptrVal = nullptr;
	arrVal = nullptr;
	arrSize = 0;
	isInit = false;
	isArrInit = nullptr;
}

Var::Var(VType t) {
	type = t;
	intVal = 0;
	ptrVal = nullptr;
	arrVal = nullptr;
	arrSize = 0;
	isInit = false;
	isArrInit = nullptr;
}

Var::Var(VType t, unsigned size) {
	if (t == T_ARR && size != 0) {
		type = T_ARR;
		intVal = 0;
		ptrVal = nullptr;
		arrVal = new int[size];
		isArrInit = new bool[size];
		for (size_t i = 0; i < size; i++) {
			arrVal[i] = 0;
			isArrInit[i] = false;
		}
		arrSize = size;
		isInit = false;
	}
	else
		throw InvalidTypeException("can't create int/ptr variable with size");
}

Var::Var(int int_val) {
	type = T_INT;
	intVal = int_val;
	ptrVal = nullptr;
	arrVal = nullptr;
	isInit = true;
	isArrInit = nullptr;
}

Var::Var(Var* ptr_val) {
	type = T_PTR;
	intVal = 0;
	ptrVal = ptr_val;
	arrVal = nullptr;
	isInit = true;
	isArrInit = nullptr;
}

Var::~Var() {
	delete arrVal;
	delete isArrInit;
}

Var::Var(const Var& other) {
	//std::cout << "Ohhh, copy constructor" << std::endl;
	type = other.type;
	arrSize = other.arrSize;
	ptrVal = other.ptrVal;
	intVal = other.intVal;
	isInit = other.isInit;
	arrVal = nullptr;
	isArrInit = nullptr;
	if (other.arrVal != nullptr && other.isArrInit != nullptr) {
		arrVal = new int[arrSize];
		isArrInit = new bool[arrSize];
		for (int i = 0; i < arrSize; i++) {
			arrVal[i] = other.arrVal[i];
			isArrInit[i] = other.isArrInit[i];
		}
	}
}

Var& Var::operator=(const Var& other) {
	//std::cout << "Ohhh, op=" << std::endl;
	if (&other == this)
		return *this;

	type = other.type;
	arrSize = other.arrSize;
	ptrVal = other.ptrVal;
	intVal = other.intVal;
	isInit = other.isInit;
	arrVal = nullptr;
	isArrInit = nullptr;
	if (other.arrVal != nullptr && other.isArrInit != nullptr) {
		arrVal = new int[arrSize];
		isArrInit = new bool[arrSize];
		for (int i = 0; i < arrSize; i++) {
			arrVal[i] = other.arrVal[i];
			isArrInit[i] = other.isArrInit[i];
		}
	}
	return *this;
}

VType Var::getType() {
	return type;
}

int Var::getIntVal() {
	//std::cout << "GETINTVAL type: " << type << std::endl;
	if (type != T_INT) {
		std::cout << "getIntVal ex" << std::endl;
		throw InvalidTypeException("invalid value's type");
	}
	if (!isInit) {
		//std::cout << "GETINTVAL not init" << std::endl;
		throw NotInitVarException("not initialized int");
	}
	else {
		//std::cout << "GETINTVAL ok" << std::endl;
		return intVal;
	}
}
const Var* Var::getPtrVal() {
	//std::cout << "getPtrVal: " << ptrVal << std::endl;
	if (type != T_PTR) {
		std::cout << "getPtrVal ex" << std::endl;
		throw InvalidTypeException("invalid value's type");
	}
	if (!isInit)
		throw NotInitVarException("not initialized pointer");
	else {
		return ptrVal;
	}
}

int Var::getArrAtVal(size_t i) {
	if (type != T_ARR) {
		std::cout << "getArrAtVal ex" << std::endl;
		throw InvalidTypeException("invalid value's type");
	}
	else {
		if (i <= arrSize) {
			if (isArrInit[i] == true) {
				return arrVal[i];
			}
			else {
				throw NotInitVarException("not initialized array element");
			}
		}
		else {
			throw EscapeFromBoundsException("escape from the bounds of array");
		}
	}
}

size_t Var::getArrSize() {
	if (type != T_ARR)
		throw InvalidTypeException("int and ptr hasn't size");
	else
		return arrSize;
}

void Var::setIntVal(int newVal) {
	if (type != T_INT) {
		std::cout << "setIntVal ex" << std::endl;
		throw InvalidTypeException("invalid value's type");
	}
	else {
		intVal = newVal;
		isInit = true;
	}
}

void Var::setPtrVal(const Var* newVal) {
	if (type != T_PTR)
		throw InvalidTypeException("invalid value's type");
	else if (newVal != nullptr) {
		//std::cout << "setPtrVal: " << newVal << std::endl;
		ptrVal = newVal;
		isInit = true;
	}
}

void Var::setArrAtVal(int newVal, size_t i) {
	if (type != T_ARR) {
		std::cout << "setArrAtVal ex" << std::endl;
		throw InvalidTypeException("invalid value's type");
	}
	else {
		if (i <= arrSize) {
			arrVal[i] = newVal;
			isArrInit[i] = true;
		}
		else
			throw EscapeFromBoundsException("escape from the bounds of array");
	}
}