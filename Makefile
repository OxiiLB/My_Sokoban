##
## EPITECH PROJECT, 2022
## Makefile project
## File description:
## compile the project and the lib
##

SRC	= 	main.c \
		src/my_popup.c \
		src/errors.c \
		src/get_tab.c \
		src/infos_str.c \
		src/free_all.c \
		src/mem_alloc_2d_array.c \
		src/print_map.c \
		src/get_info_in_struct.c \
		src/deplacements.c \
		src/get_infos.c \
		src/verify_win.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

CFLAGS	=	-Wall -Wextra  #-Werror

LDFLAGS	=	-L./lib

LDLIBS	=	-lprintf

CPPFLAGS	=	-I./include/

LIB	=	lib/libprintf.a

all:	$(NAME)

$(NAME): $(OBJ)
	make -C lib/my/
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -lncurses -ggdb3

clean:
	make clean -C lib/my/
	rm -rf $(OBJ)

fclean:	clean
	make fclean -C lib/my/
	rm -rf $(NAME)

re: fclean all

tests_run: $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	gcc -o unit_tests cat.c ../tests/test_cat.c $(CPPFLAGS) $(LDFLAGS)
	$(LDLIBS) --coverage -lcriterion
	./unit_tests

.PHONY: all clean fclean re
