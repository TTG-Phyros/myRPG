/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-baptiste.mery
** File description:
** fight_ressources
*/

#include "../include/rpg.h"

sfSprite *set_sprite_ss(char *filepath, float pos[2][2], float ss_pos[2][2])
{
    sfTexture *texture_sprite;
    sfVector2f pos_sprite = {pos[0][0], pos[0][1]};
    sfVector2f scale_sprite = {pos[1][0], pos[1][1]};
    sfIntRect *rect = malloc(sizeof(sfIntRect));
    rect->left = ss_pos[0][0];
    rect->top = ss_pos[0][1];
    rect->width = ss_pos[1][0];
    rect->height = ss_pos[1][1];
    texture_sprite = sfTexture_createFromFile(filepath, rect);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture_sprite, sfTrue);
    sfSprite_setPosition(sprite, pos_sprite);
    sfSprite_scale(sprite, scale_sprite);
    return sprite;
}

void more_more_fight_ress(fight_ressources *res, window *w)
{
    float ps_hearts_f[2][2] = {{w->width / 4.46, w->height / 108},
    {w->height / 108, w->height / 108}};
    float ps_hearts_ss_f[2][2] = {{153, 1}, {15, 15}};
    res->heart_fo = set_sprite_ss(sprite_sheet, ps_hearts_f, ps_hearts_ss_f);
}

void more_load_fight_ress(fight_ressources *res, window *w)
{
    float ps_hearts[2][2] = {{w->width / 192, w->height / 108},
    {w->height / 108, w->height / 108}};
    float ps_hearts_ss[2][2] = {{153, 1}, {15, 15}};
    res->heart_o = set_sprite_ss(sprite_sheet, ps_hearts, ps_hearts_ss);
    float ps_hearts_m[2][2] = {{w->width / 1.143, w->height / 108},
    {w->height / 67.5, w->height / 67.5}};
    float ps_hearts_m_ss[2][2] = {{153, 1}, {15, 15}};
    res->hearts_m = set_sprite_ss(sprite_sheet, ps_hearts_m, ps_hearts_m_ss);
    float ps_hearts_tw[2][2] = {{w->width / 12.8, w->height / 108},
    {w->height / 108, w->height / 108}};
    float ps_hearts_ss_tw[2][2] = {{153, 1}, {15, 15}};
    res->heart_tw = set_sprite_ss(sprite_sheet, ps_hearts_tw, ps_hearts_ss_tw);
    float ps_hearts_tr[2][2] = {{w->width / 6.6, w->height / 108},
    {w->height / 108, w->height / 108}};
    float ps_hearts_ss_tr[2][2] = {{153, 1}, {15, 15}};
    res->heart_tr = set_sprite_ss(sprite_sheet, ps_hearts_tr, ps_hearts_ss_tr);
    res->auto_damage = sfClock_create(), res->cooldown = sfClock_create();
    res->direction = sfFalse, res->hp_monster = 70, res->hp_player = 3;
    sfVector2f pos = {w->width / 1.1, w->height / 16.6};
    res->m_life = hp_monster_text(pos, w->height / 12);
}

void load_fight_ressources(fight_ressources *ress, window *w)
{
    float ps_back[2][2] = {{-(w->width / 192), -(w->height / 12.8)},
    {w->height / 360, w->height / 360}};
    ress->back = set_sprite(fight_back, ps_back);
    float pos_scale_bf[2][2] = {{w->width / 4.6, w->height / 1.54},
    {w->width / (double)1920, w->height / (double)1080}};
    ress->back_f = set_sprite(bcfight, pos_scale_bf);
    float ps_sword[2][2] = {{w->width / 4.5, w->height / 1.3},
    {w->height / 98.2, w->height / 98.2}};
    float ps_sword_ss[2][2] = {{238, 1}, {8, 16}};
    ress->sword = set_sprite_ss(sprite_sheet, ps_sword, ps_sword_ss);
    float ps_monster[2][2] = {{w->width / 1.5, w->height / 4.3},
    {w->height / 77.1, w->height / 77.4}};
    float ps_monster_ss[2][2] = {{191, 1}, {33, 33}};
    ress->monster = set_sprite_ss(sprite_sheet, ps_monster, ps_monster_ss);
    float ps_link[2][2] = {{w->width / 5.1, w->height / 2},
    {w->height / 108, w->height / 108}};
    float ps_link_ss[2][2] = {{77, 1}, {16, 16}};
    ress->link = set_sprite_ss(sprite_sheet, ps_link, ps_link_ss);
    more_load_fight_ress(ress, w);
    more_more_fight_ress(ress, w);
}

int clean_fight_ress(fight_ressources *ress, sfClock *disp,
                    sfText *text, sfBool win)
{
    sfSprite_destroy(ress->back);
    sfSprite_destroy(ress->back_f);
    sfSprite_destroy(ress->sword);
    sfSprite_destroy(ress->monster);
    sfSprite_destroy(ress->link);
    sfSprite_destroy(ress->heart_o);
    sfSprite_destroy(ress->hearts_m);
    sfSprite_destroy(ress->heart_tw);
    sfSprite_destroy(ress->heart_tr);
    sfClock_destroy(ress->auto_damage);
    sfClock_destroy(ress->cooldown);
    sfClock_destroy(disp);
    sfText_destroy(ress->m_life);
    sfText_destroy(text);
    free(ress);
    return win;
}
