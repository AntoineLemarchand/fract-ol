SRCS		= $(addprefix srcs/, \
			  	main.c \
				)

OBJS		= $(SRCS:.c=.o)

NAME		= fractol

RM			= rm -f

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

CPPFLAGS	= -I/usr/includes  -I~/minilibx/include/ -Iincludes

LIBS		= ./libft/libft.a ~/minilibx/libmlx_Linux.a -lXext -lX11 -lm



%.c%.o:
			$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $(<:.c=.o) $(LIBS)

${NAME}:	$(OBJS)
			make -C libft
			$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) -o $(NAME) $(LIBS)

all:		$(NAME)

clean:	
			$(RM) $(OBJS)

fclean:		clean
			make clean -C libft
			$(RM) $(NAME)

re:			fclean all
