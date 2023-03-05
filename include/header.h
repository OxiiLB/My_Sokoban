/*
** EPITECH PROJECT, 2022
** header
** File description:
** header of the project
*/

#include <dirent.h>
#include "s_position.h"
#include "s_array_2d.h"
#include "s_all_positions.h"

#ifndef header_project
    #define header_project

    int my_popup(s_array_2d_t *array, s_all_positions_t *positions);
    int errors(char *filepath);
    char *get_map(char *filepath);
    char **put_str_in_2d_array(char *str, char **array_2d);
    int get_cols(char *str);
    int get_rows(char *str);
    void free_all(char **array_2d, char *str, int nb_rows);
    void free_all2(s_position_t *boxes, s_position_t *holes);
    char **mem_alloc_2d_array(int nb_rows, int nb_cols);
    void print_tab(char **tab);
    void get_info_in_struct(s_all_positions_t *positions,
    s_array_2d_t *array);
    void deplacement_up(s_all_positions_t *positions, s_array_2d_t *array);
    void deplacement_down(s_all_positions_t *positions, s_array_2d_t *array);
    void deplacement_left(s_all_positions_t *positions, s_array_2d_t *array);
    void deplacement_right(s_all_positions_t *positions, s_array_2d_t *array);
    void restart(s_all_positions_t *positions, s_array_2d_t *array);
    void get_infos(s_all_positions_t *positions, s_array_2d_t *array);
    void check_holes_2(s_all_positions_t *positions, s_array_2d_t *array,
    int i);
    void verify_win(s_array_2d_t *array, s_all_positions_t *positions);

#endif /* !header_project */
