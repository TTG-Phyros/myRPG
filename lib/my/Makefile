##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for lib
##

SRC =	my_printf.c\
		my_putchar.c\
		my_putnbr.c\
		my_putstr.c\
		my_puttbl.c\
		my_revstr.c\
		my_strlen.c\
		my_strcpy.c\
		switch_flag.c\
		my_nbrlen.c\
		converter.c\
		flag.c\
		switch_long_flag.c\
		converter_long.c\
		my_putfloat.c\
		my_compute_power_rec.c\
		format.c\
		default.c\
		space.c\
		my_getnbr.c\
		my_str_to_word_array.c\
		my_strcmp.c\
		my_cat.c\
		my_dice.c\

FILE = *.c

OBJ = $(FILE: .c = .o)

NAME = libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	gcc -c $(FILE) -I.
	ar rc $(NAME) *.o

clean:
	rm -f *.o
	rm -f *~

fclean : clean
	rm -f $(NAME)

re: fclean 	all
