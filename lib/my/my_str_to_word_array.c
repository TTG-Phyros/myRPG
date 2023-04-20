/*
** EPITECH PROJECT, 2023
** LIB
** File description:
** my_str_to_word_array
*/

#include "my.h"
int verifymemory1(char const *str, char const mark)
{
    int mem = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n' || str[i] == mark)
            mem++;
    }
    mem++;
    return mem;
}

int verifymemory2(char const *str, int loc)
{
    int i = 0;
    while (str[loc] != '\n' && str[loc] != '\0' &&
        str[loc] != ':') {
        loc++;
        i++;
    }
    return i;
}

char **my_str_to_word_array(char const *str, char const mark)
{
    int j = 0, e = 0;
    char **final = malloc(sizeof(char *) * (verifymemory1(str, mark) + 1));
    final[e] = malloc(sizeof(char) * (verifymemory2(str, 0) + 1));
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n' || str[i] == mark) {
            final[e][j] = '\0';
            e++;
            final[e] = malloc(sizeof(char) * (verifymemory2(str, i + 1) + 1));
            j = 0;
        } else{
            final[e][j] = str[i];
            j++;
        }
    }
    final[e][j] = '\0';
    final[e + 1] = malloc(1);
    final[e + 1] = NULL;
    return final;
}
