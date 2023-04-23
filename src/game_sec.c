/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-baptiste.mery
** File description:
** game_sec
*/

#include "../include/rpg.h"

int death_screen(window *w)
{
    sfClock *disp = sfClock_create();
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(main_font);
    sfText_setFont(text, font), sfText_setString(text, "Vous etes mort.");
    sfText_setCharacterSize(text, 150), sfText_setColor(text, sfGrey);
    sfText_setOutlineColor(text, sfBlack), sfText_setOutlineThickness(text, 4);
    sfFloatRect r = sfText_getGlobalBounds(text);
    sfVector2f pos = {(w->width - r.width) / 2, (w->height - r.height) / 2};
    sfText_setPosition(text, pos);
    sfEvent event;
    while (sfRenderWindow_isOpen(w->win)) {
        while (sfRenderWindow_pollEvent(w->win, &event))
            check_event(w, event, NULL, NULL);
        if (sfTime_asSeconds(sfClock_getElapsedTime(disp)) >= 3) break;
        sfRenderWindow_clear(w->win, sfBlack);
        sfRenderWindow_drawText(w->win, text, NULL);
        sfRenderWindow_display(w->win);
    }
    sfFont_destroy(font), sfText_destroy(text), sfClock_destroy(disp);
    return 0;
}

int death(window *my_win, game_ressources *game_ress)
{
    sfFloatRect view_rect_reset = {0, 0, my_win->width, my_win->height};
    sfView *view_reset = sfView_createFromRect(view_rect_reset);
    sfRenderWindow_setView(my_win->win, view_reset);
    cleanup(game_ress);
    death_screen(my_win);
    play(my_win);
    return 0;
}

int check_pickup(window *my_win, game_ressources *res)
{
    sfColor temp = sfImage_getPixel(res->wa, res->pos.x + 6, res->pos.y + 10);
    if (temp.r == 64) return death(my_win, res);
    if (sfKeyboard_isKeyPressed(sfKeyNum1))
        if (sfKeyboard_isKeyPressed(sfKeyLControl) && res->has_sword == 1)
            res->has_sword = 0, sfSprite_setPosition(res->sword, res->s_pos);
    if (sfKeyboard_isKeyPressed(sfKeyNum2))
        if (sfKeyboard_isKeyPressed(sfKeyLControl) && res->has_hammer == 1)
            res->has_hammer = 0, sfSprite_setPosition(res->hammer, res->h_pos);
    if (sfKeyboard_isKeyPressed(sfKeyNum3))
        if (sfKeyboard_isKeyPressed(sfKeyLControl) && res->has_box == 1)
            res->has_box = 2;
    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        if (temp.g == 7 && res->has_key == 0) res->has_key = 1;
        if (temp.g == 6 && res->has_hammer == 1 && res->has_box == 0)
            res->has_box = 1;
        if (temp.g == 6 && res->has_box > 0); //? go to secret room
        if (temp.g == 3 && res->has_sword == 0) res->has_sword = 1;
        if (temp.g == 4 && temp.b == 159 && res->has_hammer == 0)
            res->has_hammer = 1;
    }
}

int change_pos_inv(game_ressources *ress, window *my_win)
{
    ress->sword_inv.x = ress->pos.x - 120;
    ress->sword_inv.y = ress->pos.y - 78;
    ress->hammer_inv.x = ress->pos.x - 110;
    ress->hammer_inv.y = ress->pos.y - 78;
    ress->box_inv.x = ress->pos.x - 100, ress->box_inv.y = ress->pos.y - 78;
    ress->key_inv.x = ress->pos.x - 84, ress->key_inv.y = ress->pos.y - 78;
    if (ress->has_hammer)
        sfSprite_setPosition(ress->hammer, ress->hammer_inv);
    if (ress->has_sword)
        sfSprite_setPosition(ress->sword, ress->sword_inv);
    if (ress->has_box)
        sfSprite_setPosition(ress->box, ress->box_inv);
    if (ress->has_key)
        sfSprite_setPosition(ress->key, ress->key_inv);
    if (sfKeyboard_isKeyPressed(sfKeyE)) change_dialog(ress);
    if (sfKeyboard_isKeyPressed(sfKeyE) && check_fight(ress))
        ress->is_dragon = start_fight(my_win, ress);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        return back_menu(my_win, ress);
    return 0;
}
