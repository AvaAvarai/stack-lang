#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "parse.h"
#include "stack.h"

#define STACK_SIZE 100

struct Prog
{
    char*   code;
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
    for (unsigned int iter = 0; iter < strlen (program->code); iter++)
    {
        char opcode[5];
        int pos = 0;
        
        // ignore whitespace
        if (program->code[iter] == ' ' || program->code[iter] == '\n')
        {
            printf ("%s\n", opcode);
            pos = 0;
            memset (opcode, 0, sizeof opcode);
            continue;
        }
        
        // ignore comments
        if (program->code[iter] == '#')
        {
            iter++;
            while (program->code[iter] != '#')
            {
                iter++;
            }
            continue;
        }

        // capture opcode
        if (((int)program->code[iter] >= 65 && (int)program->code[iter] <= 90) || ((int)program->code[iter] >= 97 && (int)program->code[iter] <= 172))
        {
            if (pos >= 0 && pos < 5)
            {
                opcode[pos] = program->code[iter];
                pos++;
            }
            else
            {
                fprintf (stderr, "Parsing error.\n");
                exit (EXIT_FAILURE);
            }
        }
    }
}

void progClose (Prog* program)
{
    stackDelete (program->stack);
    free (program->code);
    free (program);
}
