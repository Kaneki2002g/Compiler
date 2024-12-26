%{
//C++ part WIP
extern int yylineno;
%}
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
%token READ WRITE

%token <stringid> pidentifier 
%token <number> NUMBER

%left ADD SUB
%left MUL DIV

%%

program_all  -> procedures main

procedures   -> procedures PROCEDURE proc_head IS declarations BEGIN commands END
             | procedures PROCEDURE proc_head IS BEGIN commands END
             | 

main         -> PROGRAM IS declarations BEGIN commands END
             | PROGRAM IS BEGIN commands END

commands     -> commands command
             | command

command      -> identifier SET expression;		{std::cout<<$1<<" is set to "<<$3<<endl;}
             | IF condition THEN commands ELSE commands ENDIF
             | IF condition THEN commands ENDIF
             | WHILE condition DO commands ENDWHILE
             | REPEAT commands UNTIL condition;
             | FOR pidentifier FROM value TO value DO commands ENDFOR
             | FOR pidentifier FROM value DOWNTO value DO commands ENDFOR
             | proc_call;
             | READ identifier;
             | WRITE value;

proc_head    -> pidentifier ( args_decl )

proc_call    -> pidentifier ( args )

declarations -> declarations, pidentifier
             | declarations, pidentifier[num:num]
             | pidentifier
             | pidentifier[num:num]

args_decl    -> args_decl, pidentifier
             | args_decl, T pidentifier
             | pidentifier
             | T pidentifier

args         -> args, pidentifier
             | pidentifier

expression   -> value
             | value ADD value			{std::cout<<$1<<" adding to "<<$3<<endl;}
             | value SUB value			{std::cout<<$1<<" minus "<<$3<<endl;}
             | value MUL value			{std::cout<<$1<<" times "<<$3<<endl;}
             | value DIV value			{std::cout<<$1<<" divide by "<<$3<<endl;
             | value MOD value			{std::cout<<$1<<" modulo "<<$3<<endl;}

condition    -> value EQ value			{std::cout<<$1<<"=="<<$3<<endl;}
             | value NEQ value			{std::cout<<$1<<"!="<<$3<<endl;}
             | value GT value			{std::cout<<$1<<">"<<$3<<endl;}
             | value LT value			{std::cout<<$1<<"<+"<<$3<<endl;}
             | value GEQ value			{std::cout<<$1<<">="<<$3<<endl;}
             | value LEQ value			{std::cout<<$1<<"<="<<$3<<endl;}

value        -> num
             | identifier

identifier   -> pidentifier				{$$=$1;}
             | pidentifier[pidentifier]	{std::cout<<"calling a table field with number of different variable"/*pid[id(?) bo mozna by zrobic tez table1[table2[x]]*/<<endl;}
             | pidentifier[num]			std::cout<<"calling table with nynber"<<endl;

num			 -> NUMBER					{$$=$1;}
			 |  SUB NUMBER				{$$=-$2}

%%
//C++ part WIP