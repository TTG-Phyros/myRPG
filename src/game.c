/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-baptiste.mery
** File description:
** game
*/

#include "../include/rpg.h"

int play(window *my_win) {


    sfEvent event;
    sfVideoMode mode = {1600, 900, 32};
    sfRenderWindow* window = my_win->win;

    // load the image from file
    sfImage *image = sfImage_createFromFile(zelda_map);
    sfImage *sheet = sfImage_createFromFile(sprite_sheet);
    sfImage *walls = sfImage_createFromFile(wall_map);
    sfImage* dialogue_image = sfImage_createFromFile("./content/random_music_wallpaper.jpg");
    sfImage* dialogue_image1 = sfImage_createFromFile("./content/random_music_wallpaper.jpg");//?make these the different dialogs
    sfImage* dialogue_image2 = sfImage_createFromFile("./content/random_music_wallpaper.jpg");

    // create a texture from the image
    sfTexture* texture = sfTexture_createFromImage(image, NULL);
    sfTexture* sheet_texture = sfTexture_createFromImage(sheet, NULL);
    sfTexture* dialogue_texture = sfTexture_createFromImage(dialogue_image, NULL);
    sfTexture* dialogue_texture1 = sfTexture_createFromImage(dialogue_image1, NULL);
    sfTexture* dialogue_texture2 = sfTexture_createFromImage(dialogue_image2, NULL);


    // create a sprite from the texture
    sfSprite* map = sfSprite_create();
    sfSprite_setTexture(map, texture, sfTrue);
    sfSprite* zelda = sfSprite_create();
    sfSprite_setTexture(zelda, sheet_texture, sfTrue);
    sfSprite* dragon = sfSprite_create();
    sfSprite_setTexture(dragon, sheet_texture, sfTrue);
    sfSprite* sword = sfSprite_create();
    sfSprite_setTexture(sword, sheet_texture, sfTrue);
    sfSprite* hammer = sfSprite_create();
    sfSprite_setTexture(hammer, sheet_texture, sfTrue);
    sfSprite* dialogue = sfSprite_create();
    sfSprite_setTexture(dialogue, dialogue_texture, sfTrue);


    // select the zelda you want
    int counter = 0;
    sfIntRect textureRect = { 1, 1, 16, 16 };
    sfSprite_setTextureRect(zelda, textureRect);
    sfIntRect textureRect1 = {191, 1, 33, 33 };
    sfSprite_setTextureRect(dragon, textureRect1);
    sfIntRect textureRect2 = { 238, 1, 8, 16 };
    sfSprite_setTextureRect(sword, textureRect2);
    sfIntRect textureRect3 = { 227, 1, 8, 16 };
    sfSprite_setTextureRect(hammer, textureRect3);

    // modify the size of zelda
    sfVector2f scale = { 0.8f, 0.8f };
    sfSprite_setScale(zelda, scale);

    //set positions of the items

    sfVector2f zelda_pos = {50.f, 440.f};
    sfVector2f sword_pos = {890.f, 920.f};
    sfVector2f hammer_pos = {1405.f, 245.f};
    sfVector2f dragon_pos = {1170.f, 240.f};
    sfSprite_setPosition(sword, sword_pos);
    sfSprite_setPosition(hammer, hammer_pos);
    sfSprite_setPosition(dragon, dragon_pos);

    // create a view with the same size as the window
    sfFloatRect view_rect = {50.f - (152.3961f * 1.6 / 2), 440.f - (100.f * 1.6 / 2), 152.3961f * 1.6, 100.f * 1.6};
    sfView* view = sfView_createFromRect(view_rect);


    sfClock* clock = sfClock_create();
    sfTime time = sfClock_getElapsedTime(clock);
    float temp_time = 0;
    sfColor temp_wall;
    int scroll = 0;
    int quest_counter = 0;
    int is_dialogue = 0;
    int dialogue_option = 0;

    while (sfRenderWindow_isOpen(window)) {
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
        }
        // handle keyboard input and animate the zelda
        counter++;
        sfVector2f movement = {0.f, 0.f};
        time = sfClock_getElapsedTime(clock);
        temp_time = sfTime_asSeconds(time) * 100; //? this is the speed
        sfClock_restart(clock);
        
        
        if (sfKeyboard_isKeyPressed(sfKeyRight)) {
            temp_wall = sfImage_getPixel(walls, zelda_pos.x + 20, zelda_pos.y + 13);
            if (temp_wall.g != 255) {
                movement.x += 1.f * temp_time;
                zelda_pos.x += 1.f * temp_time;
                if (counter % 100 < 50) {
                    textureRect.left = 77;
                } else {
                    textureRect.left = 96;
                }
            is_dialogue = 0;
            }
        }
        if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
            temp_wall = sfImage_getPixel(walls, zelda_pos.x - 5, zelda_pos.y + 13);
            if (temp_wall.g != 255) {
                movement.x -= 1.f * temp_time;
                zelda_pos.x -= 1.f * temp_time;
                if (counter % 100 < 50) {
                    textureRect.left = 115;
                } else {
                    textureRect.left = 134;
                }
            is_dialogue = 0;
            }
        }
        if (sfKeyboard_isKeyPressed(sfKeyDown)) {
            temp_wall = sfImage_getPixel(walls, zelda_pos.x + 8, zelda_pos.y + 25);
            if (temp_wall.g != 255) {
                movement.y += 1.f * temp_time;
                zelda_pos.y += 1.f * temp_time;
                if (counter % 100 < 50) {
                    textureRect.left = 1;
                } else {
                    textureRect.left = 20;
                }
            is_dialogue = 0;
            }
        }
        if (sfKeyboard_isKeyPressed(sfKeyUp)) {
            temp_wall = sfImage_getPixel(walls, zelda_pos.x + 8, zelda_pos.y);
            if (temp_wall.g != 255) {
                movement.y -= 1.f * temp_time;
                zelda_pos.y -= 1.f * temp_time;
                if (counter % 100 < 50) {
                    textureRect.left = 39;
                } else {
                    textureRect.left = 58;
                }
            is_dialogue = 0;
            }
        }

        if(sfKeyboard_isKeyPressed(sfKeySpace)) {
            temp_wall = sfImage_getPixel(walls, zelda_pos.x, zelda_pos.y);

            if (temp_wall.g == 1 && dialogue_option == 0){
                sfSprite_setPosition(dialogue, zelda_pos);
                is_dialogue++;
                temp_wall.g = 1;
            }
            if (temp_wall.g == 1 && dialogue_option == 1){
                sfSprite_setTexture(dialogue, dialogue_texture1, sfTrue);
                sfSprite_setPosition(dialogue, zelda_pos);
                is_dialogue++;
                temp_wall.g = 1;
            }
            if (temp_wall.g == 1 && dialogue_option == 2){
                sfSprite_setTexture(dialogue, dialogue_texture2, sfTrue);
                sfSprite_setPosition(dialogue, zelda_pos);
                is_dialogue++;
                temp_wall.g = 1;
            }
            // while (temp_wall.g != 254) {
            //     //? start conversation for quest
            //     sfRenderWindow_drawSprite(window, dialogue, NULL);
            //     quest_counter = 1;
            //     sfSleep(sfSeconds(1));
                
            //     if (quest_counter == 1 && sfKeyboard_isKeyPressed(sfKeySpace)) {
            //         sfRenderWindow_drawSprite(window, dialogue, NULL);
            //         sfSleep(sfSeconds(1));
            //         temp_wall.g = 253;
            //     }

            //     time = sfClock_getElapsedTime(clock);
            // }
        }

        while (sfRenderWindow_pollEvent(window, &event)) {

            if (event.type == sfEvtMouseWheelMoved) {
            
                if (event.mouseWheel.delta < 0)
                {
                    scroll = event.mouseWheel.delta;
                    sfView_zoom(view, 2.f);
                }
                if (event.mouseWheel.delta > 0)
                {
                    scroll = event.mouseWheel.delta;
                    sfView_zoom(view, 0.5f);
                }
            }
        }



        // move the view and zelda
        sfView_move(view, movement);
        sfSprite_setPosition(zelda, zelda_pos);
        sfSprite_setTextureRect(zelda, textureRect);



        // set the view to the window
        sfRenderWindow_setView(window, view);

        // draw the sprite to the screen
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, map, NULL);
        if (is_dialogue)
            sfRenderWindow_drawSprite(window, dialogue, NULL);
        sfRenderWindow_drawSprite(window, zelda, NULL);
        sfRenderWindow_drawSprite(window, hammer, NULL);
        sfRenderWindow_drawSprite(window, sword, NULL);
        sfRenderWindow_drawSprite(window, dragon, NULL);
        
        sfRenderWindow_display(window);

        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            break;
        }
    }
    // clean up resources
    sfSprite_destroy(map);
    sfTexture_destroy(texture);
    sfImage_destroy(image);
    sfView_destroy(view);
    sfRenderWindow_destroy(window);

    return 0;
}
