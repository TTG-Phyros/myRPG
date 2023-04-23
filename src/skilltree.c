/*
** EPITECH PROJECT, 2023
** SkillTree
** File description:
** Mathias
*/

#include "../include/rpg.h"

buttoncod * button10(window *my_win, buttoncod *z)
{
    sfVector2f a = {1573, 205}; z->psc[0] = a, z->psc[1] = z->scale;
    z->skill_list[0] = c_button(z->psc, z->co, " ", my_win->width / 30);
    sfVector2f b = {1403, 205}; z->psc[0] = b, z->psc[1] = z->scale;
    z->skill_list[1] = c_button(z->psc, z->co, " ", my_win->width / 30);
    sfVector2f c = {1230, 205}; z->psc[0] = c, z->psc[1] = z->scale;
    z->skill_list[2] = c_button(z->psc, z->co, " ", my_win->width / 30);
    sfVector2f d = {1573, 473}; z->psc[0] = d, z->psc[1] = z->scale;
    z->skill_list[3] = c_button(z->psc, z->co, " ", my_win->width / 30);
    sfVector2f e = {1403, 468}; z->psc[0] = e, z->psc[1] = z->scale;
    z->skill_list[4] = c_button(z->psc, z->co, " ", my_win->width / 30);
    sfVector2f f = {1230, 467}; z->psc[0] = f, z->psc[1] = z->scale;
    z->skill_list[5] = c_button(z->psc, z->co, " ", my_win->width / 30);
    sfVector2f g = {1573, 730}; z->psc[0] = g, z->psc[1] = z->scale;
    z->skill_list[6] = c_button(z->psc, z->co, " ", my_win->width / 30);
    sfVector2f h = {1403, 731}; z->psc[0] = h, z->psc[1] = z->scale;
    z->skill_list[7] = c_button(z->psc, z->co, " ", my_win->width / 30);
    sfVector2f i = {1230, 730}; z->psc[0] = i, z->psc[1] = z->scale;
    z->skill_list[8] = c_button(z->psc, z->co, " ", my_win->width / 30);
    return z;
}

button_group *set_skilltree_button_group(window *my_win)
{
    buttoncod * z = malloc(sizeof(buttoncod));
    z->psc = malloc(10 * sizeof(sfVector2f));
    z->scale.x = 108; z->scale.y = 175;
    sfVector2f scale2 = {my_win->width / 5.6, my_win->height / 10.9};
    z->skill_list = malloc(sizeof(button *) * 12);
    z->co = malloc(4 * sizeof(sfColor));
    sfColor *cl = malloc(4 * sizeof(sfColor));
    z->co[0] = sfTransparent, z->co[1] = sfBlack, z->co[2] = sfTransparent,
    z->co[3] = sfLightGrey;
    cl[0] = sfDarkGrey, cl[1] = sfBlack, cl[2] = sfGrey, cl[3] = sfLightGrey;
    button10(my_win, z);
    sfVector2f po11 = {400, 600}; z->psc[0] = po11, z->psc[1] = scale2;
    z->skill_list[9] = c_button(z->psc, cl, "Back", my_win->width / 25);
    z->skill_list[10] = NULL;
    button_group *game_group = malloc(sizeof(button_group));
    game_group->button_list = z->skill_list;
}

int redirect_skilltree_check_sec(int i, window *my_win,
                                skill_ressources * skill_ress)
{
    if (i == 0) flife(my_win, skill_ress);
    if (i == 1) flife2(my_win, skill_ress);
    if (i == 2) flife3(my_win, skill_ress);
    if (i == 3) fstrong(my_win, skill_ress);
    if (i == 4) fstrong2(my_win, skill_ress);
    if (i == 5) fstrong3(my_win, skill_ress);
    if (i == 6) fspeed(my_win, skill_ress);
    if (i == 7) fspeed2(my_win, skill_ress);
    if (i == 8) fspeed3(my_win, skill_ress);
    if (i == 9) game_menu(my_win, skill_ress);
    return 0;
}

int redirect_skilltree_check(button_group *group, window *my_win)
{
    for (int i = 0; group->button_list[i]; i++) {
        if (group->button_list[i]->state == 2
                && group->button_list[i]->times_clicked == 1)
            return i;
    }
    return -1;
}

int skilltree(window *my_win, skill_ressources * skill_ress)
{
    sfEvent event;
    button_group *skilltree_group = set_skilltree_button_group(my_win);
    float pos_scale_tree[2][2] = {{400, -80}, {1.1, 1.1}};
    float pos_scale_back[2][2] = {{0, 0}, {1, 1}};
    sfSprite *skill_tree = set_sprite(skill_png, pos_scale_tree);
    sfSprite *bg2 = set_sprite(game_menu_bg, pos_scale_back);
    for (int tem = 0; sfRenderWindow_isOpen(my_win->win); ) {
        while (sfRenderWindow_pollEvent(my_win->win, &event))
            check_event(my_win, event, NULL, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            return game_menu(my_win, skill_ress);
        tem = redirect_skilltree_check(skilltree_group, my_win);
        if (tem == 9) return 0;
        if (tem != -1)
            redirect_skilltree_check_sec(tem, my_win, skill_ress);
        check_hover_and_click(skilltree_group, my_win);
        draw_skilltree(my_win, bg2, skill_tree, skilltree_group);
        draw_skillpoint(my_win, skill_ress);
        sfRenderWindow_display(my_win->win);
    }
}
