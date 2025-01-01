#include "brainpart.hpp"
//#include <map>
//#include <vector> to w brainpart.hpp

long long memCounter = 1;
long long posCounter = 0;
long long helpCounter = 0;

int mulUses=0;
int divUses=0;
int modUses=0;

std::map<std::string,int> procedure_uses;

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
};

std::map<std::string, vars::Variable> variables;
std::map<std::string, vars::Table> tables;

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


//VARIABLE MANIPULATION FUNCTIONS
void declare_var(Component* declaration){
	//TEMP
	//std::cout<<"declaring "<<declaration->pid_name<<" variable!\n";
	//TODO
	std::string name(declaration->pid_name);
	vars::Variable var(name);
	//variables[name]=var;
	variables.emplace(name,var);
	memInc();
}
void declare_tab(Component* declaration){
	//TEMP
	//std::cout<<"declaring "<<declaration->pid_name<<" table with bounds:"<<declaration->children->number_value<<" : "<<declaration->children->next->number_value<<"\n";
	//TODO
	std::string name(declaration->pid_name);
	vars::Table tab(name,declaration->children->number_value,declaration->children->next->number_value);
	//tables[name]=tab;
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
	//std::cout<<"getmemcell\n";
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
		}catch(const std::out_of_range& e){
			//TODO
			//throw error at varline
			//or if out of bounds
		}
	} else if(call->type==33){
		std::string name(call->children->pid_name);
		try{
			vars::Table tab = tables.at(name);
			//outcome = tab.getPos(call->next->number_value);
			//TODO
			//indirect call
		}catch(const std::out_of_range& e){
			//TODO
			//throw error at varline
		}
	} else{
		std::cout<<"GETMEMC: SHOULD NOT GET HERE WITH TYPE: "<<call->type<<"\n";
	}
	return outcome;
}

//ARITHMETIC FUNCTIONS
//TODO
char* add(char* a, char* b){
	//TEMP
	std::cout<<a<<" add to "<<b<<"\n";
	//TODO
	
	return strdup(std::to_string(atoll(a)+atoll(b)).c_str());
}
char* sub(char* a, char* b){
	//TEMP
	std::cout<<a<<" sub to "<<b<<"\n";
	//TODO
	
	return strdup(std::to_string(atoll(a)-atoll(b)).c_str());
}
char* mul(char* a, char* b){
	//TEMP
	std::cout<<a<<" mul to "<<b<<"\n";
	//TODO
	
	return strdup(std::to_string(atoll(a)*atoll(b)).c_str());
}
char* div(char* a, char* b){
	//TEMP
	std::cout<<a<<" div to "<<b<<"\n";
	//TODO
	
	return strdup(std::to_string(atoll(a)/atoll(b)).c_str());
}
char* mod(char* a, char* b){
	//TEMP
	std::cout<<a<<" mod to "<<b<<"\n";
	//TODO
	
	return strdup(std::to_string(atoll(a)%atoll(b)).c_str());
}
void read(char* var){}
void write(char* var){}

int getHelpCounter(){
	return helpCounter;
}
void zeroHelpCounter(){
	helpCounter = 0;
}

void useMul(){mulUses++;}
void useDiv(){divUses++;}
void useMod(){modUses++;}

void buildProgram(Component* all){
	Component* a = all->children; //a = {[procedures], main}
	buildProcedures(a);
	buildMain(a->next);
	/*
	Component* b = a->children; //b = {[procedure0(empty)], procedure1, ...}
	while(b != nullptr){
		std::cout<<"TYPE: "<<b->type<<"\n"; //printowanie typu procedur
		b=b->next;
	}*/
}
void buildProcedures(Component* procedures){
	Component* procedure = procedures->children;
	while(procedure!=nullptr){
		//TODO:Procedure translation
		procedure=procedure->next;
	}
}
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
void buildCommands(Component* commands){
	Component* comm = commands->children;
	while(comm!=nullptr){
		//std::cout<<"TYPE: "<<comm->type;
		switch(comm->type){
			case 121:
			std::cout<<"set"<<std::endl;
			//set
			break;
			case 122:
			std::cout<<"ifthenelse"<<std::endl;
			//if...then...else...
			break;
			case 123:
			std::cout<<"ifthen"<<std::endl;
			//if...then...
			break;
			case 124:
			std::cout<<"whiledo"<<std::endl;
			//while...do
			break;
			case 125:
			std::cout<<"repeatunitl"<<std::endl;
			//repeatuntil
			break;
			case 126:
			std::cout<<"forfromtodo"<<std::endl;
			//for...from...to...do...
			break;
			case 127:
			std::cout<<"forfromdowntodo"<<std::endl;
			//for...from...downto...do...
			break;
			case 128:
			std::cout<<"proccall"<<std::endl;
			//std::cout<<"LINE: "<<comm->code_line<<"\n";
			//proc_call
			break;
			case 129:
			//if pidentifier or pidentifier[num]
			long long memoryPlace = getMemCell(comm->children);
			std::cout<<"GET "<<memoryPlace<<std::endl;
			//if pidentifier[pidentifier]
			//TODO
			break;
			case 1210:
			std::cout<<"PUT "<<"WIP"<<std::endl;
			//write
			break;
		}
		//TODO: command translation
		comm=comm->next;
	}
}