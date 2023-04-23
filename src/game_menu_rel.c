/*
** EPITECH PROJECT, 2023
** test
** File description:
** game_menu_rel
*/

#include "../include/rpg.h"

void clean_game_menu(game_menu_re *ress)
{
    sfSprite_destroy(ress->bg2);
    sfText_destroy(ress->m_title);
    for (int i = 0; ress->g_group->button_list[i]; i++)
        free_button(ress->g_group->button_list[i]);
}

int return_game_menu(int option, game_menu_re *ress, window *my_win)
{
    if (option == 1) {
        clean_game_menu(ress);
        free(ress);
        return main_menu(my_win);
    }
    if (option == 2) {
        clean_game_menu(ress);
        free(ress);
        return 0;
    }
    return 0;
}

void fill_game_menu(game_menu_re *ress, window *my_win)
{
    float pos_scale_back[2][2] = {{0, 0}, {1, 1}};
    ress->bg2 = set_sprite(game_menu_bg, pos_scale_back);
    ress->m_title = game_menu_text(my_win);
    ress->g_group = set_game_bugr(my_win);
    ress->size = sfRenderWindow_getSize(my_win->win);
}
