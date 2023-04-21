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

void draw_settings_texts(settings *my_setts, sfText *s_title, window *my_win,
                        sfSprite *set_back)
{
    sfRenderWindow_drawSprite(my_win->win, set_back, NULL);
    for (int i = 0; my_setts->names[i]; i++)
        sfRenderWindow_drawText(my_win->win, my_setts->names[i], NULL);
    sfRenderWindow_drawText(my_win->win, s_title, NULL);
}

int settings_menu(window *my_win)
{
    sfEvent event;
    float pos_scale_back[2][2] = {{0, 0}, {1, 1}};
    sfSprite *set_back = set_sprite(settings_back, pos_scale_back);
    sfText *settings_title = settings_text(my_win);
    settings *my_setts = settings_names(my_win);
    button_group *settings_group = set_settings_button_group(my_win);
    while (sfRenderWindow_isOpen(my_win->win)) {
        while (sfRenderWindow_pollEvent(my_win->win, &event))
            check_event(my_win, event, settings_group, NULL);
        if (back_check(settings_group, my_win)) return main_menu(my_win);
        fix_resize(settings_group, my_win);
        check_hover_and_click(settings_group, my_win);
        if (settings_redirections(settings_group, my_setts, my_win))
            return settings_menu(my_win);
        sfRenderWindow_clear(my_win->win, sfBlack);
        draw_settings_texts(my_setts, settings_title, my_win, set_back);
        draw_button_group(settings_group, my_win);
        sfRenderWindow_display(my_win->win);
    }
    return 0;
}
