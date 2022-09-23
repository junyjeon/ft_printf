# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 21:52:21 by junyojeo          #+#    #+#              #
#    Updated: 2022/09/22 02:25:51 by junyojeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_printf.a
SRC		=	
OBJ		=
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

ifdef WITH_BONUS
	OBJECTS = $(OBJ) $(BONUS_OBJ)
else
	OBJECTS = $(OBJ)
endif

all:	$(NAME)

$(NAME) : $(OBJECTS)
	ar rc $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

bonus:
	@make WITH_BONUS1 all

re: fclean all

.PHONY : all .c.o clean fclean re bonus
