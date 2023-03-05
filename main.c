/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "my.h"
#include "s_position.h"
#include "s_array_2d.h"
#include "s_all_positions.h"
#include "header.h"
#include <stddef.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

static void flag_h(char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'h') {
        my_printf("USAGE\n      ./my_sokoban\nDESCRIPTION\n      map file \
representing the warehouse map, containing '#' for walls,\n          'P' \
for the player, 'X' for \
boxes and 'O' for srorage locations.");
        exit(0);
    }
}

int main(int argc, char **argv)
{
    s_all_positions_t positions;
    if (argv[1] == NULL || argc > 2) {
        write(2, "Invalid parameter, ./my_sokoban -h\n", 36);
        exit(84);
    }
    flag_h(argv);
    char *map = get_map(argv[1]);
    positions.boxes = malloc(sizeof(char) * my_strlen(map));
    positions.holes = malloc(sizeof(char) * my_strlen(map));
    int nb_rows = get_rows(map);
    int nb_cols = get_cols(map);
    char **array_2d = mem_alloc_2d_array(nb_rows, nb_cols);
    s_array_2d_t array = {array_2d, nb_rows, nb_cols};
    array_2d = put_str_in_2d_array(map, array_2d);
    get_info_in_struct(&positions, &array);
    my_popup(&array, &positions);
    free_all(array_2d, map, nb_rows);
    free_all2(positions.boxes, positions.holes);
    return 0;
}
