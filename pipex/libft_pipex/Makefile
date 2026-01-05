# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 17:59:58 by mmusquer          #+#    #+#              #
#    Updated: 2025/12/22 12:21:30 by mmusquer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
AR		= ar
ARFLAGS	= rcs
RM		= rm -f

NAME		= libft.a

FUNCTION	= ft_split.c ft_strjoin.c ft_strlen.c ft_strncmp.c ft_strdup.c ft_strchr.c

SRCS	= ${FUNCTION} 

OBJS 	= ${SRCS:.c=.o}

all:	${NAME}

${NAME}:	${OBJS}
		${AR} ${ARFLAGS} $@ $^

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re bonus