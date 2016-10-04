%{
    #include <iostream>
    #include "lang.cpp"
    extern int yylineno;
    extern int yylex();
    
    void yyerror(char *s) {
      std::cerr << s << ", line " << yylineno << std::endl;
      exit(1);
    }

    typedef struct {
        std::string str;
        Operator* oper;
        Expression* expr;
        std::list<Expression*> args;
    } YYSTYPE;
%}

%token IF ELSE WHILE EXIT
%token EQ LE GE NE
%token NUM ID
%token INT PTR ARR

%type<str> ID NUM
%type<oper> OPS OP1 OP2 OP
%type<expr> EXPR EXPR1 EXPR2 TERM VAL ARG DEF
%type<args> ARGS

%%

PROGRAM: OPS                            { $1->print(); $1->run(); delete $1; }
;

OPS:    OP
|       OPS OP                          { $$ = new Block($1, $2); }
;

OP1:    '{' OPS '}'                     { $$ = $2; }
|       EXPR ';'                        { $$ = new ExprOperator($1); }
|       IF '(' EXPR ')' OP1 ELSE OP1    { $$ = new IfOperator($3, $5, $7); }
|       WHILE '(' EXPR ')' OP1          { $$ = new WhileOperator($3, $5); }
;

OP2:    IF '(' EXPR ')' OP              { $$ = new IfOperator($3, $5, new Block()); }
|       IF '(' EXPR ')' OP1 ELSE OP2    { $$ = new IfOperator($3, $5, $7); }
|       WHILE '(' EXPR ')' OP2          { $$ = new WhileOperator($3, $5); }
;

OP:     OP1 | OP2 ;

EXPR:   EXPR1
|       ID '=' EXPR2                    { $$ = new AssignExpression($1, $3); }


EXPR1:  EXPR2
|       EXPR1 EQ EXPR2                  { $$ = new BinaryExpression("==", $1, $3); }
|       EXPR1 LE EXPR2                  { $$ = new BinaryExpression("<=", $1, $3); }
|       EXPR1 GE EXPR2                  { $$ = new BinaryExpression(">=", $1, $3); }
|       EXPR1 NE EXPR2                  { $$ = new BinaryExpression("!=", $1, $3); }
|       EXPR1 '>' EXPR2                 { $$ = new BinaryExpression(">", $1, $3); }
|       EXPR1 '<' EXPR2                 { $$ = new BinaryExpression("<", $1, $3); }
|       DEF
;

EXPR2:  TERM
|       EXPR2 '+' TERM                  { $$ = new BinaryExpression("+", $1, $3); }
|       EXPR2 '-' TERM                  { $$ = new BinaryExpression("-", $1, $3); }
;

TERM:   VAL
|       TERM '*' VAL                    { $$ = new BinaryExpression("*", $1, $3); }
|       TERM '/' VAL                    { $$ = new BinaryExpression("/", $1, $3); }
;

VAL:    NUM                             { $$ = new Value($1); }
|       '-' VAL                         { $$ = new UnaryExpression("-", $2); }                         
|       '(' EXPR ')'                    { $$ = $2; }
|       ID                              { $$ = new Variable($1); }
|       ID '(' ARGS ')'                 { $$ = new FunctionCall($1, $3); }
|       '&' VAL                         { $$ = new UnaryExpression("&", $2); }
|       '$' VAL                         { $$ = new UnaryExpression("$", $2); }
;

ARGS:                                   { $$.clear(); }
|       ARG                             { $$.clear(); $$.push_back($1); }
|       ARGS ',' ARG                    { $$ = $1; $$.push_back($3); }
;

ARG:    EXPR
;

DEF:    INT ID                          { $$ = new DefExpression(T_INT, $2); }
|       PTR ID                          { $$ = new DefExpression(T_PTR, $2); }
|       ARR ID '[' NUM ']'              { $$ = new DefExpression(T_ARR, $2, $4); }
;

%%
int main() { return yyparse(); }

