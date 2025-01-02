#include "brainpart.hpp"
//#include <map>
//#include <vector> to w brainpart.hpp

long long memCounter = 1;
long long ASSLINE = 0;
long long posCounter = 0;
long long helpCounter = 0;

int mulUses=0;
int divUses=0;
int modUses=0;

std::map<std::string,int> procedure_uses;
std::stack<long long> returnLines;

namespace vars{
	class Variable{
		public:
			void use(){used++;}
			void set(){sett=true;}
			bool isSet(){return sett;}
			int timesUsed(){return used;}
			std::string getName(){return name;}
			unsigned long long int getPos(){return memory_cell;}
		private:
			std::string name;
			int used;
			bool sett;
			unsigned long long int memory_cell;
			
		public:
			Variable(const std::string& name) : name(name), used(0), sett(false), memory_cell(memCounter) {}
	};
	
	class Table{
		public:
			void use(){used++;}
			void set(long long i){sett[i]=true;}
			bool isSet(long long i){return sett[i];}
			int timesUsed(){return used;}
			std::string getName(){return name;}
			unsigned long long int getPos(long long i){return memory_cell+(i-first);/*TODO - Check if (i-first+1) is better && Guard, for OutOfBounds type error*/}
		private:
			std::string name;
			std::vector<bool> sett;
			long long first;
			long long last;
			int used;
			unsigned long long int memory_cell;
		public:
			Table(const std::string& name, long long a, long long b) : name(name), sett(b-a+1,false), first(a), last(b), used(0), memory_cell(memCounter) {}
	};
	
	class Procedure{
		public:
			Procedure(const std::string& name){
				
			}
		private:
	};
};

std::map<std::string, vars::Variable> variables;
std::map<std::string, vars::Table> tables;
std::map<std::string,vars::Procedure> procedures;

void toProg(std::string comm, long long i){
	//TEMP
	std::cout<<comm<<" "<<i<<"\n";
	ASSLINE++;
}

void GET(long long i){
	toProg("GET",i);
}
void PUT(long long i){
	toProg("PUT",i);
}
void LOAD(long long i){
	toProg("LOAD",i);
}
void STORE(long long i){
	toProg("STORE",i);
}
void LOADI(long long i){
	toProg("LOADI",i);
}
void STOREI(long long i){
	toProg("STOREI",i);
}
void ADD(long long i){
	toProg("ADD",i);
}
void SUB(long long i){
	toProg("SUB",i);
}
void ADDI(long long i){
	toProg("ADDI",i);
}
void SUBI(long long i){
	toProg("SUBI",i);
}
void SET(long long i){
	toProg("SET",i);
}
void HALF(long long i){
	toProg("HALF",i);
}
void JUMP(long long i){
	toProg("JUMP",i);
}
void JPOS(long long i){
	toProg("JPOS",i);
}
void JZERO(long long i){
	toProg("JZERO",i);
}
void JNEG(long long i){
	toProg("JNEG",i);
}


void memInc(long long inc = 1){
	memCounter += inc;
}

Component* lastnext(Component* comp){
		Component* tot = comp;
		while(tot->next!=nullptr){
			tot=tot->next;
			}
		return tot;
}

void addMUL(long long reg_A, long long reg_B, long long reg_O, long long reg_R){
	/*
	SET(0);
	STORE(reg_O);
	LOAD(reg_B);
	JZERO(18)
	HALF();
	JZERO(14);
	ADD(0);
	SUB(reg_B);
	JZERO(4);
	LOAD(reg_O);
	ADD(reg_A);
	STORE(reg_O);
	LOAD(reg_B);
	HALF;
	STORE(reg_B);
	LOAD(reg_A);
	ADD(0);
	STORE(reg_A);
	JUMP(-16);
	LOAD(W);
	ADD(A);
	RTRN(reg_R);
	*/
}


//VARIABLE MANIPULATION FUNCTIONS
void declare_var(Component* declaration){
	std::string name(declaration->pid_name);
	vars::Variable var(name);
	variables.emplace(name,var);
	memInc();
}
void declare_tab(Component* declaration){
	std::string name(declaration->pid_name);
	vars::Table tab(name,declaration->children->number_value,declaration->children->next->number_value);
	tables.emplace(name,tab);
	memInc((declaration->children->next->number_value)-(declaration->children->number_value)+1);
}
void setvar(char* name, char* value){
	//TEMP
	std::cout<<name<<" is set to "<<value<<"\n";
	//TODO
}
void settab(char* name, long long pos, char* value){
	
}
long long getMemCell(Component* call){
	long long outcome=-1;
	if(call->type==31){//normal variable
		std::string name(call->children->pid_name);
		try{
			vars::Variable var = variables.at(name);	
			outcome = var.getPos();
		}catch(const std::out_of_range& e){
			//TODO
			//throw error at varline
		}
	} else if(call->type==32){//table[num]
		std::string name(call->children->pid_name);
		try{
			vars::Table tab = tables.at(name);
			outcome = tab.getPos(call->next->number_value);
			//TODO
			//error if out of bounds
		}catch(const std::out_of_range& e){
			//TODO
			//throw error at varline
			//or if out of bounds
		}
	} else if(call->type==33){//table[variable]
		std::string name(call->children->pid_name);
		try{
			vars::Table tab = tables.at(name);
			//outcome = tab.getPos(call->next->number_value);
			//TODO
			//indirect call
			//throw error if variable is table
		}catch(const std::out_of_range& e){
			//TODO
			//throw error at varline
		}
	} else{
		std::cout<<"GETMEMC: SHOULD NOT GET HERE WITH TYPE: "<<call->type<<"\n";
	}
	return outcome;
}

//ARITHMETIC/LOGIC FUNCTIONS
//TODO
void loadORset(Component* value){
	Component* check = value->children;
	if(check->type==1){
		SET(check->number_value);
	} else {
		LOAD(getMemCell(check));
	}
}
void doArithmetic(Component* expr){
	//ID := EXPR
	//long long adr = getMemCell(varsetexp->children);
	//Component* expr = varsetexp->children->next;
	//VALUES
	Component* first = expr->children;
	Component* second = expr->children->next;//NOTE: may be nullptr
	switch(expr->type){
		case 61:
			loadORset(first);
		break;
		case 62:
			if(first->children->type==1 && second->children->type==1){
				SET(first->children->number_value+second->children->number_value); //NOTE: MAY GO OUT OF LONG LONG BOUNDARIES SHOULD MAKE TEXT_CONVERSION_ADD
			} else if(first->children->type!=1 && second->children->type==1){
				SET(second->children->number_value);
				ADD(getMemCell(first->children));	//NOTE: getMemCell should throw error when trying to get address of loop variable out of said loop
			}else if(first->children->type==1 && second->children->type!=1){
				SET(first->children->number_value);
				ADD(getMemCell(second->children));
			}else{
				LOAD(getMemCell(first->children));
				ADD(getMemCell(second->children));
			}
		break;
		case 63:
			if(first->children->type==1 && second->children->type==1){
				SET(first->children->number_value-second->children->number_value); //NOTE: MAY GO OUT OF LONG LONG BOUNDARIES SHOULD MAKE TEXT_CONVERSION_ADD and SET(string)
			} else if(first->children->type!=1 && second->children->type==1){
				SET(-(second->children->number_value)); // a - b = -b + a
				ADD(getMemCell(first->children));
			}else if(first->children->type==1 && second->children->type!=1){
				SET(first->children->number_value);
				SUB(getMemCell(second->children));
			}else{
				LOAD(getMemCell(first->children));
				SUB(getMemCell(second->children));
			}
		break;
		case 64://NOTE: MUL,DIV,MOD - should be functions(if needed) with copied values instead of references
		//TODO
		break;
		case 65:
		//TODO
		break;
		case 66:
		//TODO
		break;
	}
	//STORE(adr);
}
void conditionalize(Component* condition){
	Component* first = condition->children;
	Component* second = first->next;
	Component* fidornum = first->children;
	Component* sidornum = second->children;
	switch(condition->type){
		case 51://==
			if(first->type==41 && second->type==41){
				if(sidornum->number_value==fidornum->number_value){
					//DO
				} else{
					//SKIP
				}
			}else if (first->type!=1 && second->type==41){

			}else if (first->type==41 && second->type!=41){

			}else{

			}
		break;
		case 52://!=
		break;
		case 53://>
		break;
		case 54://<
		break;
		case 55://>=
		break;
		case 56://<=
		break;
	}
}

//PROGRAM BUILDING FUNCTIONS
void useMul(){mulUses++;}
void useDiv(){divUses++;}
void useMod(){modUses++;}

void buildProgram(Component* all){
	Component* a = all->children; //a = {[procedures], main}
	buildProcedures(a);
	buildMain(a->next);
}


//PROCEDURE MAKING
void makeProcedure(Component* procedure){
	if(procedure->type==151){//with declarations-registers
		std::cout<<"#PROCEDURE "<<procedure->children->children->pid_name<<"\n";
		
	}else if(procedure->type==152){//without declarations
		std::cout<<"#PROCEDURE "<<procedure->children->children->pid_name<<"\n";
	}else{
		std::cout<<"MKPROC:SHOULD NOT GET HERE WITH TYPE:"<<procedure->type<<"\n";
	}
}
void buildProcedures(Component* procedures){
	Component* procedure = procedures->children;
	while(procedure!=nullptr){
		//TODO:Procedure translation
		makeProcedure(procedure);
		procedure=procedure->next;
	}
}

//MAIN MAKING
void buildMain(Component* main){
	if(main->type==141){
		declareVariables(main->children);
	}
	buildCommands(main->children->next);
}
void declareVariables(Component* declarations){
	//if we are here, then there's at least one variable declared
	Component* decl = declarations->children;
	while(decl!=nullptr){
		if(decl->type==21){ //variable
			declare_var(decl);
		} else if(decl->type==22){ //table
			declare_tab(decl);
		} else{
			//DEBUG
			std::cout<<"DECL: SHOULD NOT GET HERE WITH TYPE: "<<decl->type<<"!\n";
		}
		decl=decl->next;
	}
}
void ifthenelse(Component* comm){
	Component* condition = comm->children;
	Component* then = condition->next;
	Component* elsse = then->next;
}
void ifthenelse(Component* comm){
	Component* condition = comm->children;
	Component* then = condition->next;
}
void buildCommands(Component* commands){
	Component* comm = commands->children;
	while(comm!=nullptr){
		//std::cout<<"TYPE: "<<comm->type;
		switch(comm->type){
			case 121://TODO:ERROR IF SETTING LOOP VARIABLE
			long long adr = getMemCell(comm->children);
			doArithmetic(comm->children->next);
			STORE(adr);
			break;
			case 122:{
				//ifthenelse
				ifthenelse(comm);
			}
			break;
			case 123:{
				//ifthen
				ifthen(comm);
			}
			break;
			case 124:
			//TODO
			std::cout<<"whiledo"<<std::endl;
			//while...do
			break;
			case 125:
			//TODO
			std::cout<<"repeatunitl"<<std::endl;
			//repeatuntil
			break;
			case 126:
			//TODO
			std::cout<<"forfromtodo"<<std::endl;
			//for...from...to...do...
			break;
			case 127:
			//TODO
			std::cout<<"forfromdowntodo"<<std::endl;
			//for...from...downto...do...
			break;
			case 128:
			//TODO
			//proc_call
			break;
			case 129:
				{
					long long memoryPlace = getMemCell(comm->children);
					//std::cout<<"GET "<<memoryPlace<<std::endl;
					GET(memoryPlace);
				}
			break;
			case 1210:
				{
					long long printMemPlace;
					if(comm->children->type==41){
						SET(comm->children->children->number_value);
						printMemPlace = 0;
					}else if(comm->children->type==42){
						printMemPlace = getMemCell(comm->children->children);
					}else{
						printMemPlace = -1;
						std::cout<<"SHOULD NOT GET HERE WITH TYPE:"<<comm->children->type<<"\n";
					}
					PUT(printMemPlace);
				}
			break;
		}
		comm=comm->next;
	}
}