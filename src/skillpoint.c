/*
** EPITECH PROJECT, 2023
** ress->points
** File description:
** rpg
*/

#include "../include/rpg.h"

int flife(window *my_win, skill_ressources *skill_ress)
{
    if (skill_ress->point >= 1 && skill_ress->life == 0) {
        skill_ress->life++;
        skill_ress->point --;
    }
    return skill_ress->life;
}

int flife2(window *my_win, skill_ressources *skill_ress)
{
    if (skill_ress->point >= 1 && skill_ress->life == 1) {
        skill_ress->life++;
        skill_ress->point --;
    }
    return skill_ress->life;
}

int flife3(window *my_win, skill_ressources *skill_ress)
{
    if (skill_ress->point >= 1 && skill_ress->life == 2) {
        skill_ress->life++;
        skill_ress->point --;
    }
    return skill_ress->life;
}

int fspeed(window *my_win, skill_ressources *skill_ress)
{
    if (skill_ress->point >= 1 && skill_ress->speed == 0) {
        skill_ress->speed++;
        skill_ress->point --;
    }
    return skill_ress->speed;
}

int fspeed2(window *my_win, skill_ressources *skill_ress)
{
    if (skill_ress->point >= 1 && skill_ress->speed == 1) {
        skill_ress->speed++;
        skill_ress->point --;
    }
    return skill_ress->speed;
}
