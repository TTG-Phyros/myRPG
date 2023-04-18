/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** settings_button_group
*/

#include "../include/rpg.h"

button_group *set_settings_button_group(window *my_win)
{
    button **b_list = malloc(sizeof(button *) * 7);
    sfColor *co = malloc(4 * sizeof(sfColor));
    co[0] = sfDarkGrey, co[1] = sfBlack, co[2] = sfGrey, co[3] = sfLightGrey;
    sfVector2f *psc = malloc(2 * sizeof(sfVector2f));
    sfVector2f sct = {my_win->width / 5.5, my_win->height / 10.8};
    sfVector2f pt = {50, 900};
    psc[0] = pt, psc[1] = sct, b_list[0] = create_button(psc, co, "Back", 75);
    sfVector2f sc = {my_win->width / 38.4, my_win->height / 21.6};
    sfVector2f po = {my_win->width / 2.02, my_win->height / 2.54};
    psc[0] = po, psc[1] = sc, b_list[1] = create_button(psc, co, "-", 30);
    psc[0].x += my_win->width / 6.4;
    b_list[2] = create_button(psc, co, "+", 30);
    psc[0].y += my_win->height / 7.2, psc[0].x -= my_win->width / 6.4;
    b_list[3] = create_button(psc, co, "-", 30);
    psc[0].x += my_win->width / 6.4;
    b_list[4] = create_button(psc, co, "+", 30);
    psc[0].y += my_win->height / 7.2, psc[0].x -= 300;
    b_list[5] = create_button(psc, co, " ", 30), b_list[6] = NULL;
    button_group *main_group = malloc(sizeof(button_group));
    main_group->button_list = b_list;
}

void settings_names(window *my_win, settings *my_setts)
{
    sfText **names = malloc(sizeof(sfText *) * 6);
    sfVector2f pos = {my_win->width / 3.84, my_win->height / 2.7};
    names[0] = button_settings_text(my_win, pos, "Resolution", 75);
    pos.x = my_win->width / 3.28, pos.y = my_win->height / 1.96;
    names[1] = button_settings_text(my_win, pos, "Volume", 75);
    pos.x = my_win->width / 3.84, pos.y = my_win->height / 1.54;
    names[2] = button_settings_text(my_win, pos, "FullScreen", 75);
    pos.x = my_win->width / 1.89, pos.y = my_win->height / 2.54;
    names[3] = button_settings_text(my_win, pos, "1920x1080", 40);
    pos.x = my_win->width / 1.75, pos.y = my_win->height / 1.89;
    names[4] = button_settings_text(my_win, pos, int_to_str(my_win->volume), 50);
    names[5] = NULL;
    char **resolutions = malloc(3 * sizeof(char *));
    resolutions[0] = "1280x720", resolutions[1] = "1920x1080";
    my_setts->resolutions = resolutions, my_setts->selected_res = 1;
    my_setts->fullscreen = sfFalse, my_setts->names = names;
    my_setts->volume = my_win->volume;
}

void update_settings(settings *my_setts, window *my_win, int changed)
{
    if (changed == 1) {
        my_win->volume = my_setts->volume;
        sfText_setString(my_setts->names[4], int_to_str(my_win->volume));
    }
    if (changed == 2) {
        my_win->width = char_to_int(my_setts->resolutions[my_setts->selected_res]);
        my_win->height = char_to_int(&my_setts->resolutions[my_setts->selected_res][5]);
        sfVideoMode mode = {my_win->width, my_win->height, 32};
        my_win->mode = mode;
        sfVector2u size = {my_win->width, my_win->height};
        sfRenderWindow_setSize(my_win->win, size);
        sfText_setString(my_setts->names[3], my_setts->resolutions[my_setts->selected_res]);
    }
    if (changed == 3 || changed == 2) {
        my_win->fullscreen = my_setts->fullscreen;
        sfRenderWindow_destroy(my_win->win);
        if (my_win->fullscreen == 1)
            my_win = sfRenderWindow_create(my_win->mode, my_win->title, sfResize | sfClose | sfFullscreen, NULL);
        else
            my_win = sfRenderWindow_create(my_win->mode, my_win->title, sfResize | sfClose, NULL);
    }
    return 1;
}

int settings_redirections_sec(button *button, int i,
                            settings *my_setts, int changed)
{
    if (button->state == 2 && i == 3 && (button->times_clicked == 1 ||
        (button->times_clicked > 50 && button->times_clicked % 10 == 0))
        && my_setts->volume > 0) {
        my_setts->volume--;
        return 1;
    }
    if (button->state == 2 && i == 4 && (button->times_clicked == 1 ||
        (button->times_clicked > 50 && button->times_clicked % 10 == 0))
        && my_setts->volume < 100) {
        my_setts->volume++;
        return 1;
    }
    return changed;
}

void settings_redirections(button_group *settings_group, settings *my_setts, window *my_win)
{
    int changed = 0;
    for (int i = 0; settings_group->button_list[i]; i++) {
        if (settings_group->button_list[i]->state == 2 && i == 1 &&
            my_setts->selected_res > 0 &&
            settings_group->button_list[i]->times_clicked == 1)
            my_setts->selected_res--, changed = 2;
        if (settings_group->button_list[i]->state == 2 && i == 2 &&
            my_setts->selected_res < 1 &&
            settings_group->button_list[i]->times_clicked == 1)
            my_setts->selected_res++, changed = 2;
        changed = settings_redirections_sec(settings_group->button_list[i],
                                            i, my_setts, changed);
        if (settings_group->button_list[i]->state == 2 && i == 5 &&
            settings_group->button_list[i]->times_clicked == 1)
            my_setts->fullscreen = !my_setts->fullscreen, changed = 3;
    }
    if (changed > 0) return update_settings(my_setts, my_win, changed);
    return 0;
}
