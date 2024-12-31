#ifndef STRUCTS_H
#define STRUCTS_H

struct Component{
	int code_line;
	int type;
	long long number_value;
	char* pid_name;
	Component *children;
	Component *next;
	/*
	TYPES
	1 - num
	2 - pidentifier
		  - for anything else than:
		1 - var(for args_decl, declarations)
		2 - table(for args_decl, declarations)
	3 - identifier
		1 - pidentifier
		2 - pidentifier[pidentifier]
		3 - pidentifier[num]
	4 - value
		1 - num
		2 - identifier
	5 - condition
		1 - EQ
		2 - NEQ
		3 - GT
		4 - LT
		5 - GEQ
		6 - LEQ
	6 - expression
		1 - value
		2 - ADD
		3 - SUB
		4 - MUL
		5 - DIV
		6 - MOD
	7 - args
	8 - args_decl
	9 - declarations
	10 - proc_call
	11 - proc_head
	12 - command
		1 - set
		2 - if then else
		3 - if then
		4 - while do 
		5 - repeat until
		6 - for from to do
		7 - for from downto do
		8 - proc_call
		9 - read
		10 - write
	13 - commands
	14 - main
		1 - with declarations
		2 - without declarations
	15 - procedures
		  - start of list
		1 - with declarations
		2 - without declarations
	16 - all
	
	*/
};

#endif //STRUCTS_H