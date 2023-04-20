/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** concatenates a two string
*/

#include "my.h"
char *my_strcat(char const *dest, char const *src)
{
    char *f = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src)  + 1));
    int i = 0;
    for (int e = 0; dest[e] != '\0'; e++) {
        f[i] = dest[e];
        i++;
    }
    for (int e = 0; src[e] != '\0'; e++) {
        f[i] = src[e];
        i++;
    }
    f[i] = '\0';
    return f;
}
