# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/04 14:44:40 by mmusquer          #+#    #+#              #
#    Updated: 2026/02/19 17:48:04 by mmusquer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
CC = cc 
CFLAGS = -Wall -Wextra -Werror -g3 -pthread

SRCS = main_bonus.c habit_bonus.c action_bonus.c init_bonus.c parsing_bonus.c time_bonus.c utils_bonus.c

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