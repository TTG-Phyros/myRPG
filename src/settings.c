/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** settings
*/

#include "../include/rpg.h"

/*
Resolution
Fullscreen
Sound volume level
Back
*/

int back_check(button_group *settings_group, window *my_win)
{
    if (settings_group->button_list[0]->state == 2)
        return sfTrue;
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        return sfTrue;
    return sfFalse;
}

void settings_menu(window *my_win)
{
    sfEvent event;
    float height = my_win->height / (double)1080;
    float width = my_win->width / (double)1920;
    float pos_scale_back[2][2] = {{0, 0}, {width, height}};
    sfSprite *set_back = set_sprite(settings_back, pos_scale_back);
    sfText *settings_title = settings_text(my_win);
    settings *my_setts = malloc(sizeof(settings));
    settings_names(my_win, my_setts);
    button_group *settings_group = set_settings_button_group(my_win);
    while (sfRenderWindow_isOpen(my_win->win)) {
        while (sfRenderWindow_pollEvent(my_win->win, &event))
            check_event(my_win, event, settings_group);
        if (back_check(settings_group, my_win)) return;
        for (int i = 0; settings_group->button_list[i]; i++)
            settings_group->button_list[i]->state = 0;
        fix_resize(settings_group, my_win);
        check_hover_and_click(settings_group, my_win);
        sfRenderWindow_clear(my_win->win, sfBlack);
        sfRenderWindow_drawSprite(my_win->win, set_back, NULL);
        for (int i = 0; my_setts->names[i]; i++)
            sfRenderWindow_drawText(my_win->win, my_setts->names[i], NULL);
        sfRenderWindow_drawText(my_win->win, settings_title, NULL);
        draw_button_group(settings_group, my_win);
        sfRenderWindow_display(my_win->win);
    }
}
