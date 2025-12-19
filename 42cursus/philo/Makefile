# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jda-cost <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/18 09:00:21 by jda-cost          #+#    #+#              #
#    Updated: 2025/12/18 09:00:24 by jda-cost         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = main.c utils.c routine.c hobby.c

OBJ = $(SRC:.c=.o)

HEADER = philo.h

all:$(NAME)

$(NAME) :$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ): $(HEADER)

clean:
	rm -f  $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re