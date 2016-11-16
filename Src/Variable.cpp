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

Var::Var(const int* arr, size_t s) {
    type = T_ARR;
    intVal = 0;
    ptrVal = nullptr;
    arrSize = s;
    if (arr != nullptr) {
        isInit = true;
        isArrInit = new bool[s];
        arrVal = new int[s];
        for (int i = 0; i < s; i++) {
            isArrInit[i] = true;
            arrVal[i] = arr[i];
        }
    }
}

Var::~Var() {
    delete arrVal;
    delete isArrInit;
    intVal = 0;
    ptrVal = nullptr;
    arrVal = nullptr;
    arrSize = 0;
    isInit = false;
}

Var::Var(const Var& other) {
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

VType Var::getType() const {
    return type;
}

int Var::getIntVal() {
    if (type != T_INT)
        throw InvalidTypeException("invalid value's type");
    if (!isInit)
        throw NotInitVarException("not initialized int");
    else
        return intVal;
}

Var* Var::getPtrVal() {
    if (type != T_PTR)
        throw InvalidTypeException("invalid value's type");
    if (!isInit)
        throw NotInitVarException("not initialized pointer");
    return ptrVal;
}

int Var::getArrAtVal(size_t i) {
    if (type == T_INT)
        throw InvalidTypeException("invalid value's type");
    else if (arrVal != nullptr) {
        if (i < arrSize) {
            if (isArrInit[i])
                return arrVal[i];
            else
                throw NotInitVarException("not initialized array element");
        }
        else
            throw EscapeFromBoundsException("escape from the bounds of array");
    }
    else
        throw InvalidTypeException("ptr[i] (nullptr)");
}

size_t Var::getArrSize() {
    if (type == T_INT)
        throw InvalidTypeException("int has no size");
    else
        return arrSize;
}

int* Var::getArr() {
    if (type == T_INT)
        throw InvalidTypeException("int has no array");
    else
        return arrVal;
}

bool* Var::getArrInit() {
    if (type == T_INT)
        throw InvalidTypeException("int has no array");
    else
        return isArrInit;
}

void Var::setIntVal(int newVal) {
    if (type != T_INT)
        throw InvalidTypeException("invalid value's type");
    else {
        intVal = newVal;
        isInit = true;
    }
}

void Var::setPtrVal(Var* newVal) {
    if (type != T_PTR)
        throw InvalidTypeException("invalid value's type");
    else if (newVal != nullptr) {
        ptrVal = newVal;
        isInit = true;
    }
}

void Var::setArrAtVal(int newVal, size_t i) {
    if (type == T_INT)
        throw InvalidTypeException("assign to int[i]");
    else if (arrVal != nullptr) {
        if (i < arrSize) {
            arrVal[i] = newVal;
            isArrInit[i] = true;
        }
        else
            throw EscapeFromBoundsException("escape from the bounds of array");
    }
    else
        throw InvalidTypeException("assign to ptr[i]");
}

void Var::setArrVal(const int* arr, size_t s, bool* sourceArrInit) {
    if (type == T_INT)
        throw InvalidTypeException("invalid value's type");
    if (arr != nullptr && s != 0) {
        arrSize = s;
        isInit = true;
        arrVal = new int[arrSize];
        isArrInit = new bool[arrSize];
        for (int i = 0; i < arrSize; i++) {
            if (sourceArrInit != nullptr)
                isArrInit[i] = sourceArrInit[i];
            else
                isArrInit[i] = false;
            arrVal[i] = arr[i];
        }
    }
}

std::ostream & operator<<(std::ostream & os, const Var & v) {
    switch (v.type) {
        case T_INT:
            if (v.isInit)
                os << v.intVal;
            else
                os << "None";
            break;
        case T_PTR:
            if (v.isInit)
                os << v.ptrVal;
            else
                os << "None";
            if (v.arrVal != nullptr) {
                os << ", arrVal = [";
                for (size_t i = 0; i < v.arrSize - 1; i++) {
                    if (v.isArrInit[i])
                        os << v.arrVal[i] << ", ";
                    else
                        os << "None" << ", ";
                }
                if (v.isArrInit[v.arrSize - 1])
                    os << v.arrVal[v.arrSize - 1] << "]";
                else
                    os << "None" << "]";
            }
            break;
        case T_ARR:
            os << "[";
            for (size_t i = 0; i < v.arrSize - 1; i++)
                os << v.arrVal[i] << ", ";
            os << v.arrVal[v.arrSize - 1] << "]";
            break;
    }
    return os;
}

bool Var::isVarInit() const {
    return isInit;
}
