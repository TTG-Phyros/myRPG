/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** recreate the game duck hunt
*/

#include "include/my.h"

void button_pres(sfRenderWindow *window, sfEvent event, sfSprite *wall)
{
    if (event.type == sfEvtMouseButtonPressed)
        the_game(window, event, wall);
}

void click(sfRenderWindow *window, sfEvent event, sfSprite *wall)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    if (mouse.x >= 850 && mouse.x <= 1100) {
        if (mouse.y >= 500 && mouse.y <= 580) {
            button_pres(window, event, wall);
        }
    }
}

void cl_windo(sfEvent event, sfRenderWindow *window ,sfSprite *wall)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    click(window, event, wall);
}
