#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<stdbool.h>
#include<ctype.h>

char startcalcul[100];
float expression1;
float expression2;
char operator;
float resultat;

char plus = '+';
char moins = '-';
char multiplication = '*';
char division = '/';
char modulo = '%';

void red(){ printf("\033[1;31m");}
void yellow(){ printf("\033[1;33m");}
void reset(){ printf("\033[0m");}
void resetvaleur(){operator = 'a';}

/*bool digit_check(char key[])
{
    for(int i = 0; i < strlen(key); i++)
    {
        if(isdigit(key[i])==0)
        {
            return false;
        }
    }
    return true;
}

bool isDouble(double val)
{
    int truncated = (double)val;
    return (val == truncated);
}*/

int main (){
resetvaleur();
//Interogation calcul + enregistrement du calcul dans la variable #startcalcul :

    printf("\nid > ");
    fgets(startcalcul, 100, stdin);

//Condition pour QUIT ou FLUSH

    if(startcalcul[0] == 'q' && startcalcul[1] == 'u' && startcalcul[2] == 'i' && startcalcul[3] == 't'){
        exit( EXIT_SUCCESS );
    }

    if(startcalcul[0] == 'f' && startcalcul[1] == 'l' && startcalcul[2] == 'u' && startcalcul[3] == 's' && startcalcul[4] == 'h'){
        printf("\033[H\033[J");
        main();
    }

//Identification de l'opérateur de calcul :

    // on essaye de reconnaitre un plus ici :
    char * result = strstr( startcalcul, "+" );
    if(result != NULL){
        operator = '+';
    }

    // on essaye de reconnaitre un moins ici :
    result = strstr( startcalcul, "-" );
    if(result != NULL){
        operator = '-';
    }

    // on essaye de reconnaitre une division ici :
    result = strstr( startcalcul, "/" );
    if(result != NULL){
        operator = '/';
    }

    // on essaye de reconnaitre une multiplication ici :
    result = strstr( startcalcul, "*" );
    if(result != NULL){
        operator = '*';
    }

    // on essaye de reconnaitre un modulo ici :
    result = strstr( startcalcul, "%" );
    if(result != NULL){
        operator = '%';
    }

//Suppression des potentielles espaces :
 
    int i;
    int j = -1;

    for (i = 0; startcalcul[i]; i++)
        if (startcalcul[i] != ' ')
            startcalcul[++j] = startcalcul[i];
        startcalcul[++j] = '\0';


//Le calcul entier est stocké dans #startcalcul, séparation de cette variable en deux variables : opérateur1/2
    const char * separators = "%+-*/";        // élément de séparation = plus (+)
    char *p = strtok(startcalcul, separators);      // strtok découpe les chaînes de caractères 
    char *p2 = strtok(NULL, separators);            // La fonction strtok accepte deux paramètres – le premier est la chaîne de caractère à découper, le deuxième est le délimiteur

    while(p != NULL)
    {
        expression1 = (float) atoll(p);
        expression2 = (float) atoll(p2);

        p = strtok(NULL, separators); // Permet de faire passer la variable p à l'état NULL
    }

    /*if(digit_check(expression1)){

    }*/

//Calcul du calcul saisi par l'utilisateur :

    if(plus == operator){
        resultat = expression1 + expression2;
    }

    else if(operator == moins){
        resultat = expression1 - expression2;
    }

    else if(operator == multiplication){
        resultat = expression1 * expression2;
    }

    else if(operator == modulo){
        resultat = (int)expression1 % (int)expression2;
    }
    
    else if(operator == division){
        if(expression2 != 0){
            resultat = expression1 / expression2;
        }
        else{ // Message d'erreur en cas de division par zéro :
            red();
            printf("\nATTENTION : Impossible de faire une division par zero\n");
            reset();
        }
    }
    
    else{ // Message d'erreur si la saisie du calcul est incorrect
        red();
        printf("\nATTENTION : Erreur dans la saisie du calcul \n");
        reset();
    }
    
    //printf("Le resultat de %f %c %f = %f \n", expression1, operator, expression2, resultat);

    yellow();
    printf("\nRes : %f \n",resultat);
    reset();

    resetvaleur();
    main();
}