# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjuriens <rjuriens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 14:03:21 by rjuriens          #+#    #+#              #
#    Updated: 2022/10/31 13:33:21 by rjuriens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_pow.c ft_memmove.c ft_strtrim.c ft_putnbr_fd.c ft_putendl_fd.c ft_putchar_fd.c ft_putstr_fd.c ft_striteri.c ft_itoa.c ft_calloc.c ft_substr.c ft_strjoin.c ft_strdup.c ft_strjoin.c ft_substr.c ft_split.c ft_strdup.c ft_isalnum.c	ft_isdigit.c	ft_memcmp.c	ft_strchr.c	ft_strlen.c	ft_strrchr.c	ft_toupper.c ft_atoi.c	ft_isalpha.c	ft_isprint.c	ft_memcpy.c	ft_strlcat.c	ft_strncmp.c ft_bzero.c	ft_isascii.c	ft_memchr.c	ft_memset.c	ft_strlcpy.c	ft_strnstr.c	ft_tolower.c ft_strmapi.c
OBJ_DIR	= obj
OBJS	= ${SRCS:%.c=${OBJ_DIR}/%.o}

.SILENT : all clean re fclean

NAME	= libft.a

CC	= gcc

RM	= rm -rf

CFLAGS	= -Wall -Wextra -Werror

${OBJ_DIR}/%.o:		%.c
				@${CC} ${CFLAGS} -c $< -o $@
${NAME}:	${OBJ_DIR} ${OBJS}
	@ar rcs ${NAME} ${OBJS}

all	:	${NAME}
${OBJ_DIR} :	
				@mkdir -p ${OBJ_DIR}
clean :
	${RM} ${OBJ_DIR}
fclean : clean
	${RM} ${NAME}
re	:	fclean all
