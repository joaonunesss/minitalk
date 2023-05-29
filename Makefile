# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 15:22:11 by jmarinho          #+#    #+#              #
#    Updated: 2023/05/26 14:55:09 by jmarinho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRINTF = ft_printf/libftprintf.a

RM = rm -f

FLAGS = -Wall -Wextra -Werror

all:
	make -C ft_printf
	cc ${FLAGS} client.c ${PRINTF} -o client
	cc ${FLAGS} server.c ${PRINTF} -o server

clean:
	make clean -C ft_printf

fclean: clean
	${RM} server client
	make fclean -C ft_printf

re: fclean all

.PHONY: all clean fclean re

.SILENT:
