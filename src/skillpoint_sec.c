/*
** EPITECH PROJECT, 2023
** skil
** File description:
** 2
*/

#include "../include/rpg.h"

int fstrong(window *my_win, skill_ressources *skill_ress)
{
    if (skill_ress->point >= 1 && skill_ress->strong == 0) {
        skill_ress->strong++;
        skill_ress->point --;
    }
    return skill_ress->strong;
}

int fstrong2(window *my_win, skill_ressources *skill_ress)
{
    if (skill_ress->point >= 1 && skill_ress->strong == 1) {
        skill_ress->strong++;
        skill_ress->point --;
    }
    return skill_ress->strong;
}

int fstrong3(window *my_win, skill_ressources *skill_ress)
{
    if (skill_ress->point >= 1 && skill_ress->strong == 2) {
        skill_ress->strong++;
        skill_ress->point --;
    }
    return skill_ress->strong;
}

int fspeed3(window *my_win, skill_ressources *skill_ress)
{
    if (skill_ress->point >= 1 && skill_ress->speed == 2) {
        skill_ress->speed++;
        skill_ress->point --;
    }
    return skill_ress->speed;
}
