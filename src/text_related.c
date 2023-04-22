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
    sfText_setString(text, my_win->title);
    sfText_setCharacterSize(text, my_win->width / 9.6);
    sfText_setColor(text, sfDarkGrey);
    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, 5);
    sfFloatRect rect = sfText_getGlobalBounds(text);
    sfVector2f pos = {(my_win->width - rect.width) / 2, rect.height / 2};
    sfText_setPosition(text, pos);
    return text;
}

sfText *settings_text(window *my_win)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(main_font);
    sfText_setFont(text, font);
    sfText_setString(text, "Settings");
    sfText_setCharacterSize(text, my_win->width / 8);
    sfText_setColor(text, sfDarkGrey);
    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, 5);
    sfFloatRect rect = sfText_getGlobalBounds(text);
    sfVector2f pos = {(my_win->width - rect.width) / 2 , my_win->height / 30};
    sfText_setPosition(text, pos);
    return text;
}

sfText *button_settings_text(window *my_win, sfVector2f pos,
                            char *title, int size)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(main_font);
    sfText_setFont(text, font);
    sfText_setString(text, title);
    sfText_setCharacterSize(text, size);
    sfText_setColor(text, sfDarkGrey);
    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, 5);
    sfText_setPosition(text, pos);
    return text;
}

sfText *button_main_text(char *title, sfVector2f *pos_scale, int char_size)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(main_font);
    sfText_setFont(text, font);
    sfText_setString(text, title);
    sfText_setCharacterSize(text, char_size);
    sfText_setColor(text, sfDarkGrey);
    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, 5);
    sfFloatRect rect = sfText_getGlobalBounds(text);
    sfVector2f pos = pos_scale[0];
    sfVector2f scale = pos_scale[1];
    scale.y -= (scale.y * 10) / 100;
    pos.x += (scale.x - rect.width) / 2;
    pos.y += (scale.y - rect.height) / 2;
    sfText_setPosition(text, pos);
    return text;
}

sfText *hp_monster_text(sfVector2f pos)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(main_font);
    sfText_setFont(text, font);
    sfText_setString(text, "70");
    sfText_setCharacterSize(text, 90);
    sfText_setColor(text, sfGrey);
    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, 4);
    sfText_setPosition(text, pos);
    return text;
}
