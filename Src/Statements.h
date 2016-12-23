/**
    Mini Valgrind
    Statements.h

    This file contains definitions of following classes:
    Statements
        Block
        ExprStatement
        IfStatement
        WhileStatement
        ForStatement
        AssignStatement
        DefStatement
        ReturnStatement
    Expression
        FunCallExpression
        UnaryExpression
        BinaryExpression
        ArrayAtExpression
        ValueExpression
        VarExpression
    Globals
    Parameter
    FunctionCall
    Function
    Program

    @author Artem Mukhin
*/


#pragma once

#include "Types.h"
#include "Variable.h"
#include "Exceptions.h"
#include <algorithm>

// print table of variables after run each statement in program
const bool PRINT_VAR_TABLE = false;

class Block;

class Statement
{
public:
    Statement()
    {}

    virtual ~Statement()
    {}

    /**
     * Print statement
     * @param indent - Length of indentation before statement.
    */
    virtual void print(unsigned indent = 0) const = 0;

    /**
     * Run statement
     * @param parentBlock - Block inside which this block is located.
    */
    virtual void run(Block *parentBlock) = 0;
};

class Expression
{
public:
    Expression()
    {}

    virtual ~Expression()
    {}

    /**
     * Print expression
    */
    virtual void print() const = 0;

    /**
     * Evaluate expression.
     * @param parentBlock - Block inside which this block is located.
     * @return Result variable.
    */
    virtual Var eval(Block *parentBlock) = 0;
};

class Block: public Statement
{
protected:
    std::list<std::shared_ptr<Statement> > statements; // list of statements
    std::map<std::string, Var *> vars; // table of variables
    Block *parentBlock;

public:
    Block();

    Block(std::list<std::shared_ptr<Statement> > stats);

    ~Block() override;

    Block(const Block &other);

    void print(unsigned indent = 0) const override;

    void run(Block *parentBlock = nullptr) override;

    size_t size() const;

    /**
     * Find variable with given name in the table of variables of this block.
     * @param id - Name of the variable.
     * @return Pointer to the variable if it exists, nullptr otherwise.
    */
    Var *findVar(const std::string &id);

    /**
     * Add variable with given name to the table of variables of this block.
     * @param id - Name of new variable.
     * @param newVar - Pointer to new variable.
    */
    void addVar(const std::string &id, Var *newVar);

    /**
     * Print all variables from the table of variables.
    */
    void printVarTable() const;

    /**
     * Delete all variables from the table of variables.
    */
    void clearVarTable();

    /**
     * Change #RESULT variable for this block.
     * #RESULT is return value of the function comprising this block.
     * @param resultVar - New return value.
    */
    void changeReturnValue(Var resultVal);

    /**
     * Is function leaved by return statement.
     * @return True if #RESULT is already initialized, false otherwise.
     */
    bool isReturned();

    const std::map<std::string, Var *> &getVars() const;
};

class ExprStatement: public Statement
{
private:
    Expression *expr;

public:
    ExprStatement(Expression *expr);

    ~ExprStatement() override;

    void print(unsigned indent = 0) const override;

    void run(Block *parentBlock = nullptr) override;
};

class IfStatement: public Statement
{
private:
    Expression *cond;
    Block *thenBlock;
    Block *elseBlock;

public:
    IfStatement(Expression *cond, Block *thenBlock, Block *elseBlock);

    ~IfStatement() override;

    void print(unsigned indent = 0) const override;

    void run(Block *parentBlock = nullptr) override;
};

class WhileStatement: public Statement
{
private:
    Expression *cond;
    Block *body;

public:
    WhileStatement(Expression *cond, Block *body);

    ~WhileStatement() override;

    void print(unsigned indent = 0) const override;

    void run(Block *parentBlock = nullptr) override;
};

class ForStatement: public Statement
{
private:
    std::shared_ptr<Statement> initStat;
    Expression *cond;
    std::shared_ptr<Statement> stepStat;
    Block *body;
    Block *ownBlock; // this block contains local variables, created in for-loop

public:
    ForStatement(std::shared_ptr<Statement> initStat,
                 Expression *cond,
                 std::shared_ptr<Statement> stepStat,
                 Block *body);

    ~ForStatement() override;

    void print(unsigned int indent) const override;

    void run(Block *parentBlock) override;
};

class AssignStatement: public Statement
{
private:
    std::string ID;
    Expression *value;
    Expression *index; // only for array, such as 'a[5+7] = 2'
    bool isDereferecing; // false for "x = 15", true for "*p = 15"
public:
    AssignStatement(const std::string &ID, Expression *value, bool isDereferencing = false);

    AssignStatement(const std::string &ID, Expression *value, Expression *index);

    ~AssignStatement() override;

    void print(unsigned indent = 0) const override;

    void run(Block *parentBlock) override;
};

class DefStatement: public Statement
{
private:
    VType type;
    std::string ID;
    unsigned size;
    Expression *value;
    AssignStatement *assignStat; // for assign during declaration, such as 'int x = 2'

public:
    DefStatement(VType T, const std::string &ID, Expression *value);

    DefStatement(VType T, const std::string &ID, const std::string &size, Expression *value);

    ~DefStatement() override;

    void print(unsigned indent = 0) const override;

    void run(Block *parentBlock) override;
};

class ReturnStatement: public Statement
{
private:
    Expression *value;

public:
    ReturnStatement(Expression *value);

    ~ReturnStatement() override;

    void print(unsigned int indent) const override;

    void run(Block *parentBlock) override;
};

class FunCallExpression: public Expression
{
private:
    std::string ID;
    std::vector<Expression *> args;

public:
    FunCallExpression(const std::string &ID, const std::vector<Expression *> &args);

    ~FunCallExpression() override;

    void print() const override;

    Var eval(Block *parentBlock = nullptr) override;

    const std::string &getID() const;
};

class UnaryExpression: public Expression
{
private:
    const char *op;
    Expression *arg;

public:
    UnaryExpression(const char *op, Expression *arg);

    ~UnaryExpression() override;

    void print() const override;

    Var eval(Block *parentBlock) override;
};

class BinaryExpression: public Expression
{
private:
    const char *op;
    Expression *arg1, *arg2;

public:
    BinaryExpression(const char *op, Expression *arg1, Expression *arg2);

    ~BinaryExpression() override;

    void print() const override;

    Var eval(Block *parentBlock) override;
};

class ArrayAtExpression: public Expression
{
private:
    std::string ID;
    Expression *index;

public:
    ArrayAtExpression(std::string ID, Expression *index);

    ~ArrayAtExpression() override;

    void print() const override;

    Var eval(Block *parentBlock) override;
};

class ValueExpression: public Expression
{
private:
    int val;

public:
    ValueExpression(const std::string &val);

    ~ValueExpression() override;

    void print() const override;

    Var eval(Block *parentBlock) override;
};

class VarExpression: public Expression
{
private:
    std::string ID;

public:
    VarExpression(const std::string &ID);

    ~VarExpression() override;

    void print() const override;

    Var eval(Block *parentBlock) override;

    const std::string &getID() const;
};

class Globals
{
private:
    Block *globalsBlock;

public:
    Globals();

    Globals(Block *globalsBlock);

    void addToBlock(Block *block);
};

// parameters of a function
class Parameter
{
private:
    VType paramType;
    std::string id;

public:
    Parameter(VType paramType, const std::string &id);

    ~Parameter();

    VType getParamType() const;

    const std::string &getID() const;
};

class FunctionCall
{
private:
    Block *body;
    Var result;

public:
    FunctionCall(Block *block,
                 VType returnType,
                 const std::vector<Parameter *> &params,
                 const std::vector<Var> &args);

    ~FunctionCall();

    /**
     * Execute this function.
     * @param globalBlock - Block inside which this block is located.
     * @return Variable containing return value of the function
     */
    Var execute(Block *globalBlock);
};

class Function
{
private:
    std::string id;
    VType returnType;
    std::vector<Parameter *> params;
    Block *body;

public:
    Function(const std::string &id,
             VType returnType,
             const std::vector<Parameter *> params,
             Block *body);

    ~Function();

    const std::string &getID() const;

    Var eval(const std::vector<Var> &args, Block *globalBlock);
};

// Singleton pattern
class Program
{
private:
    std::list<Function *> funcs;
    Block *globalBlock;
    std::list<std::vector<int> *> allocated;
    Program()
    {}
    ~Program()
    {}
    Program(Program const &) = delete;
    Program &operator=(Program const &) = delete;

public:
    static Program &Instance()
    {
        static Program p;
        return p;
    }

    void setFuncs(std::list<Function *> f);

    void setGlobals(Globals *globs);

    /**
     * Delete allocated members and check memory leaks in miniC-program.
     */
    void finalize();

    /**
     * Run program (i.e. function 'main').
     */
    void run();

    /**
     * Run function with given arguments.
     * @param id - Name of the function.
     * @param args - Arguments of the function.
     * @return Variable containing return value of the function.
     */
    Var runFunction(std::string id, std::vector<Var> &args);

    /**
     * Add pointer to allocated vector<int>.
     * For example, code 'ptr p = malloc(10)' allocate vector<int>(10).
     * @param allocatedMemory - Pointer to vector<int>, allocated by function 'malloc' in miniC-program.
     */
    void addAllocated(std::vector<int> *allocatedMemory);

    /**
     * Remove pointer to previously allocated vector<int> after calling 'free()'
     * @param freeMemory
     */
    void removeAllocated(std::vector<int> *freeMemory);
};

/*
 * Struct for Bison parser
 */
typedef struct
{
    std::string str;
    std::shared_ptr<Statement> statement;
    Block *block;
    std::list<std::shared_ptr<Statement> > statements;
    Expression *expr;
    std::vector<Expression *> args;
    Function *func;
    std::list<Function *> funcs;
    Program *prog;
    Parameter *param;
    std::vector<Parameter *> params;
    Globals *globs;
} MyDataType;
