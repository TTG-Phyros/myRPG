/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** rpg
*/

#ifndef MY_RPG_H_
    #define MY_RPG_H_

    // * Includes
        #include <SFML/Window.h>
        #include <SFML/Graphics.h>
        #include <SFML/System.h>
        #include <SFML/Audio.h>
        #include <math.h>
        #include <stdlib.h>

    // ! MACROS
        #define IS_HOVERED(button) button->state == 1 ? sfTrue : sfFalse
        #define IS_PRESSED(button) button->state == 2 ? sfTrue : sfFalse
        #define IS_RELEASED(button) button->state == 3 ? sfTrue : sfFalse
        #define main_font "./content/main_font.otf"
        #define back_main "./content/zelda_main.png"
        #define sfOrange sfColor_fromRGB(255, 128, 0)
        #define sfGrey sfColor_fromRGB(100, 100, 100)
        #define sfLightGrey sfColor_fromRGB(160, 160, 160)
        #define sfDarkGrey sfColor_fromRGB(60, 60, 60)

    // ? Structures

    enum button_state {
        NONE = 0,
        HOVERED,
        PRESSED,
        RELEASED
    };

    typedef struct window window;
    struct window {
        int width, height, framerate;
        char *title;
        sfVideoMode mode;
        sfRenderWindow *win;
    };

    typedef struct button button;
    struct button {
        char *button_id;
        sfIntRect *hitbox;
        sfRectangleShape *shape;
        sfText *title;
        sfColor color, hover_color, click_color;
        sfBool (*is_clicked)(struct button *, window *);
        sfBool (*is_hover)(struct button *, window *);
        enum button_state state;
    };

    typedef struct button_group button_group;
    struct button_group {
        button **button_list;
    };

    // ! Functions

    // * button.c
    button *create_button(sfVector2f position, sfVector2f size,
    sfColor *colors, char *title);
    sfBool is_clicked(button *my_button, window *my_window);
    sfBool is_hovered(button *but, window *my_window);
    void change_color(button *butt, window *my_win);
    void check_hover_and_click(button_group *group, window *my_win);

    // * button_group.c
    void draw_button_group(button_group *group, window *my_win);
    button_group *set_main_button_group(window *my_win);

    // * main.c
    window *create_window(int width, int height, char *title, int framerate);
    void close_event(sfRenderWindow *window, sfEvent event);
    sfSprite *set_sprite(char *filepath, float pos[2][2]);
    void main_menu(window *my_win);
    void main(void);

    // * str_related.c
    int *len_words(char *str, char c, int *size);
    int my_strcmp(char *str_o, char *str_t);
    char **str_to_word_array(char *str, char c);
    char *my_strmerge(char *str1, char *str2);
    char *merge_int_str(char *str, int nb);

    // * more_str_related.c
    int my_strlen(char const *str);
    int my_intlen(int nb);

    // * text_related.c
    sfText *main_text(window *my_win);
    sfText *button_main_text(char *title, sfVector2f pos, sfVector2f size);

#endif
