/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** button
*/

#include "../include/rpg.h"

button *c_button(sfVector2f * pos_scale, sfColor *colors,
                    char *title, int char_size)
{
    button *new_button = malloc(sizeof(button));
    sfIntRect *hitbox = malloc(sizeof(sfIntRect));
    new_button->shape = sfRectangleShape_create();
    sfRectangleShape_setPosition(new_button->shape, pos_scale[0]);
    sfRectangleShape_setSize(new_button->shape, pos_scale[1]);
    sfRectangleShape_setFillColor(new_button->shape, colors[0]);
    sfRectangleShape_setOutlineColor(new_button->shape, colors[1]);
    sfRectangleShape_setOutlineThickness(new_button->shape, 5);
    hitbox->left = pos_scale[0].x, hitbox->top = pos_scale[0].y;
    hitbox->height = pos_scale[1].y, hitbox->width = pos_scale[1].x;
    new_button->pos = pos_scale[0], new_button->size = pos_scale[1];
    new_button->hover_color = colors[2], new_button->click_color = colors[3];
    new_button->color = colors[0], new_button->hitbox = hitbox;
    sfText *but_title = button_main_text(title, pos_scale, char_size);
    new_button->title = but_title, new_button->times_clicked = 0;
    new_button->is_clicked = is_clicked, new_button->is_hover = is_hovered;
    return new_button;
}

sfBool is_clicked(button *my_button, window *my_window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(my_window->win);
    if (sfIntRect_contains(my_button->hitbox, mouse.x, mouse.y))
        if (sfMouse_isButtonPressed(0)) {
            my_button->state = 2, my_button->times_clicked++;
            return sfTrue;
        }
        my_button->times_clicked = 0;
    return sfFalse;
}

sfBool is_hovered(button *but, window *my_window)
{
    sfVector2i ms_pos = sfMouse_getPositionRenderWindow(my_window->win);
    if (sfIntRect_contains(but->hitbox, ms_pos.x, ms_pos.y))
        return sfTrue;
    but->state = 0;
    return sfFalse;
}

void change_color(button *butt, window *my_win)
{
    if (butt->state == 1)
        sfRectangleShape_setFillColor(butt->shape,
        butt->hover_color);
    if (butt->state == 2)
        sfRectangleShape_setFillColor(butt->shape,
        butt->click_color);
    if (butt->state == 0)
        sfRectangleShape_setFillColor(butt->shape,
        butt->color);
}

void check_hover_and_click(button_group *group, window *my_win)
{
    for (int i = 0; group->button_list[i]; i++) {
        if (group->button_list[i]->is_hover(group->button_list[i], my_win))
            group->button_list[i]->state = 1;
        if (group->button_list[i]->is_clicked(group->button_list[i], my_win))
            group->button_list[i]->state = 2;
        change_color(group->button_list[i], my_win);
    }
}
