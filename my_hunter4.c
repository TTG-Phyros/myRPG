/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** create the game duck hunt
*/

#include "include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(const char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return i;
}

int description_of_game(char **argv)
{
    if (argv[1][1] == 'h')
        my_putstr("\n---My_Hunter---\n\n");
        my_putstr("In this game you have to click on the ducks ");
        my_putstr("that are flying.\n");
        my_putstr("If you miss they will go up or down.\n");
        my_putstr("If three ducks manage to escape it is game over.\n\n");
        my_putstr("---Imput---\n\n");
        my_putstr("The left click of the mouse\n\n");
}

void game(sfRenderWindow *windo, sfEvent event, sfSprite *but, sfSprite *w)
{
    while (sfRenderWindow_pollEvent(windo, &event))
        cl_windo(event, windo, w);
    sfRenderWindow_clear(windo, sfWhite);
    sfRenderWindow_drawSprite(windo, w, NULL);
    sfRenderWindow_drawSprite(windo, but, NULL);
    sfRenderWindow_display(windo);
}

int main(int argc, char **argv)
{
    sfRenderWindow* windo; sfVideoMode v_mode = {1920, 1080, 32}; sfEvent event;
    sfTexture *texture = sfTexture_createFromFile("./img/walpaper.png", NULL);
    sfSprite *wall = sfSprite_create(); sfVector2f scale = {3, 3};
    sfSprite_setTexture(wall, texture, sfTrue); sfSprite_setScale(wall, scale);
    sfTexture *texture2 = sfTexture_createFromFile("./img/button.png", NULL);
    sfSprite *button = sfSprite_create(); sfVector2f scale_but = {0.2, 0.2};
    sfSprite_setTexture(button, texture2, sfTrue);
    sfSprite_setScale(button, scale_but); sfVector2f pos_button = {850, 500};
    sfSprite_setPosition(button, pos_button);
    sfVector2f pos_wall = {-10, -150};
    sfSprite_setPosition(wall, pos_wall);
    windo = sfRenderWindow_create(v_mode, "my_hunter", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(windo, 60);
    if (argc == 2) {
        description_of_game(argv);
    }else{
        while (sfRenderWindow_isOpen(windo))
            game(windo, event, button, wall);
    }
    return 0;
}
