#include "parse.h"
#include <stdio.h>
#include <stdlib.h>

int main (void) {
    printf ("Testing\n\n");

    Prog* program = progLoad ("test_program.txt");
    progRun (program);
    printf ("\n");
    progClose (program);
    
    return EXIT_SUCCESS;
}
