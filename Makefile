##
## EPITECH PROJECT, 2023
## RPG
## File description:
## Makefile
##

NAME			=				my_rpg

SRC				=		./src/main.c					\
						./src/button.c					\
						./src/main_button_group.c		\
						./src/settings_button_group.c	\
						./src/more_str_related.c		\
						./src/str_related.c				\
						./src/text_related.c			\
						./src/settings.c				\
						./src/particle.c				\
						./src/game.c					\
						./src/movements.c				\
						./src/game_ressources.c			\
						./src/fight.c					\
						./src/fight_ressources.c		\
						./src/game_sec.c				\
						./src/game_menu.c				\
						./src/skilltree.c 				\
						./src/skillpoint.c				\
						./src/skillpoint_sec.c 			\
						./src/draw_skill.c 				\

OBJ				=				$(SRC:.c=.o)

CSFML	=		-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

MATH 	=		-lm

all:	$(OBJ)
		gcc $(OBJ) -o $(NAME) $(CFLAGS) $(CSFML) $(MATH) -g3

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean all 
	rm -f $(OBJ)

