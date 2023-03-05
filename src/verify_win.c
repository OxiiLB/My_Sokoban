/*
** EPITECH PROJECT, 2022
** verify_win
** File description:
** verify if the boxes and the holes are on the same place
*/
#include "my.h"
#include "s_array_2d.h"
#include "s_all_positions.h"
#include "header.h"
#include <stdlib.h>
#include <unistd.h>

void verify_win(s_array_2d_t *array, s_all_positions_t *positions)
{
    int count = 0;
    for (int i = 0; positions->holes[i].start_x != 0; i += 1) {
        if (array->array_2d[positions->holes[i].y][positions->holes[i].x] ==
        'X') {
            count += 1;
        }
    }
    if (count == 3) {
        usleep(2000000);
        write(1, "Félicitation, tu as gagné\n", 29);
        exit(0);
    }
}
