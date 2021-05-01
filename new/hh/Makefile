NAME		= miniRT

SRC			= srcs/set_5.c \
              srcs/intersection.c \
              srcs/cylinder_intersection.c \
              srcs/init.c \
              srcs/light_and_shadows.c \
              srcs/main.c \
              srcs/map_errors.c \
              srcs/parser.c \
              srcs/plane_intersection.c \
              srcs/rendering.c \
              srcs/screen_shot.c \
              srcs/set_2.c \
              srcs/set.c \
              srcs/set_3.c \
              srcs/set_4.c \
              srcs/set_6.c \
              srcs/sphere_intersection.c \
              srcs/square_intersection.c \
              srcs/triangle_intersection.c \
              srcs/utils.c \
              srcs/utils_2.c \
              srcs/utils_3.c \
              srcs/get_next_line.c \
			  srcs/get_next_line_utils.c \
              libft/ft_lstadd_front.c \
              libft/ft_lstnew.c \
              srcs/hooks.c

HEADER		= srcs/minirt.h minilibx_mms_20200219/mlx.h srcs/get_next_line.h

OBJS		= ${SRC:.c=.o}

LIBFT		= make all -C libft

FLAGS		= -Wall -Wextra -Werror -g

FRAMEWORKS	= -framework OpenGL -framework AppKit -lmlx

RM			= rm -f

all:	${NAME}

.c.o:
		gcc ${FLAGS} -I. -c $< -o ${<:.c=.o}

${NAME}: ${OBJS} ${HEADER}
		${LIBFT}
		make bonus -C libft
		make -C minilibx_mms_20200219
		mv minilibx_mms_20200219/libmlx.dylib .
		gcc ${FLAGS} ${OBJS} -o ${NAME} -L. -I. libft/libft.a libmlx.dylib ${FRAMEWORKS}

clean:
		${RM} ${OBJS}
		make clean -C minilibx_mms_20200219
		make clean -C libft

fclean:	clean
		${RM} ${NAME}
		${RM} libmlx.dylib
		make clean -C minilibx_mms_20200219
		make fclean -C libft
re:		fclean all

.PHONY:		re all clean fclean
