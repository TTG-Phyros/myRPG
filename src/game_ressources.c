/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-baptiste.mery
** File description:
** game_ressources
*/

#include "../include/rpg.h"

void load_more_more_more_textures(game_ressources *game_ress)
{
    sfVector2f s_pos = {893, 923}, h_pos = {1412, 245.5};
    sfVector2f dragon_pos = {1170, 240}, pos = {50, 441};
    sfVector2f box_pos = {1215, 415}, key_pos = {351, 919};
    game_ress->s_pos = s_pos, game_ress->h_pos = h_pos;
    game_ress->dragon_pos = dragon_pos, game_ress->box_pos = box_pos;
    game_ress->key_pos = key_pos, game_ress->pos = pos;
    load_more_textures(game_ress, s_pos, h_pos, dragon_pos);
    game_ress->has_sword = sfFalse, game_ress->has_hammer = sfFalse;
    game_ress->has_key = sfFalse, game_ress->has_box = sfFalse;
    game_ress->is_dragon = 0;
    sfIntRect textureRect2 = {238, 1, 8, 16}, textureRect3 = {227, 1, 8, 16};
    sfSprite_setTextureRect(game_ress->sword, textureRect2);
    sfSprite_setTextureRect(game_ress->hammer, textureRect3);
}

void load_more_more_textures(game_ressources *game_ress)
{
    sfVector2f scale = {0.8f, 0.8f};
    sfSprite_setScale(game_ress->zelda, scale);
    sfFloatRect view_rect = {50.f - (152.3961f * 1.6 / 2),
    440.f - (100.f * 1.6 / 2), 152.3961f * 1.6, 100.f * 1.6};
    game_ress->game_view = sfView_createFromRect(view_rect);
    game_ress->game_clock = sfClock_create(), game_ress->ti = 0;
    sfVector2f movement = {0, 0}, d_scale = {0.03, 0.03}, d_pos = {130, 375};
    game_ress->movement = movement, game_ress->d_box = sfSprite_create();
    game_ress->change_dialog_timer = sfClock_create();
    sfSprite_setScale(game_ress->dialog, d_scale);
    sfSprite_setPosition(game_ress->dialog, d_pos);
    sfTexture *temp_tex = sfTexture_createFromFile(Dialog_Box, NULL);
    sfSprite_setTexture(game_ress->d_box, temp_tex, sfTrue);
    sfSprite_setScale(game_ress->d_box, d_scale);
    sfSprite_setPosition(game_ress->d_box, d_pos);
    sfIntRect rect2 = {172, 1, 16, 16}, rect1 = {142, 40, 16, 16};
    sfSprite_setTextureRect(game_ress->box, rect1);
    sfSprite_setTextureRect(game_ress->key, rect2);
    sfSprite_setPosition(game_ress->box, game_ress->box_pos);
    sfSprite_setPosition(game_ress->key, game_ress->key_pos);
}

void load_more_textures(game_ressources *game_res, sfVector2f s_pos,
                        sfVector2f h_pos, sfVector2f dragon_pos)
{
    sfTexture *texture = sfTexture_createFromFile(zelda_map, NULL);
    sfTexture *sheet_texture = sfTexture_createFromFile(sprite_sheet, NULL);
    game_res->map = sfSprite_create(), game_res->zelda = sfSprite_create();
    game_res->dragon = sfSprite_create(), game_res->sword = sfSprite_create();
    game_res->box = sfSprite_create(), game_res->key = sfSprite_create();
    sfIntRect textureRect = {1, 1, 16, 16}, textureRect1 = {191, 1, 33, 33};
    sfSprite_setTexture(game_res->map, texture, sfTrue);
    sfSprite_setTexture(game_res->zelda, sheet_texture, sfTrue);
    sfSprite_setTexture(game_res->dragon, sheet_texture, sfTrue);
    sfSprite_setTexture(game_res->sword, sheet_texture, sfTrue);
    sfSprite_setTexture(game_res->hammer, sheet_texture, sfTrue);
    sfSprite_setTexture(game_res->box, sheet_texture, sfTrue);
    sfSprite_setTexture(game_res->key, sheet_texture, sfTrue);
    sfSprite_setTextureRect(game_res->zelda, textureRect);
    sfSprite_setTextureRect(game_res->dragon, textureRect1);
    sfSprite_setPosition(game_res->zelda, game_res->pos);
    sfSprite_setPosition(game_res->sword, s_pos);
    sfSprite_setPosition(game_res->hammer, h_pos);
    sfSprite_setPosition(game_res->dragon, dragon_pos);
    game_res->textureRect = textureRect;
}

void load_textures(game_ressources *game_res, window *my_win)
{
    sfTexture **d_textures = malloc(sizeof(sfTexture *) * 8);
    d_textures[0] = sfTexture_createFromFile(Dialog_1, NULL);
    d_textures[1] = sfTexture_createFromFile(Dialog_2, NULL);
    d_textures[2] = sfTexture_createFromFile(Dialog_3, NULL);
    d_textures[3] = sfTexture_createFromFile(Dialog_4, NULL);
    d_textures[4] = sfTexture_createFromFile(Dialog_5, NULL);
    d_textures[5] = sfTexture_createFromFile(Dialog_6, NULL);
    d_textures[6] = sfTexture_createFromFile(Dialog_7, NULL);
    d_textures[7] = NULL, game_res->d_textures = d_textures;
    game_res->dialog = sfSprite_create(), game_res->hammer = sfSprite_create();
    sfSprite_setTexture(game_res->dialog, game_res->d_textures[0], sfTrue);
    game_res->d_opt = -1, game_res->counter = 0;
    game_res->wa = sfImage_createFromFile(wall_map);
    game_res->roof = sfSprite_create();
    sfTexture *roof_text = sfTexture_createFromFile(roof_map, NULL);
    sfSprite_setTexture(game_res->roof, roof_text, sfTrue);
    load_more_more_more_textures(game_res);
    load_more_more_textures(game_res);
}

void draw_game(window * my_win, game_ressources * game_ress, int is_box)
{
    sfRenderWindow_clear(my_win->win, sfBlack);
    sfRenderWindow_drawSprite(my_win->win, game_ress->map, NULL);
    if (game_ress->d_opt != -1) {
        sfRenderWindow_drawSprite(my_win->win, game_ress->d_box, NULL);
        sfRenderWindow_drawSprite(my_win->win, game_ress->dialog, NULL);
    }
    sfRenderWindow_drawSprite(my_win->win, game_ress->zelda, NULL);
    sfRenderWindow_drawSprite(my_win->win, game_ress->roof, NULL);
    sfRenderWindow_drawSprite(my_win->win, game_ress->hammer, NULL);
    sfRenderWindow_drawSprite(my_win->win, game_ress->sword, NULL);
    sfRenderWindow_drawSprite(my_win->win, game_ress->key, NULL);
    if (game_ress->is_dragon == 0)
        sfRenderWindow_drawSprite(my_win->win, game_ress->dragon, NULL);
    if (is_box != 2)
        sfRenderWindow_drawSprite(my_win->win, game_ress->box, NULL);
    sfRenderWindow_display(my_win->win);
}
