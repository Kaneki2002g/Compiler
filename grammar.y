%{
//C++ part WIP
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "brainpart.hpp"
extern int yylineno;

int yylex();
void yyerror(const char* msg);
%}
%defines "grammar.hpp"

%union{
	char* stringid;
    long long number;
}

%token EQ NEQ GEQ LEQ GT LT SET
%token PROCEDURE IS T_BEGIN T_END PROGRAM
%token IF THEN ELSE ENDIF
%token WHILE DO ENDWHILE
%token REPEAT UNTIL
%token FOR FROM TO ENDFOR DOWNTO
%token T
%token READ WRITE
%token COMMA SEMICOLON SLB SRB LB RB COLON

%token <stringid> pidentifier 
%token <number> NUMBER
%type <number> num
%type <stringid> identifier
%type <stringid> value
%type <stringid> expression

%left ADD SUB
%left MUL DIV
%left MOD

%%

program_all  : procedures main

procedures   : procedures PROCEDURE proc_head IS declarations T_BEGIN commands T_END
             | procedures PROCEDURE proc_head IS T_BEGIN commands T_END
             | 

main         : PROGRAM IS declarations T_BEGIN commands T_END
             | PROGRAM IS T_BEGIN commands T_END

commands     : commands command
             | command

command      : identifier SET expression SEMICOLON		{setvar($1,$3);}
             | IF condition THEN commands ELSE commands ENDIF
             | IF condition THEN commands ENDIF
             | WHILE condition DO commands ENDWHILE
             | REPEAT commands UNTIL condition SEMICOLON
             | FOR pidentifier FROM value TO value DO commands ENDFOR
             | FOR pidentifier FROM value DOWNTO value DO commands ENDFOR
             | proc_call SEMICOLON
             | READ identifier SEMICOLON	{std::cout<<"Reading "<<$2<<"\n";}
             | WRITE value SEMICOLON		{std::cout<<"Writing "<<$2<<"\n";}

proc_head    : pidentifier LB args_decl RB

proc_call    : pidentifier LB args RB

declarations : declarations COMMA pidentifier	{declare_var($3);}
             | declarations COMMA pidentifier SLB num COLON num SRB	{declare_tab($3,$5,$7);}
             | pidentifier						{declare_var($1);}
             | pidentifier SLB num COLON num SRB	{declare_tab($1,$3,$5);}

args_decl    : args_decl COMMA pidentifier
             | args_decl COMMA T pidentifier
             | pidentifier
             | T pidentifier

args         : args COMMA pidentifier
             | pidentifier

expression   : value
             | value ADD value			{$$=add($1,$3);}
             | value SUB value			{$$=sub($1,$3);}
             | value MUL value			{$$=mul($1,$3);}
             | value DIV value			{$$=div($1,$3);}
             | value MOD value			{$$=mod($1,$3);}

condition    : value EQ value			{std::cout<<$1<<"=="<<$3<<"\n";}
             | value NEQ value			{std::cout<<$1<<"!="<<$3<<"\n";}
             | value GT value			{std::cout<<$1<<">"<<$3<<"\n";}
             | value LT value			{std::cout<<$1<<"<+"<<$3<<"\n";}
             | value GEQ value			{std::cout<<$1<<">="<<$3<<"\n";}
             | value LEQ value			{std::cout<<$1<<"<="<<$3<<"\n";}

value        : num						{$$=strdup(std::to_string($1).c_str());/*debilne ale moze zadziala*/}
             | identifier				{$$=$1;/*if not set error*/}

identifier   : pidentifier				{$$=$1;}
             | pidentifier SLB pidentifier SRB	{$$=strcpy(strcpy(strcpy($1,'['),$3),']');}
             | pidentifier SLB num SRB			{}

num			 : NUMBER					{$$=$1;}
			 |  SUB NUMBER				{$$=-$2;}

%%
//C++ part WIP