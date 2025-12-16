# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 17:59:58 by mmusquer          #+#    #+#              #
#    Updated: 2025/12/15 16:38:53 by mmusquer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f

NAME		= pipex

FUNCTION	=    pipex.c child.c exec.c utils.c
SRCS	= ${FUNCTION} 
OBJS 	= ${SRCS:.c=.o}
LIBFT = ./libft/libft.a

all:	${LIBFT} ${NAME}

${NAME}:	${OBJS} ${LIBFT}
		${CC} ${CFLAGS} ${LIBFT} -o ${NAME}

.c.o:
		${CC} ${CFLAGS} -c $< -o $@

${LIBFT}:
	${MAKE} -C libft

clean:
		${RM} ${OBJS}
		${MAKE} clean -C libft

fclean:	clean
		${RM} ${NAME}
		${MAKE} fclean -C libft

re:		fclean all

.PHONY: all clean fclean re bonus