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

button_group *set_game_button_group(window *win)
{
    button **b_l = malloc(sizeof(button *) * 4);
    sfVector2f scale = {win->width / 5.5, win->height / 10.8};
    sfVector2f pos = {win->width / 2 - scale.x / 2, win->height / 2.75};
    sfVector2f *pos_scale = malloc(sizeof(sfVector2f) * 2);
    pos_scale[0] = pos, pos_scale[1] = scale;
    sfColor *colors = malloc(4 * sizeof(sfColor));
    colors[0] = sfDarkGrey, colors[1] = sfBlack, colors[2] = sfGrey;
    colors[3] = sfWhite;
    b_l[0] = c_button(pos_scale, colors, "Resume",  win->width / 25.6);
    pos_scale[0].y += win->height / 7.2;
    b_l[1] = c_button(pos_scale, colors, "Skill Tree",  win->width / 25.6);
    pos_scale[0].y += win->height / 7.2;
    b_l[2] = c_button(pos_scale, colors, "Main Menu",  win->width / 25.6);
    b_l[3] = NULL;
    button_group *main_group = malloc(sizeof(button_group));
    main_group->button_list = b_l;
}

int redirect_game_check_sec(int i, window *my_win, 
                            skill_ressources * skill_ress)
{
    if (i == 0)
        play(my_win);
    if (i == 1)
        skilltree(my_win, skill_ress);
    if (i == 2)
        main_menu(my_win);
    return 0;
}

int redirect_game_check(button_group *group, window *my_win)
{
    for (int i = 0; group->button_list[i]; i++) {
        if (group->button_list[i]->state == 2)
            return i;
    }
    return -1;
}

int game_menu(window *my_win, skill_ressources * skill_ress)
{
    sfEvent event; int temp = 0;
    float pos_scale_back[2][2] = {{0, 0}, {1, 1}};
    sfSprite *bg2 = set_sprite(game_menu_bg, pos_scale_back);
    sfText *main_title = game_menu_text(my_win);
    button_group *game_group = set_game_button_group(my_win);
    while (sfRenderWindow_isOpen(my_win->win)) {
        while (sfRenderWindow_pollEvent(my_win->win, &event))
            check_event(my_win, event, game_group, NULL);
        if ((temp = redirect_game_check(game_group, my_win)) != -1)
            return redirect_game_check_sec(temp, my_win, skill_ress);
        check_hover_and_click(game_group, my_win);
        sfRenderWindow_clear(my_win->win, sfBlack);
        sfRenderWindow_drawSprite(my_win->win, bg2, NULL);
        draw_button_group(game_group, my_win);
        sfRenderWindow_drawText(my_win->win, main_title, NULL);
        sfRenderWindow_display(my_win->win);
    }
    return 0;
}
