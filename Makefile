# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apasos-g <apasos-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/12 19:58:06 by apasos-g          #+#    #+#              #
#    Updated: 2019/03/27 19:56:05 by apasos-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fillit
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

SRC =	get_tetrimino.c\
			tetri_shifter.c\
			tetri_validator.c\
			ft_lst_add_tail.c\
			ft_remove_lst_head.c\
			ft_empty_lst.c\
			print.c\
			ft_count_tetris.c\
			grid_size.c\
			grid_builder.c\
			solver.c\
			place_tetrimino.c\
			get_tetri_dimensions.c\
			new_tetrimino.c\
			parsero.c\
			ft_free2darray.c\
			ft_memdel.c\
			ft_strcmp.c\
			ft_strdup.c\
			get_next_line.c\
			ft_strchr.c\
			ft_strnew.c\
			ft_strdel.c\
			ft_strjoin.c\
			ft_strlen.c\
			fillit.c

OBJ			= $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRC)
	@$(CC) -g $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
