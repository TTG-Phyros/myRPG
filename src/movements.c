/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-baptiste.mery
** File description:
** movements
*/

#include "../include/rpg.h"

int change_sprite(int judge, int ans_one, int ans_two)
{
    if (judge % 100 < 50)
        return ans_one;
    else
        return ans_two;
    return 0;
}

int y_movement(game_ressources *res)
{
    sfColor co, ci;
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        co = sfImage_getPixel(res->wa, res->pos.x, res->pos.y + 18 + res->ti);
        ci = sfImage_getPixel(res->wa, res->pos.x + 14.4,
        res->pos.y + 18 + res->ti);
        if (co.g != 255 && ci.g != 255) {
            res->movement.y += res->ti, res->pos.y += res->ti, res->d_opt = -1;
            res->textureRect.left = change_sprite(res->counter, 1, 20);
        }
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        co = sfImage_getPixel(res->wa, res->pos.x, res->pos.y - res->ti);
        ci = sfImage_getPixel(res->wa, res->pos.x + 14.4,
        res->pos.y - res->ti);
        if (co.g != 255 && ci.g != 255) {
            res->movement.y -= res->ti, res->pos.y -= res->ti, res->d_opt = -1;
            res->textureRect.left = change_sprite(res->counter, 39, 58);
        }
    }
    return 0;
}

int x_movements(game_ressources *res)
{
    sfColor co, ci;
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        co = sfImage_getPixel(res->wa, res->pos.x + 16 + res->ti, res->pos.y);
        ci = sfImage_getPixel(res->wa, res->pos.x + 16 + res->ti,
        res->pos.y + 14.4);
        if (co.g != 255 && ci.g != 255) {
            res->movement.x += res->ti, res->pos.x += res->ti, res->d_opt = -1;
            res->textureRect.left = change_sprite(res->counter, 77, 96);
        }
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        co = sfImage_getPixel(res->wa, res->pos.x - res->ti - 3, res->pos.y);
        ci = sfImage_getPixel(res->wa, res->pos.x - res->ti - 3,
        res->pos.y + 14.4);
        if (co.g != 255 && ci.g != 255) {
            res->movement.x -= res->ti, res->pos.x -= res->ti, res->d_opt = -1;
            res->textureRect.left = change_sprite(res->counter, 115, 134);
        }
    }
    return y_movement(res);
}

void change_dialog(game_ressources *ress)
{
    sfTime time = sfClock_getElapsedTime(ress->change_dialog_timer);
    if (sfTime_asSeconds(time) < 2)
        return;
    sfClock_restart(ress->change_dialog_timer);
    sfColor temp;
    temp = sfImage_getPixel(ress->wa, ress->pos.x + 8, ress->pos.y + 8);
    if (temp.g == 1) {
        if (ress->d_opt < 7)
            ress->d_opt++;
        else
            ress->d_opt = 0;
        sfSprite_setTexture(ress->dialog, ress->d_textures[ress->d_opt],
                            sfTrue);
    }
}
