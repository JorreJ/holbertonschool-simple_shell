# Simple Shell

## Description
Ce projet implémente un interpréteur de ligne de commande simple en C.

## Fonctionnalités
- Affiche un prompt pour l'utilisateur
- Lit les commandes saisies par l'utilisateur
- Exécute des commandes simples en utilisant `execve`

## Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh