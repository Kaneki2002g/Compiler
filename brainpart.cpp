#include "brainpart.hpp"

long long memCounter = 1;
long long ASSLINE = 0;
long long posCounter = 0;
long long helpCounter = 0;

int mulUses=0;
int divUses=0;
int modUses=0;

std::map<std::string,int> procedure_uses;
std::vector<long long> jumpLines;
long long rLines = -1;

long long getVPOS(){
	rLines++;
	jumpLines.push_back(0);
	return rLines;
}
void setVPOS(long long pos, long long length){
	jumpLines[pos]=length; //NOTE: maybe +1
	std::cout<<"\033[F\033[10C#SET "<<pos+1<<" JUMP TO "<<length<<"\n";
}

namespace vars{
	class Variable{
		public:
			void use(){used++;}
			void set(){sett=true;}
			bool isSet(){return sett;}
			int timesUsed(){return used;}
			std::string getName(){return name;}
			unsigned long long int getPos(){return memory_cell;}
			bool isLVar(){return loopvar;}
			void makeLVar(){loopvar=true;}
			bool isnUsed(){return usednow;}
			void usen(){usednow=true;}
			void unuse(){usednow=false;}
		private:
			std::string name;
			int used;
			bool sett;
			unsigned long long int memory_cell;
			bool loopvar;
			bool usednow;
		public:
			Variable(const std::string& name) : name(name), used(0), sett(false), memory_cell(memCounter), loopvar(false), usednow(false) {}
			Variable(){}
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
			Table();
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

void uJUMP(long long i){
	//TEMP
	JUMP(123456789);
	//TODO
}
void uJZERO(long long i){
	//TEMP
	JZERO(123456789);
	//TODO
}
void uJPOS(long long i){
	//TEMP
	JPOS(123456789);
	//TODO
}
void uJNEG(long long i){
	//TEMP
	JNEG(123456789);
	//TODO
}



void memInc(long long inc = 1){
	memCounter += inc;
}

/*
REGISTERS(OPTIONAL):
1 - typical for return if function doesn't use different function
2 - for A in arithmetic operations
3 - for B in arithmetic operations
4(if 2 and 3 are used, eventually different) - for storing outcome in arithmetic operations
*/

bool rtrnset = false;
unsigned long long rtrnReg = 0;

unsigned long long getretreg{
	if (!rtrnset){
		rtrnReg = memCounter;
		memInc();
	}
	return rtrnReg;
}

bool abset = false;
unsigned long long areg = 0;
unsigned long long breg = 0;

unsigned long long getareg{
	if (!abset){
		areg = memCounter;
		memInc();
		breg = memCounter;
		memInc();
	}
	return areg;
}

unsigned long long getbreg{
	if (!abset){
		areg = memCounter;
		memInc();
		breg = memCounter;
		memInc();
	}
	return breg;
}

bool oset = false;
unsigned long long oreg = 0;

unsigned long long getoreg{
	if (!oset){
		oreg = memCounter;
		memInc();
	}
	return oreg;
}

//

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


vars::Variable decloop_var(Component* pid){
	std::string name(pid->pid_name);
	try{
			vars::Variable var = variables.at(name);
			if(var.isLVar() && !(var.isnUsed())){
				var.usen();
				return var;
			} else{
				//TODO
				//THROW USED ALREADY ERROR
			}
		}catch(const std::out_of_range& e){
			try{
				vars::Table var = tables.at(name);
				//TODO
				//THROW ERROR ALREADY USED
			}catch(const std::out_of_range& e){
				vars::Variable var(name);
				var.makeLVar();
				var.usen();
				memInc();
				return var;
			}
		}
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

int compareA(Component* cond){
	//returns:
	//1 - always True, comparison not made
	//-1 - never True, comparison not made
	//0 - make comparison
	//VALUES
	Component* first = cond->children;
	Component* sec = first->next;
	long long val1,val2;
	if(first->type==41 && sec->type==41){
		val1=first->children->number_value;
		val2=sec->children->number_value;
		switch(cond->type){
			case 51://==
				if(val1==val2)
					return 1;
				return -1;
			break;
			case 52://!=
				if(val1!=val2)
					return 1;
				return -1;
			break;
			case 53://>
				if(val1>val2)
					return 1;
				return -1;
			break;
			case 54://<!=>
				if(val1<val2)
					return 1;
				return -1;
			break;
			case 55://>=
				if(val1>=val2)
					return 1;
				return -1;
			break;
			case 56://<=
				if(val1<=val2)
					return 1;
				return -1;
			break;
		}
	}
	return 0;
}
void compareB(Component* cond){
	Component* first = cond->children;
	Component* sec = first->next;
	if(first->type!=41 && sec->type!=41){
		LOAD(getMemCell(first->children));
		SUB(getMemCell(sec->children));
	} else{
		if(first->type==41){
			SET(first->children->number_value);
			SUB(getMemCell(sec->children));
		}else{
			SET(-(sec->children->number_value));
			ADD(getMemCell(first->children));
		}
	}
}

//PROGRAM BUILDING FUNCTIONS
void useMul(){mulUses++;}
void useDiv(){divUses++;}
void useMod(){modUses++;}

void buildProgram(Component* all){
	if(mulUses>0){

	}
	if(divUses>0){

	}
	if(modUses>0){
		
	}
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
	//NOTE:MAY SHORTEN IF USED compareA() and compareB() methods, but now I'm too tired to do this 
	//IF(COND)->NOTJUMP
	//ELSE JUMP at ENDOF1COMMANDS
	//1COMMANDS
	//JUMP 2ENDOFCOMMANDS
	//ENDOF1COMMANDS: 2COMMANDS
	//ENDOF2COMMANDS:OUTOF_IFTHENELSE
	Component* condition = comm->children;
	Component* then = condition->next;
	Component* elsse = then->next;
	//BOTH NUMBERS NO JUMPS NEEDED
	if(condition->children->type == 41 && condition->children->next->type == 41){ 
		long long val1 = condition->children->children->number_value;
		long long val2 = condition->children->next->children->number_value;
		switch(condition->type){
			case 51:{
				if(val1==val2){
					buildCommands(then);
				}else{
					buildCommands(elsse);
				}}
			break;
			case 52:{
				if(val1!=val2){
					buildCommands(then);
				}else{
					buildCommands(elsse);
				}}
			break;
			case 53:{
				if(val1>val2){
					buildCommands(then);
				}else{
					buildCommands(elsse);
				}}
			break;
			case 54:{
				if(val1<val2){
					buildCommands(then);
				}else{
					buildCommands(elsse);
				}}
			break;
			case 55:{
				if(val1>=val2){
					buildCommands(then);
				}else{
					buildCommands(elsse);
				}}
			break;
			case 56:{
				if(val1<=val2){
					buildCommands(then);
				}else{
					buildCommands(elsse);
				}}
			break;
		}
	} else if (condition->children->type==41 && condition->children->next->type!=41){
		switch(condition->type){//NUM COMP ID
			case 51:{//==
				SET(condition->children->children->number_value);
				SUB(getMemCell(condition->children->next->children));
				JZERO(2);
				long long j1 = getVPOS();
				uJUMP(j1);
				buildCommands(then);
				long long j2 = getVPOS();
				uJUMP(j2);
				setVPOS(j1,helpCounter);
				buildCommands(elsse);
				setVPOS(j2,helpCounter);
				}
			break;
			case 52:{//!=
				SET(condition->children->children->number_value);
				SUB(getMemCell(condition->children->next->children));
				long long j1 = getVPOS();
				uJZERO(j1);
				buildCommands(then);
				long long j2 = getVPOS();
				uJUMP(j2);
				setVPOS(j1,helpCounter);
				buildCommands(elsse);
				setVPOS(j2,helpCounter);
				}
			break;
			case 53:{//>
				SET(condition->children->children->number_value);
				SUB(getMemCell(condition->children->next->children));
				JPOS(2);
				long long j1 = getVPOS();
				uJUMP(j1);
				buildCommands(then);
				long long j2 = getVPOS();
				uJUMP(j2);
				setVPOS(j1,helpCounter);
				buildCommands(elsse);
				setVPOS(j2,helpCounter);
				}
			break;
			case 54:{//<
				SET(condition->children->children->number_value);
				SUB(getMemCell(condition->children->next->children));
				JNEG(2);
				long long j1 = getVPOS();
				uJPOS(j1);
				buildCommands(then);
				long long j2 = getVPOS();
				uJUMP(j2);
				setVPOS(j1,helpCounter);
				buildCommands(elsse);
				setVPOS(j2,helpCounter);
				}
			break;
			case 55:{//>=
				SET(condition->children->children->number_value);
				SUB(getMemCell(condition->children->next->children));
				JPOS(2);
				long long j1 = getVPOS();
				uJNEG(j1);
				buildCommands(then);
				long long j2 = getVPOS();
				uJUMP(j2);
				setVPOS(j1,helpCounter);
				buildCommands(elsse);
				setVPOS(j2,helpCounter);
				}
			break;
			case 56:{//<=
				SET(condition->children->children->number_value);
				SUB(getMemCell(condition->children->next->children));
				JNEG(2);
				long long j1 = getVPOS();
				uJPOS(j1);
				buildCommands(then);
				long long j2 = getVPOS();
				uJUMP(j2);
				setVPOS(j1,helpCounter);
				buildCommands(elsse);
				setVPOS(j2,helpCounter);
				}
			break;
		}
	} else if (condition->children->type!=41 && condition->children->next->type==41){
		switch(condition->type){//ID COMP NUM
			case 51:{//==
				SET(-(condition->children->next->children->number_value));
				ADD(getMemCell(condition->children->children));
				JZERO(2);
				long long j1 = getVPOS();
				uJUMP(j1);
				buildCommands(then);
				long long j2 = getVPOS();
				uJUMP(j2);
				setVPOS(j1,helpCounter);
				buildCommands(elsse);
				setVPOS(j2,helpCounter);
				}
			break;
			case 52:{//!=
				SET(-(condition->children->next->children->number_value));
				ADD(getMemCell(condition->children->children));
				long long j1 = getVPOS();
				uJZERO(j1);
				buildCommands(then);
				long long j2 = getVPOS();
				uJUMP(j2);
				setVPOS(j1,helpCounter);
				buildCommands(elsse);
				setVPOS(j2,helpCounter);
				}
			break;
			case 53:{//>
				SET(-(condition->children->next->children->number_value));
				ADD(getMemCell(condition->children->children));	//-b+a = a-b
				JPOS(2);
				long long j1 = getVPOS();
				uJUMP(j1);
				buildCommands(then);
				long long j2 = getVPOS();
				uJUMP(j2);
				setVPOS(j1,helpCounter);
				buildCommands(elsse);
				setVPOS(j2,helpCounter);
				}
			break;
			case 54:{//<
				SET(-(condition->children->next->children->number_value));
				ADD(getMemCell(condition->children->children));	//-b+a = a-b
				JNEG(2);
				long long j1 = getVPOS();
				uJUMP(j1);
				buildCommands(then);
				long long j2 = getVPOS();
				uJUMP(j2);
				setVPOS(j1,helpCounter);
				buildCommands(elsse);
				setVPOS(j2,helpCounter);
				}
			break;
			case 55:{//>=
				SET(-(condition->children->next->children->number_value));
				ADD(getMemCell(condition->children->children));	//-b+a = a-b
				JPOS(2);
				long long j1 = getVPOS();
				uJNEG(j1);
				buildCommands(then);
				long long j2 = getVPOS();
				uJUMP(j2);
				setVPOS(j1,helpCounter);
				buildCommands(elsse);
				setVPOS(j2,helpCounter);
				}
			break;
			case 56:{//<=
				SET(-(condition->children->next->children->number_value));
				ADD(getMemCell(condition->children->children));	//-b+a = a-b
				JNEG(2);
				long long j1 = getVPOS();
				uJPOS(j1);
				buildCommands(then);
				long long j2 = getVPOS();
				uJUMP(j2);
				setVPOS(j1,helpCounter);
				buildCommands(elsse);
				setVPOS(j2,helpCounter);
				}
			break;
		}
	} else {
		switch(condition->type){//ID COMP ID
			case 51:{//==
				LOAD(getMemCell(condition->children->children));
				SUB(getMemCell(condition->children->next->children));
				JZERO(2);
				long long j1 = getVPOS();
				uJUMP(j1);
				buildCommands(then);
				long long j2 = getVPOS();
				uJUMP(j2);
				setVPOS(j1,helpCounter);
				buildCommands(elsse);
				setVPOS(j2,helpCounter);
				}
			break;
			case 52:{//!=
				LOAD(getMemCell(condition->children->children));
				SUB(getMemCell(condition->children->next->children));
				long long j1 = getVPOS();
				uJZERO(j1);
				buildCommands(then);
				long long j2 = getVPOS();
				uJUMP(j2);
				setVPOS(j1,helpCounter);
				buildCommands(elsse);
				setVPOS(j2,helpCounter);
				}
			break;
			case 53:{//>
				LOAD(getMemCell(condition->children->children));
				SUB(getMemCell(condition->children->next->children));
				JPOS(2);
				long long j1 = getVPOS();
				uJUMP(j1);
				buildCommands(then);
				long long j2 = getVPOS();
				uJUMP(j2);
				setVPOS(j1,helpCounter);
				buildCommands(elsse);
				setVPOS(j2,helpCounter);
				}
			break;
			case 54:{//<
				LOAD(getMemCell(condition->children->children));
				SUB(getMemCell(condition->children->next->children));
				JNEG(2);
				long long j1 = getVPOS();
				uJUMP(j1);
				buildCommands(then);
				long long j2 = getVPOS();
				uJUMP(j2);
				setVPOS(j1,helpCounter);
				buildCommands(elsse);
				setVPOS(j2,helpCounter);
				}
			break;
			case 55:{//>=
				LOAD(getMemCell(condition->children->children));
				SUB(getMemCell(condition->children->next->children));
				JPOS(2);
				long long j1 = getVPOS();
				uJNEG(j1);
				buildCommands(then);
				long long j2 = getVPOS();
				uJUMP(j2);
				setVPOS(j1,helpCounter);
				buildCommands(elsse);
				setVPOS(j2,helpCounter);
				}
			break;
			case 56:{//<=
				LOAD(getMemCell(condition->children->children));
				SUB(getMemCell(condition->children->next->children));
				JNEG(2);
				long long j1 = getVPOS();
				uJPOS(j1);
				buildCommands(then);
				long long j2 = getVPOS();
				uJUMP(j2);
				setVPOS(j1,helpCounter);
				buildCommands(elsse);
				setVPOS(j2,helpCounter);
				}
			break;
		}
	}
}
void ifthen(Component* comm){
	//NOTE:MAY SHORTEN IF USED compareA() and compareB() methods, but now I'm too tired to do this 
	//IF(!COND)->JUMP at ENDOFCOMMANDS
	//COMMANDS
	//ENDOFCOMMANDS: OUTOF_IFTHEN
	Component* condition = comm->children;
	Component* then = condition->next;
	//BOTH NUMBERS NO JUMPS NEEDED
	if(condition->children->type == 41 && condition->children->next->type == 41){ 
		long long val1 = condition->children->children->number_value;
		long long val2 = condition->children->next->children->number_value;
		switch(condition->type){
			case 51:{
				if(val1==val2){
					buildCommands(then);
				}}
			break;
			case 52:{
				if(val1!=val2){
					buildCommands(then);
				}}
			break;
			case 53:{
				if(val1>val2){
					buildCommands(then);
				}}
			break;
			case 54:{
				if(val1<val2){
					buildCommands(then);
				}}
			break;
			case 55:{
				if(val1>=val2){
					buildCommands(then);
				}}
			break;
			case 56:{
				if(val1<=val2){
					buildCommands(then);
				}}
			break;
		}
	} else if (condition->children->type==41 && condition->children->next->type!=41){
		switch(condition->type){//NUM COMP ID
			case 51:{//==
				SET(condition->children->children->number_value);
				SUB(getMemCell(condition->children->next->children));
				JZERO(2);
				long long j1 = getVPOS();
				uJUMP(j1);
				buildCommands(then);
				setVPOS(j1,helpCounter);
				}
			break;
			case 52:{//!=
				SET(condition->children->children->number_value);
				SUB(getMemCell(condition->children->next->children));
				long long j1 = getVPOS();
				uJZERO(j1);
				buildCommands(then);
				setVPOS(j1,helpCounter);
				}
			break;
			case 53:{//>
				SET(condition->children->children->number_value);
				SUB(getMemCell(condition->children->next->children));
				JPOS(2);
				long long j1 = getVPOS();
				uJUMP(j1);
				buildCommands(then);
				setVPOS(j1,helpCounter);
				}
			break;
			case 54:{//<
				SET(condition->children->children->number_value);
				SUB(getMemCell(condition->children->next->children));
				JNEG(2);
				long long j1 = getVPOS();
				uJPOS(j1);
				buildCommands(then);
				setVPOS(j1,helpCounter);
				}
			break;
			case 55:{//>=
				SET(condition->children->children->number_value);
				SUB(getMemCell(condition->children->next->children));
				JPOS(2);
				long long j1 = getVPOS();
				uJNEG(j1);
				buildCommands(then);
				setVPOS(j1,helpCounter);
				}
			break;
			case 56:{//<=
				SET(condition->children->children->number_value);
				SUB(getMemCell(condition->children->next->children));
				JNEG(2);
				long long j1 = getVPOS();
				uJPOS(j1);
				buildCommands(then);
				setVPOS(j1,helpCounter);
				}
			break;
		}
	} else if (condition->children->type!=41 && condition->children->next->type==41){
		switch(condition->type){//ID COMP NUM
			case 51:{//==
				SET(-(condition->children->next->children->number_value));
				ADD(getMemCell(condition->children->children));
				JZERO(2);
				long long j1 = getVPOS();
				uJUMP(j1);
				buildCommands(then);
				setVPOS(j1,helpCounter);
				}
			break;
			case 52:{//!=
				SET(-(condition->children->next->children->number_value));
				ADD(getMemCell(condition->children->children));
				long long j1 = getVPOS();
				uJZERO(j1);
				buildCommands(then);
				setVPOS(j1,helpCounter);
				}
			break;
			case 53:{//>
				SET(-(condition->children->next->children->number_value));
				ADD(getMemCell(condition->children->children));	//-b+a = a-b
				JPOS(2);
				long long j1 = getVPOS();
				uJUMP(j1);
				buildCommands(then);
				setVPOS(j1,helpCounter);
				}
			break;
			case 54:{//<
				SET(-(condition->children->next->children->number_value));
				ADD(getMemCell(condition->children->children));	//-b+a = a-b
				JNEG(2);
				long long j1 = getVPOS();
				uJUMP(j1);
				buildCommands(then);
				setVPOS(j1,helpCounter);
				}
			break;
			case 55:{//>=
				SET(-(condition->children->next->children->number_value));
				ADD(getMemCell(condition->children->children));	//-b+a = a-b
				JPOS(2);
				long long j1 = getVPOS();
				uJNEG(j1);
				buildCommands(then);
				setVPOS(j1,helpCounter);
				}
			break;
			case 56:{//<=
				SET(-(condition->children->next->children->number_value));
				ADD(getMemCell(condition->children->children));	//-b+a = a-b
				JNEG(2);
				long long j1 = getVPOS();
				uJPOS(j1);
				buildCommands(then);
				setVPOS(j1,helpCounter);
				}
			break;
		}
	} else {
		switch(condition->type){//ID COMP ID
			case 51:{//==
				LOAD(getMemCell(condition->children->children));
				SUB(getMemCell(condition->children->next->children));
				JZERO(2);
				long long j1 = getVPOS();
				uJUMP(j1);
				buildCommands(then);
				setVPOS(j1,helpCounter);
				}
			break;
			case 52:{//!=
				LOAD(getMemCell(condition->children->children));
				SUB(getMemCell(condition->children->next->children));
				long long j1 = getVPOS();
				uJZERO(j1);
				buildCommands(then);
				setVPOS(j1,helpCounter);
				}
			break;
			case 53:{//>
				LOAD(getMemCell(condition->children->children));
				SUB(getMemCell(condition->children->next->children));
				JPOS(2);
				long long j1 = getVPOS();
				uJUMP(j1);
				buildCommands(then);
				setVPOS(j1,helpCounter);
				}
			break;
			case 54:{//<
				LOAD(getMemCell(condition->children->children));
				SUB(getMemCell(condition->children->next->children));
				JNEG(2);
				long long j1 = getVPOS();
				uJUMP(j1);
				buildCommands(then);
				setVPOS(j1,helpCounter);
				}
			break;
			case 55:{//>=
				LOAD(getMemCell(condition->children->children));
				SUB(getMemCell(condition->children->next->children));
				JPOS(2);
				long long j1 = getVPOS();
				uJNEG(j1);
				buildCommands(then);
				setVPOS(j1,helpCounter);
				}
			break;
			case 56:{//<=
				LOAD(getMemCell(condition->children->children));
				SUB(getMemCell(condition->children->next->children));
				JNEG(2);
				long long j1 = getVPOS();
				uJPOS(j1);
				buildCommands(then);
				setVPOS(j1,helpCounter);
				}
			break;
		}
	}
}
void repeatUntil(Component* comm){
	Component* doings = comm->children;
	Component* cond = doings->next;
	int help=compareA(cond);
	if(help==0){//non defined loop
		buildCommands(doings);
		compareB(cond);
		switch(cond->type){
			case 51://==
			JZERO(2);
			JUMP(-(helpCounter+3));
			break;
			case 52://!=
			JZERO(-(helpCounter+2));
			break;
			case 53://>
			JPOS(2);
			JUMP(-(helpCounter+3));
			break;
			case 54://<
			JNEG(2);
			JUMP(-(helpCounter+3));
			break;
			case 55://>=
			JNEG(-(helpCounter+2));
			break;
			case 56://<=
			JPOS(-(helpCounter+2));
			break;
		}
	} else if(help==1){//infinite loop
		buildCommands(doings);
		JUMP(-helpCounter);
	}
	//otherwise skip;
}
void makefor(Component* loop){
	Component* pid = loop->children;
	Component* start = pid->next;
	Component* finish = start->next;
	Component* comms = finish->next;
	vars::Variable iterator = decloop_var(pid);
	long long dest=-1;
	if(loop->type==126){
		loadORset(start);
		STORE(iterator.getPos());
		loadORset(finish);
		STORE(memCounter);
		dest = memCounter;
		memInc();
	} else if(loop->type==127){
		loadORset(finish);
		STORE(iterator.getPos());
		loadORset(start);
		STORE(memCounter);
		dest = memCounter;
		memInc();
	} //4 LINES
	LOAD(iterator.getPos());
	SUB(dest);
	long long j1 = getVPOS();
	uJNEG(j1);
	buildCommands(comms);
	JUMP(-(helpCounter+2));
	iterator.unuse();
	// Component* fakeCond = new Component();
	// fakeCond->children = loop->children->next;
	// fakeCond->type = 51;
	// int compareEQ = compareA(fakeCond);
	// fakeCond->type = 53;
	// int compareGT = compareA(fakeCond);
	// if(compareEQ!=0){
	// 	if(loop->type==126){
			
	// 	}
	// }
}
void buildCommands(Component* commands){
	long long start = ASSLINE;
	Component* comm = commands->children;
	while(comm!=nullptr){
		//std::cout<<"TYPE: "<<comm->type;
		switch(comm->type){
			case 121:{//TODO:ERROR IF SETTING LOOP VARIABLE
			long long adr = getMemCell(comm->children);
			doArithmetic(comm->children->next);
			STORE(adr);}
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
			case 124:{
				//NOTE: NOT TESTED PROPERLY
				//TODO: IF ALWAYS TRUE INFINITE LOOP, ELSE SKIP
				//std::cout<<"whiledo"<<std::endl;
				Component* fakeifthen = new Component();
				long long cheatNumber = rLines+1;
				fakeifthen->children=comm->children;
				ifthen(fakeifthen);
				jumpLines[cheatNumber]++;
				//std::cout<<"\033[F\033[10C#JUMP "<<cheatNumber+1<<" WILL BE BIGGER BY 1\n";
				JUMP(-helpCounter);
				//while...do
				break;
				}
			case 125:{
				//TODO
				//std::cout<<"repeatunitl"<<std::endl;
				//repeatuntil
				repeatUntil(comm);
			}
			break;
			case 126:
			//TODO
			//std::cout<<"forfromtodo"<<std::endl;
			//for...from...to...do...
			//SHOULD MAKE LOCAL VARIABLE STACK/TABLE
			//OR CHECK FIELD IN VARIABLE (EG. currentlyUsed=true;)
			//IN PROCEDURES FOR LOOPS SHOULD HAVE ITERATOR AS SEPARATE REGISTER SAVED
			makefor(comm);
			break;
			case 127:
			//TODO
			std::cout<<"forfromdowntodo"<<std::endl;
			//for...from...downto...do...
			//--||--
			makefor(comm);
			break;
			case 128:
			//TODO
			//proc_call
			//SET REGISTERS
			//JUMP TO PROCEDURE
			//RETURN WITH RTRN
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
	helpCounter=ASSLINE-start;
	//std::cout<<"#THIS SUB-PART TOOK "<<helpCounter<<" LINES\n";
}