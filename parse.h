#ifndef _PARSE_H
#define _PARSE_H

typedef struct Prog Prog;

Prog* progLoad  (char* filename);
void  progRun   (Prog* program);
void  progClose (Prog* program);

#endif
