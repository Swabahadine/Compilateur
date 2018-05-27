%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <assert.h>

int yylex();
int yylineno;
char* yytext;
void yyerror(char *s) {
	fprintf(stderr, "Error: %s ligne %d token:%s\n", s, yylineno, yytext);
	exit(1); /* le programe s'arrete lors d'une erreur de syntaxe */
}

%}
%token IDENTIFICATEUR CONSTANTE VOID INT FOR WHILE IF ELSE SWITCH CASE DEFAULT
%token BREAK RETURN PLUS MOINS MUL DIV LSHIFT RSHIFT BAND BOR LAND LOR LT GT 
%token GEQ LEQ EQ NEQ NOT EXTERN GOTO
%left PLUS MOINS
%left MUL DIV
%left LSHIFT RSHIFT
%left BOR BAND
%left LAND LOR
%nonassoc THEN
%nonassoc ELSE
%left OP
%left REL
%start programme
%%
programme	:	
		liste_declarations liste_fonctions
;
liste_declarations	:	
		liste_declarations declaration 
	|	
;
liste_fonctions	:	
		liste_fonctions fonction
|               fonction
;
declaration	:	
		type liste_declarateurs ';'
;
liste_declarateurs	:	
		liste_declarateurs ',' declarateur
	|	declarateur
;
declarateur	:	
		IDENTIFICATEUR
| MUL IDENTIFICATEUR
| IDENTIFICATEUR '[' CONSTANTE ']'
;
fonction	:	
		type IDENTIFICATEUR '(' liste_parms ')' '{' liste_declarations liste_instructions '}'
	|	EXTERN type IDENTIFICATEUR '(' liste_parms ')' ';'
;
type	:	
		VOID
	|	INT
;
liste_parms	: 
		parm 
	|	
		liste_parms ',' parm 

	|	
;
parm	:	
		INT IDENTIFICATEUR
;
liste_instructions :	
		liste_instructions instruction
	|
;
instruction	:	
                instructionlabelisee
	|	saut
	|	affectation 
	|	bloc
	|	appel
;
saut	:	
		GOTO IDENTIFICATEUR ';'
	|	IF '(' condition ')' GOTO IDENTIFICATEUR ';'
        |       RETURN scalaire ';'
	|	RETURN ';'
;
instructionlabelisee: IDENTIFICATEUR ':' instruction 
;
affectation	:	
		IDENTIFICATEUR '=' expression ';' {printf("affectation\n");}
		| IDENTIFICATEUR '=' MUL IDENTIFICATEUR ';'
		| MUL IDENTIFICATEUR '=' scalaire ';'
;
bloc	:	
		'{' liste_declarations liste_instructions '}'
;
appel	:	
		IDENTIFICATEUR '(' liste_scalaires ')' ';'
;
scalaire	:	
		IDENTIFICATEUR
	|	CONSTANTE
;
expression	:	
		scalaire binary_op scalaire 
	|	MOINS scalaire
|       scalaire
|	IDENTIFICATEUR '(' liste_scalaires ')' {printf("expression\n");}
;
liste_scalaires	:

scalaire	|
		liste_scalaires ',' scalaire { printf("liste_scalaire\n");}
	|
;
condition	:	
		NOT IDENTIFICATEUR 
	|	NOT '(' condition ')'
	|	'(' condition ')'
	|	scalaire binary_rel scalaire %prec REL
	|	scalaire binary_comp scalaire
;
binary_op	:	
		PLUS
	|       MOINS
	|	MUL
	|	DIV
	|       LSHIFT
	|       RSHIFT
	|	BAND
	|	BOR
;
binary_rel	:	
		LAND
	|	LOR
;
binary_comp	:	
		LT
	|	GT
	|	GEQ
	|	LEQ
	|	EQ
	|	NEQ
;
%%
int main(int argc, const char *argv[]){	
 	yyparse();
 }

