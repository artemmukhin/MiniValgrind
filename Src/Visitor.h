#pragma once

#include "Types.h"
class UnaryExpression;
class BinaryExpression;
class Value;
class VarExpression;
class FunctionCall;
class ArrayAtExpression;

class Visitor {
private:
	EType value;
public:
	void visit(UnaryExpression* e) { value = E_UNARY; }
	void visit(BinaryExpression* e) { value = E_BIN; }
	void visit(Value* e) { value = E_VAL; }
	void visit(VarExpression* e) { value = E_VAR; }
	void visit(FunctionCall* e) { value = E_FUNC; }
	void visit(ArrayAtExpression* e) { value = E_ARRAT; }
	EType type() { return value; }
};