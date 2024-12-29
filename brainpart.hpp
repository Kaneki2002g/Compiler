#ifndef BRAINPART_HPP
#define BRAINPART_HPP
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <vector>
#include <map>

void declare_var(char* name);
void declare_tab(char* name, long long a, long long b);
void setvar(char* name, char* value);
char* add(char* a, char* b);
char* sub(char* a, char* b);
char* mul(char* a, char* b);
char* div(char* a, char* b);
char* mod(char* a, char* b);
void read(char* var);
void write(char* var);

#endif // BRAINPART_HPP