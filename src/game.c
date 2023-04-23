/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-baptiste.mery
** File description:
** game
*/

#include "../include/rpg.h"

void reset_variables(game_ressources *game_ress, skill_ressources *skill_ress)
{
    sfTime time = sfClock_getElapsedTime(game_ress->game_clock);
    game_ress->ti = sfTime_asSeconds(time) * 100 * (skill_ress->speed + 1);
    game_ress->counter += game_ress->ti * 5;
    sfClock_restart(game_ress->game_clock);
    game_ress->movement.x = 0, game_ress->movement.y = 0;
}

void cleanup(game_ressources *ress)
{
    for (int i = 0; ress->d_textures[i]; i++)
        sfTexture_destroy(ress->d_textures[i]);
    free(ress->d_textures);
    sfSprite_destroy(ress->dialog), sfSprite_destroy(ress->map);
    sfSprite_destroy(ress->zelda), sfSprite_destroy(ress->sword);
    sfSprite_destroy(ress->hammer), sfSprite_destroy(ress->dragon);
    sfSprite_destroy(ress->d_box);
    sfImage_destroy(ress->wa);
    sfView_destroy(ress->game_view);
    sfClock_destroy(ress->game_clock);
    sfClock_destroy(ress->change_dialog_timer);
    free(ress);
}

int back_menu(window *my_win, game_ressources *game_ress,
            skill_ressources *skill_ress)
{
    sfFloatRect view_rect_reset = {0, 0, my_win->width, my_win->height};
    sfView *view_reset = sfView_createFromRect(view_rect_reset);
    sfRenderWindow_setView(my_win->win, view_reset);
    game_menu(my_win, skill_ress);
    sfRenderWindow_setView(my_win->win, game_ress->game_view);
    return 0;
}

int start_fight(window *my_win, game_ressources *game_ress,
                skill_ressources *skill_ress)
{
    sfFloatRect view_rect_reset = {0, 0, my_win->width, my_win->height};
    sfView *view_reset = sfView_createFromRect(view_rect_reset);
    sfRenderWindow_setView(my_win->win, view_reset);
    int r_value = the_fight(my_win, skill_ress);
    sfRenderWindow_setView(my_win->win, game_ress->game_view);
    if (r_value == 1) {
        sfIntRect rect1 = {249, 1, 16, 16};
        sfSprite_setTextureRect(game_ress->key, rect1);
    }
    return r_value;
}

int play(window *my_win)
{
    skill_ressources *skill_ress = malloc(sizeof(skill_ressources));
    game_ressources *game_ress = malloc(sizeof(game_ressources));
    load_textures(game_ress, my_win, skill_ress);
    sfVector2u size = sfRenderWindow_getSize(my_win->win);
    int old_width = size.x;
    for (sfEvent event; sfRenderWindow_isOpen(my_win->win); ) {
        old_width = size.x, size = sfRenderWindow_getSize(my_win->win);
        if (size.x != old_width) {
            cleanup(game_ress), game_ress = malloc(sizeof(game_ressources));
            load_textures(game_ress, my_win, skill_ress);
        }
        reset_variables(game_ress, skill_ress);
        while (sfRenderWindow_pollEvent(my_win->win, &event))
            check_event(my_win, event, NULL, game_ress->game_view);
        gain_skillpoint(skill_ress), x_movements(game_ress);
        rotate(game_ress), check_pickup(my_win, game_ress);
        change_pos_inv(game_ress, my_win, skill_ress);
        if (game_ress->finished == 1) win_screen(game_ress, my_win);
        draw_game(my_win, game_ress, game_ress->has_box, skill_ress);
    } return 0;
}
