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
        if (sfTime_asSeconds(sfClock_getElapsedTime(disp)) >= 3) break;
        sfRenderWindow_clear(w->win, sfBlack);
        sfRenderWindow_drawText(w->win, text, NULL);
        sfRenderWindow_display(w->win);
    }
    sfFont_destroy(font);
    return clean_fight_ress(ress, disp, text, win);
}

void win_screen(game_ressources *ress, window *my_win)
{
    sfFloatRect view_rect_reset = {0, 0, my_win->width, my_win->height};
    sfView *view_reset = sfView_createFromRect(view_rect_reset);
    sfRenderWindow_setView(my_win->win, view_reset);
    cleanup(ress);
    wining_screen(my_win);
}

int wining_screen(window *my_win)
{
    float pos_scale[2][2] = {{0, 0},
    {my_win->width / (double)1920, my_win->height / (double)1080}};
    sfSprite *back_ground = set_sprite(win_screen_path, pos_scale);
    sfVector2f *pos_scale_sec = malloc(sizeof(sfVector2f) * 2);
    sfVector2f pos_sec = {300, 400}, scale_sec = {500, 250};
    pos_scale_sec[0] = pos_sec, pos_scale_sec[1] = scale_sec;
    sfColor *colors = malloc(4 * sizeof(sfColor));
    colors[0] = sfTransparent, colors[1] = sfBlack, colors[2] = sfTransparent;
    colors[3] = sfLightGrey;
    button *play_button = c_button(pos_scale_sec, colors, "Main Menu", 120);
    while (sfRenderWindow_isOpen(my_win->win)) {
        is_clicked(play_button, my_win);
        if (play_button->state == 2) return main_menu(my_win);
        sfRenderWindow_clear(my_win->win, sfBlack);
        sfRenderWindow_drawSprite(my_win->win, back_ground, NULL);
        sfRenderWindow_drawText(my_win->win, play_button->title, NULL);
        sfRenderWindow_display(my_win->win);
    }
    sfSprite_destroy(back_ground);
    return 0;
}

void draw_main(window *my_win, sfSprite *main_back,
sfText *main_title, button_group *main_group)
{
    sfRenderWindow_clear(my_win->win, sfBlack);
    sfRenderWindow_drawSprite(my_win->win, main_back, NULL);
    draw_button_group(main_group, my_win);
    sfRenderWindow_drawText(my_win->win, main_title, NULL);
    sfRenderWindow_display(my_win->win);
}
