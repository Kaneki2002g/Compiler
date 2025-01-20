#include "brainpart.hpp"

bool buildingProcedures = false; //flag for building procedures
bool encounteredErrors = false;


void log(const std::string& message) {
    static bool firstCall = true; 

    std::ofstream logFile;
    if (firstCall) {
        logFile.open("log.txt", std::ios::out);
		firstCall = false;
    } else {
        logFile.open("log.txt", std::ios::app);
    }

    if (!logFile.is_open()) {
        std::cerr << "Nie można otworzyć pliku log.txt!" << std::endl;
        return;
    }

    logFile << message << std::endl;

   	logFile.close();
}

long long memCounter = 1;
void memInc(long long inc = 1){
	memCounter += inc;
}
long long ASSLINE = 0;
long long posCounter = 0;
long long helpCounter = 0;

long long mainLine;
long long mulPlace;
long long divPlace;


int mulUses=0;
int divUses=0;
int modUses=0;
int forUses=0;
int procUses=0;

std::map<std::string,int> procedure_uses;
std::vector<long long> jumpLines;
long long rLines = -1;

std::vector<CommandStruct*> commands;
std::vector<CommandStruct*> unknownJumps;
std::vector<std::string> errorLog;
long long getVPOS(){
	log("MAKING UNKNOWN JUMP #"+std::to_string(jumpLines.size()+1));
	rLines++;
	jumpLines.push_back(0);
	return rLines;
}
void setVPOS(long long pos, long long length){
	jumpLines[pos]=length; //NOTE: maybe +1
	log("SET #"+std::to_string(pos+1)+" JUMP TO " + std::to_string(length));
	unknownJumps[pos]->value = std::to_string(length);
	//std::cout<<"#SET "<<pos+1<<" JUMP TO "<<length<<"\n";
}
void toProg(std::string comm, long long i){
	//TEMP
	//std::cout<<comm<<" "<<i<<"\n";

	commands.push_back(new CommandStruct{comm,std::to_string(i)});

	ASSLINE++;
}
void toProg(std::string comm){
	//TEMP
	//std::cout<<comm<<"\n";
	commands.push_back(new CommandStruct{comm,""});
	ASSLINE++;
}

void buildFile(){
	for(int i=0;i<jumpLines.size();i++){
		//log(std::to_string(i+1)+": "+std::to_string(jumpLines[i]));
		unknownJumps[i]->value = std::to_string(jumpLines[i]);
		//std::cout<<jumpLines[i]<<std::endl;
	}
	for (CommandStruct* comm : commands){
		//temp
		std::cout<<comm->command<<" "<<comm->value<<std::endl;
	}
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
	//TODO: "SET -", abs(i)
	toProg("SET",i);
}
void HALF(){
	toProg("HALF");
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
void RTRN(long long i){
	toProg("RTRN", i);
}
void HALT(){
	toProg("HALT");
}

//UNKNOWN JUMPS
void uJUMP(long long i){ 
	//TEMP
	JUMP(123456789);
	unknownJumps.push_back(commands[commands.size()-1]);
	//TODO
}
void uJZERO(long long i){
	//TEMP
	JZERO(123456789);
	unknownJumps.push_back(commands[commands.size()-1]);
	//TODO
}
void uJPOS(long long i){
	//TEMP
	JPOS(123456789);
	unknownJumps.push_back(commands[commands.size()-1]);
	//TODO
}
void uJNEG(long long i){
	//TEMP
	JNEG(123456789);
	unknownJumps.push_back(commands[commands.size()-1]);
	//TODO
}
/*
REGISTERS:
ret - for returns
a - for arithmetic
b - for arithmetic
asign,bsign - a and b signs
o - for arithmetic
one - for 1 in for loops
mone - for -1 in multiplcation
*/

bool rtrnset = false;
long long rtrnReg = 0;

long long getretreg(){
	if (!rtrnset){
		rtrnReg = memCounter;
		memInc();
		rtrnset=true;
	}
	return rtrnReg;
}

bool abset = false;
long long areg = 0;
long long breg = 0;
long long asign = 0;
long long bsign = 0;

long long getareg(){
	if (!abset){
		areg = memCounter;
		memInc();
		breg = memCounter;
		memInc();
		asign = memCounter;
		memInc();
		bsign = memCounter;
		memInc();
		abset=true;
	}
	return areg;
}

long long getbreg(){
	if (!abset){
		areg = memCounter;
		memInc();
		breg = memCounter;
		memInc();
		asign = memCounter;
		memInc();
		bsign = memCounter;
		memInc();
		abset=true;
	}
	return breg;
}

long long getasign(){
	if(!abset){
		//error
	}
	return asign;
}
long long getbsign(){
	if(!abset){
		//error
	}
	return bsign;
}

bool oset = false;
long long oreg = 0;

long long getoreg(){
	if (!oset){
		oreg = memCounter;
		memInc();
		oset=true;
	}
	return oreg;
}

bool oneset = false;
long long onereg = 0;

long long getonereg(){
	if (!oneset){
		onereg = memCounter;
		memInc();
		oneset=true;
	}
	return onereg;
}

bool moneset = false;
long long monereg = 0;

long long getmonereg(){
	if (!oneset){
		monereg = memCounter;
		memInc();
		moneset=true;
	}
	return monereg;
}


//sareg,treg,mreg,yreg for division and modulo
bool stmy = false;
long long sareg = 0;
long long treg = 0;
long long mreg = 0;
long long yreg = 0;

long long getsareg(){
	if(!stmy){
		sareg = memCounter;
		memInc();
		treg = memCounter;
		memInc();
		mreg = memCounter;
		memInc();
		yreg = memCounter;
		memInc();
		stmy = true;
	}
	return sareg;
}
long long gettreg(){
	if(!stmy){
		sareg = memCounter;
		memInc();
		treg = memCounter;
		memInc();
		mreg = memCounter;
		memInc();
		yreg = memCounter;
		memInc();
		stmy = true;
	}
	return treg;
}
long long getmreg(){
	if(!stmy){
		sareg = memCounter;
		memInc();
		treg = memCounter;
		memInc();
		mreg = memCounter;
		memInc();
		yreg = memCounter;
		memInc();
		stmy = true;
	}
	return mreg;
}
long long getyreg(){
	if(!stmy){
		sareg = memCounter;
		memInc();
		treg = memCounter;
		memInc();
		mreg = memCounter;
		memInc();
		yreg = memCounter;
		memInc();
		stmy = true;
	}
	return yreg;
}

//

namespace vars{
	class Variable{
		public:
			void use(){used++;}
			void set(){sett=true;}
			bool isSet(){return sett;}
			int timesUsed(){return used;}
			std::string getName(){return name;}
			long long int getPos(){return memory_cell;}
			bool isLVar(){return loopvar;}
			void makeLVar(){loopvar=true;}
			void unMakeLVar(){loopvar=false;}
			bool isnUsed(){return usednow;}
			void usen(){usednow=true;}
			void unuse(){usednow=false;}
			void setPointer(){pointer = true;}
			bool isPointer(){return pointer;}
			bool isTablePointer(){return tablePointer;}
			void setTablePointer(){tablePointer=true;}
		private:
			std::string name;
			int used;
			bool sett;
			long long int memory_cell;
			bool loopvar;
			bool usednow;
			bool pointer;
			bool tablePointer;
		public:
			Variable(const std::string& name) : name(name), used(0), sett(false), memory_cell(memCounter), loopvar(false), usednow(false), pointer(false),tablePointer(false) {}
			Variable(){}
	};
	
	class Table{
		public:
			void use(){used++;}
			void set(long long i){sett[i]=true;}
			bool isSet(long long i){return sett[i];}
			int timesUsed(){return used;}
			std::string getName(){return name;}
			long long int getPos(long long i){return memory_cell+(i-first);/*TODO - Check if (i-first+1) is better && Guard, for OutOfBounds type error*/}
			bool inBounds(long long field){if(field >= first && field <= last){return true;}else{return false;}}
		private:
			std::string name;
			std::vector<bool> sett;
			long long first;
			long long last;
			int used;
			long long int memory_cell;
		public:
			Table(const std::string& name, long long a, long long b) : name(name), sett(b-a+1,false), first(a), last(b), used(0), memory_cell(memCounter) {}
			Table();
	};
	
	class Procedure{
		public:
			Procedure(const std::string& name): name(name){}
			Procedure(){}
			void add_local_variable(Variable var, std::string vname){
				localVariables.emplace(vname,var);
				//std::cout<<"#DECLARING LOCAL VARIABLE: "<<vname<<"\n";
				log("DECLARING LOCAL VARIABLE: "+vname);
			}
			void add_local_table(Table tab, std::string tname){localTables.emplace(tname,tab);}
			void remove_local_variable(std::string it_name){
				log("REMOVING LOCAL VARIABLE: "+it_name);
				localVariables.erase(it_name);
			}
			void add_given_variable(Variable var, std::string vname){
				log("DECLARING GIVEN VARIABLE: " + vname);
				givenVariables.emplace(vname,var);}
			void add_given_table(Variable tab, std::string tname){givenTables.emplace(tname,tab);}
			std::string getName(){return name;}
			Variable* find_local_variable(std::string vname){
				try{
					return &localVariables.at(vname);
				} catch(const std::out_of_range& e){
					return nullptr;
				}
			}
			Variable* find_given_variable(std::string vname){
				try{
					return &givenVariables.at(vname);
				} catch(const std::out_of_range& e){
					return nullptr;
				}
			}
			Table* find_local_table(std::string vname){
				try{
					return &localTables.at(vname);
				} catch(const std::out_of_range& e){
					return nullptr;
				}
			}
			Variable* find_given_table(std::string vname){
				try{
					return &givenTables.at(vname);
				} catch(const std::out_of_range& e){
					return nullptr;
				}
			}
			bool at_table(int pos){return g_types.at(pos);}
			int ltfproc(std::string tname){
				try{
					SET(localTables.at(tname).getPos(0));
					return 0;
				} catch(const std::out_of_range& e){
					try{
						LOAD(givenTables.at(tname).getPos());
						return 0;
					} catch(const std::out_of_range& e){
						//TODO: error table not found
						encounteredErrors = true;
						return 1;
					}
				}
			}
			int ltvproc(std::string tname){
				try{
					SET(localVariables.at(tname).getPos());
					return 0;
				} catch(const std::out_of_range& e){
					try{
						LOAD(givenVariables.at(tname).getPos());
						return 0;
					} catch(const std::out_of_range& e){
						//TODO: error table not found
						encounteredErrors = true;
						return 1;
					}
				}
			}
			long long addressfor(int pos){return addresses.at(pos);}
			void make_it_table(bool istable){g_types.push_back(istable);}
			void add_address(long long addr){addresses.push_back(addr);}
			void useDifferentProcedure(){usesProcedures=true;}
			bool usesProc(){return usesProcedures;}
			void setrtrn(long long r){ret = r;}
			void setStartLine(long long line){startLine=line;}
			long long getStartLine(){return startLine;}
			long long getrtrn(){return ret;}
			int howManyVars(){return g_types.size();}
			void loadVariable(Component* call){
				std::string cname(call->pid_name);
				try{
					LOAD(localVariables.at(cname).getPos());
					log("LOADING LOCAL VARIABLE: "+cname);
				}catch(const std::out_of_range& e){
					try{
						LOADI(givenVariables.at(cname).getPos());
						log("LOADING GIVEN VARIABLE: "+cname);
					}catch(const std::out_of_range& e){
						log("ERROR SEARCHING VARIABLE: "+cname);
						//TODO ERROR
						encounteredErrors=true;
						//std::cout<<"ERROR: variable not found or wrong type! line: "<<call->code_line<<"\n";//just for now
						//std::cout<<"SEEKING: "<<cname<<"\n";
					}
				}
			}
			void loadFromTable(Component* call){
				std::string tname(call->children->pid_name);
				if(call->type==32){//tab[pid]
					try{
						//std::string vname(call->children->next->pid_name);
						SET(localTables.at(tname).getPos(0));
						STORE(getoreg());
						loadVariable(call->children->next);
						ADD(getoreg());
						LOADI(0);
						log("LOADING LOCAL TABLE: "+tname);
					}catch(const std::out_of_range& e){
						try{
							//SET(call->children->next->number_value);
							loadVariable(call->children->next);
							ADD(givenTables.at(tname).getPos());
							LOADI(0);

							log("LOADING GIVEN TABLE: "+tname);
						}catch(const std::out_of_range& e){
							log("ERROR SEARCHING TABLE: "+tname);
							//TODO ERROR IF NON EI
							encounteredErrors = true;
						}
					}
				}else if(call->type==33){//tab[num]
					try{
						LOAD(localTables.at(tname).getPos(call->children->next->number_value));
						log("LOADING LOCAL TABLE: "+tname);
						//TODO error if out of bounds
					}catch(const std::out_of_range& e){
						try{
							SET(call->children->next->number_value);
							ADD(givenTables.at(tname).getPos());
							LOADI(0);
							log("LOADING GIVEN TABLE: "+tname);
						}catch(const std::out_of_range& e){
							//TODO ERROR IF NON EI
							log("ERROR SEARCHING TABLE: "+tname);
							encounteredErrors=true;
						}
					}
				}
			}
			void storeVar(Component* ident){
				if(ident->type==31){
					std::string vname(ident->children->pid_name);
					try{
						STORE(localVariables.at(vname).getPos());
						log("STORING IN LOCAL VARIABLE");
					}catch(const std::out_of_range& e){
						try{
							STOREI(givenVariables.at(vname).getPos());
							log("STORING IN GIVEN VARIABLE");
						}catch(const std::out_of_range& e){
							//TODO ERROR
							log("ERROR VARIABLE NOT FOUND");
							encounteredErrors=true;
						}
					}
				}else if(ident->type==33){
					std::string tname(ident->children->pid_name);
						try{
						STORE(localTables.at(tname).getPos(ident->children->next->number_value));
						log("STORING IN LOCAL TAB[NUM]");
						//TODO ERROR OUT OF BOUNDS
					}catch(const std::out_of_range& e){
						try{
							STORE(getoreg());
							SET(ident->children->next->number_value);
							ADD(givenTables.at(tname).getPos());
							STORE(getareg());
							LOAD(getoreg());
							STOREI(getareg());
							log("STORING IN GIVEN TAB[NUM]");
						}catch(const std::out_of_range& e){
							//TODO ERROR
							log("ERROR TABLE NOT FOUND");
							encounteredErrors=true;
						}
					}
				}else{
					std::string tname(ident->children->pid_name);
					//std::string vid = ->pid_name;
					STORE(getoreg());//storing in help register to load place to save
					loadVariable(ident->children->next); // load VARIABLE
						try{
							STORE(getareg());
							LOAD(localTables.at(tname).getPos(0));
							ADD(getareg());
							STORE(getareg());
							LOAD(getoreg());
							STOREI(getareg());
							log("STORING IN LOCAL TAB[PID]: "+tname);
						//STORE(localVariables.at(tname).getPos(ident->children->next->number_value));
						//TODO ERROR OUT OF BOUNDS
						}catch(const std::out_of_range& e){
							try{
								ADD(givenTables.at(tname).getPos());
								STORE(getareg());
								LOAD(getoreg());
								STOREI(getareg());
								log("STORING IN GIVEN TAB[PID]: "+tname);
							}catch(const std::out_of_range& e){
								//TODO ERROR
								encounteredErrors=true;
							}
						}
				}
			}
			private:
			std::string name;
			std::map<std::string, Variable> localVariables;
			std::map<std::string, Table> localTables;
			std::map<std::string, Variable> givenVariables;
			std::map<std::string, Variable> givenTables; //Tables are given as variables! (blackboxes)
			std::vector<bool> g_types;//given types
			std::vector<long long> addresses;
			long long startLine;
			bool usesProcedures = false;
			long long ret;
	};
};

vars::Procedure* currentProcedure = nullptr;;

std::map<std::string, vars::Variable> variables;
std::map<std::string, vars::Table> tables;
std::map<std::string,vars::Procedure> procedures;

Component* lastnext(Component* comp){
		Component* tot = comp;
		while(tot->next!=nullptr){
			tot=tot->next;
			}
		return tot;
}

void addMUL(){
	SET(0); //pre processing 
	STORE(getoreg()); //setting outcome register to 0
	LOAD(getareg()); //checking a sign
	JPOS(7);
	JZERO(45);
	SUB(getareg());
	SUB(getareg());
	STORE(getareg()); //
	LOAD(getmonereg());
	JUMP(2);
	LOAD(getonereg());
	STORE(getasign());
	LOAD(getbreg()); //checking b sign
	JPOS(7);
	JZERO(35);
	SUB(getbreg());
	SUB(getbreg());
	STORE(getbreg());
	LOAD(getmonereg());
	JUMP(2);
	LOAD(getonereg());
	STORE(getbsign());
	LOAD(getbreg()); //multiplication start
	HALF();
	JZERO(14); //to change
	ADD(0);
	SUB(getbreg());
	JZERO(4);
	LOAD(getoreg());
	ADD(getareg());
	STORE(getoreg());
	LOAD(getbreg());
	HALF();
	STORE(getbreg());
	LOAD(getareg());
	ADD(0);
	STORE(getareg());
	JUMP(-15);
	LOAD(getoreg());
	ADD(getareg());
	STORE(getoreg());
	LOAD(getasign());
	ADD(getbsign());
	JZERO(3); //to possible sign change
	LOAD(getoreg()); //4
	JUMP(4); //toend
	LOAD(getoreg());
	SUB(getoreg());
	SUB(getoreg());
	RTRN(getretreg());
}
void addDIV(){
	SET(0);
	STORE(getoreg());
	LOAD(getbreg()); //dzielenie
	JZERO(62);
	JPOS(6);
	SUB(getbreg());
	SUB(getbreg());
	STORE(getbreg());
	LOAD(getmonereg());
	JUMP(2);
	LOAD(getonereg());
	STORE(getbsign());
	LOAD(getareg());
	JZERO(53);
	JPOS(6);
	SUB(getareg());
	SUB(getareg());
	STORE(getareg());
	LOAD(getmonereg());
	JUMP(2);
	LOAD(getonereg());
	STORE(getasign());
	LOAD(getasign());
	ADD(getbsign());
	STORE(getsareg());
	LOAD(getareg());
	SUB(getbreg());
	JNEG(25);
	LOAD(getbreg());
	STORE(gettreg());
	LOAD(getonereg());
	STORE(getmreg());
	LOAD(gettreg());
	ADD(gettreg());
	STORE(getyreg());
	LOAD(getareg());
	SUB(getyreg());
	JNEG(8);
	LOAD(gettreg());
	ADD(gettreg());
	STORE(gettreg());
	LOAD(getmreg());
	ADD(getmreg());
	STORE(getmreg());
	JUMP(-12);
	LOAD(getareg());
	SUB(gettreg());
	STORE(getareg());
	LOAD(getoreg());
	ADD(getmreg());
	STORE(getoreg());
	JUMP(-26);
	LOAD(getsareg());
	JZERO(2);
	JUMP(9); //do zmiany
	LOAD(getareg());//1
	JZERO(4);//2
	LOAD(getoreg());
	ADD(getonereg());
	STORE(getoreg());
	SUB(getoreg());
	SUB(getoreg());
	STORE(getoreg());
	LOAD(getbsign());
	JPOS(4);
	LOAD(getareg());
	SUB(getbreg());
	STORE(getareg());
	LOAD(getoreg());
	RTRN(getretreg());
}
void addMOD(){
	addDIV();
}


//VARIABLE MANIPULATION FUNCTIONS
void declare_var(Component* declaration){
	std::string name(declaration->pid_name);
	vars::Variable var(name);
	log("DECLARING VAR "+name);
	if(!buildingProcedures){
		variables.emplace(name,var);
	} else {
		currentProcedure->add_local_variable(var,name);
	}
	memInc();
}
void declare_tab(Component* declaration){
	std::string name(declaration->pid_name);
	vars::Table tab(name,declaration->children->number_value,declaration->children->next->number_value);
	log("DECLARING TAB "+name+"["+std::to_string(declaration->children->number_value)+":"+std::to_string(declaration->children->next->number_value)+"]");
	if(!buildingProcedures){
		tables.emplace(name,tab);
	} else{
		currentProcedure->add_local_table(tab,name);
	}
	memInc((declaration->children->next->number_value)-(declaration->children->number_value)+1);
}

vars::Variable decl_vartab(Component* declaration){ //NOTE: MAY NEED POINTERS
	std::string name(declaration->pid_name);
	vars::Variable var(name);//TODO:ERROR IF NAME IN DIFFERENT VARS IN PROCEDURE
	var.setPointer();
	if(declaration->type==2){
		var.setTablePointer();
	}
	memInc();
	return var;
}

vars::Variable declare_proc_var(Component* declaration){
	std::string name(declaration->pid_name);
	vars::Variable var(name);//TODO:ERROR IF NAME IN DIFFERENT VARS IN PROCEDURE
	memInc();
	return var;
}

vars::Table declare_proc_tab(Component* declaration){
	std::string name(declaration->pid_name);
	vars::Table tab(name,declaration->children->number_value,declaration->children->next->number_value);//TODO:ERROR IF NAME IN DIFFERENT VARS IN PROCEDURE
	memInc((declaration->children->next->number_value)-(declaration->children->number_value)+1);
	return tab;
}


long long getMemCell(Component* call){
	long long outcome=0;
	if(call->type==31){//normal variable
		std::string name(call->children->pid_name);
		try{
			vars::Variable var = variables.at(name);	
			outcome = var.getPos();
		}catch(const std::out_of_range& e){
			//TODO
			//throw error at varline
		}
	} else if(call->type==33){//table[num]
		std::string name(call->children->pid_name);
		try{
			vars::Table tab = tables.at(name);
			outcome = tab.getPos(call->children->next->number_value);
			if(call->children->next->type==1){
				log("all is ok!");
			} else{
				log("something wrong!");
			}
			log("TRYING TO GET POSITION: "+std::to_string(call->children->next->number_value)+" FROM TABLE: "+name);
			//TODO
			//error if out of bounds
		}catch(const std::out_of_range& e){
			//TODO
			//throw error at varline
			//or if out of bounds
		}
	} else if(call->type==32){//table[variable]
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
		log("SETTING");
		SET(check->number_value);
	} else {

		if(buildingProcedures){
			if(check->type==31){
				currentProcedure->loadVariable(check->children);
			} else{
				currentProcedure->loadFromTable(check);
			}
		}else{
			if(check->type!=32){
				log("LOADING FROM KNOWN PLACE");
				LOAD(getMemCell(check));
			} else{
				log("LOADING INDIRECT FROM UNKNOWN PLACE IN TABLE");
				std::string tname(check->children->pid_name);
				std::string vname(check->children->next->pid_name);

				//outcome = var.getPos();
				SET((tables.at(tname).getPos(0)));
				ADD(variables.at(vname).getPos());
				LOADI(0);
			}
		}
	}
}
void doArithmetic(Component* expr){
	log("DOING ARITHMETIC");
	//ID := EXPR
	//long long adr = getMemCell(varsetexp->children);
	//Component* expr = varsetexp->children->next;
	//VALUES
	Component* first = expr->children;
	Component* second = expr->children->next;//NOTE: may be nullptr
	switch(expr->type){
		case 61:
			log("ONLY ONE WORD IN EXPRESSION");
			loadORset(first);
		break;
		case 62:
			log("ADDITION");
			if(first->children->type==1 && second->children->type==1){
				log("BOTH NUMBERS");
				SET(first->children->number_value+second->children->number_value); //NOTE: MAY GO OUT OF LONG LONG BOUNDARIES SHOULD MAKE TEXT_CONVERSION_ADD
			} else if(first->children->type!=1 && second->children->type==1){
				log("FIRST VARIABLE SECOND NUMBER");
				loadORset(first);
				STORE(getoreg());
				SET(second->children->number_value);
				ADD(getoreg());	//NOTE: getMemCell should throw error when trying to get address of loop variable out of said loop
			}else if(first->children->type==1 && second->children->type!=1){
				log("FIRST NUMBER SECOND VARIABLE");
				loadORset(second);
				STORE(getoreg());
				SET(first->children->number_value);
				ADD(getoreg());
			}else{
				log("BOTH VARIABLES");
				loadORset(first);
				STORE(getoreg());
				loadORset(second);
				ADD(getoreg());
			}
		break;
		case 63:
			log("SUBTRACTION");
			if(first->children->type==1 && second->children->type==1){
				log("BOTH NUMBERS");
				SET(first->children->number_value-second->children->number_value); //NOTE: MAY GO OUT OF LONG LONG BOUNDARIES SHOULD MAKE TEXT_CONVERSION_ADD and SET(string)
			} else if(first->children->type!=1 && second->children->type==1){
				log("FIRST VARIABLE SECOND NUMBER");
				loadORset(first);
				STORE(getoreg());
				SET(-(second->children->number_value)); // a - b = -b + a
				ADD(getoreg());
			}else if(first->children->type==1 && second->children->type!=1){
				log("FIRST NUMBER SECOND VARIABLE");
				loadORset(second);
				STORE(getoreg());
				SET(first->children->number_value);
				SUB(getoreg());
			}else{
				log("BOTH VARIABLES");
				loadORset(second);
				STORE(getoreg());
				loadORset(first);
				SUB(getoreg());
			}
		break;
		case 64://NOTE: MUL,DIV,MOD - should be functions(if needed) with copied values instead of references
			log("MULTIPLICATION");
			if(first->children->type==1 && second->children->type==1){
				log("BOTH NUMBERS");
				SET(first->children->number_value*second->children->number_value); //NOTE: MAY GO OUT OF LONG LONG BOUNDARIES SHOULD MAKE TEXT_CONVERSION_ADD and SET(string)
			} else if((first->children->type==1 && first->children->number_value<50)||( second->children->type==1 && second->children->number_value<50)){
				log("ONE NUMBER, ONE VARIABLE, ABS(NUMBER) SMALLER THAN 50");
				long long times = first->children->number_value+second->children->number_value;
				if(times>0 ){ //NOTE: may be shortened with abs(long long) but for now it works
					if(first->children->type==1){
						loadORset(second);
						STORE(getoreg());
						for(long long i=1;i<times;i++){
							ADD(getoreg());
						}
					} else {
						loadORset(first);
						STORE(getoreg());
						for(long long i=1;i<=times;i++){
							ADD(getoreg());
						}
					}
				} else if(times<0){
					if(first->children->type==1){
						loadORset(second);
						STORE(getoreg());
						SUB(getoreg());
						SUB(getoreg());
						STORE(getoreg());
						for(long long i=-1;i>times;i--){
							ADD(getoreg());
						}
					} else {
						loadORset(first);
						STORE(getoreg());
						SUB(getoreg());
						SUB(getoreg());
						STORE(getoreg());
						for(long long i=-1;i>times;i--){
							ADD(getoreg());
						}
					}
				}else{
					SET(0);
				}
			}else{
				log("USING MULTIPLICATION PROCEDURE");
				if(buildingProcedures){
					currentProcedure->useDifferentProcedure();
				}
				loadORset(first);
				STORE(getareg());
				loadORset(second);
				STORE(getbreg());
				SET(ASSLINE+3);
				STORE(getretreg());
				JUMP(mulPlace-ASSLINE);
			}
		break;
		case 65://TODO DIVISION
			log("DIVISION");
			if(first->children->type==1 && second->children->type==1){
				
				SET(first->children->number_value/second->children->number_value); //NOTE: MAY GO OUT OF LONG LONG BOUNDARIES SHOULD MAKE TEXT_CONVERSION_ADD and SET(string)
			} else if(second->children->type==1 && second->children->number_value==2){
				loadORset(first);
				HALF();
			}else{
				if(buildingProcedures){
					currentProcedure->useDifferentProcedure();
				}
				loadORset(first);
				STORE(getareg());
				loadORset(second);
				STORE(getbreg());
				SET(ASSLINE+3);
				STORE(getretreg());
				JUMP(divPlace-ASSLINE);
			}
		//TODO
		break;
		case 66:
			if(buildingProcedures){
					currentProcedure->useDifferentProcedure();
			}
			log("MODULO");
			loadORset(first);
			STORE(getareg());
			loadORset(second);
			STORE(getbreg());
			SET(ASSLINE+3);
			STORE(getretreg());
			JUMP(divPlace-ASSLINE);
			LOAD(getareg());
		//TODO
		break;
	}
	//STORE(adr);
}

int compareA(Component* cond){
	//returns:
	//1 - always True
	//-1 - never True
	//0 - comparing variable
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
void compareB(Component* cond){ //NOTE:CompareB should give lines how much it took (int)
	Component* first = cond->children;
	Component* sec = first->next;
	Component* fakesub = new Component();//fake subtracting
	fakesub->type = 63;
	fakesub->children=first;
	doArithmetic(fakesub);
	/*
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
	}*/
}

//PROGRAM BUILDING FUNCTIONS
void useMul(){mulUses++;}
void useDiv(){divUses++;}
void useMod(){modUses++;}
void useFor(){forUses++;}
void useProc(){procUses++;}

void buildProgram(Component* all){
	log("STARTING PROGRAM BUILDING");
	if(mulUses+modUses+procUses+divUses>0){
		log("PROCEDURES ARE PRESENT, RESERVING PLACE FOR JUMP TO MAIN");
		ASSLINE=1; //reserve line for JUMP
	}
	if(mulUses>0){
		log("RESERVING REGISTERS FOR MULTIPLICATION, ADDING MULTIPLICATION");
		auto r = getretreg();
		auto a = getareg();
		auto b = getbreg();
		auto o = getoreg();
		auto mo = getmonereg();
		//mulPos = ASSLINE;
		mulPlace = ASSLINE;
		addMUL();
	}
	if(divUses>0){
		log("RESERVING REGISTERS FOR DIVISION, ADDING DIVISION");
		auto r = getretreg();
		auto a = getareg();
		auto b = getbreg();
		auto o = getoreg();
		auto mo = getmonereg();
		divPlace = ASSLINE;
		addDIV();
	}
	if(modUses>0){
		log("RESERVING REGISTERS FOR MODULO, ADDING DIVISION");
		auto r = getretreg();
		auto a = getareg();
		auto b = getbreg();
		auto o = getoreg();
		auto mo = getmonereg();
		divPlace = ASSLINE;
		addMOD();
	}
	Component* a = all->children; //a = {[procedures], main}
	buildingProcedures=true;
	buildProcedures(a);
	buildingProcedures=false;
	mainLine = ASSLINE;
	//REGISTERS INITIALISATION
	if(forUses>0 || mulUses>0 || divUses>0 || modUses>0){
		auto one = getonereg();
		SET(1);
		STORE(one);
	}
	if(mulUses>0 || divUses>0 || modUses>0){
		auto mone = getmonereg();
		SET(-1);
		STORE(mone);
	}
	buildMain(a->next);

	HALT();

	if(mainLine>0){
		log("JUMP" + std::to_string(mainLine)+" AT THE BEGINNING");
		commands.insert(commands.begin(), new CommandStruct{"JUMP", std::to_string(mainLine)});
		}
	
	
	log("END OF PROGRAM");
	log("UNKNOWN JUMPS:");
	for(int i=0;i<jumpLines.size();i++){
		log(std::to_string(i+1)+": "+std::to_string(jumpLines[i]));
	}
}


//PROCEDURE MAKING
void makeProcedure(Component* procedure){
	Component* proc_head=procedure->children;
	Component* declarations;
	Component* commands;
	std::string name(proc_head->children->pid_name);

	log("DECLARING PROCEDURE: "+ name);

	vars::Procedure proc(name);

	proc.setStartLine(ASSLINE);
	currentProcedure = &proc;
	if(procedure->type==151){
		declarations = proc_head->next;
		commands = declarations->next;
	}else if(procedure->type==152){
		declarations = nullptr;
		commands = proc_head->next;
	}else{
		std::cout<<"MKPROC:SHOULD NOT GET HERE WITH TYPE:"<<procedure->type<<"\n";
	}
	Component* pids = proc_head->children->next->children;
	while(pids!=nullptr){ //args_decl
		if(pids->type==21){//variable
			std::string vname(pids->pid_name);
			vars::Variable var = decl_vartab(pids);
			proc.add_given_variable(var,vname);
			proc.make_it_table(false);
			proc.add_address(var.getPos());
		}else if (pids->type==22){//table
			//std::string name(pids->pid_name);
			std::string tname(pids->pid_name);
			vars::Variable tab = decl_vartab(pids);
			proc.add_given_table(tab,tname);
			proc.make_it_table(true);
			proc.add_address(tab.getPos());
		}
		pids=pids->next;
	}
	if(declarations != nullptr){
		log("DECLARING PROCEDURE LOCAL VARIABLES");
		declareVariables(declarations);
	}
	log("BUILDING PROCEDURE COMMANDS");
	buildCommands(commands);
	long long ret;
	if(proc.usesProc()){
		log("PROCEDURE USES DIFFERENT PROCEDURE, NOT DEFAULT RETURN REGISTER");
		ret = memCounter;
		memInc();
	}else{
		log("PROCEDURE DOESN'T USE DIFFERENT PROCEDURE, DEFAULT RETURN REGISTER");
		ret = getretreg();
	}
	proc.setrtrn(ret);
	RTRN(ret);
	procedures.emplace(name,proc);
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
	log("");
	log("STARTING MAIN BUILDING");
	if(main->type==141){
		log("DECLARING MAIN VARIABLES");
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
void ifthenelse(Component* comm){ //ifthen(else)
	log("MAKING IFTHEN(ELSE) COMMAND");
	Component* condition = comm->children;
	Component* then = condition->next;
	Component* elsse = then->next;
	//BOTH NUMBERS NO JUMPS NEEDED
	int help = compareA(condition);
	int help2 = 0;
	if(help==1){
	log("THIS COMPARISON IS ALWAYS TRUE");
	buildCommands(then);
	}else if(help==-1){
		log("THIS COMPARISON IS NEVER TRUE");
		if (elsse!=nullptr){
			buildCommands(elsse);
		}
	}else{
		log("COMPARISON DEPENDANT ON VARIABLES");
		long long j1,j2;
		switch(condition->type){//NUM COMP ID
			case 51:{//==
				compareB(condition);
				JZERO(2);
				j1 = getVPOS();
				uJUMP(j1);
				}
			break;
			case 52:{//!=
				compareB(condition);
				j1 = getVPOS();
				uJZERO(j1);
				}
			break;
			case 53:{//>
				compareB(condition);
				JPOS(2);
				j1 = getVPOS();
				uJUMP(j1);
				}
			break;
			case 54:{//<
				compareB(condition);
				JNEG(2);
				j1 = getVPOS();
				uJPOS(j1);
				}
			break;
			case 55:{//>=
				compareB(condition);
				JPOS(2);
				j1 = getVPOS();
				uJNEG(j1);
				}
			break;
			case 56:{//<=
				compareB(condition);
				JNEG(2);
				j1 = getVPOS();
				uJPOS(j1);
				}
			break;
		}
		buildCommands(then);
			if(elsse!=nullptr){
				j2 = getVPOS();
				uJUMP(j2);
				help2++;
			}
			setVPOS(j1,helpCounter+1+help2);
			if(elsse!=nullptr){
				buildCommands(elsse);
				setVPOS(j2,helpCounter+1);
			}
	}
}
void repeatUntil(Component* comm){
	Component* doings = comm->children;
	Component* cond = doings->next;
	int help=compareA(cond);
	if(help==0){//non defined loop
		buildCommands(doings);
		long long a = ASSLINE;
		compareB(cond);
		long long b = ASSLINE;
		switch(cond->type){ //NOTE: another +1 may be  needed for jumps
			case 51://==
			JZERO(2);
			JUMP(-(helpCounter+(b-a)));
			break;
			case 52://!=
			JZERO(-(helpCounter+(b-a)));
			break;
			case 53://>
			JPOS(2);
			JUMP(-(helpCounter+(b-a)));
			break;
			case 54://<
			JNEG(2);
			JUMP(-(helpCounter+(b-a)+1));
			break;
			case 55://>=
			JNEG(-(helpCounter+(b-a)));
			break;
			case 56://<=
			JPOS(-(helpCounter+(b-a)));
			break;
		}
	} else if(help==1){//infinite loop
		buildCommands(doings);
		JUMP(-helpCounter);
	}//help == -1 never happens
}
void makefor(Component* loop){
	log("");
	log("STARTING FOR");
	Component* pid = loop->children;
	Component* start = pid->next;
	Component* finish = start->next;
	Component* comms = finish->next;
	vars::Variable iterator;

	bool isGlobal = false;
	
	std::string it_name(pid->pid_name);
	
	//NOTE:workaround for example 6, which in my opinion should fail because j should be local, instead is global!
	if(variables.find(it_name)!=variables.end()){
		log("USING GLOBAL ITERATOR VARIABLE!! SHOULD NOT HAPPEN!");
		variables.at(it_name).makeLVar();
		iterator = variables.at(it_name);
		isGlobal=true;
	} else{
		iterator = vars::Variable(it_name);
		iterator.makeLVar();
		memInc();
	}
	log("OKAY");
	if(!buildingProcedures){
		if(!isGlobal){
			log("PLACING ITERATOR IN VARS");
			variables.emplace(it_name,iterator);
		}
	} else{
		currentProcedure->add_local_variable(iterator,it_name);
	}
	//vars::Variable* iterator = decloop_var(pid);
	long long dest=-1;
	loadORset(start);
	STORE(iterator.getPos());
	loadORset(finish);
	STORE(memCounter);
	dest = memCounter;
	memInc();
	//4LINES
	long long j1 = getVPOS();;
	if(loop->type==126){//growing
		LOAD(dest);
		SUB(iterator.getPos());
	} else {//smolling
		LOAD(iterator.getPos());
		SUB(dest);
	}
	uJNEG(j1);
	buildCommands(comms);
	LOAD(iterator.getPos());
	if(loop->type==126){
		ADD(getonereg());
	} else {
		SUB(getonereg());
	}
	STORE(iterator.getPos());
	JUMP(-(helpCounter+6));
	setVPOS(j1,helpCounter+5);
	//iterator->unuse();
	
	if(!buildingProcedures){
		if(!isGlobal){
			variables.erase(it_name);
		} else {
			variables.at(it_name).unMakeLVar();
		}
	} else{
		currentProcedure->remove_local_variable(it_name);
	}
	log("ENDING FOR");
}
void procedureCall(Component* proc_call){
	Component* pid = proc_call->children;
	std::string pname(pid->children->pid_name);
	//std::cout<<"PROC: "<<pname<<"\n";
	Component* args = pid->children->next;//->[[arg1]->[arg2]->...]
	//std::cout<<"SEARCHING\n";
	vars::Procedure* proc = &procedures.at(pname);
	//std::cout<<"check0!\n";
	//TODO ERROR IF NOT FOUND
	if(buildingProcedures){
		if(proc->getName()==currentProcedure->getName()){
				std::cout<<"check1!\n";
			//TODO: Throw error
		}
		currentProcedure->useDifferentProcedure();
	}
	//if(proc==)TODO: error if proc not yet declared
	Component* arg = args->children;
	int pos = 0;
	while(arg!=nullptr){
		if (pos>proc->howManyVars()){
			std::cout<<proc->howManyVars()<<"\n";
			//TODO: ERROR out of bounds
		}
		//std::cout<<proc->howManyVars()<<"\n";
		if(proc->at_table(pos)){//expecting table
			std::string tname(arg->pid_name);
			if(buildingProcedures){
				currentProcedure->ltfproc(tname);
				STORE(proc->addressfor(pos));
			}else{
				try{
					SET(tables.at(tname).getPos(0));
					STORE(proc->addressfor(pos));
				} catch(const std::out_of_range& e){
					//TODO: ERROR: not found table
				}
			}
		}else{//expecting variable
			std::string vname(arg->pid_name);
			if(buildingProcedures){
				currentProcedure->ltvproc(vname);
				STORE(proc->addressfor(pos));
			}else{
				try{
					SET(variables.at(vname).getPos());
					STORE(proc->addressfor(pos));
				} catch(const std::out_of_range& e){
					//TODO: ERROR: not found table
				}
			}
		}
		pos=pos+1;
		arg=arg->next;
	}
	if(pos<proc->howManyVars()){
		//TODO: ERROR too little variables
	}
	SET(ASSLINE+3);
	STORE(proc->getrtrn());
	JUMP(proc->getStartLine()-ASSLINE);
}
void buildCommands(Component* commands){
	long long start = ASSLINE;
	Component* comm = commands->children;
	while(comm!=nullptr){
		//std::cout<<"TYPE: "<<comm->type;
		switch(comm->type){
			case 121:{//TODO:ERROR IF SETTING LOOP VARIABLE
				doArithmetic(comm->children->next);

				if(!buildingProcedures){
					//NOTE: WON'T WORK WITH tab[num] or tab[pid]
					if(comm->children->type!=32){
						log("NORMAL PLACING! type: "+std::to_string(comm->type));
						STORE(getMemCell(comm->children));
					} else{
						log("PLACING IN UNKNOWN TAB PLACE");
						STORE(getoreg());
						std::string tname(comm->children->children->pid_name);
						std::string vname(comm->children->children->next->pid_name);
						SET(tables.at(tname).getPos(0));
						ADD(variables.at(vname).getPos());
						STORE(getareg());
						LOAD(getoreg());
						STOREI(getareg());
					}

				} else{
						currentProcedure->storeVar(comm->children);
				}
			}
			break;
			case 122:{
				//ifthenelse
				ifthenelse(comm);
			}
			break;
			case 123:{
				//ifthen
				ifthenelse(comm);
			}
			break;
			case 124:{
				//NOTE: NOT TESTED PROPERLY
				//TODO: IF ALWAYS TRUE INFINITE LOOP, ELSE SKIP
				log("");
				log("WHILE LOOP (FAKE IF)");
				long long curPoint=ASSLINE;
				Component* fakeifthen = new Component();
				long long cheatNumber = rLines+1;
				fakeifthen->children=comm->children;
				ifthenelse(fakeifthen);
				log("JUMP #"+std::to_string(cheatNumber)+" INCREASE BY ONE");
				jumpLines[cheatNumber]++;
				//std::cout<<"\033[F\033[10C#JUMP "<<cheatNumber+1<<" WILL BE BIGGER BY 1\n";
				JUMP((curPoint-ASSLINE));
				//while...do
				log("END WHILE LOOP");
				log("");
				break;
				}
			case 125:{
				repeatUntil(comm);
			}
			break;
			case 126:
			makefor(comm);
			break;
			case 127:
			makefor(comm);
			break;
			case 128:
			procedureCall(comm);
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
						loadORset(comm->children);
					}else{
						printMemPlace = -1;
						std::cout<<"SHOULD NOT GET HERE WITH TYPE:"<<comm->children->type<<"\n";
					}
					PUT(0);
				}
			break;
		}
		comm=comm->next;
	}
	helpCounter=ASSLINE-start;
	//std::cout<<"#THIS SUB-PART TOOK "<<helpCounter<<" LINES\n";
}