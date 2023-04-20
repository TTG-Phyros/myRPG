/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-mypaint-anaelle.urbon
** File description:
** hihihi :3
*/

#include "my.h"

int hover(all_s * all, button_s * button)
{
    sfVector2i p = sfMouse_getPositionRenderWindow(all->wdw);
    if (p.x >= button->pos.x && p.x <= button->pos.x + BUTTON_SIZE_X)
        if (p.y >= button->pos.y && p.y <= button->pos.y + BUTTON_SIZE_Y)
            return 0;
    return 1;
}

void but2_code(all_s * all)
{
    int pressed_time = 30;
    sfRectangleShape_setFillColor(all->but2->forme, sfTransparent);
    if (hover(all, all->but2) == 0 && all->but2->pressing < 0) {
        sfRectangleShape_setFillColor(all->but2->forme, sfBlue);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {

            sfRectangleShape_setFillColor(all->but2->forme, sfGreen);

            all->but2->pressing = -1;
        }
    }
    if (all->but2->pressing == -3) {
        if (all->pencil_size == 10)
            all->pencil_size = 20;
        else if (all->pencil_size == 20)
            all->pencil_size = 30;
        else if (all->pencil_size == 30)
            all->pencil_size = 10;
        sfRectangleShape_setFillColor(all->but2->forme, sfWhite);
        all->but2->pressing = pressed_time;
    }
}

void but3_code(all_s * all)
{
    int pressed_time = 30;
    sfRectangleShape_setFillColor(all->but3->forme, sfTransparent);
    if (hover(all, all->but3) == 0 && all->but3->pressing < 0) {
        sfRectangleShape_setFillColor(all->but3->forme, sfBlue);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {

            sfRectangleShape_setFillColor(all->but3->forme, sfGreen);
            all->but3->pressing = -1;
        }
    }
    if (all->but3->pressing == -3) {
        if (all->pencil.b == 0 && all->pencil.g != 255) {
            all->pencil = sfBlue;
        } else if (all->pencil.g != 255) {
            all->pencil = sfBlack;
        }
        sfRectangleShape_setFillColor(all->but3->forme, sfWhite);
        all->but3->pressing = pressed_time;
    }
}

void but4_code(all_s * all)
{
    int pressed_time = 30;
    sfRectangleShape_setFillColor(all->but4->forme, sfTransparent);
    if (hover(all, all->but4) == 0 && all->but4->pressing < 0) {
        sfRectangleShape_setFillColor(all->but4->forme, sfBlue);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {

            sfRectangleShape_setFillColor(all->but4->forme, sfGreen);
            all->but4->pressing = -1;
        }
    }
    if (all->but4->pressing == -3) {
        if (all->pencil_shape == 0) {
            all->pencil_shape = 1;
        } else {
            all->pencil_shape = 0;
        }
        sfRectangleShape_setFillColor(all->but4->forme, sfWhite);
        all->but4->pressing = pressed_time;
    }
}

void but5_code(all_s * all)
{
    int pressed_time = 30;
    sfRectangleShape_setFillColor(all->but5->forme, sfTransparent);
    if (hover(all, all->but5) == 0 && all->but5->pressing < 0) {
        sfRectangleShape_setFillColor(all->but5->forme, sfBlue);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {

            sfRectangleShape_setFillColor(all->but5->forme, sfGreen);
            all->but5->pressing = -1;
        }
    }
    if (all->but5->pressing == -3) {
        my_putnbr(all->pencil.b);

        my_putnbr(all->pencil.g);
        if (all->pencil.g == 0) {
            all->pencil = sfWhite; 
        } else if (all->pencil.g == 255) {
            all->pencil = sfBlack;
        }
        sfRectangleShape_setFillColor(all->but5->forme, sfWhite);
        all->but5->pressing = pressed_time;
    }
}

int but_code(all_s * all)
{
    int pressed_time = 30;
    sfRectangleShape_setFillColor(all->but->forme, sfTransparent);
    if (hover(all, all->but) == 0 && all->but->pressing < 0) {
        sfRectangleShape_setFillColor(all->but->forme, sfBlue);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfRectangleShape_setOutlineColor(all->but2->forme, sfRed);
            sfRectangleShape_setOutlineColor(all->but3->forme, sfRed);
            sfRectangleShape_setOutlineColor(all->but4->forme, sfRed);
            sfRectangleShape_setOutlineColor(all->but5->forme, sfRed);
            all->but2->active = 1;
            all->but3->active = 1;
            all->but4->active = 1;
            all->but5->active = 1;
            sfRectangleShape_setFillColor(all->but->forme, sfGreen);
            all->but->pressing = -1;
            return (1);
        }
    }
    if (all->but->pressing == -3) {
        sfRectangleShape_setFillColor(all->but->forme, sfWhite);
        all->but->pressing = pressed_time;
    } return (0);
}

void button_handling(all_s * all)
{
    int deactivate = 0;
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfRectangleShape_setOutlineColor(all->but2->forme, sfTransparent);
            sfRectangleShape_setOutlineColor(all->but3->forme, sfTransparent);
            sfRectangleShape_setOutlineColor(all->but4->forme, sfTransparent);
            sfRectangleShape_setOutlineColor(all->but5->forme, sfTransparent);
            deactivate = 1;
    }
    if (all->but->active == 1 && all->but->pressing < 0) {
        deactivate -= but_code(all);
    }
    all->but->pressing -= 2;

    if (all->but2->active == 1 || all->but2->pressing == -3
    || all->but2->pressing == 0) {
        but2_code(all);
    }
    all->but2->pressing -= 2;

    if (all->but3->active == 1 || all->but3->pressing == -3
    || all->but3->pressing == 0) {
        but3_code(all);
    }
    all->but3->pressing -= 2;
    if (all->but4->active == 1 || all->but4->pressing == -3
    || all->but4->pressing == 0) {
        but4_code(all);
    }
    all->but4->pressing -= 2;
    if (all->but5->active == 1 || all->but5->pressing == -3
    || all->but5->pressing == 0) {
        but5_code(all);
    }
    all->but5->pressing -= 2;
    if (deactivate == 1) {
        all->but2->active = 0; all->but3->active = 0; all->but4->active = 0;
        all->but4->active = 0; all->but5->active = 0;
    }
}
