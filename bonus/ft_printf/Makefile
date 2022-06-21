NAME		=	libftprintf.a

SRCS		= 	ft_printf.c libft_function.c\

HEADER		=	ft_printf.h
OBJS		=	$(patsubst %.c,%.o,$(SRCS))

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I$(HEADER)

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(HEADER)
	@ar rcs $(NAME) $?

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean		:	
	@rm -f $(OBJS) 

fclean		:	clean
	@rm -f $(NAME)

re:			fclean all