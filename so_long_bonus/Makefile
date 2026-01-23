# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 17:59:58 by mmusquer          #+#    #+#              #
#    Updated: 2026/01/23 20:23:19 by mmusquer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc 
CFLAGS = -Wall -Wextra -Werror -g3
LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/libft.a
MLX_DIR = Minilibx/minilibx-linux
MLX = ${MLX_DIR}/libmlx.a
INCLUDES = -I${LIBFT_DIR} -I${MLX_DIR}

SRCS = main.c flood_fill.c parsing_utils.c parsing.c mlx.c key.c movement.c movement2.c utils_graph.c utils_mlx.c utils.c

OBJS = ${SRCS:.c=.o}

all:	libft mlx ${NAME}

.PHONY: libft

libft:
	${MAKE} -C ${LIBFT_DIR} all bonus

mlx:
	${MAKE} -C ${MLX_DIR} all

${NAME}: ${OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT} -L${MLX_DIR} -lmlx -lXext -lX11 -lm -o ${NAME}

%.o: %.c
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

clean:
		rm -f ${OBJS} 
		${MAKE} -C ${LIBFT_DIR} clean

fclean:	clean
		rm -f ${NAME} 
		${MAKE} -C ${LIBFT_DIR} fclean

re:		fclean all

.PHONY: all clean fclean re