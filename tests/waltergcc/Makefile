# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 01:34:02 by wcorrea-          #+#    #+#              #
#    Updated: 2023/04/22 23:21:11 by wcorrea-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GNL = ../../get_next_line

MANDATORY = ${GNL}/get_next_line.c ${GNL}/get_next_line_utils.c

BONUS = ${GNL}/get_next_line_bonus.c ${GNL}/get_next_line_utils_bonus.c

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I ${GNL}
MAKE = make -C
BUFFER_SIZE = -D BUFFER_SIZE=42

m:	fclean
		${CC} ${CFLAGS} ${INCLUDE} ${BUFFER_SIZE} mandatory.c ${MANDATORY} -o m

b:	fclean
		${CC} ${CFLAGS} ${INCLUDE} ${BUFFER_SIZE} bonus.c ${MANDATORY} -o b

fclean:
		${RM} m b
		
.PHONY: all clean fclean re