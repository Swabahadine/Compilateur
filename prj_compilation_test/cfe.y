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

char* concat(int n_args, ...) {
	/* Fonction a arité variable qui concactène des chaines de caractères */
   va_list valist;
   int i;
   int BUFFER_SIZE;
   va_start(valist, n_args);
   for (i = 0; i < n_args; i++) BUFFER_SIZE += strlen(va_arg(valist, char*));
   va_end(valist);
   char* result = (char*) calloc(BUFFER_SIZE*2, sizeof(char));
   va_start(valist, n_args);
   for (i = 0; i < n_args; i++) strcat(result, va_arg(valist, char*));
   va_end(valist);
   return result;
}

int noEtq = 1;
int break_temp = 0;
    
char* newEtq() {
    char* nc = (char*) calloc(10, sizeof(char));
    sprintf(nc,"L%d",noEtq++);
    if(break_temp != 0){
        sprintf(nc,"L%d",break_temp);
        break_temp = 0;
            }
    return nc;
}
    

typedef struct Case_instuction Case_instuction;
struct Case_instuction
{
    char* cons;
    char* instruction;
};

typedef struct Switcher Switcher;
struct Switcher
{
    Case_instuction tab_case[100];
    int n;
};
    
Switcher switcher;
char* conser[10];
char* caser[10];
int cpt_n = 0;
    
char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}


%}
%token<chaine> VOID INT FOR WHILE IF ELSE SWITCH CASE DEFAULT
%token<chaine> IDENTIFICATEUR;
%token<chaine> CONSTANTE;


%token BREAK RETURN PLUS MOINS MUL DIV LSHIFT RSHIFT BAND BOR LAND LOR LT GT 
%token GEQ LEQ EQ NEQ NOT EXTERN
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

%type<chaine> liste_declarateurs declarateur programme liste_declarations declaration type liste_parms liste_instructions binary_op binary_comp binary_rel condition liste_fonctions fonction parm instruction iteration selection saut affectation bloc appel expression variable 
liste_expressions 
%union{
	char* chaine; 
	int valnum;
};

%%
programme	:	
		liste_declarations liste_fonctions {
            FILE* fichier = fopen("out.c","w");
            fprintf(fichier, "%s%s\n", $1,$2);
            fclose(fichier);
        }
;
liste_declarations	:	
		liste_declarations declaration { $$ = concat(2, $1, $2);}
	|	{$$ = "";}
;
liste_fonctions	:	
		liste_fonctions fonction { $$ = concat(2, $1, $2);}
|               fonction {$$ = $1;}
;
declaration	:	
		type liste_declarateurs ';' {$$ = concat(4, $1, " ", $2, ";\n");}
;
liste_declarateurs	:	
		liste_declarateurs ',' declarateur {$$ = concat(3, $1, ",", $3);}
	|	declarateur {$$ = $1;}
;
declarateur	:	
		IDENTIFICATEUR {$$ = $1;}
	|	declarateur '[' CONSTANTE ']' {$$ = concat(4, $1, "[",$3, "]");}
;
fonction	:	
		type IDENTIFICATEUR '(' liste_parms ')' '{' liste_declarations liste_instructions '}' {$$ = concat(10,$1," ",$2,"(",$4,")","{\n",$7,$8,"}\n");}
	|	EXTERN type IDENTIFICATEUR '(' liste_parms ')' ';' {$$ = concat(7, "extern ", $2," ", $3, "(", $5, ");\n");}
;
type	:	
		VOID {$$ = "void";}
	|	INT {$$ = "int";}
;
liste_parms	: 
		parm {$$ = $1;}
	|	
		liste_parms ',' parm {$$ = concat(3,$1,",",$3);}
	|	{$$="";}
;
parm	:	
		INT IDENTIFICATEUR {$$ = concat(2,"int ",$2);}
;
liste_instructions :	
		liste_instructions instruction {$$ = concat(2,$1,$2);}
	| {$$ = "";}
;
instruction	:	
		iteration {$$ = $1;}
	|	selection {$$ = $1;}
	|	saut {$$ = $1;}
	|	affectation ';' {$$ = concat(2,$1,";\n");}
	|	bloc {$$ = $1;}
	|	appel {$$ = $1;}
; 
iteration	:	
		FOR '(' affectation ';' condition ';' affectation ')' instruction {
            char* L1 = newEtq();
            char* L2 = newEtq();
            $$ = concat(17,$3,"\n",L1,":if(",$5,")","goto ",L2,";",$9,$7,"\n","goto ",L1,";\n",L2,":") ; 
        }
	|	WHILE '(' condition ')' instruction /*{$$ = concat(5,"while","(",$3,")",$5);}*/
    {
        char* L1 = newEtq();
        char* L2 = newEtq();
        
        $$ = concat(14,"goto ",L1,";\n",L2,":",$5,L1,": if","(",$3,")","goto ",L2,";\n");
    }
;
selection	:	
		IF '(' condition ')' instruction %prec THEN 
        {  
            
            char* L = newEtq();
            $$ = concat(9,"if","(!",$3,") goto ",L,";\n",$5,L,": ");
        
        }
	|	IF '(' condition ')' instruction ELSE instruction {
            char* L1 = newEtq();
            char* L2 = newEtq();
            $$ = concat(16,"if","(!(",$3,")) goto ",L2,";\n",$5,"goto ",L1,";\n",L2,": ",$7,"\n",L1,": ");
        }
	|	SWITCH '(' expression ')' instruction {
            int i = 0;
            $$="";
            char* Ld = newEtq();
            while(i<cpt_n){
            
                char* L = newEtq();
                
                $$ = concat(12,$$,"if","(!(",$3,"==",conser[i],")) goto ",L,";\n",caser[i],L,": ");
                i=i+1;
            }
            $$ = concat(4,$$,"\n",Ld,":");
            
            cpt_n = 0;
        }
	|	CASE CONSTANTE ':' instruction {
            printf("$2==%s\n",$2);
            conser[cpt_n] = $2;
            caser[cpt_n++] = $4;
            $$="";
            }
	|	DEFAULT ':' instruction {$$ = concat(3,"default",":",$3);}
;
saut	:	
		BREAK ';' {
            char* L = newEtq();
            break_temp = --noEtq;
            $$ = concat(3,"goto ",L,";\n");
        }
	|	RETURN ';' {$$ = concat(2,"return ",";\n");}
	|	RETURN expression ';' {$$ = concat(3,"return ",$2,";\n");}
;
affectation	:	
		variable '=' expression {$$ = concat(3,$1," = ",$3);}
;
bloc	:	
		'{' liste_declarations liste_instructions '}' {$$ = concat(4,"{\n",$2,$3,"}\n");}
;
appel	:	
		IDENTIFICATEUR '(' liste_expressions ')' ';' {$$ = concat(5,$1,"(",$3,")",";\n");}
;
variable	:	
		IDENTIFICATEUR {$$ = $1 ;}
	|	variable '[' expression ']' {$$ = concat(4,$1,"[",$3,"]");}
;
expression	:	
		'(' expression ')' {$$ = concat(3,"(",$2,")");}
	|	expression binary_op expression %prec OP {$$= concat(3,$1,$2,$3);}
	|	MOINS expression {$$ = concat(2,"-",$2);}
	|	CONSTANTE {$$ = $1 ;}
	|	variable {$$ = $1 ;}
	|	IDENTIFICATEUR '(' liste_expressions ')' {$$ = concat(4,$1,"(",$3,")") ;}
;
liste_expressions	: 
		expression {$$ = $1;}
	| 
		liste_expressions ',' expression {$$ = concat(3,$1,",",$3);}
	| {$$ = "";}
;
condition	:	
		NOT '(' condition ')' {$$ = concat(4,"!","(",$3,")");}
	|	condition binary_rel condition %prec REL {$$ = concat(3,$1,$2,$3);}
	|	'(' condition ')' {$$ = concat(3,"(",$2,")");}
	|	expression binary_comp expression {$$ = concat(3,$1,$2,$3);}
;
binary_op	:	
		PLUS {$$ = "+";}
	|       MOINS {$$ = "-";}
	|	MUL {$$ = "*";}
	|	DIV {$$ = "/";}
	|       LSHIFT {$$ = "<<";}
	|       RSHIFT {$$ = ">>";}
	|	BAND {$$ = "&";}
	|	BOR {$$ = "|";}
;
binary_rel	:	
		LAND {$$ = "&&";}
	|	LOR {$$ = "||";}
;
binary_comp	:	
		LT {$$ = "<";}
	|	GT {$$ = ">";}
	|	GEQ {$$ = ">=";}
	|	LEQ {$$ = "<=";}
	|	EQ {$$ = "==";}
	|	NEQ {$$ = "!=";}
;
%%

int main(int argc, const char *argv[]){	
 	yyparse();
 }

