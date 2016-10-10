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
        std::list<Operator*> opers;
        Expression* expr;
        std::list<Expression*> args;
    } YYSTYPE;
    #define YYSTYPE YYSTYPE
%}

%token IF ELSE WHILE EXIT
%token EQ LE GE NE
%token NUM ID
%token INT PTR ARR

%type<str> ID NUM
%type<oper> OP1 OP2 OP BLOCK
%type<opers> OPS
%type<expr> EXPR EXPR2 TERM VAL ARG
%type<args> ARGS

%%

PROGRAM: BLOCK                          { $1->print(); delete $1; }
;

BLOCK:  '{' OPS '}'                     { $$ = new Block($2); }

OPS:                                    { $$.clear(); }
|       OP                              { $$.clear(); $$.push_back($1); }
|       OPS OP                          { $$ = $1; $$.push_back($2); }
;

OP1:    BLOCK                           { $$ = $1; }
|       EXPR ';'                        { $$ = new ExprOperator($1); }
|       IF '(' EXPR ')' OP1 ELSE OP1    { $$ = new IfOperator($3, $5, $7); }
|       WHILE '(' EXPR ')' OP1          { $$ = new WhileOperator($3, $5); }
;

OP2:    IF '(' EXPR ')' OP1             { $$ = new IfOperator($3, $5, nullptr); }
|       IF '(' EXPR ')' OP2             { $$ = new IfOperator($3, $5, nullptr); }
|       IF '(' EXPR ')' OP1 ELSE OP2    { $$ = new IfOperator($3, $5, $7); }
|       WHILE '(' EXPR ')' OP2          { $$ = new WhileOperator($3, $5); }
;

OP:     OP1
|       OP2
|       INT ID ';'                      { $$ = new DefOperator(T_INT, $2); }
|       PTR ID ';'                      { $$ = new DefOperator(T_PTR, $2); }
|       ARR ID "[[" NUM "]]" ';'        { $$ = new DefOperator(T_ARR, $2, $4); }
|       ID '=' EXPR2 ';'                { $$ = new AssignOperator($1, $3); }
|       ID '[' EXPR2 ']' '=' EXPR2 ';'  { $$ = new AssignOperator($1, $6, $3); }
;

EXPR:   EXPR2
|       EXPR EQ EXPR2                  { $$ = new BinaryExpression("==", $1, $3); }
|       EXPR LE EXPR2                  { $$ = new BinaryExpression("<=", $1, $3); }
|       EXPR GE EXPR2                  { $$ = new BinaryExpression(">=", $1, $3); }
|       EXPR NE EXPR2                  { $$ = new BinaryExpression("!=", $1, $3); }
|       EXPR '>' EXPR2                 { $$ = new BinaryExpression(">", $1, $3);  }
|       EXPR '<' EXPR2                 { $$ = new BinaryExpression("<", $1, $3);  }
|       ID '[' EXPR2 ']'               { $$ = new ArrayAtExpression($1, $3); }
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


%%
int main() { return yyparse(); }

