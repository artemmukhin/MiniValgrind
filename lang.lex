%{
    #define YYSTYPE MyDataType
    #include <iostream>
    #include <string>
    #include "../Src/Types.h"
    #include "../Src/Variable.h"
    #include "../Src/Operators.h"
    #include "parser.hpp"
    extern MyDataType yylval;
    void yyerror(char *s);
%}
%option yylineno
%option noyywrap

%x STR

%%

[/][/].*\n                      ; // comment
if                              return IF;
else                            return ELSE;
while                           return WHILE;
for                             return FOR;
return                          return RETURN;
int                             return INT;
ptr                             return PTR;
arr                             return ARR;
==                              return EQ;
[<]=                            return LE;
>=                              return GE;
!=                              return NE;
&&                              return AND;
\|\|                            return OR;
\+\+                            return INC;
\-\-                            return DEC;
#begin                          return P_BEGIN;
#end                            return P_END;

[0-9]+                          {
                                    yylval.str = yytext;
                                    return NUM;
                                }

[a-zA-Z_][a-zA-Z0-9_]*          {
                                    yylval.str = yytext;
                                    return ID;
                                }

[ \t\r\n]                       ; // whitespace
[-{};()=<>+*%&/!,\[\]]          { return *yytext; }
.                               yyerror("Invalid character");

%%
