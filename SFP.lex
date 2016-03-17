%{
//GOTO NON-TERMINALS
#define PROGRAM 7
#define STATEMENTS 8
#define STATEMENT 9
#define FUCNTIONCALL 10
#define PARAMETER 11
//ACTION TABLE TERMINALS
#define RIGHTPARANTHESIS 99
#define LEFTPARANTHERIS 100
#define FUNCTIONNAME 101
#define PRINT	102
#define KEYWORD 103
#define NUMBER 104
#define ID	82918
%}

%%
[" ""\n""\t"]                 ;
"%"			|
"+"			|
"-"			printf("predefined function  %s \n",yytext);
"return" 		printf("keyword : %s \n",yytext);
"CONSTANTS"	        printf("CONSTANT : %s \n",yytext);
"FUNCTIONS"		printf("FUNCTIONS : %s \n",yytext);
"{"			printf("opening brace : %s \n",yytext);
"}"			printf("closing brace : %s \n",yytext);
"if"			printf("keyword : %s\n",yytext);
"else"			printf("keyword %s\n",yytext);
"T"|"F"			printf("boolean recognised : %s ",yytext);
[a-zA-Z][a-zA-Z0-9]*	printf("Identifier : %s\n",yytext);
"0"			printf("leading zeroes");
[- ]?[0-9](.(0+))?	printf("Integer %s \n",yytext);
[0-9][0-9]*.[0-9][0-9]* printf("Floats %s\n",yytext);
\([a-z ]*\)             printf("this is a string %s \n",yytext);
0(0).*$                 printf("trailing zeroes \n");
.			printf("could not find at line %d \n",yylineno);
%%
