%{ 1
/*
* Word recognizer with a symbol table.
*/
enum {
LOOKUP = 0,
VERB,
ADJ,
ADV,
NOUN,
PREP,
PRON,
CONJ,
};
int state;
int addword(int type, char *word) ;
int lookupPtrj0rd (char *word) ;
%}
%%
"go"  						{printf("%s: is a verb\n", yytext);}  
%%
main(){
printf("here starts the main");
yylex();
return 0;
}
