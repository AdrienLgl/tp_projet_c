#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include <curses.h>

char input[100]; // input
void red(){ printf("\033[1;31m");} // red color
void yellow(){ printf("\033[1;33m");} // color yellow
void reset(){ printf("\033[0m");} // reset color
void size(){ printf("\033[25;80H"); }
bool quit = false; // quit status
char operators[5] = {'+', '-', '*', '/', '%'}; // operators
char * previous = "null"; // previous result
char operand; // operator
float result; // final result
float x1; // first expression
float x2; // second expression

int str_length(char str[]) { // get string length
    int count; 
    for (count = 0; str[count] != '\0'; ++count);
    return count; 
}

bool checkIfCharIsNumber(char *value) { // check if one char is number or not and if number is float
    bool status = true;
    int points = 0;
    for (int i = 0; i <= str_length(value); i++) {
        if (value[i] == '.') {
            points++;
        }
        if (isdigit(value[i]) == 0 && value[i] != '\0' && value[i] != '\n' && value[i] != '.') {
            status = false;
            break;
        }
        if (points > 2) {
            status = false; 
            break;
        }
    }
    return status;
}

void error(char * message) { // generic error message
    red();
    printf("\n%s\n", message);
    reset();
}

char findOperator(char * value) { // get operator from string
    char operator;
    for (int op = 0; op <= 4; op++) {
        char * result = strchr(value, operators[op]);
        if (result != NULL) {
            switch(operators[op])
            {
                case '+':
                    return '+';
                    break;
                case '-':
                    return '-';
                    break;
                case '*':
                    return '*';
                    break;
                case '/':
                    return '/';
                    break;
                case '%':
                    return '%';
                    break;
                default:
                    return 'E'; // error
                    break;
            }
        }
    }
    return 'E'; // error
}

void initCalculator() { // init calculator
    while(!quit) { // loop
        printf("\nid > ");
        fgets(input, 100, stdin); // input

        bool isQuit = input[0] == 'q' && input[1] == 'u' && input[2] == 'i' && input[3] == 't';
        bool isFlush = input[0] == 'f' && input[1] == 'l' && input[2] == 'u' && input[3] == 's' && input[4] == 'h';

        if(isQuit){ // check if command is 'quit'
            printf("%s\n", "Bye !");
            exit( EXIT_SUCCESS );
        }

        if(isFlush){ // check if command is 'flush'
            printf("\033[H\033[J");
            initCalculator();
        }

        operand = findOperator(input); // find operator

        if (operand == 'E') { // check if error during operator identification
            error("Your operation is invalid, please retry");
            initCalculator();
        }


        // remove whitespace in expression
        int i;
        int j = -1;
        for (i = 0; input[i]; i++)
            if (input[i] != ' ')
                input[++j] = input[i];
            input[++j] = '\0';


        const char *sep = "%+-*/"; // separators
        char *x1_str = strtok(input, sep); // strok slice char * value, first parameter is input and second the separator
        char *x2_str = strtok(NULL, sep);

        if (*x1_str == '\n' || *x2_str == '\n') { // syntax error
            error("Syntax error");
            initCalculator();
        }

        if (x1_str[0] == 'r' && x1_str[1] == 'e' && x1_str[2] == 's') { // check if value is 'res'
            if (previous == "null") { // check if previous have existing value
                error("Error, no res value");
                initCalculator();
                return;
            } else { // assign previous
                x1_str = previous;
            }
        }

        if (x2_str[0] == 'r' && x2_str[1] == 'e' && x2_str[2] == 's') {
            if (previous == "null") {
                error("Error, no res value");
                initCalculator();
            } else {
                x2_str = previous;
            }
        }

        if (*x1_str == '\n' || *x2_str == '\n') { // error during 
            error("Invalid operation");
            initCalculator();
        }

        if (checkIfCharIsNumber(x1_str) && checkIfCharIsNumber(x2_str)) { // assign expressions if numbers
            x1 = (float) strtod(x1_str, NULL);
            x2 = (float) strtod(x2_str, NULL);
        } else {
            error("Please retry with correct values");
            initCalculator();
        }


        if ((operand == '/' || operand == '%') && x2 == 0) { // prevent 0 for division
            error("Incorrect operation");
            initCalculator();
        }

        switch(operand) // make operation
            {
                case '+':
                    result = x1 + x2;
                    break;
                case '-':
                    result = x1 - x2;
                    break;
                case '*':
                    result = x1 * x2;
                    break;
                case '/':
                    result = x1 / x2;
                    break;
                case '%':
                    result = (int) x1 % (int) x2;
                    break;
                default:
                    error("Incorrect operation, please retry");
                    initCalculator();
                    break;
            }

        char str[100];
        previous = str; // reset previous value
        operand = 'E'; // reset operand
        sprintf(previous, "%f", result); // assign result to previous
        printf("res: %g", result); // display result
    }
}



int main (){
    printf("%s\n", "Hello ! Please enter an integer or float operation");
    initCalculator();
    return 0;
}

