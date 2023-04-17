/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** str_related
*/

#include "../include/rpg.h"

int *len_words(char *str, char c, int *size)
{
    if (!str[0])
        return 0;
    int word_count = 1, space = 1, word = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == c && space == 0)
            word_count++, space = 1;
        if (str[i] != c)
            space = 0;
    }
    if (space == 1)
        word_count--;
    int *lens = malloc((word_count + 1) * sizeof(int)), lenth = 0, h = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == c && word == 1)
            lens[h] = lenth, lenth = 0, h++, word = 0;
        if (str[i] != c)
            lenth++, word = 1;
    }
    lens[h] = lenth, *size = word_count;
    return lens;
}

int my_strcmp(char *str_o, char *str_t)
{
    if (!str_o || !str_t)
        return -1;
    int i = 0;
    for (; str_o[i] && str_t[i] && str_o[i] == str_t[i]; i++)
        ;
    if (i == my_strlen(str_o) && my_strlen(str_o) == my_strlen(str_t))
        return 0;
    return 1;
}

char **str_to_word_array(char *str, char c)
{
    if (str == NULL)
        return NULL;
    if (my_strcmp(str, "\0") == 0)
        return NULL;
    int size;
    int *lens = len_words(str, c, &size);
    char **map = malloc((size + 1) * sizeof(char *));
    int i = 0, j = 0;
    for (int h = 0; i < size; i++) {
        for (; str[j] && str[j] == c; j++)
            ;
        map[i] = malloc((lens[i] + 1) * sizeof(char));
        for (h = 0; str[j] && str[j] != c; j++, h++)
            map[i][h] = str[j];
        map[i][h] = '\0';
    }
    map[i] = NULL;
    free(lens);
    return map;
}

char *my_strmerge(char *str1, char *str2)
{
    int size_o = my_strlen(str1), size = size_o + my_strlen(str2);
    char *answer = malloc((size + 1) * sizeof(char));
    int i = 0;
    for (; i <= size_o; i++)
        answer[i] = str1[i];
    i--;
    for (int j = 0; i < size; i++, j++)
        answer[i] = str2[j];
    answer[i] = '\0';
    return answer;
}

char *merge_int_str(char *str, int nb)
{
    int str_l = my_strlen(str), i = 0, int_l = my_intlen(nb), num = 0;
    char *dest = malloc(str_l + int_l + 1);
    int diviseur = 1;
    while (my_intlen(diviseur) < int_l)
        diviseur *= 10;
    for (; i != str_l; i++)
        dest[i] = str[i];
    for (int j = 0; j != int_l; i++, j++, diviseur /= 10) {
        if (diviseur < 10)
            num = nb;
        else
            num = nb / diviseur;
        dest[i] = (num + '0'), nb -= (nb / diviseur) * diviseur;
    }
    dest[i] = '\0';
    return dest;
}
