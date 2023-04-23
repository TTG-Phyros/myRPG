/*
** EPITECH PROJECT, 2023
** ress->points
** File description:
** rpg
*/

#include "../include/rpg.h"

int draw_life(window *my_win, skill_ressources *skill_ress, sfFont *font)
{
    sfVector2f pos2 = {250, 250};
    char *string2 = merge_int_str("Life : ", skill_ress->life);
    sfText *lifetext = sfText_create();
    sfText_setFont(lifetext, font);
    sfText_setCharacterSize(lifetext, 70);
    sfText_setColor(lifetext, sfDarkGrey);
    sfText_setOutlineColor(lifetext, sfBlack);
    sfText_setOutlineThickness(lifetext, 5);
    sfText_setPosition(lifetext, pos2);
    sfText_setString(lifetext, string2);
    sfRenderWindow_drawText(my_win->win, lifetext, NULL);
    sfText_destroy(lifetext);
    free(string2);
    return 0;
}

int draw_strong(window *my_win, skill_ressources *skill_ress, sfFont *font)
{
    sfVector2f pos3 = {250, 350};
    char *string3 = merge_int_str("Strengh : ", skill_ress->strong);
    sfText *strongtext = sfText_create();
    sfText_setFont(strongtext, font);
    sfText_setCharacterSize(strongtext, 70);
    sfText_setColor(strongtext, sfDarkGrey);
    sfText_setOutlineColor(strongtext, sfBlack);
    sfText_setOutlineThickness(strongtext, 5);
    sfText_setPosition(strongtext, pos3);
    sfText_setString(strongtext, string3);
    sfRenderWindow_drawText(my_win->win, strongtext, NULL);
    sfText_destroy(strongtext);
    free(string3);
    return 0;
}

int draw_speed(window *my_win, skill_ressources *skill_ress, sfFont *font)
{
    sfVector2f pos4 = {250, 450};
    char *string4 = merge_int_str("Speed : ", skill_ress->speed);
    sfText *speedtext = sfText_create();
    sfText_setFont(speedtext, font);
    sfText_setCharacterSize(speedtext, 70);
    sfText_setColor(speedtext, sfDarkGrey);
    sfText_setOutlineColor(speedtext, sfBlack);
    sfText_setOutlineThickness(speedtext, 5);
    sfText_setPosition(speedtext, pos4);
    sfText_setString(speedtext, string4);
    sfRenderWindow_drawText(my_win->win, speedtext, NULL);
    sfText_destroy(speedtext);
    free(string4);
    return 0;
}

int draw_skillpoint(window *my_win, skill_ressources *skill_ress)
{
    char *string = merge_int_str("Skill Point : ", skill_ress->point);
    sfText *skilltext = sfText_create();
    sfFont *font = sfFont_createFromFile(main_font);
    sfFloatRect rect = sfText_getGlobalBounds(skilltext);
    sfText_setFont(skilltext, font);
    sfText_setCharacterSize(skilltext, 100);
    sfText_setColor(skilltext, sfDarkGrey);
    sfText_setOutlineColor(skilltext, sfBlack);
    sfText_setOutlineThickness(skilltext, 5);
    sfVector2f pos = {250, 100};
    sfText_setPosition(skilltext, pos);
    sfText_setString(skilltext, string);
    sfRenderWindow_drawText(my_win->win, skilltext, NULL);
    sfText_destroy(skilltext);
    free(string);
    draw_life(my_win, skill_ress, font);
    draw_strong(my_win, skill_ress, font);
    draw_speed(my_win, skill_ress, font);
    sfFont_destroy(font);
}

void draw_skilltree(window *my_win, sfSprite *bg2, sfSprite *skill_tree,
button_group *skilltree_group)
{
    sfRenderWindow_clear(my_win->win, sfBlack);
    sfRenderWindow_drawSprite(my_win->win, bg2, NULL);
    sfRenderWindow_drawSprite(my_win->win, skill_tree, NULL);
    draw_button_group(skilltree_group, my_win);
}
