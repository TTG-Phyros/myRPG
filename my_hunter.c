/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** recreat the game dunk hunt
*/

#include "include/my.h"

sfSprite* bc_figh(void)
{
    sfVector2f scale_duck = {1, 1};
    sfTexture *texture3 = sfTexture_createFromFile("./img/bcfight.png", NULL);
    sfSprite *duck1 = sfSprite_create();
    sfSprite_setTexture(duck1, texture3, sfTrue);
    sfSprite_setScale(duck1, scale_duck);
    return duck1;
}

sfSprite* sword(void)
{
    sfVector2f scale_duck = {11, 11};
    int const ss[2][2] = {{238, 1}, {8, 16}};
    sfIntRect * rect = malloc (sizeof(sfIntRect));
    rect->left = ss[0][0];
    rect->top = ss[0][1];
    rect->width = ss[1][0];
    rect->height = ss[1][1];
    sfTexture *texture2 = sfTexture_createFromFile("./img/spriteshit.png", rect);
    sfSprite *duck1 = sfSprite_create();
    sfSprite_setTexture(duck1, texture2, sfTrue);
    sfSprite_setScale(duck1, scale_duck);
    return duck1;
}

sfSprite* monstre(void)
{
    sfVector2f scale_duck = {14, 14};
    int const ss[2][2] = {{191, 1}, {33, 33}};
    sfIntRect * rect = malloc (sizeof(sfIntRect));
    rect->left = ss[0][0];
    rect->top = ss[0][1];
    rect->width = ss[1][0];
    rect->height = ss[1][1];
    sfTexture *texture2 = sfTexture_createFromFile("./img/spriteshit.png", rect);
    sfSprite *duck1 = sfSprite_create();
    sfSprite_setTexture(duck1, texture2, sfTrue);
    sfSprite_setScale(duck1, scale_duck);
    return duck1;
}

sfSprite* links(void)
{
    sfVector2f scale_duck = {10, 10};
    int const ss[2][2] = {{77, 1}, {16, 16}};
    sfIntRect * rect = malloc (sizeof(sfIntRect));
    rect->left = ss[0][0];
    rect->top = ss[0][1];
    rect->width = ss[1][0];
    rect->height = ss[1][1];
    sfTexture *texture2 = sfTexture_createFromFile("./img/spriteshit.png", rect);
    sfSprite *duck1 = sfSprite_create();
    sfSprite_setTexture(duck1, texture2, sfTrue);
    sfSprite_setScale(duck1, scale_duck);
    return duck1;
}

sfSprite* heart(void)
{
    sfVector2f scale_duck = {10, 10};
    int const ss[2][2] = {{153, 1}, {15, 15}};
    sfIntRect * rect = malloc (sizeof(sfIntRect));
    rect->left = ss[0][0];
    rect->top = ss[0][1];
    rect->width = ss[1][0];
    rect->height = ss[1][1];
    sfTexture *texture2 = sfTexture_createFromFile("./img/spriteshit.png", rect);
    sfSprite *duck1 = sfSprite_create();
    sfSprite_setTexture(duck1, texture2, sfTrue);
    sfSprite_setScale(duck1, scale_duck);
    return duck1;
}

sfSprite* heart_n(void)
{
    sfVector2f scale_duck = {16, 16};
    int const ss[2][2] = {{153, 1}, {15, 15}};
    sfIntRect * rect = malloc (sizeof(sfIntRect));
    rect->left = ss[0][0];
    rect->top = ss[0][1];
    rect->width = ss[1][0];
    rect->height = ss[1][1];
    sfTexture *texture2 = sfTexture_createFromFile("./img/spriteshit.png", rect);
    sfSprite *duck1 = sfSprite_create();
    sfSprite_setTexture(duck1, texture2, sfTrue);
    sfSprite_setScale(duck1, scale_duck);
    return duck1;
}

sfText* hp_monst(sfRenderWindow *window, char* hp_mst)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("./img/main_font.otf");
    sfText_setFont(text, font);
    sfText_setString(text, hp_mst);
    sfText_setCharacterSize(text, 90);
    sfText_setColor(text, sfGrey);
    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, 4);
    sfFloatRect rect = sfText_getGlobalBounds(text);
    sfVector2f pos = {1745, 60};
    sfText_setPosition(text, pos);
    return text;
}
