#pragma once

#include "Types.h"
#include "Variable.h"
#include "Visitor.h"
#include "Exceptions.h"

//enum VType;
//enum EType;

class Block;
class Visitor;

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
	virtual void accept(Visitor &v) = 0;
};

class Block : public Operator {
private:
	std::list<Operator*> ops;
	std::map<std::string, Var*> vars;
	Block* parentBlock;
	void addOperator(Operator* op);
public:
	Block();
	Block(Operator* op);
	Block(Operator* op1, Operator* op2);
	Block(std::list<Operator*> newOps);
	size_t size();
	void print(unsigned indent = 0);
	~Block();
	void run(Block* parentBlock = nullptr);
	Var* findVar(const std::string& id);
	void addVar(const std::string& id, Var* newVar);
	void printVarTable() const;
	void clearVarTable();
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


class FunctionCall : public Expression {
private:
	std::string ID;
	std::list<Expression*> args;
public:
	FunctionCall(const std::string& ID, const std::list<Expression*>& args);
	virtual void print();
	virtual ~FunctionCall();
	virtual Var eval(Block* parentBlock = nullptr);
	//int* returnValue(Block* parentBlock);
	virtual void accept(Visitor & v);
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
	void accept(Visitor &v);
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
	virtual void accept(Visitor &v);
};

class ArrayAtExpression : public Expression {
private:
	std::string ID;
	Expression* index;
public:
	ArrayAtExpression(std::string ID, Expression* index);
	virtual Var eval(Block* parentBlock);
	virtual void accept(Visitor &v);
	virtual void print();
};

class Value : public Expression {
private:
	int val;
public:
	Value(const std::string& val);
	virtual void print();
	Var eval(Block* parentBlock = nullptr);
	void accept(Visitor &v);
};

class Variable : public Expression {
private:
	std::string ID;
public:
	Variable(const std::string& ID);
	virtual void print();
	std::string getID();
	// лучше не использовать, т.к. возвращается новый объект Var
	virtual Var eval(Block* parentBlock);
	virtual void accept(Visitor &v);
};
