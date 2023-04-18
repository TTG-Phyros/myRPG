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
						./src/play.c					\
						./src/fonction/my_putstr.c		\

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
