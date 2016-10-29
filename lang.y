%{
    #include <iostream>
    #include "../Src/Types.h"
    #include "../Src/Variable.h"
    #include "../Src/Operators.h"
    extern int yylineno;
    extern int yylex();
    
    void yyerror(char *s) {
      std::cerr << s << ", line " << yylineno << std::endl;
      exit(1);
    }

    typedef struct {
        std::string str;
        Operator* oper;
        Block* block;
        std::list<Operator*> opers;
        Expression* expr;
        std::list<Expression*> args;
    } YYSTYPE;
    #define YYSTYPE YYSTYPE
%}

%token IF ELSE WHILE EXIT
%token EQ LE GE NE AND OR
%token NUM ID
%token INT PTR ARR

%type<str> ID NUM
%type<oper> OP
%type<block> BLOCK
%type<opers> OPS
%type<expr> EXPR EXPR2 TERM VAL ARG
%type<args> ARGS

%%

PROGRAM: BLOCK                          { $1->print(); $1->run(nullptr); delete $1; }
;

BLOCK:  '{' OPS '}'                     { $$ = new Block($2); }

OPS:    OP                              { $$.clear(); $$.push_back($1); }
|       OPS OP                          { $$ = $1; $$.push_back($2); }
;

OP:     EXPR ';'                        { $$ = new ExprOperator($1); }
|       IF'(' EXPR ')' BLOCK ELSE BLOCK { $$ = new IfOperator($3, $5, $7); }
|       IF '(' EXPR ')' BLOCK           { $$ = new IfOperator($3, $5, nullptr); }
|       WHILE '(' EXPR ')' BLOCK        { $$ = new WhileOperator($3, $5); }
|       INT ID ';'                      { $$ = new DefOperator(T_INT, $2, nullptr); }
|       INT ID '=' EXPR ';'             { $$ = new DefOperator(T_INT, $2, $4); }
|       PTR ID ';'                      { $$ = new DefOperator(T_PTR, $2, nullptr); }
|       PTR ID '=' EXPR ';'             { $$ = new DefOperator(T_PTR, $2, $4); }
|       ARR ID '[' NUM ']' ';'          { $$ = new DefOperator(T_ARR, $2, $4, nullptr); }
|       ID '=' EXPR ';'                 { $$ = new AssignOperator($1, $3); }
|       '*' ID '=' EXPR ';'             { $$ = new AssignOperator($2, $4, true); }
|       ID '[' EXPR2 ']' '=' EXPR2 ';'  { $$ = new AssignOperator($1, $6, $3); }
;

EXPR:   EXPR2
|       EXPR EQ EXPR2                  { $$ = new BinaryExpression("==", $1, $3); }
|       EXPR LE EXPR2                  { $$ = new BinaryExpression("<=", $1, $3); }
|       EXPR GE EXPR2                  { $$ = new BinaryExpression(">=", $1, $3); }
|       EXPR NE EXPR2                  { $$ = new BinaryExpression("!=", $1, $3); }
|       EXPR '>' EXPR2                 { $$ = new BinaryExpression(">", $1, $3); }
|       EXPR '<' EXPR2                 { $$ = new BinaryExpression("<", $1, $3); }
|       EXPR AND EXPR2                 { $$ = new BinaryExpression("&&", $1, $3); }
|       EXPR OR EXPR2                  { $$ = new BinaryExpression("||", $1, $3); }
;

EXPR2:  TERM
|       EXPR2 '+' TERM                  { $$ = new BinaryExpression("+", $1, $3); }
|       EXPR2 '-' TERM                  { $$ = new BinaryExpression("-", $1, $3); }
|       EXPR2 '%' EXPR2                 { $$ = new BinaryExpression("%", $1, $3); }
;

TERM:   VAL
|       TERM '*' VAL                    { $$ = new BinaryExpression("*", $1, $3); }
|       TERM '/' VAL                    { $$ = new BinaryExpression("/", $1, $3); }
;

VAL:    NUM                             { $$ = new Value($1); }
|       '-' VAL                         { $$ = new UnaryExpression("-", $2); }
|       '!' VAL                         { $$ = new UnaryExpression("!", $2); }
|       '(' EXPR ')'                    { $$ = $2; }
|       ID                              { $$ = new Variable($1); }
|       ID '(' ARGS ')'                 { $$ = new FunctionCall($1, $3); }
|       '&' VAL                         { $$ = new UnaryExpression("&", $2); }
|       '*' VAL                         { $$ = new UnaryExpression("*", $2); }
|       ID '[' EXPR2 ']'                { $$ = new ArrayAtExpression($1, $3); }
;

ARGS:                                   { $$.clear(); }
|       ARG                             { $$.clear(); $$.push_back($1); }
|       ARGS ',' ARG                    { $$ = $1; $$.push_back($3); }
;

ARG:    EXPR
;


%%
int main() { return yyparse(); }

