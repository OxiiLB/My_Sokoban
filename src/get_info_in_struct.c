/*
** EPITECH PROJECT, 2022
** get info in struct
** File description:
** get all the emplacement of the holes and box
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

static int check_h(s_array_2d_t *array, s_all_positions_t *positions,
int count_holes)
{
    if (array->array_2d[array->lines][array->cols] == 'O') {
        positions->holes[count_holes].start_x = array->cols;
        positions->holes[count_holes].start_y = array->lines;
        positions->holes[count_holes].x = array->cols;
        positions->holes[count_holes].y = array->lines;
        return 1;
    }
    return 0;
}

static int check_b(s_array_2d_t *array, s_all_positions_t *positions,
int count_boxes)
{
    if (array->array_2d[array->lines][array->cols] == 'X') {
        positions->boxes[count_boxes].start_x = array->cols;
        positions->boxes[count_boxes].start_y = array->lines;
        positions->boxes[count_boxes].x = array->cols;
        positions->boxes[count_boxes].y = array->lines;
        return 1;
    }
    return 0;
}

static int check_p(s_array_2d_t *array, s_all_positions_t *positions)
{
    if (array->array_2d[array->lines][array->cols] == 'P') {
        positions->player.start_x = array->cols;
        positions->player.start_y = array->lines;
        positions->player.x = array->cols;
        positions->player.y = array->lines;
        return 1;
    }
    return 0;
}

static void wrong_char(s_array_2d_t *array)
{
    if (array->array_2d[array->lines][array->cols] != ' ' &&
    array->array_2d[array->lines][array->cols] != '\n' &&
    array->array_2d[array->lines][array->cols] != '#' &&
    array->array_2d[array->lines][array->cols] != 'X' &&
    array->array_2d[array->lines][array->cols] != 'O' &&
    array->array_2d[array->lines][array->cols] != 'P') {
        write(2, "The map is false\n", 18);
        exit(84);
    }
}

void get_info_in_struct(s_all_positions_t *positions, s_array_2d_t *array)
{
    int count_boxes = 0;
    int count_holes = 0;
    int count_player = 0;
    for (int lines = 0; array->array_2d[lines] != NULL; lines += 1) {
        for (int cols = 0; array->array_2d[lines][cols] != '\n'; cols += 1) {
            array->cols = cols;
            array->lines = lines;
            wrong_char(array);
            count_player += check_p(array, positions);
            count_boxes += check_b(array, positions, count_boxes);
            count_holes += check_h(array, positions, count_holes);
        }
    }
    if (count_boxes != count_holes || count_player > 1) {
        write(2, "The map is false\n", 18);
        exit(84);
    }
}
