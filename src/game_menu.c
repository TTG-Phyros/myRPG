/*
** EPITECH PROJECT, 2023
** game menu
** File description:
** game_menu
*/

#include "../include/rpg.h"

sfText *game_menu_text(window *my_win)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(main_font);
    sfText_setFont(text, font);
    sfText_setString(text, "Pause");
    sfText_setCharacterSize(text, my_win->width / 9.6);
    sfText_setColor(text, sfWhite);
    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, 5);
    sfFloatRect rect = sfText_getGlobalBounds(text);
    sfVector2f pos = {(my_win->width - rect.width) / 2, rect.height / 2};
    sfText_setPosition(text, pos);
    return text;
}

button_group *set_game_bugr(window *win)
{
    button **b_l = malloc(sizeof(button *) * 5);
    sfVector2f scale = {win->width / 5.5, win->height / 10.8};
    sfVector2f pos = {win->width / 2 - scale.x / 2, win->height / 2.75};
    sfVector2f *pos_scale = malloc(sizeof(sfVector2f) * 2);
    pos_scale[0] = pos, pos_scale[1] = scale;
    sfColor *colors = malloc(4 * sizeof(sfColor));
    colors[0] = sfDarkGrey, colors[1] = sfBlack, colors[2] = sfGrey;
    colors[3] = sfWhite;
    b_l[0] = c_button(pos_scale, colors, "Resume", win->width / 25.6);
    pos_scale[0].y += win->height / 7.2;
    b_l[1] = c_button(pos_scale, colors, "Skill Tree", win->width / 25.6);
    pos_scale[0].y += win->height / 7.2;
    b_l[2] = c_button(pos_scale, colors, "Settings", win->width / 25.6);
    pos_scale[0].y += win->height / 7.2;
    b_l[3] = c_button(pos_scale, colors, "Main Menu", win->width / 25.6);
    b_l[4] = NULL;
    button_group *main_group = malloc(sizeof(button_group));
    main_group->button_list = b_l;
}

int redirect_game_check_sec(int i, window *my_win,
skill_ressources *skill_ress)
{
    if (i == 1)
        skilltree(my_win, skill_ress);
    if (i == 2)
        settings_menu(my_win, NULL);
    return 0;
}

void draw_game_menu(window *my_win, sfSprite *bg2,
button_group *game_group, sfText *main_title)
{
    sfRenderWindow_clear(my_win->win, sfBlack);
    sfRenderWindow_drawSprite(my_win->win, bg2, NULL);
    draw_button_group(game_group, my_win);
    sfRenderWindow_drawText(my_win->win, main_title, NULL);
    sfRenderWindow_display(my_win->win);
}

int game_menu(window *my_win, skill_ressources *skill_ress)
{
    sfEvent event;
    game_menu_re *ress = malloc(sizeof(game_menu_re));
    fill_game_menu(ress, my_win);
    int old_w = ress->size.x;
    for (int tem = 0; sfRenderWindow_isOpen(my_win->win);) {
        old_w = ress->size.x, ress->size = sfRenderWindow_getSize(my_win->win);
        if (ress->size.x != old_w)
            clean_game_menu(ress), fill_game_menu(ress, my_win);
        while (sfRenderWindow_pollEvent(my_win->win, &event))
            check_event(my_win, event, ress->g_group, NULL);
        tem = redirect_main_check(ress->g_group, my_win);
        if (tem == 3) return return_game_menu(1, ress, my_win);
        if (tem == 0) return return_game_menu(2, ress, my_win);
        if (tem > 0)
            redirect_game_check_sec(tem, my_win, skill_ress);
        check_hover_and_click(ress->g_group, my_win);
        draw_game_menu(my_win, ress->bg2, ress->g_group, ress->m_title);
    }
    return 0;
}
