/**
    Mini Valgrind
    lang.y
    Parser for MiniC (Bison)

    @author Artem Mukhin
*/

%{
    #define YYSTYPE MyDataType
    #include <iostream>
    #include <string>
    #include "../Src/Types.h"
    #include "../Src/Variable.h"
    #include "../Src/Statements.h"
    extern int yylineno;
    int yylex();
    void yyerror(char *s) {
       std::cerr << s << ", line " << yylineno << std::endl;
       exit(1);
    }
%}

%token IF ELSE WHILE FOR RETURN P_BEGIN P_END
%token EQ LE GE NE AND OR INC DEC
%token NUM IDENTIFIER GLOBAL
%token INT PTR ARR

%type<str> IDENTIFIER NUM
%type<statement> STAT STAT1
%type<block> BLOCK
%type<statements> STATS
%type<expr> EXPR EXPR2 TERM VAL ARG
%type<args> ARGS
%type<func> FUNC
%type<funcs> FUNCS
%type<prog> PROGRAM
%type<param> PARAM
%type<params> PARAMS
%type<globs> GLOBALS

%%

PROGRAM: P_BEGIN GLOBALS FUNCS P_END            {
                                                    Program& p = Program::Instance();
                                                    p.setGlobals($2);
                                                    p.setFuncs($3);
                                                    p.run();
                                                    p.finalize();
                                                    delete $2;
                                                }
|        P_BEGIN FUNCS P_END                    {
                                                    Program& p = Program::Instance();
                                                    p.setFuncs($2);
                                                    p.run();
                                                    p.finalize();
                                                }
;

GLOBALS: GLOBAL BLOCK                           { $$ = new Globals($2); }

FUNCS:  FUNC                                    { $$.clear(); $$.push_back($1); }
|       FUNCS FUNC                              { $$ = $1; $$.push_back($2); }
;

FUNC:   INT IDENTIFIER '(' PARAMS ')' BLOCK     { $$ = new Function($2, T_INT, $4, $6); }
|       PTR IDENTIFIER '(' PARAMS ')' BLOCK     { $$ = new Function($2, T_PTR, $4, $6); }
|       ARR IDENTIFIER '(' PARAMS ')' BLOCK     { $$ = new Function($2, T_ARR, $4, $6); }
;

PARAM:  INT IDENTIFIER                          { $$ = new Parameter(T_INT, $2); }
|       PTR IDENTIFIER                          { $$ = new Parameter(T_PTR, $2); }
|       ARR IDENTIFIER                          { $$ = new Parameter(T_ARR, $2); }
;

PARAMS:                                         { $$.clear(); }
|       PARAM                                   { $$.clear(); $$.push_back($1); }
|       PARAMS ',' PARAM                        { $$ = $1; $$.push_back($3); }

BLOCK:  '{' STATS '}'                           { $$ = new Block($2); }
|       '{'     '}'                             { $$ = new Block(); }

STATS:  STAT                                    { $$.clear(); $$.push_back($1); }
|       STATS STAT                              { $$ = $1; $$.push_back($2); }
;

STAT:   STAT1                                   { $$ = $$; }
|       IF'(' EXPR ')' BLOCK ELSE BLOCK         { $$ = new IfStatement($3, $5, $7); }
|       IF '(' EXPR ')' BLOCK                   { $$ = new IfStatement($3, $5, nullptr); }
|       WHILE '(' EXPR ')' BLOCK                { $$ = new WhileStatement($3, $5); }
|       FOR '(' STAT1 EXPR ';' STAT1 ')' BLOCK  { $$ = new ForStatement($3, $4, $6, $8); }
|       RETURN EXPR ';'                         { $$ = new ReturnStatement($2); }
;

STAT1:  INT IDENTIFIER ';'                      { $$ = new DefStatement(T_INT, $2, nullptr); }
|       INT IDENTIFIER '=' EXPR ';'             { $$ = new DefStatement(T_INT, $2, $4); }
|       PTR IDENTIFIER ';'                      { $$ = new DefStatement(T_PTR, $2, nullptr); }
|       PTR IDENTIFIER '=' EXPR ';'             { $$ = new DefStatement(T_PTR, $2, $4); }
|       ARR IDENTIFIER '[' NUM ']' ';'          { $$ = new DefStatement(T_ARR, $2, $4, nullptr); }
|       IDENTIFIER '=' EXPR ';'                 { $$ = new AssignStatement($1, $3); }
|       '*' IDENTIFIER '=' EXPR ';'             { $$ = new AssignStatement($2, $4, true); }
|       IDENTIFIER '[' EXPR2 ']' '=' EXPR2 ';'  { $$ = new AssignStatement($1, $6, $3); }
|       EXPR ';'                                { $$ = new ExprStatement($1); }
;

EXPR:   EXPR2
|       EXPR EQ EXPR2                           { $$ = new BinaryExpression("==", $1, $3); }
|       EXPR LE EXPR2                           { $$ = new BinaryExpression("<=", $1, $3); }
|       EXPR GE EXPR2                           { $$ = new BinaryExpression(">=", $1, $3); }
|       EXPR NE EXPR2                           { $$ = new BinaryExpression("!=", $1, $3); }
|       EXPR '>' EXPR2                          { $$ = new BinaryExpression(">", $1, $3); }
|       EXPR '<' EXPR2                          { $$ = new BinaryExpression("<", $1, $3); }
|       EXPR AND EXPR2                          { $$ = new BinaryExpression("&&", $1, $3); }
|       EXPR OR EXPR2                           { $$ = new BinaryExpression("||", $1, $3); }
;

EXPR2:  TERM
|       EXPR2 '+' TERM                          { $$ = new BinaryExpression("+", $1, $3); }
|       EXPR2 '-' TERM                          { $$ = new BinaryExpression("-", $1, $3); }
|       EXPR2 '%' EXPR2                         { $$ = new BinaryExpression("%", $1, $3); }
;

TERM:   VAL
|       TERM '*' VAL                            { $$ = new BinaryExpression("*", $1, $3); }
|       TERM '/' VAL                            { $$ = new BinaryExpression("/", $1, $3); }
;

VAL:    NUM                                     { $$ = new ValueExpression($1); }
|       '-' VAL                                 { $$ = new UnaryExpression("-", $2); }
|       '!' VAL                                 { $$ = new UnaryExpression("!", $2); }
|       VAL INC                                 { $$ = new UnaryExpression(".++", $1); }
|       VAL DEC                                 { $$ = new UnaryExpression(".--", $1); }
|       INC VAL                                 { $$ = new UnaryExpression("++.", $2); }
|       DEC VAL                                 { $$ = new UnaryExpression("--.", $2); }
|       '(' EXPR ')'                            { $$ = $2; }
|       IDENTIFIER                              { $$ = new VarExpression($1); }
|       IDENTIFIER '(' ARGS ')'                 { $$ = new FunCallExpression($1, $3); }
|       '&' VAL                                 { $$ = new UnaryExpression("&", $2); }
|       '*' VAL                                 { $$ = new UnaryExpression("*", $2); }
|       IDENTIFIER '[' EXPR2 ']'                { $$ = new ArrayAtExpression($1, $3); }
;

ARGS:                                           { $$.clear(); }
|       ARG                                     { $$.clear(); $$.push_back($1); }
|       ARGS ',' ARG                            { $$ = $1; $$.push_back($3); }
;

ARG:    EXPR
;


%%
int main() { return yyparse(); }

