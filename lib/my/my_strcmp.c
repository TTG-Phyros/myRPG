/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-minishell1-anaelle.urbon
** File description:
** my_strcmp
*/

#include "my.h"
bool my_strcmp(char const *str1, char const *str2)
{
    int i = 0;
    if (my_strlen(str1) != my_strlen(str2))
        return (false);
    while (i < my_strlen(str1)) {
        if (str1[i] != str2[i])
            return (false);
    }
    return (true);
}

bool my_strncmp(char const *str1, char const *str2, int nbr)
{
    int i = 0, len;
    if (my_strlen(str1) < nbr)
        return (false);
    if (my_strlen(str2) < nbr)
        return (false);
    while (i < nbr) {
        if (str1[i] != str2[i])
            return (false);
        i++;
    }
    return (true);
}
