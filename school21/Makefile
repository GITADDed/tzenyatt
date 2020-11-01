.PHONY : all clean fclean re main

SOURSES = ft_bzero.c ft_isalpha.c ft_isprint.c ft_memchr.c ft_memmove.c \
ft_putendl_fd.c ft_split.c ft_strjoin.c ft_strlen.c ft_strnstr.c ft_substr.c \
ft_calloc.c ft_isascii.c ft_itoa.c ft_memcmp.c ft_memset.c ft_putnbr_fd.c \
ft_strchr.c ft_strlcat.c ft_strmapi.c ft_strrchr.c ft_tolower.c ft_atoi.c \
ft_isalnum.c ft_isdigit.c ft_memccpy.c ft_memcpy.c ft_putchar_fd.c \
ft_putstr_fd.c ft_strdup.c ft_strlcpy.c ft_strncmp.c ft_strtrim.c ft_toupper.c \
main.c
HEADERS = libft.h
HEADOBJ := $(HEADERS:.h=.h.gch)
OBJECTS := $(SOURSES:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99
NAME = libft

all: $(NAME)
		./$(NAME)

$(NAME): $(OBJECTS)
		$(CC) $(OBJECTS) -o $(NAME)

$(OBJECTS):
		$(CC) $(CFLAGS) -c $(SOURSES)

clean:
		rm -rf $(OBJECTS) $(HEADOBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all
