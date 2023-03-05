/*
** EPITECH PROJECT, 2022
** get infos
** File description:
** get all the emplacement of the boxes
*/

#include "my.h"
#include "s_position.h"
#include "s_all_positions.h"
#include "s_array_2d.h"
#include "header.h"
#include <stddef.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

void check_holes_2(s_all_positions_t *positions, s_array_2d_t *array, int i)
{
    if (array->array_2d[positions->holes[i].y][positions->holes[i].x]
    == ' ') {
        array->array_2d[positions->holes[i].y][positions->holes[i].x] =
        'O';
    }
}

static int check_b(s_array_2d_t *array, s_all_positions_t *positions,
int count_boxes, s_position_t *x_and_y)
{
    if (array->array_2d[x_and_y->x][x_and_y->y] == 'X') {
        positions->boxes[count_boxes].x = x_and_y->x;
        positions->boxes[count_boxes].y = x_and_y->y;
        return 1;
    }
    return 0;
}

void get_infos(s_all_positions_t *positions, s_array_2d_t *array)
{
    int count_boxes = 0;
    for (int lines = 0; lines < array->lines; lines += 1) {
        for (int cols = 0; cols < array->cols; cols += 1) {
            s_position_t x_and_y = {0, 0, lines, cols};
            count_boxes += check_b(array, positions, count_boxes, &x_and_y);
        }
    }
}
