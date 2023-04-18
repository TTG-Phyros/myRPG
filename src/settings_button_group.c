/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** settings_button_group
*/

#include "../include/rpg.h"

button_group *set_settings_button_group(window *my_win)
{
    button **b_list = malloc(sizeof(button *) * 7);
    sfColor *co = malloc(3 * sizeof(sfColor));
    co[0] = sfDarkGrey, co[1] = sfBlack, co[2] = sfGrey, co[3] = sfLightGrey;
    sfVector2f *psc = malloc(2 * sizeof(sfVector2f));
    sfVector2f sct = {my_win->width / 5.5, my_win->height / 10.8};
    sfVector2f pt = {50, 900};
    psc[0] = pt, psc[1] = sct, b_list[0] = create_button(psc, co, "Back", 75);
    sfVector2f sc = {my_win->width / 38.4, my_win->height / 21.6};
    sfVector2f po = {my_win->width / 2.02, my_win->height / 2.54};
    psc[0] = po, psc[1] = sc, b_list[1] = create_button(psc, co, "-", 30);
    psc[0].x += my_win->width / 6.4;
    b_list[2] = create_button(psc, co, "+", 30);
    psc[0].y += my_win->height / 7.2, psc[0].x -= my_win->width / 6.4;
    b_list[3] = create_button(psc, co, "-", 30);
    psc[0].x += my_win->width / 6.4;
    b_list[4] = create_button(psc, co, "+", 30);
    psc[0].y += my_win->height / 7.2, psc[0].x -= 300;
    b_list[5] = create_button(psc, co, " ", 30), b_list[6] = NULL;
    button_group *main_group = malloc(sizeof(button_group));
    main_group->button_list = b_list;
}

void settings_names(window *my_win, settings *my_setts)
{
    sfText **names = malloc(sizeof(sfText *) * 6);
    sfVector2f pos = {my_win->width / 3.84, my_win->height / 2.7};
    names[0] = button_settings_text(my_win, pos, "Resolution", 75);
    pos.x = my_win->width / 3.28, pos.y = my_win->height / 1.96;
    names[1] = button_settings_text(my_win, pos, "Volume", 75);
    pos.x = my_win->width / 3.84, pos.y = my_win->height / 1.54;
    names[2] = button_settings_text(my_win, pos, "FullScreen", 75);
    pos.x = my_win->width / 1.89, pos.y = my_win->height / 2.54;
    names[3] = button_settings_text(my_win, pos, "1920x1080", 40);
    pos.x = my_win->width / 1.75, pos.y = my_win->height / 1.89;
    names[4] = button_settings_text(my_win, pos, "75", 50);
    names[5] = NULL;
    my_setts->names = names;
}