#include "parse.h"
#include <stdio.h>
#include <stdlib.h>

int main (void) {
    printf ("Testing\n\n");

    Prog* program = progLoad ("test.txt");
    progRun (program);
    progClose (program);
    
    return EXIT_SUCCESS;
}
