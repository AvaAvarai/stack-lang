#ifndef _STACK_H
#define _STACK_H

typedef struct Stack Stack;

Stack* stackCreate (int    n);
void   stackDelete (Stack* stack);

void   stackPush   (Stack* stack,  int val);
int    stackPop    (Stack* stack);
int    stackPeek   (Stack* stack);

#endif
