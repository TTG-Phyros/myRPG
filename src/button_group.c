/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** button_group
*/

#include "../include/rpg.h"

void draw_button_group(button_group *group, window *my_win)
{
    for (int i = 0; group->button_list[i]; i++) {
        sfRenderWindow_drawRectangleShape(my_win->win,
        group->button_list[i]->shape, NULL);
        sfRenderWindow_drawText(my_win->win,
        group->button_list[i]->title, NULL);
    }
}

button_group *set_main_button_group(window *my_win)
{
    button **button_list = malloc(sizeof(button *) * 5);
    sfVector2f scale = {my_win->width / 5.5, my_win->height / 10.8};
    sfVector2f pos = {my_win->width / 2 - scale.x / 2, my_win->height / 2.75};
    sfColor * colors = malloc(3 * sizeof(sfColor));
    colors[0] = sfDarkGrey;
    colors[1] = sfBlack;
    colors[2] = sfGrey;
    colors[3] = sfLightGrey;
    button_list[0] = create_button(pos, scale, colors, "Play");
    pos.y += my_win->height / 7.2;
    button_list[1] = create_button(pos, scale, colors, "Resume");
    pos.y += my_win->height / 7.2;
    button_list[2] = create_button(pos, scale, colors, "Settings");
    pos.y += my_win->height / 7.2;
    button_list[3] = create_button(pos, scale, colors, "Quit");
    button_list[4] = NULL;
    button_group *main_group = malloc(sizeof(button_group));
    main_group->button_list = button_list;
}
