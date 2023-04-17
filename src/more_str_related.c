/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** more_str_related
*/

#include "../include/rpg.h"

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

int my_intlen(int nb)
{
    int i = 0;
    if (nb >= 0) i++;
    while (nb > 0)
        nb /= 10, i++;
    return i - 1;
}
