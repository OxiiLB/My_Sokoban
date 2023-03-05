/*
** EPITECH PROJECT, 2022
** s_all_positions
** File description:
** stock all positions
*/

#include "s_position.h"

#ifndef s_all_positions
    #define s_all_positions

    typedef struct s_all_positions {
        s_position_t player;
        s_position_t *boxes;
        s_position_t *holes;
    }s_all_positions_t;

#endif /* !s_all_positions */
