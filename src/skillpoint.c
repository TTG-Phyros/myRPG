/*
** EPITECH PROJECT, 2023
** ress->points
** File description:
** rpg
*/

#include "../include/rpg.h"

/*
int life(window *my_win, skill_ressources *skill_ress)
{
    int life = 0;
        if (skill_ress->point = 1) {
            life++ ;
            if (skill_ress->point = 2)
                life++ ;
        }
    return life;
}

int speed(window *my_win, skill_ressources *skill_ress)
{
    int speed = 0;
        if (skill_ress->point = 1) {
            speed++ ;
            if (skill_ress->point = 2)
                speed++ ;
        }
    return speed;
}

int strong(window *my_win, skill_ressources *skill_ress)
{
    int strong = 0;
        if (skill_ress->point = 1) {
            strong++ ;
            if (skill_ress->point = 2)
                strong++ ;
        }
    return strong;
}

int skill_params(window *my_win, skill_ressources *skill_ress)
{
    if (skill_ress->point > 0) {
        if (is_clicked(life, my_win))
            life + 1;
        if (is_clicked(strong, my_win))
            strong + 10;
        if (is_clicked(speed, my_win))
            speed + 100;
    }
}
*/

int draw_skillpoint(window *my_win, skill_ressources *skill_ress)
{
    if (skill_ress->point == 1)
        printf("skillpoint : %d \n", skill_ress->point);
    if (skill_ress->point == 2)
        printf("skillpoint : %d \n", skill_ress->point);
    if (skill_ress->point == 3)
        printf("skillpoint : %d \n", skill_ress->point);
    if (skill_ress->point == 4)
        printf("skillpoint : %d \n", skill_ress->point);
    if (skill_ress->point == 5)
        printf("skillpoint : %d \n", skill_ress->point);
    if (skill_ress->point == 6)
        printf("skillpoint : %d \n", skill_ress->point);
}