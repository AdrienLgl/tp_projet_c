# Projet C

Dans le cadre du projet final en C, nous avons implémenté plusieurs fonctions de bases sans avoir recours à des librairies, uniquement en utilisant le langage C et de l'ASM.

Vous trouverez les différentes parties du sujet dans ce repo ainsi que le détail de l'énoncé ci-dessous. Enjoy ;-) !

## Partie 1

Le but de cette partie de l'énoncé est de créer une fonction équivalente à **printf()**. Nous allons réaliser cette fonction grâce à l'implémentation de différentes fonctions annexes.

Nous pourrons tester ces différentes fonctions via les options de compilation présentes dans le **Makefile**. Exemple : Pour compiler le projet pour tester le  **TODO1** vous pouvez utiliser **make TODO1**.

**TODO1 :**

Compléter la fonction **printChar(char)** dans **Projet/Partie1/lib/io.c** qui imprime un **char** passé en paramètre.

```sh
make TODO1
./a.out

C
```

**TODO2 :**

Compléter une fonction **printString(char \*)** dans **Projet/Partie1/lib/io.c**, qui imprime une chaîne de caractères passée en paramètre.

```sh
make TODO2
./a.out

Hello World !
```

**TODO3 :**

Compléter une fonction **printDigit(int)** dans **Projet/Partie1/lib/io.c**, qui imprime le caractère correspondant au digit passé en paramètre. Attention : le caractère 5 par exemple n’a pas le code ASCII 5. Si votre entier n’est pas compris entre 0 et 9 ce n’est pas un digit, vous n’afficherez simplement pas les entiers qui ne sont pas des digits.

```sh
make TODO3
./a.out

0123456789
```

**TODO 4 :**

Compléter une fonction **printInteger(int)** dans **Projet/Partie1/lib/io.c,** qui imprime une chaîne de caractères correspondant à l’entier passé en paramètre. Exemple : printInteger(12) doit afficher la chaîne de caractères ‘‘12’’ 

```sh
make TODO4
./a.out

123456
```

**TODO 5 :**

Le fonction **printf()** original est une fonction variadique, c’est à dire qu’elle possède un nombre d’arguments supérieur ou égal à 1. Renseignez vous sur les fonctions variadiques (par exemple : https://en.cppreference.com/w/c/variadic ). Vous allez malheureusement être obligé d’utiliser au moins une bibliothèque,  **stdarg.h**

Tentez maintenant d’implémenter une fonction  **newPrintf(char \*, …)** dans **Projet/Partie1/lib/io.c**, qui prend une chaîne de caractères en premier paramètre représentant la structure à afficher, puis le nombre d’arguments attendus pour remplir le template. On se concentre dans cet exercice uniquement sur les types suivants : **integer :%d char : %c char \* :%s**

```sh
make TODO5
./a.out

L'entier vaut : 111, le charactère est : A, et le string est : hello
```

**TODO 6 :**

Interessez vous à la selection **\_Generic** (par exemple https://en.cppreference.com/w/c/language/generic ). Créez ensuite une fonction **printG()** dans **Projet/Partie1/lib/io.h** qui accepte tous les types de données présentées avant dans le document et les affiche.

```sh
make TODO6
./a.out

123
C
Hello
```

**FURTHER 7**

Pour ce point bonus, nous avons pu ajouter le type float ainsi que les pourcentages (uniquement float) dans notre fonction ```newPrintf```.

Pour afficher un type float, veuillez utiliser le caractère ```%f``` comme paramètre de la fonction.
Pour afficher le pourcentage, veuillez utiliser le caractère ```%%```.

**FURTHER 8**


Nous pourrions réaliser une fonction variadique sans librairie  en utilisant une structure de données qui contient tous les arguments de la fonction variadique.

```c
struct arguments {
    int arg1;
    char *arg2;
    double arg3;
};

void ma_fonction_variadique(struct arguments args) {
    // Traitement des différents arguments de la structure
    int arg1 = args.arg1;
    char *arg2 = args.arg2;
    double arg3 = args.arg3;

    // Utilisation des arguments dans le corps de la fonction
    printf("arg1 = %d, arg2 = %s, arg3 = %f\n", arg1, arg2, arg3);
}
```

Cependant, cette méthode est plus fastidieuse car il convient de créer une structure de données pour chaque combinaison d'arguments possibles et de la remplir à chaque appel de fonction.

**FURTHER 9**

Pour porter notre code vers une autre archi ou autre OS, nous avons plusieurs options disponibles lors de la compilation sous GCC.

En effet, nous pouvons notamment utiliser l'option ```-mtune```.

```sh
gcc -o a.out main.c -mtune=generic // pour linux (nom du système variable)
gcc -o a.out main.c -mtune=corei7 // pour le processeur Intel Core i7
```

Pour porter notre code vers Windows, nous pouvons utiliser ```x86_64-w64-mingw32-gcc``` :

```sh
x86_64-w64-mingw32-gcc -o programme.exe main.c // pour windows 64-bit
i686-w64-mingw32-gcc -o programme.exe main.c // pour windows 32-bit
```

Vous pouvez exécuter ces commandes pour exporter le code vers Windows :

```sh
make win-64 (windows 64-bit)
make win-32 (windows 32-bit)
```

## Partie 2

Sur cet exercice, le but était de concevoir une calculatrice acceptant les calculs flotants et entiers selon certains opérateurs.

Différentes bibliothèques pouvaient être employées.

La commande ```make install``` vous permettra de récupérer les différentes dépendences du projet et ```make clean``` de nettoyer les fichiers non sources.

Pour lancer la calculatrice, veuillez exécuter cette commande :

```sh
make
```

Un terminal de commande apparaitra ensuite de la forme :

```sh
Hello ! Please enter an integer or float operation

id >
```

Veuillez saisir vos calculs via ce terminal :

```sh
Hello ! Please enter an integer or float operation

id > 24 + 8
res: 32
```
Vous avez la possibilité de réutiliser le résultat précédent via ```res```.

Ex:

```sh
id > 24 + 8
res: 32

id > res + 4
res: 36
```


La commande ```quit``` vous permet de quitter la calculatrice et ```flush``` de vider le contenu de l'interface.

Voici les opérations possibles à ce jour :

| Opération | Opérateur |
|-----------|:----------|
| Addition | + |
| Soustraction | - |
| Multiplication | * |
| Division | / |
| Modulo | % |
| Puissance | ^ |

Pour la taille de la console, nous avons étudier la librairie ```ncurses``` pour préciser une taille de colonnes et de lignes précise mais sans succès. Nous nous sommes ensuite tournés vers ```ioctl``` qui permet de redimensionner le terminal selon nos spécifications, ici 80x25.

### Partie Bonus

Pour la partie bonus, nous avons rajouté une opération supplémentaire et avons pensé le système d'interprétation des commandes.

Pour gérer les parenthèses, nous aurions utilisé un système de "piles" en empilant les opérandes et opérateurs pendant les calculs.

Lorsque l'on rencontre une parenthèse ouvrante, on extrait l'expression jusqu'à la parenthèse fermante. On traite cette expression séparemment et on la remplace par le résultat.

On poursuit ainsi récursivement.