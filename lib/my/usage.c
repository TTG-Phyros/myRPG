/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-dante-anaelle.urbon
** File description:
** usage
*/

#include "my.h"
void usage(int ac, char **av, char *txt)
{
    for (int i = 0; i < ac; i++) {
        if (my_strncmp(av[i], "-h", 2) == true) {
            my_cat(txt);
            exit(0);
        }
    }
}
