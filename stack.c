#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

struct Stack
{
    int*         array;
    unsigned int size;
    int          top;
};

Stack* stackCreate (int n)
{
    if (n <= 0)
    {
        fprintf (stderr, "Invalid stack size %d.\n", n);
        exit (EXIT_FAILURE);
    }
        
    Stack* out = malloc (sizeof (Stack));
    if (out == NULL)
    {
        fprintf (stderr, "Memory allocation error.\n");
        exit (EXIT_FAILURE);
    }

    int* outArr = malloc (n * sizeof *outArr);
    if (outArr == NULL)
    {
        fprintf (stderr, "Memory allocation error.\n");
        exit (EXIT_FAILURE);
    }

    out->array = outArr;
    out->size  = n;
    out->top   = -1;
    return out;
}

void stackDelete (Stack* stack)
{
    if (stack == NULL)
    {
        fprintf (stderr, "Empty memory.\n");
        exit (EXIT_FAILURE);
    }

    free (stack->array);
    free (stack);
}

void stackPush (Stack* stack, int val)
{
    if (stack == NULL)
    {
        fprintf (stderr, "Empty memory.\n");
        exit (EXIT_FAILURE);
    }

    stack->array[stack->top+1] = val;
    stack->top++;
}

int stackPop (Stack* stack)
{
    if (stack == NULL)
    {
        fprintf (stderr, "Empty memory.\n");
        exit (EXIT_FAILURE);
    }

    if (stack->top + 1 >= stack->size)
    {
        fprintf (stderr, "Full stack.\n");
        exit (EXIT_FAILURE);
    }
    
    if (stack->top < 0)
    {
        fprintf (stderr, "Memory error.\n");
        exit (EXIT_FAILURE);
    }
    
    int out = stack->array[stack->top];
    stack->array[stack->top] = 0;
    stack->top--;
    return out;
}

int stackPeek (Stack* stack)
{
    if (stack == NULL)
    {
        fprintf (stderr, "Empty memory.\n");
        exit (1);
    }
    if (stack->top == -1)
    {
        fprintf (stderr, "Memory error.\n");
        exit (EXIT_FAILURE);
    }
    return stack->array[stack->top];
}

bool isEmpty (Stack* stack)
{
    return stack->top == -1;
}

bool isFull (Stack* stack)
{
    return stack->top + 1 >= stack->size;
}
