%{
#define CONTSTANT 11
#define IF 1
#define ELSE 2
#define STRING 3
#define FLOAT	4
#define INTEGER	5
#define SIGNEDINT 6
#define PREDEFINED_FUNCTION	77
%}
%%
[a-zA-Z][a-zA-Z0-9]*	printf("Identifier : %s\n",yytext);
[^+]?[0-9]+(.(0+))?	printf("Integer %s \n",yytext);
[0-9]+.[0-9][1-9]+ printf("Float %s\n",yytext);
.			printf("could not find at line %d \n",yylineno);
%%
