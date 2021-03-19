.PHONY : all clean fclean re

SRC := main.c

libs := -lglut -lGLU -lGL

OBJ := $(SRC:.c=.o)

CC := gcc

NAME := miniRT.out

all:			$(NAME)

$(NAME):		$(OBJ)
								$(CC) -o $(NAME) $(OBJ) $(libs)
				./$(NAME)

clean:
				rm -rf $(OBJ)

fclean:			clean
				rm -rf $(NAME)

re:				fclean all
