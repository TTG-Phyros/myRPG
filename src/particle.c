/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-baptiste.mery
** File description:
** particle
*/

#include "../include/rpg.h"

void set_animation(animation *anim)
{
    sfSprite **anims = malloc(sizeof(sfSprite *) * (anim->nb_frames + 1));
    sfTexture *texture_sprite;
    sfIntRect *rect = malloc(sizeof(sfIntRect));
    sfSprite *sprite;
    for (int i = 0; i < anim->nb_frames; i++) {
        rect->left = anim->pos_ss[0], rect->top = anim->pos_ss[1];
        rect->width = anim->size[0], rect->height = anim->size[1];
        texture_sprite = sfTexture_createFromFile(anim->filepath_ss, rect);
        sprite = sfSprite_create();
        sfSprite_setTexture(sprite, texture_sprite, sfTrue);
        sfSprite_setPosition(sprite, anim->position);
        sfSprite_scale(sprite, anim->scale);
        anims[i] = sprite;
        anim->pos_ss[0] += anim->spacing[0];
        anim->size[1] += anim->spacing[1];
    }
    anims[anim->nb_frames] = NULL;
    anim->animations = anims;
}
