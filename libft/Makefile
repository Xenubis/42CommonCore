# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 17:59:58 by mmusquer          #+#    #+#              #
#    Updated: 2025/11/13 14:13:54 by mmusquer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
AR		= ar
ARFLAGS	= rcs
RM		= rm -f

NAME		= libft.a

BASE 		=    ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
        ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c \
        ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
        ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
        ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c 

ADDITIONAL	=    ft_itoa.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
        ft_split.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_substr.c ft_striteri.c

BONUS		=    ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
        ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
        ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

SRCS	= ${BASE} ${ADDITIONAL}
SRCSALL = ${BASE} ${ADDITIONAL} ${BONUS}

OBJS 	= ${SRCS:.c=.o}
OBJSALL = ${SRCSALL:.c=.o} 

.c.o:
		${CC} ${CFLAGS} -c $< -o $@

all:	${NAME}

${NAME}:	${OBJS}
		${AR} ${ARFLAGS} $@ $^

bonus:	${OBJSALL}
		${AR} ${ARFLAGS} ${NAME} $^

clean:
		${RM} ${OBJSALL}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re bonus