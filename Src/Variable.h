/**
    Mini Valgrind
    Variable.h

    @author Artem Mukhin
*/

#pragma once

#include "Types.h"
#include "Exceptions.h"

enum VType;
enum EType;


// Every variable has three values: integer, pointer and array

class Var
{
    VType type;
    int intVal;
    Var *ptrVal;
    // two variables can contain identical arrVal
    std::shared_ptr<std::vector<int> > arrVal;
    size_t arrSize;
    // isInit == false, if this is uninitialized variable
    bool isInit;
    // isArrInit[i] == false, if this[i] is uninitialized element of array
    std::shared_ptr<std::vector<bool> > isArrInit;
public:
    Var();

    Var(VType t);

    Var(VType t, size_t size);

    Var(int intVal);

    Var(Var *ptrVal);

    ~Var();

    Var(const Var &other);

    Var &operator=(const Var &other);

    VType getType() const;

    bool isVarInit() const;

    int getIntVal() const;

    Var *getPtrVal();

    int getArrAtVal(size_t i) const;

    size_t getArrSize() const;

    std::shared_ptr<std::vector<int> > &getArr();

    std::shared_ptr<std::vector<bool> > &getArrInit();

    void setIntVal(int newVal);

    void setPtrVal(Var *newVal);

    void setArrAtVal(int newVal, size_t i);

    void setArrVal(std::shared_ptr<std::vector<int> > &sourceArr, std::shared_ptr<std::vector<bool> > &sourceArrInit);

    /**
     * Delete previously allocated vector<int>
     * Only for T_ARR and T_PTR
     */
    void freeArr();

    friend std::ostream &operator<<(std::ostream &os, const Var &v);
};
