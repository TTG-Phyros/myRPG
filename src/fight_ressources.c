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

void more_load_fight_ress(fight_ressources *ress)
{
    float ps_hearts_tw[2][2] = {{150, 10}, {10, 10}};
    float ps_hearts_ss_tw[2][2] = {{153, 1}, {15, 15}};
    ress->heart_tw = set_sprite_ss(sprite_sheet, ps_hearts_tw, ps_hearts_ss_tw);
    float ps_hearts_tr[2][2] = {{290, 10}, {10, 10}};
    float ps_hearts_ss_tr[2][2] = {{153, 1}, {15, 15}};
    ress->heart_tr = set_sprite_ss(sprite_sheet, ps_hearts_tr, ps_hearts_ss_tr);
    ress->auto_damage = sfClock_create();
    ress->cooldown = sfClock_create();
    ress->direction = sfFalse;
    sfVector2f pos = {1745, 65};
    ress->m_life = hp_monster_text(pos);
    ress->hp_monster = 70, ress->hp_player = 3;
}

void load_fight_ressources(fight_ressources *ress)
{
    float pos_scale_back[2][2] = {{-10, -150}, {3, 3}};
    ress->back = set_sprite(fight_back, pos_scale_back);
    float pos_scale_bf[2][2] = {{1920 / 2 - 1090 / 2, 700}, {1, 1}};
    ress->back_f = set_sprite(bcfight, pos_scale_bf);
    float ps_sword[2][2] = {{430, 820}, {11, 11}};
    float ps_sword_ss[2][2] = {{238, 1}, {8, 16}};
    ress->sword = set_sprite_ss(sprite_sheet, ps_sword, ps_sword_ss);
    float ps_monster[2][2] = {{1300, 250}, {14, 14}};
    float ps_monster_ss[2][2] = {{191, 1}, {33, 33}};
    ress->monster = set_sprite_ss(sprite_sheet, ps_monster, ps_monster_ss);
    float ps_link[2][2] = {{370, 530}, {10, 10}};
    float ps_link_ss[2][2] = {{77, 1}, {16, 16}};
    ress->link = set_sprite_ss(sprite_sheet, ps_link, ps_link_ss);
    float ps_hearts[2][2] = {{10, 10}, {10, 10}};
    float ps_hearts_ss[2][2] = {{153, 1}, {15, 15}};
    ress->heart_o = set_sprite_ss(sprite_sheet, ps_hearts, ps_hearts_ss);
    float ps_hearts_m[2][2] = {{1680, 10}, {16, 16}};
    float ps_hearts_m_ss[2][2] = {{153, 1}, {15, 15}};
    ress->hearts_m = set_sprite_ss(sprite_sheet, ps_hearts_m, ps_hearts_m_ss);
    more_load_fight_ress(ress);
}

int clean_fight_ress(fight_ressources *ress, sfClock *disp, sfText *text)
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
}

int end_screen(sfBool win, window *w, fight_ressources *ress)
{
    sfClock *disp = sfClock_create();
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(main_font);
    sfText_setFont(text, font);
    if (win) sfText_setString(text, "   Bravo,\nTu as gagne.");
    else
        sfText_setString(text, "  Dommage,\nTu as perdu.");
    sfText_setCharacterSize(text, 150), sfText_setColor(text, sfGrey);
    sfText_setOutlineColor(text, sfBlack), sfText_setOutlineThickness(text, 4);
    sfFloatRect r = sfText_getGlobalBounds(text);
    sfVector2f pos = {(w->width - r.width) / 2, (w->height - r.height) / 2};
    sfText_setPosition(text, pos);
    while (sfRenderWindow_isOpen(w->win)) {
        if (sfTime_asSeconds(sfClock_getElapsedTime(disp)) >= 5) break;
        sfRenderWindow_clear(w->win, sfBlack);
        sfRenderWindow_drawText(w->win, text, NULL);
        sfRenderWindow_display(w->win);
    }
    sfFont_destroy(font);
    return clean_fight_ress(ress, disp, text);
}
