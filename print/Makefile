SRCS = ft_printf.c  ft_parcer.c ft_proc_nbr.c   ft_proc_p.c ft_proc_str.c   ft_utils.c

OBJS = ${SRCS:.c=.o}

ARCH = ar rc

HEADER = ft_printf.h

NAME = libftprintf.a

CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEADER}


${NAME}:	${OBJS}
			${ARCH} ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
