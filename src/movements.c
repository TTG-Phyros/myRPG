/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-baptiste.mery
** File description:
** movements
*/

#include "../include/rpg.h"

int pixel_test(sfColor *temp, int green_percent, game_ressources *ress)
{
    if ((temp[0].g == green_percent || temp[1].g == green_percent
        || temp[2].g == green_percent || temp[3].g == green_percent
        || temp[4].g == green_percent) && ress->has_key == 0)
        return 1;
    return 0;
}

int y_movement_more(game_ressources *res)
{
    sfColor *co = malloc(sizeof(sfColor) * 5);
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        co[0] = getPixel(res->wa, res->pos.x, res->pos.y - res->ti);
        co[1] = getPixel(res->wa, res->pos.x + 14, res->pos.y - res->ti);
        co[2] = getPixel(res->wa, res->pos.x + 4, res->pos.y - res->ti);
        co[3] = getPixel(res->wa, res->pos.x + 11, res->pos.y - res->ti);
        co[4] = getPixel(res->wa, res->pos.x + 8, res->pos.y - res->ti);
        if (pixel_test(co, 12, res) && !res->has_key) co[0].g = 255;
        if (pixel_test(co, 13, res) && !res->has_box) co[0].g = 255;
        if (pixel_test(co, 11, res) && !res->is_dragon) co[0].g = 255;
        if (co[0].g != 255 && co[1].g != 255 && co[2].g != 255 &&
            co[3].g != 255 && co[4].g != 255) {
            res->movement.y -= res->ti, res->pos.y -= res->ti, res->d_opt = -1;
            res->textureRect.left = change_sprite(res->counter, 39, 58);
        }
    }
    free(co);
    return 0;
}

int y_movement(game_ressources *res)
{
    sfColor *co = malloc(sizeof(sfColor) * 5);
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        co[0] = getPixel(res->wa, res->pos.x, res->pos.y + 18 + res->ti);
        co[1] = getPixel(res->wa, res->pos.x + 14, res->pos.y + 18 + res->ti);
        co[2] = getPixel(res->wa, res->pos.x + 4, res->pos.y + 18 + res->ti);
        co[3] = getPixel(res->wa, res->pos.x + 11, res->pos.y + 18 + res->ti);
        co[4] = getPixel(res->wa, res->pos.x + 8, res->pos.y + 18 + res->ti);
        if (pixel_test(co, 12, res) && !res->has_key) co[0].g = 255;
        if (pixel_test(co, 13, res) && !res->has_box) co[0].g = 255;
        if (pixel_test(co, 11, res) && !res->is_dragon) co[0].g = 255;
        if (co[0].g != 255 && co[1].g != 255 && co[2].g != 255 &&
        co[3].g != 255 && co[4].g != 255) {
            res->movement.y += res->ti, res->pos.y += res->ti, res->d_opt = -1;
            res->textureRect.left = change_sprite(res->counter, 1, 20);
        }
    }
    free(co);
    return y_movement_more(res);
}

int x_movements_more(game_ressources *res)
{
    sfColor *co = malloc(sizeof(sfColor) * 5);
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        co[0] = getPixel(res->wa, res->pos.x - res->ti - 3, res->pos.y);
        co[1] = getPixel(res->wa, res->pos.x - res->ti - 3, res->pos.y + 16);
        co[2] = getPixel(res->wa, res->pos.x - res->ti - 3, res->pos.y + 4);
        co[3] = getPixel(res->wa, res->pos.x - res->ti - 3, res->pos.y + 8);
        co[4] = getPixel(res->wa, res->pos.x - res->ti - 3, res->pos.y + 12);
        if (pixel_test(co, 12, res) && !res->has_key) co[0].g = 255;
        if (pixel_test(co, 13, res) && !res->has_box) co[0].g = 255;
        if (pixel_test(co, 11, res) && !res->is_dragon) co[0].g = 255;
        if (co[0].g != 255 && co[1].g != 255 && co[2].g != 255 &&
        co[3].g != 255 && co[4].g != 255) {
            res->movement.x -= res->ti, res->pos.x -= res->ti, res->d_opt = -1;
            res->textureRect.left = change_sprite(res->counter, 115, 134);
        }
    }
    free(co);
    return y_movement(res);
}

int x_movements(game_ressources *res)
{
    sfColor *co = malloc(sizeof(sfColor) * 5);
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        co[0] = getPixel(res->wa, res->pos.x + 16 + res->ti, res->pos.y);
        co[1] = getPixel(res->wa, res->pos.x + 16 + res->ti, res->pos.y + 16);
        co[2] = getPixel(res->wa, res->pos.x + 16 + res->ti, res->pos.y + 4);
        co[3] = getPixel(res->wa, res->pos.x + 16 + res->ti, res->pos.y + 8);
        co[4] = getPixel(res->wa, res->pos.x + 16 + res->ti, res->pos.y + 12);
        if (pixel_test(co, 12, res) && !res->has_key) co[0].g = 255;
        if (pixel_test(co, 13, res) && !res->has_box) co[0].g = 255;
        if (pixel_test(co, 11, res) && !res->is_dragon) co[0].g = 255;
        if (co[0].g != 255 && co[1].g != 255 && co[2].g != 255 &&
        co[3].g != 255 && co[4].g != 255) {
            res->movement.x += res->ti, res->pos.x += res->ti, res->d_opt = -1;
            res->textureRect.left = change_sprite(res->counter, 77, 96);
        }
    }
    free(co);
    return x_movements_more(res);
}
