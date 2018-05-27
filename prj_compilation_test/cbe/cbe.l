D                       [0-9]
L                       [a-zA-Z_]
H                       [a-fA-F0-9]
E                       [Ee][+-]?{D}+
FS                      (f|F|l|L)
IS                      (u|U|l|L)*

%{
#include <stdio.h>
#include "y.tab.h"


/* Ne gere pas les commentaires. A rajouter */
/* Supprimer les lignes dont vous n'avez pas besoin. */

%}
%option yylineno
%%
"extern"                { return EXTERN;}
"if"                    { return IF;}
"int"                   { return INT;}
"return"                { return RETURN;}
"void"                  { return VOID;}
"goto"                  { return GOTO;}

{L}({L}|{D})*           { return IDENTIFICATEUR; }
{D}+                 	{ return CONSTANTE;}



"+"			{return PLUS;}
"-"			{return MOINS;}
"*"			{return MUL;}
"/"			{return DIV;}
">>"                    {return RSHIFT;}
"<<"                    {return LSHIFT;}
"&"			{return BAND;}
"|"			{return BOR;}
"&&"                    {return LAND;}
"||"                    {return LOR;}
"<"                     {return LT;}
">"                     {return GT;}
"<="                    {return LEQ;}
">="                    {return GEQ;}
"=="                    {return EQ;}
"!="                    {return NEQ;}
"!"			{return NOT;}

[ \t\v\n\f]             { ; }
"/*"([^*]|\*+[^*/])*\*+"/"		{}

";"			{return ';';}
"("			{return '(';}
")"			{return ')';}
"["			{return '[';}
"]"			{return ']';}
"{"			{return '{';}
"}"			{return '}';}
"="			{return '=';}
":"			{return ':';}
","			{return ',';}

.                       { printf("Lex erreur:%s\n\n",yytext); }
%%
