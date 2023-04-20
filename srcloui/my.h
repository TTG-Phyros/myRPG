/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-bsminishell1-anaelle.urbon
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System/Clock.h>
    #include <SFML/Graphics/Text.h>
    #include "../lib/my/my.h"
    #include "struct.h"

    #define WINDOW_SIZE_X 1500.0000
    #define WINDOW_SIZE_Y 800.0000
    #define BUTTON_SIZE_X 50.0000
    #define BUTTON_SIZE_Y 50.0000
    #define TEXT_SIZE 12.0000
    #define WINDOW_BPP 60
    #define SPRITE_SIZE_X 400.0000
    #define SPRITE_SIZE_Y 400.0000

    sfRenderWindow *create_window(char *Title);
    void conditions_event(sfEvent event, all_s *all);
    void button_handling(all_s * all);

#endif /* !MY_H_ */
