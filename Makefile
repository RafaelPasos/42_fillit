# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apasos-g <apasos-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/12 19:58:06 by apasos-g          #+#    #+#              #
#    Updated: 2019/03/23 02:48:59 by apasos-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror -g -I libft/

NAME = fillit.a

DO	= fillit

SOURCES =	get_tetrimino.c\
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
			parser.c

OBJECT = $(SOURCES:.c=.o)

$(NAME):
	@$(CC) $(FLAGS) -c $(SOURCES)
	@ar rcs $(NAME) $(OBJECT)
	@gcc -g -o $(DO) fillit.c fillit.a libft/libft.a

all: $(NAME)

clean:
	@rm -rf $(OBJECT)

fclean: clean
	@rm -fr $(NAME)
	@rm	$(DO)

re: fclean all
