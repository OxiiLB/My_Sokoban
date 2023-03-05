/*
** EPITECH PROJECT, 2022
** deplacements
** File description:
** functions that can moove the player and boxes
*/

#include "my.h"
#include "s_array_2d.h"
#include "header.h"
#include <curses.h>
#include <stdlib.h>
#include <dirent.h>

void deplacement_up(s_all_positions_t *positions, s_array_2d_t *array)
{
    char player_up =
    array->array_2d[positions->player.y - 1][positions->player.x];
    if (player_up == ' ' || player_up == 'O') {
        array->array_2d[positions->player.y - 1][positions->player.x] = 'P';
        array->array_2d[positions->player.y][positions->player.x] = ' ';
        positions->player.y -= 1;
    } else if (player_up == 'X' &&
    (array->array_2d[positions->player.y - 2][positions->player.x] == 'O' ||
    array->array_2d[positions->player.y - 2][positions->player.x] == ' ')) {
        array->array_2d[positions->player.y - 2][positions->player.x] = 'X';
        array->array_2d[positions->player.y - 1][positions->player.x] = 'P';
        array->array_2d[positions->player.y][positions->player.x] = ' ';
        positions->player.y -= 1;
    }
}

void deplacement_down(s_all_positions_t *positions, s_array_2d_t *array)
{
    char player_down =
    array->array_2d[positions->player.y + 1][positions->player.x];
    if (player_down == ' ' || player_down == 'O') {
        array->array_2d[positions->player.y + 1][positions->player.x] = 'P';
        array->array_2d[positions->player.y][positions->player.x] = ' ';
        positions->player.y += 1;
    } else if (player_down == 'X' &&
    (array->array_2d[positions->player.y + 2][positions->player.x] == 'O' ||
    array->array_2d[positions->player.y + 2][positions->player.x] == ' ')) {
        array->array_2d[positions->player.y + 2][positions->player.x] = 'X';
        array->array_2d[positions->player.y + 1][positions->player.x] = 'P';
        array->array_2d[positions->player.y][positions->player.x] = ' ';
        positions->player.y += 1;
    }
}

void deplacement_left(s_all_positions_t *positions, s_array_2d_t *array)
{

    char player_left =
    array->array_2d[positions->player.y][positions->player.x - 1];
    if (player_left == ' ' || player_left == 'O') {
        array->array_2d[positions->player.y][positions->player.x - 1] = 'P';
        array->array_2d[positions->player.y][positions->player.x] = ' ';
        positions->player.x -= 1;
    } else if (player_left == 'X' &&
    (array->array_2d[positions->player.y][positions->player.x - 2] == 'O' ||
    array->array_2d[positions->player.y][positions->player.x - 2] == ' ')) {
        array->array_2d[positions->player.y][positions->player.x - 2] = 'X';
        array->array_2d[positions->player.y][positions->player.x - 1] = 'P';
        array->array_2d[positions->player.y][positions->player.x] = ' ';
        positions->player.x -= 1;
    }
}

void deplacement_right(s_all_positions_t *positions, s_array_2d_t *array)
{
    char player_right =
    array->array_2d[positions->player.y][positions->player.x + 1];
    if (player_right == ' ' || player_right == 'O') {
        array->array_2d[positions->player.y][positions->player.x + 1] = 'P';
        array->array_2d[positions->player.y][positions->player.x] = ' ';
        positions->player.x += 1;
    } else if (player_right == 'X' &&
    (array->array_2d[positions->player.y][positions->player.x + 2] == 'O' ||
    array->array_2d[positions->player.y][positions->player.x + 2] == ' ')) {
        array->array_2d[positions->player.y][positions->player.x + 2] = 'X';
        array->array_2d[positions->player.y][positions->player.x + 1] = 'P';
        array->array_2d[positions->player.y][positions->player.x] = ' ';
        positions->player.x += 1;
    }
}
