/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** interaction
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

int check_fight(game_ressources *ress)
{
    sfColor temp;
    temp = sfImage_getPixel(ress->wa, ress->pos.x + 8, ress->pos.y + 8);
    if (temp.g == 4 && temp.b == 100 && ress->is_dragon == 0)
        if (ress->has_sword == 1)
            return 1;
    return 0;
}

void rotate(game_ressources *ress)
{
    if (ress->has_box == 1 || ress->rotation != 0) {
        if (ress->rotation != 360) {
            ress->rotation++;
            sfView_rotate(ress->game_view, 1);
        }
    }
    return;
}
