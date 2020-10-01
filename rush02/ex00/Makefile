# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jacher <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/26 10:04:43 by jacher            #+#    #+#              #
#    Updated: 2020/09/26 12:15:13 by jacher           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c  srcs/*.c 

NAME = rush-02

${NAME}:
			gcc -Wall -Wextra -Werror -Ift.h -o ${NAME} ${SRCS}

all:		${NAME}

clean:
			rm -f *.o

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
