# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noam <noam@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/26 23:32:25 by noam              #+#    #+#              #
#    Updated: 2023/11/26 23:41:43 by noam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_libftprintf.a
CC = cc
FLAGS = -Wall -Werror -Wextra
SRCS = 	ft_printf.c
		ft_putnbr_base.c
OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

all : $(NAME)

.PHONY: clean fclean re
clean :
    rm -f *.o

fclean : clean
    rm -f $(NAME)
    rm -f a.out

re : fclean all