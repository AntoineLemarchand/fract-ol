SRCS		= $(addprefix srcs,
				)

OBJS		= ${SRCS:.c=.o}

BONUS_OBJS	= ${LST:.c=.o}

NAME		= fractol

RM			= rm -f

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

%.c%.o:
			${CC} ${CFLAGS} $< -I includes -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

all:		${NAME}

bonus:		${OBJS} ${BONUS_OBJS}
			ar rcs ${NAME} ${OBJS} ${BONUS_OBJS}

clean:	
			${RM} ${OBJS} ${BONUS_OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
