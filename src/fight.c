/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** recreatethe famous game my hunter
*/

#include "../include/rpg.h"

void damage(fight_ressources *ress)
{
    sfTime time = sfClock_getElapsedTime(ress->cooldown);
    if (sfTime_asSeconds(time) < 0.2)
        return;
    int dmg = 0;
    sfVector2f pos = sfSprite_getPosition(ress->sword);
    if (pos.x <= 516 || pos.x >= 1290)
        ress->hp_player--;
    if (pos.x <= 708 || pos.x >= 1110)
        dmg = 1;
    if (pos.x <= 867 || pos.x >= 968)
        dmg = 2;
    if (pos.x >= 867 && pos.x <= 968)
        dmg = 3;
    ress->hp_monster -= dmg;
    sfClock_restart(ress->auto_damage);
    sfClock_restart(ress->cooldown);
}

void draw_fight(fight_ressources *ress, window *my_win)
{
    sfRenderWindow_clear(my_win->win, sfBlack);
    sfRenderWindow_drawSprite(my_win->win, ress->back, NULL);
    sfRenderWindow_drawSprite(my_win->win, ress->back_f, NULL);
    sfRenderWindow_drawSprite(my_win->win, ress->sword, NULL);
    sfRenderWindow_drawSprite(my_win->win, ress->monster, NULL);
    sfRenderWindow_drawSprite(my_win->win, ress->link, NULL);
    sfRenderWindow_drawSprite(my_win->win, ress->heart_o, NULL);
    if (ress->hp_player >= 2)
        sfRenderWindow_drawSprite(my_win->win, ress->heart_tw, NULL);
    if (ress->hp_player >= 3)
        sfRenderWindow_drawSprite(my_win->win, ress->heart_tr, NULL);
    sfRenderWindow_drawSprite(my_win->win, ress->hearts_m, NULL);
    sfText_setString(ress->m_life, int_to_str(ress->hp_monster));
    sfRenderWindow_drawText(my_win->win, ress->m_life, NULL);
    sfRenderWindow_display(my_win->win);
}

void eventhandler(sfEvent event, fight_ressources *ress,
                window *my_win)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(my_win->win);
    if (sfKeyboard_isKeyPressed(sfKeySpace))
        damage(ress);
}

void move_sword(fight_ressources *ress, sfClock *clock)
{
    sfClock_restart(clock);
    sfTime time = sfClock_getElapsedTime(ress->auto_damage);
    if (sfTime_asSeconds(time) >= 2.3) {
        ress->hp_player--;
        sfClock_restart(ress->auto_damage);
    }
    sfVector2f pos = sfSprite_getPosition(ress->sword);
    if (pos.x >= 1400 && ress->direction == sfTrue)
        ress->direction = sfFalse;
    if (pos.x <= 430 && ress->direction == sfFalse)
        ress->direction = sfTrue;
    if (ress->direction == sfTrue)
        pos.x += 20;
    if (ress->direction == sfFalse)
        pos.x -= 20;
    if (pos.x > 1600)
        pos.x = 430;
    sfSprite_setPosition(ress->sword, pos);
}

int the_fight(window *my_win)
{
    sfEvent event;
    fight_ressources *fight_ress = malloc(sizeof(fight_ressources));
    load_fight_ressources(fight_ress);
    sfClock *clock_to_move = sfClock_create();
    sfTime time;
    while (sfRenderWindow_isOpen(my_win->win)) {
        time = sfClock_getElapsedTime(clock_to_move);
        if (sfTime_asMilliseconds(time) >= 10)
            move_sword(fight_ress, clock_to_move);
        while (sfRenderWindow_pollEvent(my_win->win, &event))
            eventhandler(event, fight_ress, my_win);
        if (fight_ress->hp_player <= 0)
            return end_screen(0, my_win, fight_ress);
        if (fight_ress->hp_monster <= 0)
            return end_screen(1, my_win, fight_ress);
        draw_fight(fight_ress, my_win);
    }
    return 0;
}
