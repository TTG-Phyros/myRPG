/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** main
*/

#include "../include/rpg.h"

window *create_window(int width, int height, char *title, int framerate)
{
    window *new_window = malloc(sizeof(window));
    new_window->height = height, new_window->width = width;
    new_window->framerate = framerate;
    sfVideoMode mode = {width, height, 32};
    new_window->mode = mode;
    sfRenderWindow *window;
    window = sfRenderWindow_create(mode, title, sfResize | sfClose, NULL);
    sfRenderWindow_setKeyRepeatEnabled(window, sfFalse);
    new_window->win = window;
    return new_window;
}

void close_event(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

sfSprite *set_sprite(char *filepath, float pos[2][2])
{
    sfTexture *texture_sprite;
    sfVector2f pos_sprite = {pos[0][0], pos[0][1]};
    sfVector2f scale_sprite = {pos[1][0], pos[1][1]};
    texture_sprite = sfTexture_createFromFile(filepath, NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture_sprite, sfTrue);
    sfSprite_setPosition(sprite, pos_sprite);
    sfSprite_scale(sprite, scale_sprite);
    return sprite;
}

void main_menu(window *my_win)
{
    sfEvent event;
    float height = my_win->height / (double)1080;
    float width = my_win->width / (double)1920;
    float pos_scale_back[2][2] = {{0, 0}, {width, height}};
    sfSprite *main_back = set_sprite(back_main, pos_scale_back);
    sfText *main_title = main_text(my_win);
    button_group *main_group = set_main_button_group(my_win);
    while (sfRenderWindow_isOpen(my_win->win)) {
        while (sfRenderWindow_pollEvent(my_win->win, &event))
            close_event(my_win->win, event);
        check_hover_and_click(main_group, my_win);
        sfRenderWindow_clear(my_win->win, sfBlack);
        sfRenderWindow_drawSprite(my_win->win, main_back, NULL);
        draw_button_group(main_group, my_win);
        sfRenderWindow_drawText(my_win->win, main_title, NULL);
        sfRenderWindow_display(my_win->win);
    }
}

void main(void)
{
    window *my_win = create_window(1920, 1080, "My RPG", 60);
    main_menu(my_win);
}
