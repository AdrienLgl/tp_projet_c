# Projet C

Dans le cadre du projet final en C, nous avons implémenté plusieurs fonctions de bases sans avoir recours à des librairies, uniquement en utilisant le langage C et de l'ASM.

Vous trouverez les différentes parties du sujet dans ce repo ainsi que le détail de l'énoncé ci-dessous. Enjoy ;-) !

## Partie 1

### Enoncé

Nous avons le basecode nécessaire pour afficher un caractère avec un appel système depuis le C. Le but de cet exercice est de développer en C à  partir de ce code une fonction plus sophistiquée présentant des fonctionnalités équivalentes à  **printf()** de la bibliothèque **stdio.h**. Vous disposez d’un basecode assez complet pour cet exercice ; il vous suffit pour la majorité des questions de compléter la fonction correspondante dans le fichier **Projet/Partie1/lib/io.c**

Des morceaux de code de test des différentes fonctions à implémenter sont présentes dans le **main.c.** Pour les utiliser il vous sufit de compiler avec les bonnes options de compilation (présentes dans le **Makefile**).

Exemple : Pour compiler le projet pour tester le  **TODO1** vous pouvez utiliser **make TODO1**.

**TODO1 :**

Compléter la fonction **printChar(char)** dans **Projet/Partie1/lib/io.c** qui imprime un **char** passé en paramètre. 

**TODO2 :**

Compléter une fonction **printString(char \*)** dans **Projet/Partie1/lib/io.c**, qui imprime une chaîne de caractères passée en paramètre. Rappel : les chaînes de caractères sont terminées par char(0) ;

**TODO3 :**

Compléter une fonction **printDigit(int)** dans **Projet/Partie1/lib/io.c**, qui imprime le caractère correspondant au digit passé en paramètre. Attention : le caractère 5 par exemple n’a pas le code ASCII 5. Si votre entier n’est pas compris entre 0 et 9 ce n’est pas un digit, vous n’afficherez simplement pas les entiers qui ne sont pas des digits.

**TODO 4 :**

Compléter une fonction **printInteger(int)** dans **Projet/Partie1/lib/io.c,** qui imprime une chaîne de caractères correspondant à l’entier passé en paramètre. Exemple : printInteger(12) doit afficher la chaîne de caractères ‘‘12’’ 

**TODO 5 :**

Le fonction **printf()** original est une fonction variadique, c’est à dire qu’elle possède un nombre d’arguments supérieur ou égal à 1. Renseignez vous sur les fonctions variadiques (par exemple : https://en.cppreference.com/w/c/variadic ). Vous allez malheureusement être obligé d’utiliser au moins une bibliothèque,  **stdarg.h**

Tentez maintenant d’implémenter une fonction  **newPrintf(char \*, …)** dans **Projet/Partie1/lib/io.c**, qui prend une chaîne de caractères en premier paramètre représentant la structure à afficher, puis le nombre d’arguments attendus pour remplir le template. On se concentre dans cet exercice uniquement sur les types suivants : **integer :%d char : %c char \* :%s**

**TODO 6 :**

Interessez vous à la selection **\_Generic** (par exemple https://en.cppreference.com/w/c/language/generic ). Créez ensuite une fonction **printG()** dans **Projet/Partie1/lib/io.h** qui accepte tous les types de données présentées avant dans le document et les affiche.

**FURTHER  :7**

Rajoutez maintenant les types manquants du langage C à votre fonction  **newPrintf(char \*, …)**.


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
