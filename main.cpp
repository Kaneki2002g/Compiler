#include <stdio.h>
#include "grammar.hpp"

extern FILE* yyin; // Strumień wejściowy dla leksera

int main(int argc, char** argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror("Cannot open file");
            return 1;
        }
    }

    printf("Parsing.\n");
    if (yyparse() == 0) {
        printf("Parsing completed successfully.\n");
    } else {
        printf("Parsing failed.\n");
    }

    return 0;
}