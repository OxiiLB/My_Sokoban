/*
** EPITECH PROJECT, 2022
** my_popup
** File description:
** display the game
*/

#include "my.h"
#include "s_array_2d.h"
#include "header.h"
#include <curses.h>
#include <stdlib.h>
#include <dirent.h>

static void check_enlarge(s_array_2d_t *array, WINDOW *win, int ch)
{
    while (COLS <= array->cols || LINES <= array->lines) {
        wclear(win);
        waddstr(win, "enlarge");
        ch = getch();
    }
}

static void display_str_centered(s_array_2d_t *array, WINDOW *win)
{
    for (int i = 0; i <= array->lines; i += 1) {
        mvwaddstr(win, ((LINES / 2) + i) - (array->lines / 2),
        (COLS / 2) - (array->cols / 2), array->array_2d[i]);
    }
}

static void deplacement(s_array_2d_t *array, s_all_positions_t *positions,
int ch)
{
    if (ch == KEY_UP)
        deplacement_up(positions, array);
    if (ch == KEY_DOWN)
        deplacement_down(positions, array);
    if (ch == KEY_LEFT)
        deplacement_left(positions, array);
    if (ch == KEY_RIGHT)
        deplacement_right(positions, array);
}

static void check_holes(s_array_2d_t *array, s_all_positions_t *positions)
{
    for (int i = 0; positions->holes[i].start_x != 0; i += 1) {
        for (int j = 0; positions->boxes[j].start_x != 0; j += 1){
            check_holes_2(positions, array, i);
        }
    }
}

int my_popup(s_array_2d_t *array, s_all_positions_t *positions)
{
    int ch = 'a';
    WINDOW * win = initscr();
    keypad(win, true);
    while (ch != 'q') {
        check_enlarge(array, win, ch);
        wclear(win);
        verify_win(array, positions);
        deplacement(array, positions, ch);
        get_infos(positions, array);
        check_holes(array, positions);
        display_str_centered(array, win);
        wrefresh(win);
        ch = getch();
    }
    refresh();
    endwin();
    return 0;
}
