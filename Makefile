SRCS		= $(addprefix srcs,
				main.c
				)

OBJS		= ${SRCS:.c=.o}

BONUS_OBJS	= ${LST:.c=.o}

NAME		= fractol

RM			= rm -f

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

%.c%.o:
			${CC} ${CFLAGS} -I/usr/includes -Imlx_linux -03 -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			$(CC) $(CFLAGS) -Lmlx_linux -lmlx_linux -L/usr/lib -Iminilibx -lXext -lX11 -lm -lz -o $(NAME)

all:		${NAME}

bonus:		${OBJS} ${BONUS_OBJS}
			ar rcs ${NAME} ${OBJS} ${BONUS_OBJS}

clean:	
			${RM} ${OBJS} ${BONUS_OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
