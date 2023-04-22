/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-baptiste.mery
** File description:
** game
*/

#include "../include/rpg.h"

void reset_variables(game_ressources *game_ress)
{
    sfTime time = sfClock_getElapsedTime(game_ress->game_clock);
    game_ress->ti = sfTime_asSeconds(time) * 100;
    game_ress->counter += game_ress->ti * 5;
    sfClock_restart(game_ress->game_clock);
    game_ress->movement.x = 0, game_ress->movement.y = 0;
}

void cleanup(game_ressources *ress)
{
    for (int i = 0; ress->d_textures[i]; i++)
        sfTexture_destroy(ress->d_textures[i]);
    free(ress->d_textures);
    sfSprite_destroy(ress->dialog);
    sfSprite_destroy(ress->map);
    sfSprite_destroy(ress->zelda);
    sfSprite_destroy(ress->sword);
    sfSprite_destroy(ress->hammer);
    sfSprite_destroy(ress->dragon);
    sfSprite_destroy(ress->d_box);
    sfImage_destroy(ress->wa);
    sfView_destroy(ress->game_view);
    sfClock_destroy(ress->game_clock);
    sfClock_destroy(ress->change_dialog_timer);
    free(ress);
}

int back_menu(window *my_win, game_ressources *game_ress)
{
    sfFloatRect view_rect_reset = {0, 0, my_win->width, my_win->height};
    sfView *view_reset = sfView_createFromRect(view_rect_reset);
    sfRenderWindow_setView(my_win->win, view_reset);
    cleanup(game_ress);
    main_menu(my_win);
    return 0;
}

int start_fight(window *my_win, game_ressources *game_ress)
{
    sfFloatRect view_rect_reset = {0, 0, my_win->width, my_win->height};
    sfView *view_reset = sfView_createFromRect(view_rect_reset);
    sfRenderWindow_setView(my_win->win, view_reset);
    the_fight(my_win);
    sfRenderWindow_setView(my_win->win, game_ress->game_view);
}

int play(window *my_win)
{
    sfColor temp_wall;
    int is_sword = 1;
    int is_dragon = 1;
    int is_hammer = 1;
    int is_box = 1;
    int is_key = 1;
    int is_cle = 1;
    int temp_i = 0;

    sfEvent event;
    game_ressources *game_ress = malloc(sizeof(game_ressources));
    load_textures(game_ress, my_win);
    while (sfRenderWindow_isOpen(my_win->win)) {
        reset_variables(game_ress);
        while (sfRenderWindow_pollEvent(my_win->win, &event))
            check_event(my_win, event, NULL, game_ress->game_view);
        x_movements(game_ress);
        sfView_move(game_ress->game_view, game_ress->movement);
        sfSprite_setPosition(game_ress->zelda, game_ress->pos);
        sfSprite_setTextureRect(game_ress->zelda, game_ress->textureRect);
        sfRenderWindow_setView(my_win->win, game_ress->game_view);

//*
        temp_wall = sfImage_getPixel(game_ress->wa, game_ress->pos.x, game_ress->pos.y);
        if (temp_wall.r == 64) {
            puts("you died dumbass");
            //? death screen
        }

        if (sfKeyboard_isKeyPressed(sfKeyNum1) /* && on the correct detection */) {
            if (sfKeyboard_isKeyPressed(sfKeyLControl) && is_sword == 0) {
                is_sword = 1;
            }
            if (temp_wall.g == 2 && is_dragon == 1 && is_sword == 0) {
                //?start dragon fight remove door
                is_dragon = 0;
            }
        }


        if (sfKeyboard_isKeyPressed(sfKeyNum2) /* && on the correct detection */) {
            if (sfKeyboard_isKeyPressed(sfKeyLControl) && is_hammer == 0) {
                is_hammer = 1;
            }

            //? remove the floor tile give the brick
            if (temp_wall.g == 6 && is_hammer == 0 && is_box != 2) {
                is_box = 0;
            }
        }

        if (sfKeyboard_isKeyPressed(sfKeyNum3) /* && on the correct detection */) {
            if (sfKeyboard_isKeyPressed(sfKeyLControl) && is_box == 0) {
                is_box = 2;
            }
        }


        if(sfKeyboard_isKeyPressed(sfKeySpace)) {
            temp_wall = sfImage_getPixel(game_ress->wa, game_ress->pos.x, pos.y);//* here changed how the dialogue worked and made dialog option shift up

            if (temp_wall.g == 7 && is_key == 1) {
                is_key = 0;
            }
            if (temp_wall.g == 6 && is_box == 0) {
                //? go to secret room
            }
            if (temp_wall.g == 3 && is_sword == 1) {
                is_sword = 0;
            }
            if (temp_wall.g == 4 && is_hammer == 1) {
                is_hammer = 0;
            }

        sword_inv.x = zelda_pos.x - 120;
        sword_inv.y = zelda_pos.y - 78;
        hammer_inv.x = zelda_pos.x - 110;
        hammer_inv.y = zelda_pos.y - 78;
        box_inv.x = zelda_pos.x - 100;
        box_inv.y = zelda_pos.y - 78;
        key_inv.x = zelda_pos.x - 84;
        key_inv.y = zelda_pos.y - 78;

        sfSprite_setPosition(sword, sword_pos);
        sfSprite_setPosition(hammer, hammer_pos);
        sfSprite_setPosition(box, box_pos);
        sfSprite_setPosition(key, key_pos);
        if (!is_hammer)
            sfSprite_setPosition(hammer, hammer_inv);
        if (!is_sword)
            sfSprite_setPosition(sword, sword_inv);
        if (!is_box)
            sfSprite_setPosition(box, box_inv);
        if (!is_key)
            sfSprite_setPosition(key, key_inv);

//*
        
        draw_game(my_win, game_ress);
        if (sfKeyboard_isKeyPressed(sfKeyE)) change_dialog(game_ress);
        if (sfKeyboard_isKeyPressed(sfKeyE) && check_fight(game_ress))
            start_fight(my_win, game_ress);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            return back_menu(my_win, game_ress);

    }
    return 0;
}
