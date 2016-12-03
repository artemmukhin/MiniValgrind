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
        isInit = false;
        arrSize = size;
        arrVal = std::make_shared<std::vector<int> >(size, 0);
        isArrInit = std::make_shared<std::vector<bool> >(size, false);
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
    intVal = 0;
    ptrVal = nullptr;
    arrVal = nullptr;
    isArrInit = nullptr;
    arrSize = 0;
    isInit = false;
}

Var::Var(const Var& other) {
    type = other.type;
    arrSize = other.arrSize;
    ptrVal = other.ptrVal;
    intVal = other.intVal;
    isInit = other.isInit;
    if (other.arrVal)
        arrVal = other.arrVal;
    if (other.isArrInit)
        isArrInit = other.isArrInit;
    }

Var& Var::operator=(const Var& other) {
    if (&other == this)
        return *this;
    type = other.type;
    arrSize = other.arrSize;
    ptrVal = other.ptrVal;
    intVal = other.intVal;
    isInit = other.isInit;
    arrVal = other.arrVal;
    isArrInit = other.isArrInit;

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
            if ( (*isArrInit.get())[i] )
                return (*arrVal.get())[i];
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

std::shared_ptr<std::vector<int> >& Var::getArr() {
    if (type == T_INT)
        throw InvalidTypeException("int has no array");
    else
        return arrVal;
}

std::shared_ptr<std::vector<bool> >& Var::getArrInit() {
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
            (*arrVal.get())[i] = newVal;
            (*isArrInit.get())[i] = true;
        }
        else
            throw EscapeFromBoundsException("escape from the bounds of array");
    }
    else
        throw InvalidTypeException("assign to ptr[i]");
}

void Var::setArrVal(std::shared_ptr<std::vector<int> > &arr, std::shared_ptr<std::vector<bool> > &sourceArrInit) {
    if (type == T_INT)
        throw InvalidTypeException("invalid value's type");
    if (arr != nullptr) {
        if (arr.get()->size() != sourceArrInit.get()->size())
            throw InvalidFunctionCall("setArrVal's arguments must have identical size");
        arrSize = arr.get()->size();
        isInit = true;
        arrVal = arr;
        isArrInit = sourceArrInit;
    }
    else {
        arrVal = nullptr;
        arrSize = 0;
        isArrInit = nullptr;
    }
}


void Var::freeArr() {
    if (type == T_INT)
        throw InvalidTypeException("Can't free int variable");
    arrVal.reset();
    isArrInit.reset();
    arrSize = 0;
    isInit = false;
}

std::ostream & operator<<(std::ostream & os, const Var &v) {
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
                    if ( (*v.isArrInit.get())[i] )
                        os << (*v.arrVal.get())[i] << ", ";
                    else
                        os << "None" << ", ";
                }
                if ( (*v.isArrInit.get())[v.arrSize - 1] )
                    os << (*v.arrVal.get())[v.arrSize - 1] << "]";
                else
                    os << "None" << "]";
            }
            break;
        case T_ARR:
            os << "[";
            for (size_t i = 0; i < ((v.arrSize > 0) ? v.arrSize - 1 : 0); i++) {
                if ( (*v.isArrInit.get())[i] )
                    os << (*v.arrVal.get())[i] << ", ";
                else
                    os << "None" << ", ";
            }
            if (v.arrSize > 0) {
                if ( (*v.isArrInit.get())[v.arrSize - 1] )
                    os << (*v.arrVal.get())[v.arrSize - 1] << "]";
                else
                    os << "None" << "]";
            }
            else
                os << "]";
            break;
    }
    return os;
}

bool Var::isVarInit() const {
    return isInit;
}

