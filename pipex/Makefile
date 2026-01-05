# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 17:59:58 by mmusquer          #+#    #+#              #
#    Updated: 2026/01/05 18:05:37 by mmusquer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BONUS_NAME = pipex_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft_pipex
LIBFT = ${LIBFT_DIR}/libft.a
INCLUDES = -I${LIBFT_DIR}

SRCS = pipex.c exec.c child.c utils.c
BONUS_SRCS = pipex_bonus.c exec_bonus.c child_bonus.c utils_bonus.c

OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o}

all:	libft ${NAME}

bonus : libft ${BONUS_NAME}

.PHONY: libft

libft:
	${MAKE} -C ${LIBFT_DIR} all

${NAME}: ${OBJS} ${LIBFT}
		${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME}

${BONUS_NAME}: ${BONUS_OBJS} ${LIBFT}
		${CC} ${CFLAGS} ${BONUS_OBJS} ${LIBFT} -o ${BONUS_NAME}

%.o: %.c
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

clean:
		rm -f ${OBJS} ${BONUS_OBJS}
		${MAKE} -C ${LIBFT_DIR} clean

fclean:	clean
		rm -f ${NAME} ${BONUS_NAME}
		${MAKE} -C ${LIBFT_DIR} fclean

re:		fclean all

.PHONY: all clean fclean re