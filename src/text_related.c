/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** text_related
*/

#include "../include/rpg.h"

sfText *main_text(window *my_win)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(main_font);
    sfText_setFont(text, font);
    sfText_setString(text, "My_RPG");
    sfVector2f pos = {my_win->width / 3.49, my_win->height / 14.4};
    sfText_setPosition(text, pos);
    sfText_setCharacterSize(text, my_win->width / 9.6);
    sfText_setColor(text, sfDarkGrey);
    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, 5);
    return text;
}

sfText *button_main_text(char *title, sfVector2f pos, sfVector2f size)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(main_font);
    sfText_setFont(text, font);
    sfText_setString(text, title);
    sfText_setCharacterSize(text, 75);
    sfText_setColor(text, sfDarkGrey);
    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, 5);
    sfFloatRect rect = sfText_getGlobalBounds(text);
    size.y -= (size.y * 10) / 100;
    pos.x += (size.x - rect.width) / 2, pos.y += (size.y - rect.height) / 2;
    sfText_setPosition(text, pos);
    return text;
}
