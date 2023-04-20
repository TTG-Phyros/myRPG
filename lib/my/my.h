/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** no warning
*/

#ifndef __MY_H__
    #define __MY_H__
    #include <unistd.h>
    #include <stdio.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <stdbool.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <time.h>
    #include "struct.h"

    /* converter_long.c */
    char *exa_long(unsigned long int nb, int base, int maj);
    char *converter_long(unsigned long nb, int base, int maj);
    /* converter.c */
    char *checkhastag(char *tab, char *str, int maj);
    int majletters(int maj);
    char *exa(unsigned int nb, int base, int maj);
    char *converter(unsigned int nb, int base, int maj, char *tab);
    int converter_int(int nb, int base, int maj);
    /* default.c */
    int defaultswitch(struct Dataf *data);
    /* flag.c */
    void backslash(int dual);
    char majs(const char *str);
    char *add0(char *str);
    int exa_adress(long unsigned int point);
    int flagn(int *a, int counter);
    /* format.c*/
    int getnbr(struct Dataf *data, int *j);
    int jumpspace(struct Dataf *data);
    int checkformat(struct Dataf *data);
    int checkformat_2(struct Dataf *data, int j);
    /* my_cat.c */
    int my_cat(char *av);
    /* my_compute_power_rec.c */
    int my_compute_power_rec(int nb, int p);
    /* my_dice.c */
    int *my_dice(int nb, int dice);
    /* my_getnbr.c */
    int my_getnbr(char *str);
    /* my_nbrlen.c */
    int my_nbrlen(int n);
    int my_unnbrlen(unsigned int n);
    int my_longnbrlen(long n);
    int my_unlongnbrlen(unsigned long n);
    /* my_printf.c */
    int checkiflong(struct Dataf *data, va_list *ap);
    int condition(struct Dataf *data , va_list *ap);
    int my_printf(const char *format, ...);
    /* my_putchar.c */
    void my_putchar(char c);
    /* my_putfloat.c */
    int my_putfloat(double nb, int dec);
    char my_putfloat_exa(double nb, int dec, int maj);
    int put_i(int i, int len);
    int nota_scient(double nb, int dec);
    /* my_putnbr.c */
    int my_putnbr(int nb);
    int my_putunnbr(unsigned int nb);
    int my_putlongnbr(long nb);
    int my_putunlongnbr(unsigned long nb);
    /* my_putstr.c */
    void my_putstr(char const *str);
    /* my_puttbl.c */
    void my_puttbl(char **tbl);
    /* my_revstr.c */
    char *my_revstr(char *str);
    /* my_str_to_word_array.c */
    int verifymemory1(char const *str, char const mark);
    int verifymemory2(char const *str, int loc);
    char **my_str_to_word_array(char const *str, char const mark);
    /* my_strcat.c */
    char *my_strcat(char const *dest, char const *src);
    /* my_strcmp.c */
    bool my_strcmp(char const *str1, char const *str2);
    bool my_strncmp(char const *str1, char const *str2, int nbr);
    /* my_strcpy.c */
    char *my_strcpy(char *str, char *copy);
    char **my_tblcpy(char **tbl, char **copy);
    /* my_strlen.c */
    int my_strlen(char const *str);
    int my_tbllen(char **tbl);
    /* space.c */
    int pos(int nb, char *tab);
    int verifneg(char *tab);
    char if0(char *tab, int check);
    int posspace(char *tab, int nbrlen, int check);
    int negspace(char *tab, int nbrlen);
    /* switch_flag.c */
    int modulo_type4(struct Dataf *data, va_list *ap, char *tab);
    int modulo_type3(struct Dataf *data, va_list *ap);
    int modulo_type2(struct Dataf *data, va_list *ap);
    int modulo_type(struct Dataf *data, va_list *ap);
    /* switch_long_flag.c */
    int modulo_type4_l(struct Dataf *data, va_list *ap);
    int modulo_type3_l(struct Dataf *data, va_list *ap);
    int modulo_type2_l(struct Dataf *data, va_list *ap);
    int modulo_type_l(struct Dataf *data, va_list *ap);
    /* usage.c */
    void usage(int ac, char **av, char *txt);

#endif /* __MY_H__ */
