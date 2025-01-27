#include <stdio.h>
#include <iostream>
#include "brainpart.hpp"
#include "grammar.hpp"

extern FILE* yyin;

void yyerror(const char* msg) {
    std::cerr << "Error: " << msg << std::endl;
}

int main(int argc, char** argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            std::cout<<"Cannot open file\n";
            return 0;
        }
    }
    if(argc<3){
        std::cout<<"Usage: " +std::string(argv[0])+" <source_file> <output_filename> !\n";
        return 0;
    }

    std::string filename(argv[2]);

    //std::cout<<"Parsing.\n";
    if (yyparse() == 0) {
        buildFile(filename);
    } else {
        std::cout<<"Parsing failed.\n";
    }
    

    return 0;
}