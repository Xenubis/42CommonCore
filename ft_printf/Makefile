# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 17:59:58 by mmusquer          #+#    #+#              #
#    Updated: 2025/11/18 14:49:48 by mmusquer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
AR		= ar
ARFLAGS	= rcs
RM		= rm -f

NAME		= libftprintf.a

FUNCTION	=    ft_printf.c \
			  ft_print_char.c \
			  ft_print_str.c \
			  ft_print_nbr.c \
			  ft_print_unbr.c \
			  ft_print_hex.c \
			  ft_print_ptr.c \
			  ft_conversion.c

SRCS	= ${FUNCTION} 

OBJS 	= ${SRCS:.c=.o}

all:	${NAME}

${NAME}:	${OBJS}
		${AR} ${ARFLAGS} $@ $^

.c.o:
		${CC} ${CFLAGS} -c $< -o $@

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re bonus