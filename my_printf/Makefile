.PHONY : all clean fclean re

SOURSES := ft_printf.c printer.c utils.c process.c parcer.c

OBJECTS := $(SOURSES:.c=.o)

CC := gcc

CFLAGS := -Wall -Wextra -Werror

NAME := libftprintf.a

all:		$(NAME)

$(NAME):	$(OBJECTS)
			ar rc $(NAME) $(OBJECTS)

clean:
			rm -rf $(OBJECTS) $(BONUSOBJ)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all
