#ifndef IO_H
#define IO_H


extern void print(int, char*, int);

//TODO1
void printChar(char c);

//TODO2
void printString(char* str);

//TODO3
void printDigit(int i);

//TODO4
void printInteger(int i);

//TODO5
int newPrintf(char* str, ...);

#endif

//TODO6
// generic function
#define printG(X) _Generic((X), \
				int: printInteger, \
				char*: printString, \
                char: printChar, \
                  default: printString \
              )(X)
