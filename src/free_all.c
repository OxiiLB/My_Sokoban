/*
** EPITECH PROJECT, 2022
** free_all
** File description:
** free_all the mallocs
*/

#include "my.h"
#include "header.h"
#include <stdlib.h>
#include <unistd.h>

void free_all(char **array_2d, char *str, int nb_rows)
{
    for (int i = 0; i < nb_rows; i++) {
        free(array_2d[i]);
    }
    free(array_2d);
    free(str);
}

void free_all2(s_position_t *boxes, s_position_t *holes)
{
    free(holes);
    free(boxes);
}
