/*
** EPITECH PROJECT, 2022
** print_map.c
** File description:
** print the map in char ** in the terminal
*/

#include <my.h>
#include <unistd.h>

void print_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i += 1) {
        my_printf("%s", tab[i]);
    }
}
