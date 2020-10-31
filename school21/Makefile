.PHONY : all clean fclean re

SOURSES = $(wildcard *.c)
HEADERS = $(wildcard *.h)
HEADOBJ := $(HEADERS:.h=.h.gch)
OBJECTS := $(SOURSES:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99
OUT = libft.a

all: hello
		./$(OUT)

hello: $(OBJECTS) &(HEADOBJ)
		$(CC) $(OBJECTS) -o $(OUT)

$(OBJECTS):
		$(CC) $(CFLAGS) -c $(SOURSES)

&(HEADOBJ):
		$(CC) $(CFLAGS) -c $(HEADERS)

clean:
		rm -rf $(OBJECTS) $(HEADOBJ)

fclean: clean
		rm -rf $(OUT)

re: fclean all
