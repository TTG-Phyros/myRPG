/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-dante-anaelle.urbon
** File description:
** my_dice
*/

#include "my.h"
int *my_dice(int nb, int dice)
{
    srand(time(NULL));
    int *result = malloc(sizeof(int) * (nb + 1));
    for (int i = 0; i != nb; i++) {
        result[i] = rand() % (dice + 1);
        while (result[i] == 0)
            result[i] = rand() % (dice + 1);
    }
    return (result);
}
