# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drakan <drakan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 20:34:53 by drakan            #+#    #+#              #
#    Updated: 2022/02/28 21:13:37 by drakan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = so_long_bonus

SRCS =	get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		ft_printf/ft_printf.c \
		ft_printf/libft_function.c \
		utils.c \
		so_long.c \
		map_utils.c \
		creating_objects.c \
		button_hook.c \
		left_and_right_move.c \
		win_condition.c 

SRCS_BONUS =	bonus/get_next_line/get_next_line.c \
		bonus/get_next_line/get_next_line_utils.c \
		bonus/ft_printf/ft_printf.c \
		bonus/ft_printf/libft_function.c \
		bonus/utils_bonus.c \
		bonus/so_long_bonus.c \
		bonus/map_utils_bonus.c \
		bonus/creating_objects_bonus.c \
		bonus/button_hook_bonus.c \
		bonus/left_and_right_move_bonus.c \
		bonus/win_condition_bonus.c \
		bonus/utils2_bonus.c

OBJ=$(SRCS:.c=.o)

OBJ_BONUS=$(SRCS_BONUS:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
		$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS)
		$(CC) $(OBJ_BONUS) -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)

all:
	$(MAKE) $(NAME)

bonus:
	$(MAKE) $(NAME_BONUS)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re:
	make fclean
	make all