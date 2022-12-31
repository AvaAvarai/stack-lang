# stack-lang
A single-pass interpreted stack-based programming language. This project is not meant for serious use.  

## instructions

### Data storage:  
* push <number> - push a number on top of the stack  
* pop - pop a number from the top of the stack  
* dup - push a copy of the top number of the stack  

### Arithmetic:  
* add - pop off the top 2 numbers of the stack and push their sum  
* sub - pop off the top 2 numbers of the stack and push their difference  
* mult - pop off the top 2 numbers of the stack and push their product  
* div - pop off the top 2 numbers of the stack and push their quotient  
* mod - pop off the top 2 numbers of the stack and push their remainder  

### Flow control:  
* ifeq  <address\> - if the number on the top of the stack equals 0 continue, else jump execution to the line number <address\>  
* ifneq <address\> - if the number on the top of the stack does not equal 0 continue, else jump execution to the line number <address\>  
* jump  <address\> - jump execution to the line number <address\>  

### Output:  
* print - print the number on the top of the stack  

### Comments:  
* \# comment \# - comments are ignored while interpreting programs, they must be wrapped with # characters  

## error handling  
Error handling is rudimentary right now if a program is inaccurate or reaches an error then a semi-generic error message will be given and the interpreter will close.

## runnning programs  
Currently this is done through hard-coding and is not accessible, the goal is to have the intepreter accept  programs via a file or input stream.  

## example programs

These two snippets are identical in meaning ( print 3 + 7 ):  

\# sample program v1a \#  
push 7  
push 3  
print  
pop  

\# sample program v1b \# push 7 push 3 print pop  

# license  
This work is purely academic and is made publically available under the GNU GPLv3 license.  
