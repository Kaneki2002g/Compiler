#include "brainpart.hpp"
//#include <map>
//#include <vector> to w brainpart.hpp

int memCounter = 1;
int posCounter = 0;

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

void declare_var(char* name){
	//TEMP
	std::cout<<"declaring "<<name<<" variable!\n";
	//TODO
}
void declare_tab(char* name, long long a, long long b){
	//TEMP
	std::cout<<"declaring "<<name<<" table!\n";
	//TODO
}
void setvar(char* name, char* value){
	//TEMP
	std::cout<<name<<" is set to "<<value<<"\n";
	//TODO
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
void read(){}
void write(char* var){}