/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-baptiste.mery
** File description:
** game_ressources
*/

#include "../include/rpg.h"

void load_more_more_textures(game_ressources *game_ress)
{
    sfVector2f scale = {0.8f, 0.8f};
    sfSprite_setScale(game_ress->zelda, scale);
    sfFloatRect view_rect = {50.f - (152.3961f * 1.6 / 2),
    440.f - (100.f * 1.6 / 2), 152.3961f * 1.6, 100.f * 1.6};
    game_ress->game_view = sfView_createFromRect(view_rect);
    game_ress->game_clock = sfClock_create();
    game_ress->ti = 0;
    sfVector2f movement = {0, 0};
    game_ress->movement = movement;
    game_ress->change_dialog_timer = sfClock_create();
    sfVector2f d_scale = {0.03, 0.03};
    sfVector2f d_pos = {130, 375};
    sfSprite_setScale(game_ress->dialog, d_scale);
    sfSprite_setPosition(game_ress->dialog, d_pos);
    sfTexture *temp_tex = sfTexture_createFromFile(Dialog_Box, NULL);
    game_ress->d_box = sfSprite_create();
    sfSprite_setTexture(game_ress->d_box, temp_tex, sfTrue);
    sfSprite_setScale(game_ress->d_box, d_scale);
    sfSprite_setPosition(game_ress->d_box, d_pos);
}

void load_more_textures(game_ressources *game_res, sfVector2f sword_pos,
                        sfVector2f hammer_pos, sfVector2f dragon_pos)
{
    sfTexture *texture = sfTexture_createFromFile(zelda_map, NULL);
    sfTexture *sheet_texture = sfTexture_createFromFile(sprite_sheet, NULL);
    game_res->map = sfSprite_create(), game_res->zelda = sfSprite_create();
    game_res->dragon = sfSprite_create(), game_res->sword = sfSprite_create();
    sfIntRect textureRect = {1, 1, 16, 16}, textureRect1 = {191, 1, 33, 33};
    sfIntRect textureRect2 = {238, 1, 8, 16}, textureRect3 = {227, 1, 8, 16};
    sfSprite_setTexture(game_res->map, texture, sfTrue);
    sfSprite_setTexture(game_res->zelda, sheet_texture, sfTrue);
    sfSprite_setTexture(game_res->dragon, sheet_texture, sfTrue);
    sfSprite_setTexture(game_res->sword, sheet_texture, sfTrue);
    sfSprite_setTexture(game_res->hammer, sheet_texture, sfTrue);
    sfSprite_setTextureRect(game_res->zelda, textureRect);
    sfSprite_setTextureRect(game_res->dragon, textureRect1);
    sfSprite_setTextureRect(game_res->sword, textureRect2);
    sfSprite_setTextureRect(game_res->hammer, textureRect3);
    sfSprite_setPosition(game_res->zelda, game_res->pos);
    sfSprite_setPosition(game_res->sword, sword_pos);
    sfSprite_setPosition(game_res->hammer, hammer_pos);
    sfSprite_setPosition(game_res->dragon, dragon_pos);
    game_res->textureRect = textureRect;
}

load_more_more_more_textures(game_ressources* game_res, sfVector2f sword_inv,
                             sfVector2f hammer_inv, sfVector2f box_inv)
{

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
    sfVector2f sword_pos = {my_win->width / 2.15, my_win->height / 1.17};
    sfVector2f hammer_pos = {my_win->width / 1.36, my_win->height / 4.4};
    sfVector2f dragon_pos = {my_win->width / 1.64, my_win->height / 4.5};
    sfVector2f pos = {my_win->width / 38.4, my_win->width / 2.45};
    sfVector2f sword_inv = {my_win->width / 2.1573, my_win->width / 1.1739};
    sfVector2f hammer_inv = {my_win->width / 1.3665, my_win->width / 4.4082};
    sfVector2f box_inv = {my_win->width / 1.5802, my_win->width / 2.6024};
    sfVector2f key_inv = {my_win->width / 5.4701, my_win->width / 1.1752};
    game_res->pos = pos;
    load_more_textures(game_res, sword_pos, hammer_pos, dragon_pos);
    load_more_more_textures(game_res);
    load_more_more_more_textures(game_res, sword_inv, hammer_inv, box_inv);
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
    sfRenderWindow_drawSprite(my_win->win, game_ress->hammer, NULL);
    sfRenderWindow_drawSprite(my_win->win, game_ress->sword, NULL);
    sfRenderWindow_drawSprite(my_win->win, game_ress->dragon, NULL);

//*
        if (is_box != 2)
            sfRenderWindow_drawSprite(my_win->win, game_ress->box, NULL);
        sfRenderWindow_drawSprite(my_win->win, game_ress->key, NULL);
        sfRenderWindow_drawSprite(my_win->win, game_ress->roof, NULL);
//*

    sfRenderWindow_display(my_win->win);
}
