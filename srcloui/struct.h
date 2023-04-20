/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-minishell1-anaelle.urbon
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
    #include <SFML/Graphics.h>

    #define PANEAUX 2

    enum {HOVER, PRESSED, CLICKED};

    typedef struct button_t {
        sfVector2f size, xBox, pos;
        sfRectangleShape *forme;
        sfRectangleShape *test;
        sfColor color;
        sfText *text;
        int active;
        float text_size;
        int pressing;
    } button_s;

    typedef struct menu_t {
        sfVector2f size, pos;
        sfRectangleShape *forme;
        sfColor color;
    } menu_s;

    typedef struct all_t {
        sfRenderWindow *wdw;
        sfImage * image;
        sfTexture * texture;
        sfSprite * sprite;
        sfVector2f sprite_pos;
        menu_s *menu[PANEAUX - 1];
        button_s *but;
        button_s *but2;
        button_s *but3;
        button_s *but4;
        button_s *but5;
        sfColor pencil;
        int pencil_size;
        int pencil_shape;
    } all_s;

    all_s *init_all(void);
    void update_all(all_s *all);
    void display_all(all_s *all);
    void destroy_all(all_s *all);

    menu_s *init_menu(void);
    void display_menu(menu_s **menu);
    void destroy_menu(menu_s **menu);

    button_s *init_button(int x);
    void update_but(button_s *but);
    void destroy_but(button_s *but);

#endif /* !STRUCT_H_ */
