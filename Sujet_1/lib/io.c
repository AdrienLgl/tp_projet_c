#include"io.h"
#include<stdarg.h>
#include<string.h>
extern void putChar(int, char*, int);

int getLength(char* str) {
	int length = 0;
	while (str[length] != '\0') {
		length++;
	}
	return length;
}

void printChar(char c)
{
	putChar(0,&c,1);
}


void printString(char* str)
{
	int length = getLength(str);
	for (int i = 0; i <= length; i++)
	{
		printChar(str[i]);
	}
}


void printDigit(int i)
{
	if (i >= 0 && i < 10) {
		char c = { 0 };
		c = (i%10) + '0';
		printChar(c);
	}
}


void printInteger(int i)
{
	char c[128] = { 0 };
	int n = 0;
	do {
		c[n++] = (i%10) + '0';
	} while ((i/=10) > 0);
	c[n] = '\0';
	char rev[n];
	int end = n -1;
	for (int begin = 0; begin < n; begin++)
	{
		rev[begin] = c[end];
		end--;
	}
	printString(rev);
}

int intlen(int i) {
	int count = 0;
	do {
		i /= 10;
		++count;
  	} while (i != 0);
	return count;
}


int newPrintf(char* str, ...)
{
	va_list parameters;
    va_start(parameters, str);

	size_t totalCharacters = 0; 
    char currentChar;

    while( (currentChar = *str) != '\0' ) {
        str ++;
        if ( currentChar != '%' ) {
            printChar( currentChar );
			totalCharacters++;
            continue;
        }

        switch( *str ++ ) {
            case 'd':
                {
                    int integerValue = (int) va_arg(parameters, int);
					totalCharacters += intlen(integerValue);
                    printInteger(integerValue);
                }
                break;
            case 's':
                {
                    char* string = (char*) va_arg(parameters, char*);
					totalCharacters += strlen(string);
                    printString(string);
                }
                break;
			case 'c':
				{
					char c = (char) va_arg(parameters, int);
					totalCharacters ++;
					printChar(c);
				}
				break;
            default:
                printString("Specified str is not supported!");
				break;
        }
    }

    /* Release va_list resources */
    va_end( parameters );
	return totalCharacters;
}

int printG() {
	
}


















