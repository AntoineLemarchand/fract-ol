SRCS		= $(addprefix srcs/, \
				color.c \
			  	utils.c \
				sets.c \
			  	main.c \
				)

OBJS		= $(SRCS:.c=.o)

NAME		= fractol

RM			= rm -f

CC			= cc

CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address

CPPFLAGS	= -I/usr/includes  -I~/minilibx/include/ -Iincludes

LIBS		= ./libft/libft.a minilibx/libmlx_Linux.a -lXext -lX11 -lm



%.c%.o:
			$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $(<:.c=.o) $(LIBS)

${NAME}:	$(OBJS)
			make -C libft
			make -C minilibx
			$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) -o $(NAME) $(LIBS)

all:		$(NAME)

clean:	
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C libft
			make clean -C minilibx
			$(RM) $(NAME)

re:			fclean all
