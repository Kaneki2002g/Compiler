#ifndef BRAINPART_HPP
#define BRAINPART_HPP
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include "structs.h"

Component* lastnext(Component* comp);
void declare_var(Component* declaration);
void declare_tab(Component* declaration);
void setvar(char* name, char* value);
char* add(char* a, char* b);
char* sub(char* a, char* b);
char* mul(char* a, char* b);
char* div(char* a, char* b);
char* mod(char* a, char* b);
void read(char* var);
void write(char* var);

void useMul();
void useDiv();
void useMod();

void buildProgram(Component* all);
void buildProcedures(Component* procedures);
void buildMain(Component* main);
void declareVariables(Component* declarations);
void buildCommands(Component* commands);

#endif // BRAINPART_HPP