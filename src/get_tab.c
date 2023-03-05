/*
** EPITECH PROJECT, 2022
** get_tab
** File description:
** get all the tab (char * and char **)
*/

#include "my.h"
#include "header.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

char *get_map(char *filepath)
{
    int fd;
    struct stat s;
    fd = open(filepath, O_RDONLY);
    stat(filepath, &s);
    errors(filepath);
    int size = s.st_size;
    char *buffer = malloc(sizeof(char) * (size + 1));
    buffer[size] = '\0';
    read(fd, buffer, size);
    if (buffer[0] == '\0') {
        write(2, "Error with the map\n", 20);
        exit (84);
    }
    close(fd);
    return buffer;
}

char **put_str_in_2d_array(char *str, char **array_2d)
{
    int count = 0;
    int x = 0;
    for (int y = 0; str[count] != '\0' ; y += 1) {
        x = 0;
        while (str[count] != '\n') {
            array_2d[y][x] = str[count];
            count += 1;
            x += 1;
        }
        array_2d[y][x] = '\n';
        count += 1;
    }
    return array_2d;
}
