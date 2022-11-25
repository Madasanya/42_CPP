# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 21:05:52 by mamuller          #+#    #+#              #
#    Updated: 2022/04/02 21:05:52 by mamuller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -f
SRC			= main.cpp Fixed.cpp

OBJ			= $(SRC:%.cpp=%.o)
NAME		= ex00

.cpp.o:
			${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

$(NAME):	${OBJ}
			$(CC) $(CFLAGS) $(SRC) -o $(NAME) 

all:		${NAME}

clean:		
			${RM} ${OBJ}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re