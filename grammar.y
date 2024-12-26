%{
//C++ part WIP
extern int yylineno;

int yylex();
void yyerror(const char* msg);
%}
%language "c++"
%defines "grammar.hpp"

%union{
	char* stringid;
    long long number;
}

%token EQ NEQ GEQ LEQ GT LT SET
%token PROCEDURE IS BEGIN END PROGRAM
%token IF THEN ELSE ENDIF
%token WHILE DO ENDWHILE
%token REPEAT UNTIL
%token FOR FROM TO ENDFOR DOWNTO
%token T
%token READ WRITE
%token COMMA SEMICOLON SLB SRB LB RB COLON
%token pidentifier NUMBER

%type <stringid> pidentifier 
%type <number> NUMBER

%left ADD SUB
%left MUL DIV
%left MOD

%%

program_all  : procedures main

procedures   : procedures PROCEDURE proc_head IS declarations BEGIN commands END
             | procedures PROCEDURE proc_head IS BEGIN commands END
             | 

main         : PROGRAM IS declarations BEGIN commands END
             | PROGRAM IS BEGIN commands END

commands     : commands command
             | command

command      : identifier SET expression SEMICOLON		{std::cout<<$1<<" is set to "<<$3<<endl;}
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
             | value ADD value			{std::cout<<$1<<" adding to "<<$3<<endl;$$=$1+$3;}
             | value SUB value			{std::cout<<$1<<" minus "<<$3<<endl;$$=$1-$3;}
             | value MUL value			{std::cout<<$1<<" times "<<$3<<endl;$$=$1*$3;}
             | value DIV value			{std::cout<<$1<<" divide by "<<$3<<endl;$$=$1-$3;}
             | value MOD value			{std::cout<<$1<<" modulo "<<$3<<endl;$$=$1 % $3;}

condition    : value EQ value			{std::cout<<$1<<"=="<<$3<<endl;}
             | value NEQ value			{std::cout<<$1<<"!="<<$3<<endl;}
             | value GT value			{std::cout<<$1<<">"<<$3<<endl;}
             | value LT value			{std::cout<<$1<<"<+"<<$3<<endl;}
             | value GEQ value			{std::cout<<$1<<">="<<$3<<endl;}
             | value LEQ value			{std::cout<<$1<<"<="<<$3<<endl;}

value        : num						{$$=$1;}
             | identifier				{$$=1000;}

identifier   : pidentifier				{$$=$1;}
             | pidentifier SLB pidentifier SRB	{std::cout<<"calling a table field with number of different variable"/*pid[id(?) bo mozna by zrobic tez table1[table2[x]]*/<<endl;}
             | pidentifier SLB num SRB			{std::cout<<"calling table with nynber"<<endl;}

num			 : NUMBER					{$$=$1;}
			 |  SUB NUMBER				{$$=-$2;}

%%
//C++ part WIP