.PHONY: all, fclean, clean, re
SRC := get_next_line.c get_next_line_utils.c

SRC := $(addprefix src/, $(SRC))

TESTSUBDIR := test1

TESTSUBDIR := $(addprefix test/, $(TESTSUBDIR))

INCLUDES := src/get_next_line.h

TESTSRC := $(addsuffix /main.c, $(TESTSUBDIR))

TESTOBJ := $(TESTSRC:.c=.o)

OBJECTS := $(SRC:.c=.o)

CC := gcc

#CFLAGS := -Wall -Wextra -Werror -std=c99

NAME := gnl.out

TESTNAME := test.out

all:		$(NAME)

$(NAME):	$(OBJECTS)
			$(CC) -o $(NAME) $(OBJECTS) src/libft.a

test:		$(OBJECTS) $(TESTOBJ)
			$(CC) -o $(TESTNAME) $(OBJECTS) $(TESTOBJ)

clean:
			rm -rf $(OBJECTS) $(BONUSOBJ)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all
