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
        #include <unistd.h>

    // ! MACROS
        #define IS_HOVERED(button) button->state == 1 ? sfTrue : sfFalse
        #define IS_PRESSED(button) button->state == 2 ? sfTrue : sfFalse
        #define IS_RELEASED(button) button->state == 3 ? sfTrue : sfFalse
        #define main_font "./content/main_font.otf"
        #define back_main "./content/zelda_main.png"
        #define settings_back "./content/settings_back.png"
        #define sprite_sheet "./content/spritesheet.png"
        #define zelda_map "./content/map_zelda.png"
        #define wall_map "./content/wall_map.png"
        #define Dialog_1 "./content/dialog/1Dialog.png"
        #define Dialog_2 "./content/dialog/2Dialog.png"
        #define Dialog_3 "./content/dialog/3Dialog.png"
        #define Dialog_4 "./content/dialog/4Dialog.png"
        #define Dialog_5 "./content/dialog/5Dialog.png"
        #define Dialog_6 "./content/dialog/6Dialog.png"
        #define Dialog_7 "./content/dialog/7Dialog.png"
        #define Dialog_Box "./content/dialog/Dialog_Box.png"
        #define fight_back "./content/fight_back.png"
        #define bcfight "./content/bcfight.png"
        #define roof_map "./content/roof.png"
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
        int width, height, framerate, volume, selected_res;
        char *title;
        sfBool fullscreen;
        sfVideoMode mode;
        sfRenderWindow *win;
        sfMusic *music;
    };

    typedef struct settings settings;
    struct settings {
        sfText **names;
        int volume, selected_res;
        char **resolutions;
        sfBool fullscreen;
        sfRectangleShape *check_box, *cross_o, *cross_t;
    };

    typedef struct button button;
    struct button {
        sfVector2f size, pos;
        int times_clicked;
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

    typedef struct animation animation;
    struct animation {
        sfVector2f position, scale;
        int *pos_ss, *size, *spacing, nb_frames;
        char *filepath_ss;
        sfSprite **animations;
        sfClock *clock;
    };

    typedef struct game_ressources game_ressources;
    struct game_ressources {
        sfSprite *dialog, *map, *zelda, *sword, *hammer, *dragon, *d_box;
        sfSprite *box, *key, *roof;
        sfTexture **d_textures;
        sfImage *wa;
        sfVector2f pos, movement, sword_inv, hammer_inv, box_inv, key_inv;
        sfVector2f s_pos, h_pos, dragon_pos, box_pos, key_pos;
        sfIntRect textureRect;
        sfView *game_view;
        sfClock *game_clock, *change_dialog_timer;
        sfBool has_sword, has_hammer, has_key, has_box;
        int counter, d_opt, is_dragon;
        float ti;
    };

    typedef struct fight_ressources fight_ressources;
    struct fight_ressources {
        sfSprite *back, *back_f, *sword, *monster, *link, *heart_o, *hearts_m;
        sfSprite *heart_tw, *heart_tr;
        sfClock *auto_damage, *cooldown;
        sfText *m_life;
        int hp_monster, hp_player;
        sfBool direction;
    };

    // ! Functions

    // * button.c
    button *c_button(sfVector2f *pos_scale, sfColor *colors,
    char *title, int char_size);
    sfBool is_clicked(button *my_button, window *my_window);
    sfBool is_hovered(button *but, window *my_window);
    void change_color(button *butt, window *my_win);
    void check_hover_and_click(button_group *group, window *my_win);

    // * button_group.c
    void draw_button_group(button_group *group, window *my_win);
    button_group *set_main_button_group(window *my_win);
    void fix_resize(button_group *group, window *my_win);
    int redirect_main_check_sec(int i, window *my_win);
    int redirect_main_check(button_group *group, window *my_win);

    // * main.c
    window *create_window(int width, int height, char *title, int framerate);
    void check_event(window *my_win, sfEvent event, button_group *group,
                    sfView *view);
    sfSprite *set_sprite(char *filepath, float pos[2][2]);
    int main_menu(window *my_win);
    int main(int ac, char **av);

    // * str_related.c
    int *len_words(char *str, char c, int *size);
    int my_strcmp(char *str_o, char *str_t);
    char **str_to_word_array(char *str, char c);
    char *my_strmerge(char *str1, char *str2);
    char *merge_int_str(char *str, int nb);

    // * more_str_related.c
    int my_strlen(char const *str);
    int my_intlen(int nb);
    int char_to_int(char *str);
    char *int_to_str(int nb);
    int my_putstr(char const *str);

    // * settings.c
    int settings_menu(window *my_win, settings *my_setts);

    // * settings_button_group.c
    button_group *set_settings_button_group(window *my_win);
    settings *settings_names(window *my_win);
    int settings_redirections(button_group *settings_group,
                            settings *my_setts, window *my_win);

    // * text_related.c
    sfText *main_text(window *my_win);
    sfText *settings_text(window *my_win);
    sfText *button_main_text(char *title, sfVector2f *pos_scale,
                            int char_size);
    sfText *button_settings_text(window *my_win, sfVector2f pos, char *title,
    int size);
    sfText *hp_monster_text(sfVector2f pos, int size);

    // * game.c
    int play(window *my_win);
    void cleanup(game_ressources *ress);
    int back_menu(window *my_win, game_ressources *game_ress);
    int start_fight(window *my_win, game_ressources *game_ress);

    // * movements.c
    int change_sprite(int judge, int ans_one, int ans_two);
    int y_movement(game_ressources *ress);
    int x_movements(game_ressources *ress);
    void change_dialog(game_ressources *ress);
    int check_fight(game_ressources *ress);

    // * game_ressources.c
    void load_more_textures(game_ressources *game_res, sfVector2f s_pos,
    sfVector2f h_pos, sfVector2f dragon_pos);
    void load_textures(game_ressources *game_ress, window *my_win);
    void draw_game(window *my_win, game_ressources *game_ress, int is_box);

    // *fight.c
    int the_fight(window *my_win);

    // * fight_ressources.c
    void load_fight_ressources(fight_ressources *fight_ress, window *w);
    int end_screen(sfBool win, window *my_win, fight_ressources *ress);

    // * game_sec.c
    int death_screen(window *w);
    int check_pickup(window *my_win, game_ressources *ress);
    int change_pos_inv(game_ressources *ress, window *my_win);

#endif
