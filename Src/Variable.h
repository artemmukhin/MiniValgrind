#pragma once

#include "Types.h"
#include "Exceptions.h"

enum VType;
enum EType;


// Every variable has three values: integer, pointer and array

class Var {
    VType type;
    int intVal;
    Var* ptrVal;
    std::shared_ptr<std::vector<int> > arrVal; // two variables can contain identical arrVal
    size_t arrSize;
    bool isInit;  // isInit == false, if this is uninitialized variable
    std::shared_ptr<std::vector<bool> > isArrInit;  // isArrInit[i] == false, if this[i] is uninitialized element of array
public:
    Var();
    Var(VType t);
    Var(VType t, unsigned size);
    Var(int int_val);
    Var(Var* ptr_val);
    ~Var();
    Var(const Var& other);
    Var& operator=(const Var& other);
    VType getType() const;
    bool isVarInit() const;
    int getIntVal();
    Var* getPtrVal();
    int getArrAtVal(size_t i);
    size_t getArrSize();
    std::shared_ptr<std::vector<int> >& getArr();
    std::shared_ptr<std::vector<bool> >& getArrInit();
    void setIntVal(int newVal);
    void setPtrVal(Var* newVal);
    void setArrAtVal(int newVal, size_t i);
    void setArrVal(std::shared_ptr<std::vector<int> > &arr, std::shared_ptr<std::vector<bool> > &sourceArrInit);
    void freeArr();
    friend std::ostream& operator<<(std::ostream & os, const Var & v);
};
