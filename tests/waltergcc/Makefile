# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 01:34:02 by wcorrea-          #+#    #+#              #
#    Updated: 2023/04/22 18:56:32 by wcorrea-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GNL = ../../get_next_line
SRC = ${GNL}/get_next_line.c ${GNL}/get_next_line_utils.c

TEST = main.c

OUT = ${TEST:.c=}

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I ${GNL}
MAKE = make -C
BUFFER_SIZE = -D BUFFER_SIZE=1000

all:	fclean
		${CC} ${CFLAGS} ${INCLUDE} ${BUFFER_SIZE} ${TEST} ${SRC} -o ${OUT}

fclean:
		${RM} main
		
.PHONY: all clean fclean re