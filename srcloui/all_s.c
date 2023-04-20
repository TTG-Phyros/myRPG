/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-mypaint-anaelle.urbon
** File description:
** all_s
*/

#include "my.h"

all_s *init_all(void)
{
    all_s *all = malloc(sizeof(all_s));
    return (all);
}

int hover_sprite(all_s * all)
{
    sfVector2i p = sfMouse_getPositionRenderWindow(all->wdw);
    if (p.x >= all->sprite_pos.x && p.x <= all->sprite_pos.x + SPRITE_SIZE_X - all->pencil_size)
        if (p.y >= all->sprite_pos.y && p.y <= all->sprite_pos.y + SPRITE_SIZE_Y - all->pencil_size)
            return 0;
    return 1;
}

void draw_diamond(all_s * all, sfVector2i position, int x, int y)
{
    int a = 1; int b = 0;
    int spaces = all->pencil_size / 2 + 1;
        while (spaces) {
            for (int j = 0; j < a; j++) {
                b = x + j + all->pencil_size / 2 + 1;
                sfImage_setPixel(all->image, y + all->pencil_size, b, all->pencil);
            }
            y--;
            spaces--;
            x--;
            a += 2;
        }
        while (0 < a) {
            for (int j = 0; j < a; j++) {
                sfImage_setPixel(all->image, y + all->pencil_size, x + j + all->pencil_size / 2 + 1, all->pencil);
            }
            y--;
            x++;
            spaces++;
            a -= 2;
    }
}

void sprite_handling(all_s * all)
{
    int x = 0, y = 0, z = 0;
    sfVector2i position = sfMouse_getPositionRenderWindow(all->wdw);
    if (all->pencil_shape == 1) {
        draw_diamond(all, position, position.y - all->sprite_pos.y,
        position.x - all->sprite_pos.x);
    }
    while (x != all->pencil_size && all->pencil_shape == 0) {
        while (y != all->pencil_size) {
            sfImage_setPixel(all->image, position.x - all->sprite_pos.x + x,
            position.y - all->sprite_pos.y + y, all->pencil);
            y++;
        }
        y = 0; x++;
    }
}

void update_all(all_s *all)
{
    
}

void display_all(all_s *all)
{
    sfRenderWindow_clear(all->wdw, sfBlack);
    all->texture = sfTexture_createFromImage(all->image, NULL);
    sfSprite_setTexture(all->sprite, all->texture, sfTrue);
    sfSprite_setPosition(all->sprite, all->sprite_pos);
    sfRenderWindow_drawSprite(all->wdw, all->sprite, NULL);
    sfRenderWindow_display(all->wdw);
}
