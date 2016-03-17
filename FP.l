%{
#include "FP.h"
%}

%%
[\n \t]							 ;
"{"                            			  	 return OB;
"}"                              				 return CB;
loop							 return LOOP;
print                               			 return PRINT;
=                               			 return EQUALS;
"+"                              			 return FUNC;
"*"                              			 return FUNC;
"0"                                                    	 return NUMBER;
[-]?[ ]+?[1-9][0-9]?[0-9]?[0-9]?[0-9]?[0-9]?             return NUMBER;
[-]?[ ]+?[1-9][0-9][0-9][0-9][0-9][0-9][0-9]+            printf("overflow%s",yytext);
[ ]+?(0)"."(0)+					         return NUMBER; 
(-)?[ ]+?(0)(".")[0]+[1-9]+[0-9]*                        return NUMBER;
(-)?[ ]+?(0)(".")[1-9]+[0-9]*			       	 return NUMBER; 
(-)?[ ]+?([1-9])([0-9]*)"."([0-9]+)                	 return NUMBER;
[a-z][a-z]*	                                	 return IDENTIFIER;
END							 return -1;
.							 printf("unrecognised string: %s\n",yytext);
%%

int yywrap(void){
//[a-z][a-z0-9]*                                                 return IDENTIFIER;
	
return 1;
}
