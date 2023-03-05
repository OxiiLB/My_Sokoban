/*
** EPITECH PROJECT, 2022
** mem_alloc_2d_array
** File description:
** allocate a space for a 2d array
*/

#include "my.h"
#include "header.h"
#include <stdlib.h>
#include <unistd.h>

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **array_2d;
    int count_rows = 0;
    int count_cols = 0;

    array_2d = malloc(sizeof(char *) * (nb_rows + 1));
    array_2d[nb_rows] = NULL;
    while (count_rows < nb_rows) {
        array_2d[count_rows] = malloc(sizeof(char) * nb_cols + 1);
        while (count_cols < nb_cols) {
            count_cols = count_cols + 1;
        }
        count_rows = count_rows + 1;
        count_cols = 0;
    }
    return array_2d;
}
