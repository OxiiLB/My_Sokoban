/*
** EPITECH PROJECT, 2022
** errors
** File description:
** detect all possible errors in order to return errors messages
*/

#include "my.h"
#include "header.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <unistd.h>

int errors(char *filepath)
{
    int ret_status = 0;
    struct stat s;
    if (lstat(filepath, &s) == -1) {
        write(2,"Cannot open the file\n", 22);
        ret_status = 84;
        exit (84);
    }
    if ((s.st_mode & __S_IFMT) != __S_IFREG) {
        write(2, "Cannot open a folder\n", 22);
        ret_status = 84;
        exit (84);
    }
    return ret_status;
}
