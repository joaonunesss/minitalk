# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 15:22:11 by jmarinho          #+#    #+#              #
#    Updated: 2023/05/23 18:44:59 by jmarinho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = server.c client.c \

NAME = minitalk.a

OBJS = ${SRC:.c=.o}

RM = rm -f

FLAGS = -Wall -Wextra -Werror

all: ${NAME}

$(NAME): ${OBJS}
	make -C ft_printf
	cp ft_printf/ft_printf.a ${NAME}
	ar rcs ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}
	make clean -C ft_printf

fclean: clean
	${RM} ${NAME}
	make fclean -C ft_printf

re: fclean all

.PHONY: all clean fclean re

.SILENT: