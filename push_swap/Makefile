# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/13 11:07:40 by mmusquer          #+#    #+#              #
#    Updated: 2026/01/15 15:29:44 by mmusquer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc 
CFLAGS = -Wall -Wextra -Werror -g

SRCS = main.c push.c rotate.c reverse_rotate.c sort3.c sorting.c radix.c stack.c swap.c utils.c ft_split.c utils2.c

OBJS = ${SRCS:.c=.o}

all:	${NAME}

${NAME}: ${OBJS}  
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
		rm -f ${OBJS} 

fclean:	clean
		rm -f ${NAME} 

re:		fclean all

.PHONY: all clean fclean re