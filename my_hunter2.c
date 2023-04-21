/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** recreatethe famous game my hunter
*/

#include "include/my.h"

void draw_sprite1(sfRenderWindow *w, sfVector2f pos_duck, sfSprite *d1)
{
    sfSprite_setPosition (d1, pos_duck);
    sfRenderWindow_drawSprite(w, d1, NULL);
}

void draw_sprite2(sfRenderWindow *w, sfVector2f poss_swd, sfSprite *swd)
{
    sfSprite_setPosition (swd, poss_swd);
    sfRenderWindow_drawSprite(w, swd, NULL);
}

void draw_sprite3(sfRenderWindow *w, sfVector2f poss_mst, sfSprite *mst)
{
    sfSprite_setPosition (mst, poss_mst);
    sfRenderWindow_drawSprite(w, mst, NULL);
}

void draw_sprite4(sfRenderWindow *w, sfVector2f poss_link, sfSprite *link)
{
    sfSprite_setPosition (link, poss_link);
    sfRenderWindow_drawSprite(w, link, NULL);
}

void draw_sprite5(sfRenderWindow *w, sfVector2f poss_hearts, sfSprite *hearts)
{
    sfSprite_setPosition (hearts, poss_hearts);
    sfRenderWindow_drawSprite(w, hearts, NULL);
}

void draw_sprite6(sfRenderWindow *w, sfVector2f poss_hearts, sfSprite *hearts)
{
    sfSprite_setPosition (hearts, poss_hearts);
    sfRenderWindow_drawSprite(w, hearts, NULL);
}

int mv_sword(int pswd, int *i)
{
    if (pswd >= 1400)
        *i = 1;
    if (pswd <= 430)
        *i = 0;
    if (*i == 0){
        pswd += 20;
        return pswd;
    }
    if (*i == 1){
        pswd -= 20;
        return pswd;
    }
    return pswd;
}

int damage(int pswd, int dmg)
{
    if (pswd <= 516 || pswd >= 1290)
        return dmg = -1;
    if (pswd <= 708 || pswd >= 1110)
        return dmg = 1;
    if (pswd <= 867 || pswd >= 968)
        return dmg = 2;
    if (pswd >= 867 && pswd <= 968)
        return dmg = 3;
    else 
        return dmg = 4;
}

int my_intlen(int nb)
{
    int i = 0;
    if (nb >= 0) i++;
    while (nb > 0)
        nb /= 10, i++;
    return i - 1;
}

char *int_to_str(int nb)
{
    if (nb == 0) return "0";
    int i = 0, int_l = my_intlen(nb);
    int diviseur = 1;
    char *ans = malloc((int_l + 1) * sizeof(char));
    while (my_intlen(diviseur) < int_l)
        diviseur *= 10;
    for (int num = 0, j = 0; j != int_l; i++, j++) {
        num = nb / diviseur;
        ans[i] = (num + '0');
        nb -= num * diviseur;
        diviseur /= 10;
    }
    ans[i] = '\0';
    return ans;
}

void the_game(sfRenderWindow *window, sfEvent event, sfSprite *wall)
{
    int pswd = 431, i = 0, dmg = 0, hp_n = 70, hp_p = 3; sfSprite *bs_fig = bc_figh();
    sfSprite *swd = sword(); sfSprite *mst = monstre(); sfSprite *link = links();
    sfSprite *hearts = heart(); sfSprite *hearts_n = heart_n(); char* hp_mst = "70";
    sfText *hp_of_monst = hp_monst(window, hp_mst);
    while (sfRenderWindow_isOpen(window)) {
        pswd = mv_sword(pswd, &i);
        if (pswd > 1600) pswd = 430;
        sfVector2f poss_bcf = {1920 / 2 - 1090 / 2, 700};
        sfVector2f poss_sword = {pswd, 820};
        sfVector2f poss_mst = {1300, 250};
        sfVector2f poss_link = {350, 500};
        sfVector2f poss_hearts = {10, 10};
        sfVector2f poss_hearts_n = {1680, 10};
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (sfKeyboard_isKeyPressed(sfKeySpace)){
                dmg = damage(pswd, dmg);
                hp_n = hp_n - dmg;
                printf("%d = hp enemie et hp player = %d\n", hp_n, hp_p);
                }
            }
            if (dmg == -1){
                hp_p--;
                dmg = 0;
            }
            if (hp_p <= 0)
                return;
            if (hp_n <= 0)
                return;
        sfRenderWindow_drawSprite(window, wall, NULL);
        draw_sprite1(window, poss_bcf, bs_fig);
        draw_sprite2(window, poss_sword, swd);
        draw_sprite3(window, poss_mst, mst);
        draw_sprite4(window, poss_link, link);
        draw_sprite5(window, poss_hearts, hearts);
        poss_hearts.x = 150;
        if (hp_p >= 2)
            draw_sprite5(window, poss_hearts, hearts);
        poss_hearts.x = 290;
        if (hp_p >= 3)
            draw_sprite5(window, poss_hearts, hearts);
        draw_sprite6(window, poss_hearts_n, hearts_n);
        hp_mst = int_to_str(hp_n);
        sfText_setString(hp_of_monst, hp_mst);
        sfRenderWindow_drawText(window, hp_of_monst, NULL);
        sfRenderWindow_display(window);
    }
}
