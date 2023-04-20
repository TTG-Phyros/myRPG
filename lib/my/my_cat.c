/*
** EPITECH PROJECT, 2022
** cat.c
** File description:
** Day12
*/

#include "my.h"
int my_cat(char *av)
{
    struct stat s;
    int fd, size, size_buf;
    if (stat(av, &s) != -1)
        size_buf = s.st_size;
    char *buf = malloc(sizeof(char) * size_buf + 1);
    fd = open(av, O_RDONLY);
    if (fd == -1) {
        my_putstr("Error whith open\n");
        return (84);
    }
    size = read(fd, buf, size_buf);
    if (size <= 1)
        my_putstr("The read of size 1 is forbidden\n");
    else
        write(1, buf, size_buf);
    close(fd);
    return (0);
}
