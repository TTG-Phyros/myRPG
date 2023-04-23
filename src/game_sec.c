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
        if (temp.g == 14) res->finished = 1;
        if (temp.g == 3 && res->has_sword == 0) res->has_sword = 1;
        if (temp.g == 4 && temp.b == 159 && res->has_hammer == 0)
            res->has_hammer = 1;
    }
}

int change_pos_inv(game_ressources *res, window *my_win,
                skill_ressources *skill_ress)
{
    sfView_move(res->game_view, res->movement);
    sfSprite_setPosition(res->zelda, res->pos);
    sfSprite_setTextureRect(res->zelda, res->textureRect);
    sfRenderWindow_setView(my_win->win, res->game_view);
    res->sword_inv.x = res->pos.x - 120, res->sword_inv.y = res->pos.y - 78;
    res->hammer_inv.x = res->pos.x - 110, res->hammer_inv.y = res->pos.y - 78;
    res->box_inv.x = res->pos.x - 100, res->box_inv.y = res->pos.y - 78;
    res->key_inv.x = res->pos.x - 84, res->key_inv.y = res->pos.y - 78;
    sfVector2f pos = {res->pos.x + 40, res->pos.y + 60};
    sfText_setPosition(skill_ress->text, pos);
    if (res->has_hammer) sfSprite_setPosition(res->hammer, res->hammer_inv);
    if (res->has_sword) sfSprite_setPosition(res->sword, res->sword_inv);
    if (res->has_box) sfSprite_setPosition(res->box, res->box_inv);
    if (res->has_key) sfSprite_setPosition(res->key, res->key_inv);
    if (sfKeyboard_isKeyPressed(sfKeyE)) change_dialog(res);
    if (sfKeyboard_isKeyPressed(sfKeyE) && check_fight(res))
        res->is_dragon = start_fight(my_win, res, skill_ress);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        return back_menu(my_win, res, skill_ress);
    return 0;
}
