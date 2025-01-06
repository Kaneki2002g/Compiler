%{
//C++ part WIP
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <string.h>
#include "brainpart.hpp"
#include "structs.h"
extern int yylineno;

int yylex();
void yyerror(const char* msg);
int digitCount(long long num);
Component* lastnext(Component* comp);
%}
%defines "grammar.hpp"

%union{
	char* stringid;
    long long number;
	struct Component* component;
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
%type <component> num
%type <component> identifier
%type <component> value
%type <component> expression
%type <component> condition
%type <component> args
%type <component> args_decl
%type <component> declarations
%type <component> proc_call
%type <component> proc_head
%type <component> command
%type <component> main
%type <component> procedures
%type <component> program_all
%type <component> commands

%left ADD SUB
%left MUL DIV
%left MOD

%%

program_all  : procedures main		{
										$$ = new Component();
										$$->code_line=0;
										$$->type=16;
										$$->number_value=0;
										$$->pid_name=nullptr;
										$$->children=$1;
										$1->next = $2;
										$$->next=nullptr;
										buildProgram($$);
									}

procedures   : procedures PROCEDURE proc_head IS declarations T_BEGIN commands T_END	{	
																							$$=$1;
																							Component* proc = new Component();
																							proc->code_line=yylineno;
																							proc->type=151;
																							proc->number_value=0;
																							proc->pid_name=nullptr;
																							proc->children=$3;
																							proc->next=nullptr;
																							$3->next=$5;
																							$5->next=$7;
																							if($$->children==nullptr){
																								$$->children=proc; //first procedure
																							} else {
																								lastnext($$->children)->next=proc;
																							}
																						}
             | procedures PROCEDURE proc_head IS T_BEGIN commands T_END					{	
																							$$=$1; //procedures
																							Component* proc = new Component();
																							proc->code_line=yylineno;
																							proc->type=152;
																							proc->number_value=0;
																							proc->pid_name=nullptr;
																							proc->children=$3;
																							proc->next=nullptr;
																							$3->next=$6;
																							if($$->children==nullptr){
																								$$->children=proc; //first procedure
																							} else {
																								lastnext($$->children)->next=proc;
																							}
																						}
             | 																			{
																							$$ = new Component();
																							$$->code_line=0;
																							$$->type=15;
																							$$->number_value=0;
																							$$->pid_name=nullptr;
																							$$->children=nullptr;
																							$$->next=nullptr;
																						}

main         : PROGRAM IS declarations T_BEGIN commands T_END	{	
																	$$ = new Component();
																	$$->code_line=yylineno;
																	$$->type=141;
																	$$->number_value=0;
																	$$->pid_name=nullptr;
																	$$->children=$3;
																	$3->next=$5;
																	$$->next=nullptr;
																}
             | PROGRAM IS T_BEGIN commands T_END				{	
																	$$ = new Component();
																	$$->code_line=yylineno;
																	$$->type=142;
																	$$->number_value=0;
																	$$->pid_name=nullptr;
																	$$->children=$4;
																	$$->next=nullptr;
																}

commands     : commands command		{	
										$$=$1;
										lastnext($$->children)->next=$2;
									}
             | command				{	
										$$ = new Component();
										$$->code_line=yylineno;
										$$->type=13;
										$$->number_value=0;
										$$->pid_name=nullptr;
										$$->children=$1;
										$$->next=nullptr;
									}

command      : identifier SET expression SEMICOLON							{	
																				$$ = new Component();
																				$$->code_line=yylineno;
																				$$->type=121;
																				$$->number_value=0;
																				$$->pid_name=nullptr;
																				$$->children=$1;
																				$1->next=$3;
																				$$->next=nullptr;
																			}
             | IF condition THEN commands ELSE commands ENDIF				{	
																				$$ = new Component();
																				$$->code_line=yylineno;
																				$$->type=122;
																				$$->number_value=0;
																				$$->pid_name=nullptr;
																				$$->children=$2;
																				$2->next=$4;
																				$4->next=$6;
																				$$->next=nullptr;
																			}
             | IF condition THEN commands ENDIF								{	
																				$$ = new Component();
																				$$->code_line=yylineno;
																				$$->type=123;
																				$$->number_value=0;
																				$$->pid_name=nullptr;
																				$$->children=$2;
																				$2->next=$4;
																				$$->next=nullptr;
																			}
             | WHILE condition DO commands ENDWHILE							{	
																				$$ = new Component();
																				$$->code_line=yylineno;
																				$$->type=124;
																				$$->number_value=0;
																				$$->pid_name=nullptr;
																				$$->children=$2;
																				$2->next=$4;
																				$$->next=nullptr;
																			}
             | REPEAT commands UNTIL condition SEMICOLON					{	
																				$$ = new Component();
																				$$->code_line=yylineno;
																				$$->type=125;
																				$$->number_value=0;
																				$$->pid_name=nullptr;
																				$$->children=$2;
																				$2->next=$4;
																				$$->next=nullptr;
																			}
             | FOR pidentifier FROM value TO value DO commands ENDFOR		{	
																				Component* pid = new Component();
																				pid->code_line=yylineno;
																				pid->type=2; //type=pidentifier;
																				pid->number_value=0;
																				pid->pid_name=strdup($2);
																				pid->children=nullptr;
																				pid->next=nullptr;
			 
																				$$ = new Component();
																				$$->code_line=yylineno;
																				$$->type=126;
																				$$->number_value=0;
																				$$->pid_name=nullptr;
																				$$->children=pid;
																				pid->next=$4;
																				$4->next=$6;
																				$6->next=$8;
																				$$->next=nullptr;
																				useFor();
																			}
             | FOR pidentifier FROM value DOWNTO value DO commands ENDFOR	{		
																				Component* pid = new Component();
																				pid->code_line=yylineno;
																				pid->type=2; //type=pidentifier;
																				pid->number_value=0;
																				pid->pid_name=strdup($2);
																				pid->children=nullptr;
																				pid->next=nullptr;
																				
																				$$ = new Component();
																				$$->code_line=yylineno;
																				$$->type=127;
																				$$->number_value=0;
																				$$->pid_name=nullptr;
																				$$->children=pid;
																				pid->next=$4;
																				$4->next=$6;
																				$6->next=$8;
																				$$->next=nullptr;
																				useFor();
																			}
             | proc_call SEMICOLON											{	
																				$$ = new Component();
																				$$->code_line=yylineno;
																				$$->type=128;
																				$$->number_value=0;
																				$$->pid_name=nullptr;
																				$$->children=$1;
																				$$->next=nullptr;
																			}
             | READ identifier SEMICOLON									{	
																				$$ = new Component();
																				$$->code_line=yylineno;
																				$$->type=129;
																				$$->number_value=0;
																				$$->pid_name=nullptr;
																				$$->children=$2;
																				$$->next=nullptr;
																			}
             | WRITE value SEMICOLON										{	
																				$$ = new Component();
																				$$->code_line=yylineno;
																				$$->type=1210;
																				$$->number_value=0;
																				$$->pid_name=nullptr;
																				$$->children=$2;
																				$$->next=nullptr;
																			}

proc_head    : pidentifier LB args_decl RB	{	
												Component* pid = new Component();
												pid->code_line=yylineno;
												pid->type=2; //type=pidentifier;
												pid->number_value=0;
												pid->pid_name=strdup($1);
												pid->children=nullptr;
												pid->next=$3;
												
												$$ = new Component();
												$$->code_line=yylineno;
												$$->type=11;
												$$->number_value=0;
												$$->pid_name=nullptr;
												$$->children=pid;
											}

proc_call    : pidentifier LB args RB		{	
												Component* pid = new Component();
												pid->code_line=yylineno;
												pid->type=2; //type=pidentifier;
												pid->number_value=0;
												pid->pid_name=strdup($1);
												pid->children=nullptr;
												pid->next=$3;
												
												$$ = new Component();
												$$->code_line=yylineno;
												$$->type=10;
												$$->number_value=0;
												$$->pid_name=nullptr;
												$$->children=pid;
											}

declarations : declarations COMMA pidentifier						{	
																		Component* pid = new Component();
																		pid->code_line=yylineno;
																		pid->type=21; //type=pidentifier;
																		pid->number_value=0;
																		pid->pid_name=strdup($3);
																		pid->children=nullptr;
																		pid->next=nullptr;
																		
																		$$=$1;
																		lastnext($$->children)->next=pid;
																	}
             | declarations COMMA pidentifier SLB num COLON num SRB	{	
																		Component* pid = new Component();
																		pid->code_line=yylineno;
																		pid->type=22; //type=pidentifier;
																		pid->number_value=0;
																		pid->pid_name=strdup($3);
																		pid->children=$5;
																		pid->next=nullptr;
																		$5->next=$7;
																		
																		$$=$1;
																		lastnext($$->children)->next=pid;
																	}
             | pidentifier											{	
																		Component* pid = new Component();
																		pid->code_line=yylineno;
																		pid->type=21; //type=pidentifier;
																		pid->number_value=0;
																		pid->pid_name=strdup($1);
																		pid->children=nullptr;
																		pid->next=nullptr;
																		
																		$$ = new Component();
																		$$->code_line=yylineno;
																		$$->type=9;
																		$$->number_value=0;
																		$$->pid_name=nullptr;
																		$$->children=pid;
																		$$->next=nullptr;
																	}
             | pidentifier SLB num COLON num SRB					{	
																		Component* pid = new Component();
																		pid->code_line=yylineno;
																		pid->type=22; //type=pidentifier;
																		pid->number_value=0;
																		pid->pid_name=strdup($1);
																		pid->children=$3;
																		pid->next=nullptr;
																		$3->next=$5;
																		
																		$$ = new Component();
																		$$->code_line=yylineno;
																		$$->type=9;
																		$$->number_value=0;
																		$$->pid_name=nullptr;
																		$$->children=pid;
																		$$->next=nullptr;
																	}

args_decl    : args_decl COMMA pidentifier		{	
													Component* pid = new Component();
													pid->code_line=yylineno;
													pid->type=21; //type=pidentifier;
													pid->number_value=0;
													pid->pid_name=strdup($3);
													pid->children=nullptr;
													pid->next=nullptr;
													
													$$=$1;
													lastnext($$->children)->next = pid;//NIEPEWNY JESTEM
												}
             | args_decl COMMA T pidentifier	{	
													Component* pid = new Component();
													pid->code_line=yylineno;
													pid->type=22; //type=pidentifier;
													pid->number_value=0;
													pid->pid_name=strdup($4);
													pid->children=nullptr;
													pid->next=nullptr;
													
													$$=$1;
													lastnext($$->children)->next = pid;//NIEPEWNY JESTEM
												}
             | pidentifier						{	
													Component* pid = new Component();
													pid->code_line=yylineno;
													pid->type=21; //type=pidentifier;
													pid->number_value=0;
													pid->pid_name=strdup($1);
													pid->children=nullptr;
													pid->next=nullptr;
													
													$$ = new Component();
													$$->code_line=yylineno;
													$$->type=8;
													$$->number_value=0;
													$$->pid_name=nullptr;
													$$->children=pid;
													$$->next=nullptr;
												}
             | T pidentifier					{	
													Component* pid = new Component();
													pid->code_line=yylineno;
													pid->type=22; //type=pidentifier;
													pid->number_value=0;
													pid->pid_name=strdup($2);
													pid->children=nullptr;
													pid->next=nullptr;
													
													$$ = new Component();
													$$->code_line=yylineno;
													$$->type=8;
													$$->number_value=0;
													$$->pid_name=nullptr;
													$$->children=pid;
													$$->next=nullptr;
												}

args         : args COMMA pidentifier	{	
											Component* pid = new Component();
											pid->code_line=yylineno;
											pid->type=2; //type=pidentifier;
											pid->number_value=0;
											pid->pid_name=strdup($3);
											pid->children=nullptr;
											pid->next=nullptr;
											
											$$=$1;
											lastnext($$->children)->next=pid;
										}
             | pidentifier				{		
											Component* pid = new Component();
											pid->code_line=yylineno;
											pid->type=2; //type=pidentifier;
											pid->number_value=0;
											pid->pid_name=strdup($1);
											pid->children=nullptr;
											pid->next=nullptr;
											
											$$ = new Component();
											$$->code_line=yylineno;
											$$->type=7;
											$$->number_value=0;
											$$->pid_name=nullptr;
											$$->children=pid;
											$$->next=nullptr;
										}

expression   : value					{	
											$$ = new Component();
											$$->code_line=yylineno;
											$$->type=61;
											$$->number_value=0;
											$$->pid_name=nullptr;
											$$->children=$1;
											$$->next=nullptr;
										}
             | value ADD value			{	
											$$ = new Component();
											$$->code_line=yylineno;
											$$->type=62;
											$$->number_value=0;
											$$->pid_name=nullptr;
											$$->children=$1;
											$1->next=$3;
											$$->next=nullptr;
										}
             | value SUB value			{	
											$$ = new Component();
											$$->code_line=yylineno;
											$$->type=63;
											$$->number_value=0;
											$$->pid_name=nullptr;
											$$->children=$1;
											$1->next=$3;
											$$->next=nullptr;
										}
             | value MUL value			{	
											$$ = new Component();
											$$->code_line=yylineno;
											$$->type=64;
											$$->number_value=0;
											$$->pid_name=nullptr;
											$$->children=$1;
											$1->next=$3;
											$$->next=nullptr;
											if($1->children->type!=1 && $3->children->type!=1){
												useMul();
											} else{
												if($1->children->type==1){
													if($1->children->number_value>10){
														useMul();
													}
												}
												if($3->children->type==1){
													if($3->children->number_value>10){
														useMul();
													}
												}
											}
										}
             | value DIV value			{	
											$$ = new Component();
											$$->code_line=yylineno;
											$$->type=65;
											$$->number_value=0;
											$$->pid_name=nullptr;
											$$->children=$1;
											$1->next=$3;
											$$->next=nullptr;
											if($1->children->type==1 && $3->children->type==1){
												//dont use div just place a number here
											} else if ($3->children->number_value%2==0){
												//use half
											} else {
												useDiv();
											}
										}
             | value MOD value			{	
											$$ = new Component();
											$$->code_line=yylineno;
											$$->type=66;
											$$->number_value=0;
											$$->pid_name=nullptr;
											$$->children=$1;
											$1->next=$3;
											$$->next=nullptr;
											if($1->children->type==1 && $3->children->type==1){
												//dont use div just place a number here
											} else if ($3->children->number_value==2){
												//use half
												//and sub
											} else {
												useMod();
											}
										}

condition    : value EQ value			{	
											$$ = new Component();
											$$->code_line=yylineno;
											$$->type=51;
											$$->number_value=0;
											$$->pid_name=nullptr;
											$$->children=$1;
											$1->next = $3;
											$$->next=nullptr;
										}
             | value NEQ value			{	
											$$ = new Component();
											$$->code_line=yylineno;
											$$->type=52;
											$$->number_value=0;
											$$->pid_name=nullptr;
											$$->children=$1;
											$1->next = $3;
											$$->next=nullptr;
										}
             | value GT value			{	
											$$ = new Component();
											$$->code_line=yylineno;
											$$->type=53;
											$$->number_value=0;
											$$->pid_name=nullptr;
											$$->children=$1;
											$1->next = $3;
											$$->next=nullptr;
										}
             | value LT value			{	
											$$ = new Component();
											$$->code_line=yylineno;
											$$->type=54;
											$$->number_value=0;
											$$->pid_name=nullptr;
											$$->children=$1;
											$1->next = $3;
											$$->next=nullptr;
										}
             | value GEQ value			{	
											$$ = new Component();
											$$->code_line=yylineno;
											$$->type=55;
											$$->number_value=0;
											$$->pid_name=nullptr;
											$$->children=$1;
											$1->next = $3;
											$$->next=nullptr;
										}
             | value LEQ value			{	
											$$ = new Component();
											$$->code_line=yylineno;
											$$->type=56;
											$$->number_value=0;
											$$->pid_name=nullptr;
											$$->children=$1;
											$1->next = $3;
											$$->next=nullptr;
										}

value        : num						{	
											$$ = new Component();
											$$->code_line=yylineno;
											$$->type=41; //type=value ale moze mozna by robic odrazu skoierowanie na num
											$$->number_value=0;
											$$->pid_name=nullptr;
											$$->children=$1;
											$$->next=nullptr;
										}
             | identifier				{	
											$$ = new Component();
											$$->code_line=yylineno;
											$$->type=42; //type=value ale moznaby robic odrazu skoierowanie na num
											$$->number_value=0;
											$$->pid_name=nullptr;
											$$->children=$1;
											$$->next=nullptr;
										}

identifier   : pidentifier						{	
													Component* pid = new Component();
													pid->code_line=yylineno;
													pid->type=2; //type=pidentifier;
													pid->number_value=0;
													pid->pid_name=strdup($1);
													pid->children=nullptr;
													pid->next=nullptr;
													
													$$ = new Component();
													$$->code_line=yylineno;
													$$->type=31; //type=identifier;
													$$->number_value=0;
													$$->pid_name=nullptr;
													$$->children=pid;
													$$->next=nullptr;
												}
             | pidentifier SLB pidentifier SRB	{
													Component* pid1 = new Component();
													pid1->code_line=yylineno;
													pid1->type=2; //type=pidentifier;
													pid1->number_value=0;
													pid1->pid_name=strdup($1);
													pid1->children=nullptr;
													
													Component* pid2 = new Component();
													pid2->code_line=yylineno;
													pid2->type=2; //type=pidentifier;
													pid2->number_value=0;
													pid2->pid_name=strdup($3);
													pid2->children=nullptr;
													pid2->next=nullptr;
													
													pid1->next=pid2;
													
													$$ = new Component();
													$$->code_line=yylineno;
													$$->type=32; //type=identifier;
													$$->number_value=0;
													$$->pid_name=nullptr;
													$$->children=pid1;
													$$->next=nullptr;
												}
             | pidentifier SLB num SRB			{
													Component* pid = new Component();
													pid->code_line=yylineno;
													pid->type=2; //type=pidentifier;
													pid->number_value=0;
													pid->pid_name=strdup($1);
													pid->children=nullptr;
													pid->next=$3;
													
													$$ = new Component();
													$$->code_line=yylineno;
													$$->type=33; //type=identifier;
													$$->number_value=0;
													$$->pid_name=nullptr;
													$$->children=pid;
													$$->next=nullptr;
													}

num			 : NUMBER					{	
											$$ = new Component();
											$$->code_line=yylineno;
											$$->type=1; //type=num;
											$$->number_value=$1;
											$$->pid_name=nullptr;
											$$->children=nullptr;
											$$->next=nullptr;
										}
			 |  SUB NUMBER				{
											$$ = new Component();
											$$->code_line=yylineno;
											$$->type=1; //type=1;
											$$->number_value=-$2;
											$$->pid_name=nullptr;
											$$->children=nullptr;
											$$->next=nullptr;
										}

%%