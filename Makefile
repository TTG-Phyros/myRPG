##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Compile the whole project
##

NAME		=		my_rpg

##CFLAGS		=		-W -Wall -Werror

SRC		=		my_hunter.c		\
				my_hunter2.c	\
				my_hunter3.c	\
				my_hunter4.c	\

OBJ		=		$(SRC:.c=.o)

CSFML	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

all:	$(OBJ)
		gcc  $(SRC) -o $(NAME) $(CSFML)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean all
