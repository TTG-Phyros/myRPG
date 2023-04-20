/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-mypaint-anaelle.urbon
** File description:
** menu_s
*/

#include "my.h"
menu_s *init_menu(void)
{
    menu_s *menu = malloc(sizeof(menu_s));
    menu->size.x = 0;
    menu->size.y = 0;
    return (menu);
}

void display_menu(menu_s **menu)
{
    menu[0]->size.x = 0;
}

void destroy_menu(menu_s **menu)
{
    free(menu);
}
