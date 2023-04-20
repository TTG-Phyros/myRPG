/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-mypaint-anaelle.urbon
** File description:
** init
*/

#include "my.h"

button_s *init_button(int x)
{
    button_s *but = malloc(sizeof(button_s));
    but->size.x = BUTTON_SIZE_X;
    but->size.y = BUTTON_SIZE_Y;
    but->pos.x = WINDOW_SIZE_X / 100;
    but->pos.y = WINDOW_SIZE_Y / 50 + (60 * x);
    but->color = sfTransparent;
    but->pressing = -2;
    but->active = 0;
    return (but);
}

void update_but(button_s *but)
{
    if (but->pressing == -2)
        but->pressing = -2;
}

void destroy_but(button_s *but)
{
    free(but);
}
