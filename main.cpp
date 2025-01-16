#include <stdio.h>
#include <iostream>
#include "grammar.hpp"

extern FILE* yyin;

void yyerror(const char* msg) {
    std::cerr << "Error: " << msg << std::endl;
}

int main(int argc, char** argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror("Cannot open file");
            return 1;
        }
    }

    //std::cout<<"Parsing.\n";
    if (yyparse() == 0) {
        //std::cout<<"Parsing completed successfully.\n";
    } else {
        std::cout<<"Parsing failed.\n";
    }

    return 0;
}