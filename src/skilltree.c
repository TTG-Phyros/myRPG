/*
** EPITECH PROJECT, 2023
** SkillTree
** File description:
** Mathias
*/

#include "../include/rpg.h"

sfText *skilltext(window *my_win)
{
    char *addskill = "+1 Skill Point";
    sfText *skilltext = sfText_create();
    sfFont *font = sfFont_createFromFile(main_font);
    sfText_setFont(skilltext, font);
    sfText_setString(skilltext, addskill);
    sfText_setCharacterSize(skilltext, my_win->width / 9.6);
    sfText_setColor(skilltext, sfDarkGrey);
    sfText_setOutlineColor(skilltext, sfBlack);
    sfText_setOutlineThickness(skilltext, 5);
    sfFloatRect rect = sfText_getGlobalBounds(skilltext);
    sfVector2f pos = {500, 300};
    sfText_setPosition(skilltext, pos);
    return skilltext;
}

button_group *set_skilltree_button_group(window *my_win)
{
    sfVector2f *psc = malloc(10 * sizeof(sfVector2f));
    sfVector2f scale = {108, 175}; sfVector2f scale2 = {my_win->width / 5.6, my_win->height / 10.9};
    button **skill_list = malloc(sizeof(button *) * 12);
    sfColor *co = malloc(4 * sizeof(sfColor)); sfColor *cl = malloc(4 * sizeof(sfColor));
    co[0] = sfTransparent, co[1] = sfBlack, co[2] = sfTransparent, co[3] = sfLightGrey;
    cl[0] = sfDarkGrey, cl[1] = sfBlack, cl[2] = sfGrey, cl[3] = sfLightGrey;
    sfVector2f pos2 = {1573, 205}; psc[0] = pos2, psc[1] = scale;
    skill_list[0] = c_button(psc, co, " ", my_win->width / 30);
    sfVector2f pos3 = {1403, 205}; psc[0] = pos3, psc[1] = scale;
    skill_list[1] = c_button(psc, co, " ", my_win->width / 30);
    sfVector2f pos4 = {1230, 205}; psc[0] = pos4, psc[1] = scale;
    skill_list[2] = c_button(psc, co, " ", my_win->width / 30);
    sfVector2f pos5 = {1573, 473}; psc[0] = pos5, psc[1] = scale;
    skill_list[3] = c_button(psc, co, " ", my_win->width / 30);
    sfVector2f pos6 = {1403, 468}; psc[0] = pos6, psc[1] = scale;
    skill_list[4] = c_button(psc, co, " ", my_win->width / 30);
    sfVector2f pos7 = {1230, 467}; psc[0] = pos7, psc[1] = scale;
    skill_list[5] = c_button(psc, co, " ", my_win->width / 30);
    sfVector2f pos8 = {1573, 730}; psc[0] = pos8, psc[1] = scale;
    skill_list[6] = c_button(psc, co, " ", my_win->width / 30);
    sfVector2f pos9 = {1403, 731}; psc[0] = pos9, psc[1] = scale;
    skill_list[7] = c_button(psc, co, " ", my_win->width / 30);
    sfVector2f po10 = {1230, 730}; psc[0] = po10, psc[1] = scale;
    skill_list[8] = c_button(psc, co, " ", my_win->width / 30);
    sfVector2f po11 = {400, 500}; psc[0] = po11, psc[1] = scale2;
    skill_list[9] = c_button(psc, cl, "Back", my_win->width / 25);
    skill_list[10] = NULL;
    button_group *game_group = malloc(sizeof(button_group));
    game_group->button_list = skill_list;
}

int redirect_skilltree_check_sec(int i, window *my_win, skill_ressources * skill_ress)
{
    if (i == 1)
        printf("life %d", 1);
    if (i == 2)
        printf("life %d", 2);
    if (i == 4)
        printf("strong %d", 3);
    if (i == 5)
        printf("strong %d", 4);
    if (i == 7)
        printf("speed %d", 5);
    if (i == 8)
        printf("speed %d", 6);
    if (i == 9)
        game_menu(my_win);
    return 0;
}

int redirect_skilltree_check(button_group *group, window *my_win)
{
    for (int i = 0; group->button_list[i]; i++) {
        if (group->button_list[i]->state == 2)
            return i;
    }
    return -1;
}

int skilltree(window *my_win, skill_ressources * skill_ress)
{
    sfEvent event; int temp = 0;
    button_group *skilltree_group = set_skilltree_button_group(my_win);
    float pos_scale_tree[2][2] = {{400, -80}, {1.1, 1.1}};
    float pos_scale_back[2][2] = {{0, 0}, {1, 1}};
    sfSprite *skill_tree = set_sprite(skill_png, pos_scale_tree);
    sfSprite *bg2 = set_sprite(game_menu_bg, pos_scale_back);
    while (sfRenderWindow_isOpen(my_win->win)) {
        while (sfRenderWindow_pollEvent(my_win->win, &event))
            check_event(my_win, event, NULL, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) return game_menu(my_win);
        if ((temp = redirect_skilltree_check(skilltree_group, my_win)) != -1)
            redirect_skilltree_check_sec(temp, my_win, skill_ress);
        check_hover_and_click(skilltree_group, my_win);
        sfRenderWindow_clear(my_win->win, sfBlack);
        sfRenderWindow_drawSprite(my_win->win, bg2, NULL);
        sfRenderWindow_drawSprite(my_win->win, skill_tree, NULL);
        draw_button_group(skilltree_group, my_win);
        sfText *text = skilltext(my_win);
        sfRenderWindow_drawText(my_win->win, text, NULL);
        sfRenderWindow_display(my_win->win);
    }
}
