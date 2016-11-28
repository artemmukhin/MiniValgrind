#pragma once

#include "Types.h"
#include "Variable.h"
#include "Exceptions.h"
#include <algorithm>

class Block;

class Operator {
protected:
    Operator() {}
public:
    virtual ~Operator() {}
    virtual void print(unsigned indent = 0) = 0;
    virtual void run(Block* parentBlock) = 0;
};

class Expression {
protected:
    Expression() {}
public:
    virtual ~Expression() {}
    virtual void print() = 0;
    virtual Var eval(Block* parentBlock) = 0;
};


class Block : public Operator {
private:
    std::list<Operator*> ops; // list of operators
    std::map<std::string, Var*> vars; // table of variables
    Block* parentBlock;
public:
    Block(std::list<Operator*> newOps);
    size_t size();
    void print(unsigned indent = 0);
    ~Block();
    void run(Block* parentBlock = nullptr);
    Var* findVar(const std::string& id);
    void addVar(const std::string& id, Var* newVar);
    void printVarTable() const;
    void clearVarTable();
    void changeReturnValue(Var resultVal);
    bool isReturned(); // true, if #RESULT is already init
};

class ExprOperator : public Operator {
private:
    Expression* expr;
public:
    ExprOperator(Expression* expr);
    virtual void print(unsigned indent = 0);
    virtual ~ExprOperator();
    virtual void run(Block* parentBlock = nullptr);
};

class IfOperator : public Operator {
private:
    Expression* cond;
    Block* thenBlock;
    Block* elseBlock;
public:
    IfOperator(Expression* cond, Block* thenBlock, Block* elseBlock);
    virtual void print(unsigned indent = 0);
    virtual ~IfOperator();
    virtual void run(Block* parentBlock = nullptr);
};

class WhileOperator : public Operator {
private:
    Expression* cond;
    Block* body;
public:
    WhileOperator(Expression* cond, Block* body);
    virtual void print(unsigned indent = 0);
    virtual ~WhileOperator();
    virtual void run(Block * parentBlock = nullptr);
};

class ForOperator : public Operator {
private:
    Operator* initOp;
    Expression* cond;
    Operator* stepOp;
    Block* body;
public:
    ForOperator(Operator *initOp, Expression *cond, Operator *stepOp, Block *body);
    virtual ~ForOperator();
    virtual void print(unsigned int indent) override;
    virtual void run(Block *parentBlock) override;
};

class AssignOperator : public Operator {
private:
    std::string ID;
    Expression* value;
    Expression* index; // only for array, such as 'a[5+7] = 2'
    bool isDereferecing; // false for "x = 15", true for "*p = 15"
public:
    AssignOperator(const std::string& ID, Expression* value, bool isDereferencing = false);
    AssignOperator(const std::string& ID, Expression* value, Expression* index);
    virtual void print(unsigned indent = 0);
    virtual ~AssignOperator();
    void run(Block* parentBlock = nullptr);
};

class DefOperator : public Operator {
private:
    VType type;
    std::string ID;
    unsigned size;
    Expression* value;
public:
    DefOperator(VType T, const std::string& ID, Expression* value);
    DefOperator(VType T, const std::string& ID, const std::string& size, Expression* value);
    virtual void print(unsigned indent = 0);
    virtual void run(Block* parentBlock);
};

class ReturnOperator : public Operator {
private:
    Expression* value;
public:
    ReturnOperator(Expression *value);
    void run(Block* parentBlock);

    virtual ~ReturnOperator();

    virtual void print(unsigned int indent) override;
};

class FunctionCall : public Expression {
private:
    std::string ID;
    std::vector<Expression*> args;
public:
    FunctionCall(const std::string& ID, const std::vector<Expression*>& args);
    virtual void print();
    virtual ~FunctionCall();
    virtual Var eval(Block* parentBlock = nullptr);
    //int* returnValue(Block* parentBlock);
};

class UnaryExpression : public Expression {
private:
    const char* op;
    Expression* arg;
public:
    UnaryExpression(const char* op, Expression* arg);
    virtual void print();
    virtual ~UnaryExpression();
    Var eval(Block* parentBlock);
};

class BinaryExpression : public Expression {
private:
    const char* op;
    Expression *arg1, *arg2;
public:
    BinaryExpression(const char* op, Expression* arg1, Expression* arg2);
    virtual void print();
    virtual ~BinaryExpression();
    virtual Var eval(Block* parentBlock);
};

class ArrayAtExpression : public Expression {
private:
    std::string ID;
    Expression* index;
public:
    ArrayAtExpression(std::string ID, Expression* index);
    virtual Var eval(Block* parentBlock);
    virtual void print();
};

class Value : public Expression {
private:
    int val;
public:
    Value(const std::string& val);
    virtual void print();
    Var eval(Block* parentBlock = nullptr);
};

class VarExpression : public Expression {
private:
    std::string ID;
public:
    VarExpression(const std::string& ID);
    virtual void print();
    std::string getID();
    virtual Var eval(Block* parentBlock);
};


// parameters of a function
class Parameter {
public:
    Parameter(VType paramType, const std::string &id);
    virtual ~Parameter();
    VType getParamType() const;
    const std::string &getId() const;

private:
    VType paramType;
    std::string id;
};

class Function {
private:
    std::string id;
    VType returnType;
    std::vector<Parameter*> params;
    Block* body;
public:
    Function(const std::string &id, VType returnType, const std::vector<Parameter *> &params, Block *body);
    virtual ~Function();
    const std::string &getId() const;
    Var eval(const std::vector<Var>& args);
};

// Singleton pattern
class Program {
private:
    std::list<Function*> funcs;
    Program() {}
    ~Program() {}
    Program(Program const&) = delete;
    Program&operator=(Program const&) = delete;
public:
    static Program& Instance() {
        static Program p;
        return p;
    }
    void setFuncs(std::list<Function*> f);
    //std::list<Function*> getFuncs();
    void run();
    Var runFunction(std::string& id, std::vector<Var>& args);
};


typedef struct {
    std::string str;
    Operator* oper;
    Block* block;
    std::list<Operator*> opers;
    Expression* expr;
    std::vector<Expression*> args;
    Function* func;
    std::list<Function*> funcs;
    Program* prog;
    Parameter* param;
    std::vector<Parameter*> params;
} MyDataType;