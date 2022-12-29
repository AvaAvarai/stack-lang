#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "parse.h"

struct Prog
{
    char* code;
    int   line;
    bool  run;
};

Prog* parseFile (char* filename)
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
    char* text = malloc ( ftell(file) * sizeof *text);
    fseek (file, 0L, SEEK_SET);

    if (text == NULL)
    {
        fprintf (stderr, "Memory allocation error.\n");
        exit (EXIT_FAILURE);
    }

    out->code = "";
    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        strncat(out->code, line, 256);
    }
    
    out->line = 0;
    out->run  = false;

    return out;
}
