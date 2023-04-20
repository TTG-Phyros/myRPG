/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-mypaint-anaelle.urbon
** File description:
** condition
*/

#include "my.h"

/* Regarde si l'event Closed est actif et ferme la fenêtre*/
void conditions_event(sfEvent event, all_s *all)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(all->wdw);
}
