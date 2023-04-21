/*
** EPITECH PROJECT, 2022
** my_h
** File description:
** I don't know what it does
*/

#ifndef MY
    #define MY
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System/Clock.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>

    #define sfOrange sfColor_fromRGB(255, 128, 0)
    #define sfGrey sfColor_fromRGB(100, 100, 100)
    #define sfLightGrey sfColor_fromRGB(160, 160, 160)
    #define sfDarkGrey sfColor_fromRGB(60, 60, 60)
    int main(int argc, char **argv);
    void the_game(sfRenderWindow *window, sfEvent event, sfSprite *wall);
    void click(sfRenderWindow *window, sfEvent event, sfSprite *wall);
    void game(sfRenderWindow *windo, sfEvent event, sfSprite *but, sfSprite *w);
    void button_pres(sfRenderWindow *window, sfEvent event, sfSprite *wall);
    int poss(int b);
    void cl_windo(sfEvent event, sfRenderWindow *window ,sfSprite *wall);
    int click_d(sfRenderWindow *window, int a, sfVector2f pos);
    void draw_sprite1(sfRenderWindow *w, sfVector2f pos_duck, sfSprite *d1);
    void draw_sprite2(sfRenderWindow *w, sfVector2f poss_swd, sfSprite *swd);
    void draw_sprite3(sfRenderWindow *w, sfVector2f poss_mst, sfSprite *mst);
    void draw_sprite4(sfRenderWindow *w, sfVector2f poss_link, sfSprite *link);
    void draw_sprite5(sfRenderWindow *w, sfVector2f poss_hearts, sfSprite *hearts);
    void draw_sprite6(sfRenderWindow *w, sfVector2f poss_hearts, sfSprite *hearts);
    int mv_sword(int pswd, int *i);
    char *int_to_str(int nb);
    int my_intlen(int nb);
    sfSprite* bc_figh(void);
    sfSprite* sword(void);
    sfSprite* monstre(void);
    sfSprite* links(void);
    sfSprite* heart(void);
    sfSprite* heart_n(void);
    sfText* hp_monst(sfRenderWindow *window, char *hp_mst);
#endif
