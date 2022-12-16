#include"io.h"
#include<stdarg.h>
extern void putChar(int, char*, int);

int getLength(char* str) {
	int length = 0;
	while (str[length] != '\0') {
		length++;
	}
	return length;
}

// TODO 1
// print character type
void printChar(char c)
{
	putChar(0,&c,1);
}

// TODO 2
// print string type
void printString(char* str)
{
	int length = getLength(str);
	for (int i = 0; i <= length; i++)
	{
		printChar(str[i]);
	}
}

// TODO 3
// print digit
void printDigit(int i)
{
	if (i >= 0 && i < 10) {
		char c = { 0 };
		c = (i%10) + '0';
		printChar(c);
	}
}

// TODO 4
// print integer type
void printInteger(int i)
{
	char c[128] = { 0 };
	int n = 0;
	do {
		c[n++] = (i%10) + '0';
	} while ((i/=10) > 0);
	c[n] = '\0';
	char rev[n];
	int end = n - 1;
	for (int begin = 0; begin <= n; begin++) // reverse
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

/* FURTHER 7 */
void printFloat(float value) {
    int integer_part = (int)value;  // integer part
    float decimal_part = value - integer_part;  // decimal part
    if (integer_part < 0) {
        printChar('-');  // negative sign
        integer_part = -integer_part;
    }
    if (integer_part >= 10) {
        // recursively print the tens and units digits
        printInteger(integer_part / 10);
    }
    printChar('0' + integer_part % 10);  // print the units digit
    // print the decimal point and the decimal part
    printChar('.');
    int precision = 3;  // number of digits after the decimal point
    while (precision-- > 0) {
        decimal_part *= 10;
        int digit = (int)decimal_part;
        printChar('0' + digit);
        decimal_part -= digit;
    }
}

void printPercentage(float value) {
    printFloat(value);
	printChar('%');
}

/* FURTHER 7 */

// TODO 5
// create a printf to print differents types
int newPrintf(char* str, ...)
{
	va_list parameters;
    va_start(parameters, str);

	int totalCharacters = 0; 
    char currentChar;

    while( (currentChar = *str) != '\0' ) {
        str ++;
        if ( currentChar != '%' ) {
            printChar( currentChar );
			totalCharacters++;
            continue;
        }

        switch( *str ++ ) {
            case 'd': // integer
                {
                    int integerValue = (int) va_arg(parameters, int);
					totalCharacters += intlen(integerValue);
                    printInteger(integerValue);
                }
                break;
            case 's': // string
                {
                    char* string = (char*) va_arg(parameters, char*);
					totalCharacters += getLength(string);
                    printString(string);
                }
                break;
			case 'c': // character
				{
					char c = (char) va_arg(parameters, int);
					totalCharacters ++;
					printChar(c);
				}
				break;
			case 'f': // float
				{
					float floatValue = (float) va_arg(parameters, double);
					totalCharacters ++;
					printFloat(floatValue);
				}
				break;
			case '%': // percentage (only float)
				{
					float value = (float) va_arg(parameters, double);
					totalCharacters ++;
					printPercentage(value);

				}
				break;
            default: // error if type isn't defined
                printString("Specified str is not supported!");
				break;
        }
    }

    // Release va_list resources
    va_end( parameters );
	return totalCharacters;
}
















