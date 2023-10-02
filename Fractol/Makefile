# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjuriens <rjuriens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/24 12:06:42 by rjuriens          #+#    #+#              #
#    Updated: 2023/09/25 11:01:44 by rjuriens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = src/
SRCS = ${wildcard ${SRC_DIR}*.c}
SRC = ${notdir ${SRCS}}
OBJ_DIR = obj/
OBJ = ${SRC:.c=.o}
OBJS = ${addprefix ${OBJ_DIR}, ${OBJ}}
MLX = minilibx/
LMLX = ${MLX}libmlx.a

INC			=	-I ./includes/\
				-I ./libft/\
				-I ./minilibx/

NAME = fractol.a

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Werror -Wextra

NC =	'\033[0m'
RED =	'\033[0;31m'
GREEN =	'\033[0;32m'

LIBFT_PATH	= ./libft/
LIBFT	= ${LIBFT_PATH}libft.a



all: $(NAME)

${NAME}	: ${LIBFT} ${LMLX} ${OBJ_DIR} ${OBJS}
	$(CC) ${CFLAGS} -o $(NAME) ${OBJS} ${LMLX} ${LIBFT} ${INC} -lmlx -framework OpenGL -framework AppKit -L ./minilibx
	@echo ${GREEN}Compiled !${NC}
${LIBFT}	:
				@make -C ${LIBFT_PATH} all
${LMLX}		:
				@make -C ${MLX} all
${OBJS}		: ${OBJ_DIR}
${OBJ_DIR}	:
				@mkdir -p ${OBJ_DIR}
${OBJ_DIR}%.o:		${SRC_DIR}%.c
				@${CC} ${CFLAGS} -c $< -o $@ ${INC}
clean	:
				@make -C ${LIBFT_PATH} clean
				@make -C ${MLX} clean
				${RM} ${OBJ_DIR}
				@echo ${GREEN}Cleaned !${NC}
fclean	:	clean
				make -C ${LIBFT_PATH} fclean
				${RM} ${NAME}

re	:		fclean all