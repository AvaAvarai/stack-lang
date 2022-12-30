#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "parse.h"
#include "stack.h"

#define STACK_SIZE 100

struct Prog
{
    char*   code; // this should be a tree not a char* IR needs work
    Stack* stack;
};

Prog* progLoad (char* filename)
{
    FILE* file = fopen (filename, "r");
    if (file == NULL)
    {
        fprintf (stderr, "File open error.\n");
        exit (EXIT_FAILURE);
    }

    Prog* out = malloc (sizeof (Prog));
    if (out == NULL)
    {
        fprintf (stderr, "Memory allocation error.\n");
        exit (EXIT_FAILURE);
    }
 
    fseek (file, 0L, SEEK_END);
    long size = ftell (file);
    char* text = malloc ( size * sizeof *text);
    out->code = malloc ( size * sizeof out->code);
    fseek (file, 0L, SEEK_SET);

    if (text == NULL)
    {
        fprintf (stderr, "Memory allocation error.\n");
        exit (EXIT_FAILURE);
    }

    size_t read = fread (out->code, 1, size, file);
    if (read != size)
    {
        fprintf (stderr, "Memory allocation error.\n");
        exit (EXIT_FAILURE);
    }

    out->stack = stackCreate (STACK_SIZE);

    return out;
}

void progRun (Prog* program)
{
    // parsing wip
    for (size_t iter = 0; iter < strlen (program->code); iter++)
    {
        // ignore comments
        if ( program->code[iter] == '#' )
        {
            while ( program->code[iter] != '\n' )
            {
                iter++;
            }
        }

        // capture opcode
        while ( program->code[iter] != ' ' )
        {
            iter++;
        }
        printf("%c", program->code[iter]);
    }
}

void progClose (Prog* program)
{
    stackDelete (program->stack);
    free (program->code);
    free (program);
}
