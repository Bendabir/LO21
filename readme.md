# UTComputer : Calculatrice RPN

La notation polonaise inversée permet une écriture arithmétique sans ambiguité et sans parenthèses :

- `1 + 1` donne `1 1 +` en RPN.
- `2 * 2 + 1` donne `2 2 * 1 +`
- `(2 + 3) * 4` donne `2 3 + 4 *`

Cela nécessite l'implémentation d'une pile pour le calcul :

- Si l'opérande est une littérale, elle est empiler sur la pile
- Si l'opérande est un opérateur d'arité *n*, *n* expressions sont dépilés et le résultat du calcul est empilé. 

Un opérateur a **une et une seule** arité. 

## Priorité des opérateurs

Associativité : De gauche à droite

Il manque des opérateurs. 

| Opérateur | Priorité | Arité |
|:---------:|:--------:|:--------:|
| `()` | **8** | Pas vraiment un opérateur |
| `NEG` | 7 | unaire |
| `NOT` | 7 | unaire |
| `*` | **6** | binaire |
| `/` | **6** | binaire |
| `MOD` | **6** | binaire |
| `DIV` | **6** | binaire |
| `+` | 5 | binaire |
| `-` | 5 | binaire | 
| `<` | **4** | binaire |
| `<=` | **4** | binaire |
| `>` | **4** | binaire |
| `>=` | **4** | binaire |
| `=` | 3 | binaire |
| `!=` | 3 | binaire |
| `AND` | **2** | binaire |
| `OR` | 1 | binaire |
| Autres (opérateurs de pile, etc.) | 0 | Pas d'arité |


## Options de l'application

- Affichage du clavier
- X derniers éléments de la pile à afficher
- Bip sonore (message utilisateurs)
- 