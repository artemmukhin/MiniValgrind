#include <cstdlib>
#include <list>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stdexcept>

enum VType {T_INT, T_PTR, T_ARR};
enum EType {E_UNARY, E_BIN, E_VAL, E_VAR, E_FUNC, E_ARRAT}; // expression type

class Operator;
class Expression;
class Var;
class Block;
class ExprOperator;
class IfOperator;
class WhileOperator;
class AssignOperator;
class DefOperator;
class FunctionCall;
class UnaryExpression;
class BinaryExpression;
class ArrayAtExpression;
class Value;
class Variable;

std::string indentation(unsigned indent) {
    std::string res = "";
    for (unsigned i = 0; i < indent; i++)
        res += "  ";
    return res;
}

class Visitor {
private:
	EType value;
public:
	void visit(UnaryExpression* e) { value = E_UNARY; }
	void visit(BinaryExpression* e) { value = E_BIN; }
	void visit(Value* e) { value = E_VAL; }
	void visit(Variable* e) { value = E_VAR; }
	void visit(FunctionCall* e) { value = E_FUNC; }
	void visit(ArrayAtExpression* e) { value = E_ARRAT; }
	EType type() { return value; }
};

class Operator {
protected:
    Operator() {}
public:
    virtual ~Operator() {}
    virtual void print(unsigned indent = 0) = 0;
    virtual void run(Block* parentBlock = nullptr) = 0;
};

class Expression {
protected:
    Expression() {}
public:
    virtual ~Expression() {}
    virtual void print() = 0;
    virtual Var eval(Block* parentBlock = nullptr) = 0;
	virtual void accept(Visitor &v) = 0;
};

class Var {
	VType type;
    int intVal;
    int* ptrVal;
    int* arrVal;
	size_t arrSize;
    bool isInit;
public:
	Var() {
		intVal = 0;
		ptrVal = nullptr;
		arrVal = nullptr;
		arrSize = 0;
		isInit = false;
	}
    Var(VType t) {
		type = t;
		intVal = 0;
		ptrVal = nullptr;
		arrVal = nullptr;
		arrSize = 0;
        isInit = false;
    }
	Var(VType t, unsigned size) {
		if (t == T_ARR && size != 0) {
			type = T_ARR;
			intVal = 0;
			ptrVal = nullptr;
			arrVal = new int[size];
			for (size_t i = 0; i < size; i++)
				arrVal[i] = 0;
			arrSize = size;
			isInit = false;
		}
		else
			throw std::logic_error("Can't create int/ptr variable with size");
	}
    Var(int int_val) {
        type = T_INT;
        intVal = int_val;
        ptrVal = nullptr;
		arrVal = nullptr;
        isInit = true;
    }
    Var(int* ptr_val) {
        type = T_PTR;
        intVal = 0;
        ptrVal = ptr_val;
		arrVal = nullptr;
        isInit = true;
    }
	~Var() {
		delete ptrVal;
		delete arrVal;
	}
	Var(const Var& other) {
		//std::cout << "Ohhh, copy constructor" << std::endl;
		type = other.type;
		arrSize = other.arrSize;
		ptrVal = other.ptrVal;
		intVal = other.intVal;
		isInit = other.isInit;
		if (other.arrVal != nullptr) {
			arrVal = new int[arrSize];
			for (int i = 0; i < arrSize; i++)
				arrVal[i] = other.arrVal[i];
		}
		else
			arrVal = nullptr;
	}
	Var& operator=(const Var& other) {
		//std::cout << "Ohhh, op=" << std::endl;
		if (&other == this)
			return *this;

		type = other.type;
		arrSize = other.arrSize;
		ptrVal = other.ptrVal;
		intVal = other.intVal;
		isInit = other.isInit;
		if (other.arrVal != nullptr) {
			arrVal = new int[arrSize];
			for (int i = 0; i < arrSize; i++)
				arrVal[i] = other.arrVal[i];
		}
		else
			arrVal = nullptr;

		return *this;
	}
    VType getType() {
        return type;
    }
    int getIntVal() {
        if (type != T_INT)
            throw std::logic_error("Invalid value's type");
        else
            return intVal;
    }
    int* getPtrVal() {
        if (type != T_PTR)
            throw std::logic_error("Invalid value's type");
        else
            return ptrVal;
    }
    int getArrAtVal(size_t i) {
        if (type != T_ARR)
            throw std::logic_error("Invalid value's type");
        else {
            if (i <= arrSize)
                return arrVal[i];
            else
                throw std::logic_error("Escape from the bounds of array");
        }
    }
	size_t getArrSize() {
		if (type != T_ARR)
			throw std::logic_error("Int and ptr hasn't size");
		else
			return arrSize;
	}
    void setIntVal(int newVal) {
        if (type != T_INT)
            throw std::logic_error("Invalid value's type");
        else
            intVal = newVal;
    }
    void setPtrVal(int* newVal) {
        if (type != T_PTR)
            throw std::logic_error("Invalid value's type");
        else
            ptrVal = newVal;
    }
    void setArrAtVal(int newVal, size_t i) {
        if (type != T_ARR)
            throw std::logic_error("Invalid value's type");
        else {
            if (i <= arrSize)
                arrVal[i] = newVal;
            else
                throw std::logic_error("Escape from the bounds of array");
        }
    }
};

class Block : public Operator {
private:
	std::list<Operator*> ops;
	std::map<std::string, Var> vars;
	Block* parentBlock;

	void addOperator(Operator* op) {
		ops.push_back(op);
	}

public:
	// Не нужно?
	Block() { ops = std::list<Operator*>(); }
	Block(Operator* op) { addOperator(op); }
	Block(Operator* op1, Operator* op2) {
		addOperator(op1);
		addOperator(op2);
	}
	// ???
	Block(std::list<Operator*> newOps) {
		ops = newOps;
	}
	size_t size() {
		return ops.size();
	}
	void print(unsigned indent = 0) {
		std::cout << indentation(indent) << "{" << std::endl;
		for (std::list<Operator*>::iterator i = ops.begin(); i != ops.end(); i++) {
			(*i)->print(indent + 1);
		}
		std::cout << indentation(indent) << "}" << std::endl;
	}
	~Block() {
		for (std::list<Operator*>::iterator i = ops.begin(); i != ops.end(); i++) {
			delete *i;
		}
	}
	void run(Block* parentBlock = nullptr) {
		this->parentBlock = parentBlock;
		for (std::list<Operator*>::iterator i = ops.begin(); i != ops.end(); i++) {
			try {
				(*i)->run(this);
			}
			catch (const std::exception & ex) {
				std::cerr << "!!! Error !!!  " << ex.what() << std::endl;
			}
			printVarTable();
			std::cout << std::endl;
		}
	}
	std::map<std::string, Var>::iterator findVar(std::string id) {
		Block* currBlock = this;
		// будем возвращать intVars.end() (для блока, из которого вызывается поиск),
		// если указанная переменная не найдена
		std::map<std::string, Var>::iterator result = this->vars.end();
		while (result == vars.end() && currBlock != nullptr) {
			if (currBlock->vars.find(id) != currBlock->vars.end())
				result = currBlock->vars.find(id); // win!
			else
				currBlock = currBlock->parentBlock;
		}
		return result;
	}
	std::map<std::string, Var>::iterator getVarsEnd() {
		return vars.end();
	}
	void addVar(std::string id, Var newVar) {
		if (findVar(id) == vars.end()) {
            vars.insert( std::pair<std::string, Var>(id, newVar) );
        }
		else
			throw std::logic_error("Variable with the same ID already exists");
	}
    void printVarTable() {
		std::cout << "**** Variables ****" << std::endl;
		for (std::map<std::string, Var>::iterator i = vars.begin(); i != vars.end(); i++) {
			std::cout << (*i).first << " = ";
			switch ((*i).second.getType()) {
				case T_INT: {
					std::cout << (*i).second.getIntVal();
					break;
				}
				case T_PTR: {
					std::cout << (*i).second.getPtrVal();
					break;
				}
				case T_ARR: {
					size_t s = (*i).second.getArrSize();
					for (size_t j = 0; j < s - 1; j++)
						std::cout << (*i).second.getArrAtVal(j) << ", ";
					std::cout << (*i).second.getArrAtVal(s - 1);
				}
			}
			std::cout << std::endl;
		}
		std::cout << "*******************" << std::endl;
    }
};

class FunctionCall : public Expression {
private:
	std::string ID;
	std::list<Expression*> args;
public:
	FunctionCall(const std::string& ID, const std::list<Expression*>& args) :
		ID(ID), args(args) {}
	virtual void print() {
		std::cout << ID << "(";
		for (std::list<Expression*>::iterator i = args.begin(); i != args.end(); i++) {
			if (i != args.begin())
				std::cout << ", ";
			(*i)->print();
		}
		std::cout << ")";
	}
	virtual ~FunctionCall() {
		for (std::list<Expression*>::iterator i = args.begin(); i != args.end(); i++) {
			delete *i;
		}
	}
	virtual Var eval(Block* parentBlock = nullptr) {
		// 
	}
	// to do: all
	void* returnValue() {
		if (ID == "malloc") return nullptr;
	}
	virtual void accept(Visitor & v) { v.visit(this); }
};

class UnaryExpression : public Expression {
private:
	const char* op;
	Expression *arg;
public:
	UnaryExpression(const char* op, Expression* arg) :
		op(op), arg(arg) {}
	virtual void print() {
		std::cout << op;
		arg->print();
	}
	virtual ~UnaryExpression() { delete arg; }
	Var eval(Block* parentBlock) {
		return Var();
	}
	void accept(Visitor &v) { v.visit(this); }
};

class BinaryExpression : public Expression {
private:
	const char* op;
	Expression *arg1, *arg2;
public:
	BinaryExpression(const char* op, Expression* arg1, Expression* arg2) :
		op(op), arg1(arg1), arg2(arg2) {}
	virtual void print() {
		std::cout << "(";
		arg1->print();
		std::cout << " " << op << " ";
		arg2->print();
		std::cout << ")";
	}
	virtual ~BinaryExpression() { delete arg1; delete arg2; }
	virtual Var eval(Block* parentBlock) {
		return Var();
	}
	virtual void accept(Visitor &v) { v.visit(this); }
};

class ArrayAtExpression : public Expression {
private:
	std::string ID;
	Expression* index;
public:
	ArrayAtExpression(std::string ID, Expression* index) : ID(ID), index(index) {}
	virtual Var eval(Block* parentBlock) {
		Var result;
		std::map<std::string, Var>::iterator sourceArr = parentBlock->findVar(ID);
		if (sourceArr == parentBlock->getVarsEnd())
			throw std::logic_error("Undefined variable");
		else if (sourceArr->second.getType() != T_ARR || index == nullptr) {
			throw std::logic_error("Int and ptr has no index");
		}
		result = Var(sourceArr->second.getArrAtVal(index->eval().getIntVal()));
		return result;
	}
	virtual void accept(Visitor &v) { v.visit(this); }
	virtual void print() {
		std::cout << ID << "[" << index->eval().getIntVal() << "]";
	}
};

class Value : public Expression {
private:
	int val;
public:
	Value(const std::string& val) : val(atoi(val.c_str())) {}
	virtual void print() { std::cout << val; }
	Var eval(Block* parentBlock = nullptr) {
		return Var(val);
	}
	void accept(Visitor &v) { v.visit(this); }
};

class Variable : public Expression {
private:
	std::string ID;
public:
	Variable(const std::string& ID) : ID(ID) {}
	virtual void print() { std::cout << ID; }
	std::string getID() { return ID; }
	// лучше не использовать, т.к. возвращается новый объект Var
	virtual Var eval(Block* parentBlock) {
		//return parentBlock->findVar(ID)->second;
		return Var();
	}
	virtual void accept(Visitor &v) {
		v.visit(this);
	}
};

class ExprOperator : public Operator {
private:
    Expression* expr;
public:
    ExprOperator(Expression* expr) : expr(expr) {}
    virtual void print(unsigned indent = 0) {
		//std::cout << "print exprop\n";
		std::cout << indentation(indent);
        expr->print();
        std::cout << ";" << std::endl;
    }
    virtual ~ExprOperator() { delete expr; }
    virtual void run(Block* parentBlock = nullptr) {
		Visitor v;
		expr->accept(v);
		// do nothing...
	}
};

class IfOperator : public Operator {
private:
    Expression* cond;
	Operator* thenBlock;
	Operator* elseBlock;
public:
	IfOperator(Expression* cond, Operator* thenBlock, Operator* elseBlock) :
		cond(cond), thenBlock(thenBlock), elseBlock(elseBlock) {}
    virtual void print(unsigned indent = 0) {
		std::cout << indentation(indent);
        std::cout << "if ";
		cond->print();
		std::cout << std::endl;
        thenBlock->print(indent);
		if (elseBlock != nullptr) {
			std::cout << indentation(indent) << "else" << std::endl;
			elseBlock->print(indent);
		}
	}
    virtual ~IfOperator() { delete cond; }
	virtual void run(Block* parentBlock = nullptr) {
	}
};

class WhileOperator: public Operator {
private:
    Expression* cond;
    Operator* body;
public:
    WhileOperator(Expression* cond, Operator* body) :
            cond(cond), body(body) {}
    virtual void print(unsigned indent = 0) {
        std::cout << indentation(indent) << "while ";
        cond->print();
        std::cout << std::endl;
        body->print(indent);
    }
    virtual ~WhileOperator() { delete cond; }
	virtual void run(Block * parentBlock = nullptr) {
	}
};

class AssignOperator : public Operator {
private:
    std::string ID;
    Expression* value;
    Expression* index; // only for array, such as 'a[5+7] = 2'
public:
    AssignOperator(const std::string& ID, Expression* value) :
            ID(ID), value(value) { index = nullptr; }
    AssignOperator(const std::string& ID, Expression* value, Expression* index) :
            ID(ID), value(value), index(index) {}
    virtual void print(unsigned indent = 0) {
        std::cout << indentation(indent) << ID << " = ";
        value->print();
		std::cout << ";" << std::endl;
    }
    virtual ~AssignOperator() { delete value; }
    void run(Block* parentBlock = nullptr) {
        // value may be: unaryexpr, binaryexpr, value, variable, funccal
		Visitor v;
		value->accept(v);

        std::map<std::string, Var>::iterator targetVar = parentBlock->findVar(ID);
        if (targetVar == parentBlock->getVarsEnd())
            throw std::logic_error("Undefined variable");
        else if (targetVar->second.getType() != T_ARR && index != nullptr) {
            throw std::logic_error("Int and ptr has no index");
        }
        else if (targetVar->second.getType() == T_ARR && index == nullptr) {
            throw std::logic_error("Assign to array without index");
        }

		// x = 5
        if (v.type() == E_VAL) {
            switch (targetVar->second.getType()) {
                case T_INT : {
                    targetVar->second.setIntVal(value->eval().getIntVal());
                    break;
                }
                case T_PTR : {
                    throw std::logic_error("Assign int to ptr");
                    break;
                }
                case T_ARR : {
                    if (index != nullptr)
                        targetVar->second.setArrAtVal(value->eval().getIntVal(), index->eval().getIntVal());
                    else
                        throw std::logic_error("Assign int to arr without index");
                    break;
                }
            }
        }
		// x = y
        else if (v.type() == E_VAR) {
			Variable* valueVariable = dynamic_cast<Variable*>(value);
            std::map<std::string, Var>::iterator sourceVar = parentBlock->findVar(valueVariable->getID());
			//sourceVar = value->eval();
			switch (targetVar->second.getType()) {
                case T_INT : {
                    if (sourceVar->second.getType() != T_INT)
                        throw std::logic_error("Assign non-int to int");
                    targetVar->second.setIntVal(sourceVar->second.getIntVal());
                    break;
                }
                case T_PTR : {
                    if (sourceVar->second.getType() == T_INT)
                        throw std::logic_error("Assign int to ptr");
                    else if (sourceVar->second.getType() == T_PTR)
                        targetVar->second.setPtrVal(sourceVar->second.getPtrVal());
                    else if (sourceVar->second.getType() == T_ARR)
						throw std::logic_error("Assign arr to ptr");
                    break;
                }
                case T_ARR : {
                    if (sourceVar->second.getType() != T_INT)
                        throw std::logic_error("Assign non-int to arr[int]");
                    targetVar->second.setArrAtVal(sourceVar->second.getIntVal(),
                                                  index->eval(parentBlock).getIntVal());
                    break;
                }
            }
        }
		// x = malloc(2)
        else if (v.type() == E_FUNC) {
            // to do: malloc
        }
		// x = -(y + 5)
        else if (v.type() == E_UNARY) {
            switch (targetVar->second.getType()) {
                case T_INT : {
                    targetVar->second.setIntVal(value->eval(parentBlock).getIntVal());
                    break;
                }
                case T_PTR : {
                    targetVar->second.setPtrVal(value->eval(parentBlock).getPtrVal());
                    break;
                }
                case T_ARR : {
                    if (index == nullptr)
                        throw std::logic_error("Assign to arr without index");

                    targetVar->second.setArrAtVal(value->eval(parentBlock).getIntVal(),
                                                  index->eval().getIntVal());
                    break;
                }
            }
        }
		// x = y + 2
        else if (v.type() == E_BIN) {
            switch (targetVar->second.getType()) {
                case T_INT : {
                    targetVar->second.setIntVal(value->eval(parentBlock).getIntVal());
                    break;
                }
                case T_PTR : {
                    targetVar->second.setIntVal(value->eval(parentBlock).getIntVal());
                    break;
                }
                case T_ARR : {
                    if (index == nullptr)
                        throw std::logic_error("Assign to arr without index");

                    targetVar->second.setArrAtVal(value->eval(parentBlock).getIntVal(),
                                                  index->eval().getIntVal());
                    break;
                }
            }
        }
    }
};

class DefOperator : public Operator {
private:
    VType T;
    std::string ID;
    unsigned size;
public:
    DefOperator(VType T, const std::string& ID) :
            T(T), ID(ID) { size = 0; }
    DefOperator(VType T, const std::string& ID, const std::string& size) :
            T(T), ID(ID), size(atoi(size.c_str())) {} // to do: stoi
    virtual void print(unsigned indent = 0) {
		//std::cout << "print def\n";
		std::cout << indentation(indent);
        if (T == T_INT)
            std::cout << "int " << ID;
        else if (T == T_PTR)
            std::cout << "ptr " << ID;
        else
            std::cout << "arr " << ID << "[" << size << "]";
		std::cout << ";" << std::endl;
	}
	virtual void run(Block* parentBlock) {
        //std::cout << "Run def operator" << std::endl;
		if (T == T_ARR && size != 0) {
			Var newVar(T_ARR, size);
			parentBlock->addVar(ID, newVar);
		}
		else {
			Var newVar(T);
			parentBlock->addVar(ID, newVar);
		}
	}
};
