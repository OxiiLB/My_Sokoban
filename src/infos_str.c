/*
** EPITECH PROJECT, 2022
** infos_str
** File description:
** give the infos of the str (nbr cols and lines)
*/

#include "my.h"
#include "header.h"

int get_cols(char *str)
{
    int max_cols = 0;
    int j = 0;
    for (int i = 0; str[i] != '\0'; i += 1) {
        while (str[j] != '\n') {
            j += 1;
        }
        if (j > max_cols) {
            max_cols = j;
        }
    }
    return max_cols;
}

int get_rows(char *str)
{
    int nb_rows = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == '\n') {
            nb_rows += 1;
        }
    }
    return nb_rows;
}
