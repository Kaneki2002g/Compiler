%{
//C++ part WIP
#include <iostream>
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
%type <number> value
%type <number> expression

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

command      : identifier SET expression SEMICOLON		{std::cout<<$1<<" is set to "<<$3<<"\n";}
             | IF condition THEN commands ELSE commands ENDIF
             | IF condition THEN commands ENDIF
             | WHILE condition DO commands ENDWHILE
             | REPEAT commands UNTIL condition SEMICOLON
             | FOR pidentifier FROM value TO value DO commands ENDFOR
             | FOR pidentifier FROM value DOWNTO value DO commands ENDFOR
             | proc_call SEMICOLON
             | READ identifier SEMICOLON
             | WRITE value SEMICOLON

proc_head    : pidentifier LB args_decl RB

proc_call    : pidentifier LB args RB

declarations : declarations COMMA pidentifier
             | declarations COMMA pidentifier SLB num COLON num SRB
             | pidentifier
             | pidentifier SLB num COLON num SRB

args_decl    : args_decl COMMA pidentifier
             | args_decl COMMA T pidentifier
             | pidentifier
             | T pidentifier

args         : args COMMA pidentifier
             | pidentifier

expression   : value
             | value ADD value			{std::cout<<$1<<" adding to "<<$3<<"\n";$$=$1+$3;}
             | value SUB value			{std::cout<<$1<<" minus "<<$3<<"\n";$$=$1-$3;}
             | value MUL value			{std::cout<<$1<<" times "<<$3<<"\n";$$=$1*$3;}
             | value DIV value			{std::cout<<$1<<" divide by "<<$3<<"\n";$$=$1-$3;}
             | value MOD value			{std::cout<<$1<<" modulo "<<$3<<"\n";$$=$1 % $3;}

condition    : value EQ value			{std::cout<<$1<<"=="<<$3<<"\n";}
             | value NEQ value			{std::cout<<$1<<"!="<<$3<<"\n";}
             | value GT value			{std::cout<<$1<<">"<<$3<<"\n";}
             | value LT value			{std::cout<<$1<<"<+"<<$3<<"\n";}
             | value GEQ value			{std::cout<<$1<<">="<<$3<<"\n";}
             | value LEQ value			{std::cout<<$1<<"<="<<$3<<"\n";}

value        : num						{$$=$1;}
             | identifier				{$$=1000;}

identifier   : pidentifier				{$$=$1;}
             | pidentifier SLB pidentifier SRB	{std::cout<<"calling a table field with number of different variable"/*pid[id(?) bo mozna by zrobic tez table1[table2[x]]*/<<"\n";}
             | pidentifier SLB num SRB			{std::cout<<"calling table with nynber"<<"\n";}

num			 : NUMBER					{$$=$1;}
			 |  SUB NUMBER				{$$=-$2;}

%%
//C++ part WIP