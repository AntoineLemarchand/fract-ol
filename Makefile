define building
	@echo -n "$(shell tput setaf 6)Building $1 $(shell tput sgr0)"
endef

define compiling
	@echo -n "$(shell tput bold)$(shell tput setaf 3)Compiling $1 $(shell tput sgr0)"
endef

define cleaning
	@echo -n "$(shell tput bold)$(shell tput setaf 1)Cleaning $1 $(shell tput sgr0)"
	@make $2 -sC $1 > /dev/null
	@echo "$(shell tput bold)$(shell tput setaf 2)√$(shell tput sgr0)"
endef

define removing
	@echo -n "$(shell tput bold)$(shell tput setaf 1)Removing $1 $(shell tput sgr0)"
	@$(RM) $1 > /dev/null
	@echo "$(shell tput bold)$(shell tput setaf 2)√$(shell tput sgr0)"
endef

DONE		= @echo "$(shell tput bold)$(shell tput setaf 2)√$(shell tput sgr0)"

SRCS		= $(addprefix srcs/, \
			  	input.c \
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

CPPFLAGS	= -I/usr/includes  -Iminilibx/include/ -Iincludes

LIBS		= ./libft/libft.a minilibx/libmlx_Linux.a -lXext -lX11 -lm



%.o : %.c
			$(call compiling,$<)
			@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $(<:.c=.o)
			$(DONE)

${NAME}:	$(OBJS)
			$(call building,libft)
			@make -sC libft
			$(DONE)
			$(call building,minilibx)
			@make -sC minilibx > /dev/null
			$(DONE)
			$(call building,executable)
			@$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) -o $(NAME) $(LIBS)
			$(DONE)

all:		$(NAME)

clean:	
			$(call removing,$(OBJS))

fclean:		clean
			$(call cleaning,libft,fclean)
			$(call cleaning,minilibx,clean)
			$(call removing,fract-ol)

re:			fclean all
