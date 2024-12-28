%option noyywrap
%option yylineno
%{
#include <iostream>
#include <stdlib.h>
#include <cstring>

#include "grammar.hpp"
extern YYSTYPE yylval;
int yylex();
%}
%%
[ \t\n]+				;
#.*(\n)?$				;

[_a-z]+ 				{
						   yylval.stringid = strdup(yytext); 
						   return pidentifier; 
						}
		   
[0-9]+      			{ 
							yylval.number = atoll(yytext);
							return NUMBER;
						}

","						{return COMMA;}
";"						{return SEMICOLON;}
"["						{return SLB;}
"]"						{return SRB;}
"("						{return LB;}
")"						{return RB;}
":"						{return COLON;}

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


T 						{return T;}
PROCEDURE				{return PROCEDURE;}
IS						{return IS;}
BEGIN					{return T_BEGIN;}
END						{return T_END;}
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
%%