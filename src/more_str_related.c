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

int char_to_int(char *str)
{
    int nb = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return nb;
        if (str[i] >= '0' && str[i] <= '9')
            nb *= 10, nb += str[i] - '0';
    }
    return nb;
}

char *int_to_str(int nb)
{
    if (nb == 0) return "0";
    int i = 0, int_l = my_intlen(nb);
    int diviseur = 1;
    char *ans = malloc((int_l + 1) * sizeof(char));
    while (my_intlen(diviseur) < int_l)
        diviseur *= 10;
    for (int num = 0, j = 0; j != int_l; i++, j++) {
        num = nb / diviseur;
        ans[i] = (num + '0');
        nb -= num * diviseur;
        diviseur /= 10;
    }
    ans[i] = '\0';
    return ans;
}

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
