/*
** EPITECH PROJECT, 2023
** LIB
** File description:
** my_puttbl
*/

#include "my.h"
void my_puttbl(char **tbl)
{
    int i = 0;
    while (tbl[i] != NULL) {
        my_printf("%s\n", tbl[i]);
        i++;
    }
}
