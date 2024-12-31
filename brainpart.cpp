#include "brainpart.hpp"
//#include <map>
//#include <vector> to w brainpart.hpp

int memCounter = 1;
int posCounter = 0;
int helpCounter = 0;

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
	std::map<std::string, Variable> variables;
	std::map<std::string, Table> tables;
};

Component* lastnext(Component* comp){
		Component* tot = comp;
		while(tot->next!=nullptr){
			tot=tot->next;
			}
		return tot;
}

void declare_var(Component* declaration){
	//TEMP
	std::cout<<"declaring "<<declaration->pid_name<<" variable!\n";
	//TODO
}
void declare_tab(Component* declaration){
	//TEMP
	std::cout<<"declaring "<<declaration->pid_name<<" table with bounds:"<<declaration->children->number_value<<" : "<<declaration->children->next->number_value<<"\n";
	//TODO
}
void setvar(char* name, char* value){
	//TEMP
	std::cout<<name<<" is set to "<<value<<"\n";
	//TODO
}
void settab(char* name, long long pos, char* value){
	
}
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
			std::cout<<"DECL: SHOULD NOT GET HERE WITH TYPE: "<<decl->type<<"!\n";
		}
		decl=decl->next;
	}
}
void buildCommands(Component* commands){
	Component* comm = commands->children;
	while(comm!=nullptr){
		std::cout<<"TYPE: "<<comm->type<<"\n";
		//TODO: command translation
		comm=comm->next;
	}
}



































