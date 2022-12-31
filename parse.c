#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
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
    char opcode[6];
    int pos = 0;

    char operand[11];
    int pos2 = 0;
    
    for (unsigned int iter = 0; iter < strlen (program->code); iter++)
    {
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
        
        // ignore whitespace
        if (program->code[iter] == ' ' || program->code[iter] == '\n')
        {
            if (pos > 0) // an opcode was read in
            {
                for (int i = 0; i < strlen (opcode); i++)
                {
                    opcode[i] = tolower (opcode[i]);
                }
                
                if (strcmp (opcode, "push") == 0)
                {
                    iter++;
                    while (program->code[iter] == ' ' || program->code[iter] == '\n')
                    {
                        iter++;
                    }
                    while (isdigit (program->code[iter]))
                    {
                        operand[pos2] = program->code[iter];
                        pos2++;
                        iter++;
                    }
                    stackPush (program->stack, atoi (operand));
                    pos2 = 0;
                    memset (operand, 0, sizeof operand);
                }
                else if (strcmp (opcode, "pop") == 0)
                {
                    stackPop (program->stack);
                }
                else if (strcmp (opcode, "dup") == 0)
                {
                    stackPush (program->stack, stackPeek (program->stack));
                }
                else if (strcmp (opcode, "add") == 0)
                {
                    stackPush (program->stack, stackPop (program->stack) + stackPop (program->stack));
                }
                else if (strcmp (opcode, "sub") == 0)
                {
                    stackPush (program->stack, stackPop (program->stack) - stackPop (program->stack));
                }
                else if (strcmp (opcode, "mult") == 0)
                {
                    stackPush (program->stack, stackPop (program->stack) * stackPop (program->stack));
                }
                else if (strcmp (opcode, "div") == 0)
                {
                    stackPush (program->stack, stackPop (program->stack) / stackPop (program->stack));
                }
                else if (strcmp (opcode, "mod") == 0)
                {
                    stackPush (program->stack, stackPop (program->stack) % stackPop (program->stack));
                }
                else if (strcmp (opcode, "ifeq") == 0)
                {
                    // todo
                }
                else if (strcmp (opcode, "ifneq") == 0)
                {
                    // todo
                }
                else if (strcmp (opcode, "jump") == 0)
                {
                    // todo
                }
                else if (strcmp (opcode, "print") == 0)
                {
                    printf ("%d", stackPeek (program->stack));
                }
                else
                {
                    fprintf (stderr, "Invalid opcode: %s.\n", opcode);
                }
            } // an opcode was not read in
            pos = 0;
            memset (opcode, 0, sizeof opcode);
            continue;
        }
        else
        {
            opcode[pos] = program->code[iter];
            pos++;
            continue;
        }

    }
}

void progClose (Prog* program)
{
    stackDelete (program->stack);
    free (program->code);
    free (program);
}
