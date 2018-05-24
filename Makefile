##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Desc
##

SRC	=	./src/main.c					\
		./src/graphics_base.c				\
		./src/graphics_tools.c				\
		./src/keyboard.c				\
		./src/printer.c					\
		./src/screensaver.c				\
		./src/utils.c					\
		./src/utils2.c

OBJ	=	$(SRC:.c=.o)

INC_DIR	=	$(realpath ./include)

LIB_DIR	=	$(realpath ./lib)

NAME	=	my_screensaver

CFLAGS	=	-W -Wall -Wextra -Werror -pedantic -I$(INC_DIR) -g3

LDFLAGS	=	-L$(LIB_DIR) -lmy -lc_graph_prog

all:		$(NAME)
$(NAME):	$(OBJ)
		make -C ./lib/my
		gcc -o	$(NAME)	$(OBJ) $(LDFLAGS)

clean:
		rm -f $(OBJ)
		make clean -C ./lib/my

fclean:		clean
		rm -f $(NAME)
		make fclean -C ./lib/my

re:		fclean all

tests_run:
		make tests_run -C ./tests

tests_coverage:	tests_run
		lcov --directory ./tests -c -o rapport.info &>/dev/null
		genhtml -o ./bonus/cov_report -t "code coverage report" rapport.info &>/dev/null
		xdg-open ./bonus/cov_report/src/index.html &>/dev/null

.PHONY: all clean fclean re tests_run tests_coverage
