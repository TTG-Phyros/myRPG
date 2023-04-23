/*
** EPITECH PROJECT, 2023
** settings
** File description:
** game_menu
*/

#include "../include/rpg.h"

int settings_game_menu(window *my_win, skill_ressources * skill_ress)
{
    sfEvent event; float pos_scale_back[2][2] = {{0, 0}, {1, 1}};
    sfSprite *set_back = set_sprite(settings_back, pos_scale_back);
    sfText *settings_title = settings_text(my_win);
    settings *my_setts = settings_names(my_win);
    button_group *settings_group = set_settings_button_group(my_win);
    while (sfRenderWindow_isOpen(my_win->win)) {
        while (sfRenderWindow_pollEvent(my_win->win, &event))
            check_event(my_win, event, settings_group, NULL);
        if (back_check(settings_group, my_win))
            return game_menu(my_win, skill_ress);
        fix_resize(settings_group, my_win);
        check_hover_and_click(settings_group, my_win);
        if (settings_redirections(settings_group, my_setts, my_win))
            return settings_game_menu(my_win, skill_ress);
        sfRenderWindow_clear(my_win->win, sfBlack);
        draw_settings_texts(my_setts, settings_title, my_win, set_back);
        draw_button_group(settings_group, my_win);
        sfRenderWindow_display(my_win->win);
    }
    return 0;
}
