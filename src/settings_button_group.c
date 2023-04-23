/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** settings_button_group
*/

#include "../include/rpg.h"

button_group *set_settings_button_group(window *w)
{
    button **b_l = malloc(sizeof(button *) * 7);
    sfColor *co = malloc(4 * sizeof(sfColor));
    co[0] = sfDarkGrey, co[1] = sfBlack, co[2] = sfGrey, co[3] = sfLightGrey;
    sfVector2f *psc = malloc(2 * sizeof(sfVector2f));
    sfVector2f sct = {w->width / 5.5, w->height / 10.8};
    sfVector2f pt = {w->width / 38.4, w->height / 1.2};
    psc[0] = pt, psc[1] = sct;
    b_l[0] = c_button(psc, co, "Back", w->width / 25.6);
    sfVector2f sc = {w->width / 38.4, w->height / 21.6};
    sfVector2f po = {w->width / 2.02, w->height / 2.54};
    psc[0] = po, psc[1] = sc, b_l[1] = c_button(psc, co, "-", w->width / 64);
    psc[0].x += w->width / 6.4, b_l[2] = c_button(psc, co, "+", w->width / 64);
    psc[0].y += w->height / 7.2, psc[0].x -= w->width / 6.4;
    b_l[3] = c_button(psc, co, "-", w->width / 64), psc[0].x += w->width / 6.4;
    b_l[4] = c_button(psc, co, "+", w->width / 64);
    psc[0].y += w->height / 7.2;
    b_l[5] = c_button(psc, co, " ", w->width / 64), b_l[6] = NULL;
    button_group *main_group = malloc(sizeof(button_group));
    main_group->button_list = b_l;
    return main_group;
}

settings *settings_names(window *w)
{
    settings *my_setts = malloc(sizeof(settings));
    char **res = malloc(3 * sizeof(char *));
    res[0] = "1280x720", res[1] = "1920x1080";
    my_setts->resolutions = res, my_setts->selected_res = w->selected_res;
    sfText **names = malloc(sizeof(sfText *) * 6);
    sfVector2f pos = {w->width / 3.84, w->height / 2.7};
    names[0] = button_settings_text(w, pos, "Resolution", w->width / 25.6);
    pos.x = w->width / 3.28, pos.y = w->height / 1.96;
    names[1] = button_settings_text(w, pos, "Volume", w->width / 25.6);
    pos.x = w->width / 3.84, pos.y = w->height / 1.54;
    names[2] = button_settings_text(w, pos, "FullScreen", w->width / 25.6);
    pos.x = w->width / 1.89, pos.y = w->height / 2.54;
    char *reso = my_setts->resolutions[my_setts->selected_res];
    names[3] = button_settings_text(w, pos, reso, w->width / 48);
    pos.x = w->width / 1.75, pos.y = w->height / 1.89;
    names[4] = button_settings_text(w, pos, int_to_str(w->volume),
    w->width / 38.4);
    names[5] = NULL, my_setts->volume = w->volume;
    my_setts->fullscreen = w->fullscreen, my_setts->names = names;
    return my_setts;
}

int update_settings(settings *s, window *w, int changed)
{
    if (changed == 1) {
        w->volume = s->volume, sfMusic_setVolume(w->music, w->volume);
        sfText_setString(s->names[4], int_to_str(w->volume));
        return 0;
    }
    if (changed == 2) {
        w->width = char_to_int(s->resolutions[s->selected_res]);
        w->height = char_to_int(&s->resolutions[s->selected_res][5]);
        sfVideoMode mode = {w->width, w->height, 32};
        w->mode = mode;
        sfText_setString(s->names[3], s->resolutions[s->selected_res]);
    }
    if (changed == 3) w->fullscreen = s->fullscreen;
    sfRenderWindow_destroy(w->win);
    if (w->fullscreen == 1) w->win = sfRenderWindow_create(w->mode, w->title,
        sfResize | sfClose | sfFullscreen, NULL);
    else
        w->win = sfRenderWindow_create(w->mode, w->title,
        sfResize | sfClose, NULL);
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

int settings_redirections(button_group *settings_group, settings *my_setts,
window *my_win)
{
    int changed = 0;
    for (int i = 0; settings_group->button_list[i]; i++) {
        if (settings_group->button_list[i]->state == 2 && i == 1 &&
        my_setts->selected_res > 0 &&
        settings_group->button_list[i]->times_clicked == 1)
            my_setts->selected_res--, changed = 2, my_win->selected_res--;
        if (settings_group->button_list[i]->state == 2 && i == 2 &&
        my_setts->selected_res < 1 &&
        settings_group->button_list[i]->times_clicked == 1)
            my_setts->selected_res++, changed = 2, my_win->selected_res++;
        changed = settings_redirections_sec(settings_group->button_list[i],
        i, my_setts, changed);
        if (settings_group->button_list[i]->state == 2 && i == 5 &&
        settings_group->button_list[i]->times_clicked == 1)
            my_setts->fullscreen = !my_setts->fullscreen, changed = 3;
    }
    if (changed > 0)
        return update_settings(my_setts, my_win, changed);
    return 0;
}
