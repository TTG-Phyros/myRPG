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
    sfVector2f *pos_scale = malloc(sizeof(sfVector2f) * 2);
    pos_scale[0] = pos, pos_scale[1] = scale;
    sfColor *colors = malloc(4 * sizeof(sfColor));
    colors[0] = sfDarkGrey, colors[1] = sfBlack, colors[2] = sfGrey;
    colors[3] = sfLightGrey;
    button_list[0] = create_button(pos_scale, colors, "Play", 75);
    pos_scale[0].y += my_win->height / 7.2;
    button_list[1] = create_button(pos_scale, colors, "Resume", 75);
    pos_scale[0].y += my_win->height / 7.2;
    button_list[2] = create_button(pos_scale, colors, "Settings", 75);
    pos_scale[0].y += my_win->height / 7.2;
    button_list[3] = create_button(pos_scale, colors, "Quit", 75);
    button_list[4] = NULL;
    button_group *main_group = malloc(sizeof(button_group));
    main_group->button_list = button_list;
}

void fix_resize(button_group *grp, window *my_win)
{
    sfVector2u size;
    float x, y;
    for (int i = 0; grp->button_list[i]; i++) {
        size = sfRenderWindow_getSize(my_win->win);
        x = size.x / (double)1920;
        y = size.y / (double)1080;
        grp->button_list[i]->hitbox->width = grp->button_list[i]->size.x * x;
        grp->button_list[i]->hitbox->height = grp->button_list[i]->size.y * y;
        grp->button_list[i]->hitbox->left = grp->button_list[i]->pos.x * x;
        grp->button_list[i]->hitbox->top = grp->button_list[i]->pos.y * y;
    }
}

void redirect_main_check_sec(int i, window *my_win)
{
    if (i == 0)
        printf("Play\n");
    if (i == 1)
        printf("Resume\n");
    if (i == 2)
        settings_menu(my_win);
    if (i == 3) {
        sfEvent event;
        event.type = sfEvtClosed;
        check_event(my_win, event, NULL);
    }
}

void redirect_main_check(button_group *group, window *my_win)
{
    for (int i = 0; group->button_list[i]; i++) {
        if (group->button_list[i]->state == 2)
            redirect_main_check_sec(i, my_win);
    }
}
