%{
//C++ part WIP
%}

%union{
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

command      -> identifier SET expression;
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
             | value ADD value
             | value SUB value
             | value MUL value
             | value DIV value
             | value MOD value

condition    -> value EQ value
             | value NEQ value
             | value GT value
             | value LT value
             | value GEQ value
             | value LEQ value

value        -> num
             | identifier

identifier   -> pidentifier
             | pidentifier[pidentifier]
             | pidentifier[num]

num			 -> NUMBER
			 |  SUB NUMBER

%%
//C++ part WIP