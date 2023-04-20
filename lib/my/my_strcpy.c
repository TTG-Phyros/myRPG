/*
** EPITECH PROJECT, 2023
** B-MUL-100-MAR-1-1-myradar
** File description:
** my_strcpy
*/

#include "my.h"
char *my_strcpy(char *str, char *copy)
{
    int n = 0;
    copy = malloc(sizeof(char) * (my_strlen(str) + 1));
    while (str[n] != '\0') {
        copy[n] = str[n];
        n++;
    }
    copy[n] = '\0';
    return (copy);
}

char **my_tblcpy(char **tbl, char **copy)
{
    int x = 0, y = 0;
    copy = malloc(sizeof(char *) * my_tbllen(tbl) + 1);
    while (tbl[y] != NULL) {
        copy[y] = malloc(sizeof(char) * my_strlen(tbl[y]) + 1);
        while (tbl[y][x] != '\0') {
            copy[y][x] = tbl[y][x];
            x++;
        }
        copy[y][x] = '\0';
        x = 0;
        y++;
    }
    return (copy);
}
