# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apasos-g <apasos-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/12 19:58:06 by apasos-g          #+#    #+#              #
#    Updated: 2019/03/18 23:32:41 by apasos-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror -I libft/

NAME = fillit.a

DO	= fillit

SOURCES =	get_tetrimino.c\
			tetri_shifter.c\
			tetri_validator.c\
			ft_lst_add_tail.c\
			ft_remove_lst_head.c\
			ft_empty_lst.c\
			print.c\
			parser.c

OBJECT = $(SOURCES:.c=.o)

$(DO):
	@gcc -fsanitize=address -g -o $(DO) fillit.c fillit.a libft/libft.a

$(NAME):
	@$(CC) $(FLAGS) -c $(SOURCES)
	@ar rcs $(NAME) $(OBJECT)

all: $(NAME)

do: $(DO)

del:
	@rm $(DO)

clean:
	@rm -rf $(OBJECT)

fclean: clean
	@rm -fr $(NAME)


re: fclean all
