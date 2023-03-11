# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seycho <seycho@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 22:00:20 by seycho            #+#    #+#              #
#    Updated: 2023/03/11 22:11:28 by seycho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc

FLAG = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = ft_printf.c\
      ft_print_utils.c\

OBJ = $(SRC:%.c=%.o)

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)

all : $(NAME)

%.o : %.c
	$(GCC) $(FLAG) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re