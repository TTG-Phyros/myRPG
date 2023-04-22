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
    new_window->title = title;
    new_window->volume = 50;
    new_window->selected_res = 1;
    return new_window;
}

void check_event(window *my_win, sfEvent event, button_group *group,
                sfView *view)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(my_win->win);
    if (event.type == sfEvtResized)
        fix_resize(group, my_win);
    if (event.type == sfEvtMouseWheelMoved) {
        int scroll = 0;
        if (event.mouseWheel.delta < 0) {
            scroll = event.mouseWheel.delta;
            sfView_zoom(view, 2.f);
        }
        if (event.mouseWheel.delta > 0) {
            scroll = event.mouseWheel.delta;
            sfView_zoom(view, 0.5f);
        }
    }
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

int main_menu(window *my_win)
{
    sfEvent event;
    float pos_scale_back[2][2] = {{0, 0}, {1, 1}};
    sfSprite *main_back = set_sprite(back_main, pos_scale_back);
    sfText *main_title = main_text(my_win);
    sfClock *delay = sfClock_create();
    button_group *main_group = set_main_button_group(my_win);
    for (int temp = 0; sfRenderWindow_isOpen(my_win->win); ) {
        while (sfRenderWindow_pollEvent(my_win->win, &event))
            check_event(my_win, event, main_group, NULL);
        if ((temp = redirect_main_check(main_group, my_win)) != -1)
            return redirect_main_check_sec(temp, my_win);
        if (sfTime_asSeconds(sfClock_getElapsedTime(delay)) > 1)
            check_hover_and_click(main_group, my_win);
        sfRenderWindow_clear(my_win->win, sfBlack);
        sfRenderWindow_drawSprite(my_win->win, main_back, NULL);
        draw_button_group(main_group, my_win);
        sfRenderWindow_drawText(my_win->win, main_title, NULL);
        sfRenderWindow_display(my_win->win);
    }
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("\n- RPG -\n\n");
        my_putstr(" Role Play Game\n");
        my_putstr(" Le vieux vous expliqueras tout.\n\n");
        return (0);
    }
    window *my_win = create_window(1920, 1080, "ZelDouille", 60);
    my_win->music = sfMusic_createFromFile("content/Soundtrack.ogg");
    sfMusic_setLoop(my_win->music, sfTrue);
    sfMusic_setVolume(my_win->music, 50);
    sfMusic_play(my_win->music);
    main_menu(my_win);
}
