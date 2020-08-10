
SRCS	= $(wildcard *.c)

OBJS	= ${SRCS:.c=.o}

NAME	= ft_tail

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} -c $< -o ${<:.c=.o}

.PHONY:		all clean fclean

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}


