# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/04 14:44:40 by mmusquer          #+#    #+#              #
#    Updated: 2026/02/18 14:18:42 by mmusquer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc 
CFLAGS = -Wall -Wextra -Werror -g3 -pthread

SRCS = main.c habit.c action.c action2.c init.c monitoring.c parsing.c time.c locker.c utils.c

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