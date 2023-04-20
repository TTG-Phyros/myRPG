/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-mypaint-anaelle.urbon
** File description:
** window
*/

#include "my.h"
sfRenderWindow *create_window(char *Title)
{
    sfVideoMode video = {WINDOW_SIZE_X, WINDOW_SIZE_Y, WINDOW_BPP};
    return (sfRenderWindow_create(video,  Title, sfResize | sfClose, NULL));
}
