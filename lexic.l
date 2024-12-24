%option noyywrap
%option yylineno
%{
#include "gramatic_y.h"
int yylex();
%}
%%
[ \t\n]+				;
#.*(\n)?$				;

[_a-z]+ 				{
						   yylval.stringid = strdup(yytext); 
						   return pidentifer; 
						}
		   
[0-9]+      			{ 
							yylval.number = atoi(yytext);
							return NUMBER;
						}

"="						{return EQ;}
"!="					{return NEQ;}
">="					{return GEQ;}
"<="					{return LEQ;}
">"						{return GT;}
"<"						{return LT;}


"+"						{return ADD;}
"-"						{return SUB;}
"*"						{return MUL;}
"/"						{return DIV;}
"%"						{return MOD;}
":="					{return SET;}

[\[\]\(\)\:\,]			{return yytext[0];}

PROCEDURE				{return PROCEDURE;}
IS						{return IS;}
BEGIN					{return BEGIN;}
END						{return END;}
PROGRAM					{return PROGRAM;}
IF						{return IF;}
THEN					{return THEN;}
ELSE					{return ELSE;}
ENDIF					{return ENDIF;}
WHILE					{return WHILE;}
DO						{return DO;}
ENDWHILE				{return ENDWHILE;}
REPEAT					{return REPEAT;}
UNTIL					{return UNTIL;}
FOR						{return FOR;}
FROM					{return FROM;}
TO						{return TO;}
ENDFOR					{return ENDFOR;}
DOWNTO					{return DOWNTO;}
READ					{return READ;}
WRITE					{return WRITE;}
T 						{return T;}