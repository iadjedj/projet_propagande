# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iadjedj <iadjedj@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/21 13:29:21 by iadjedj           #+#    #+#              #
#    Updated: 2015/02/02 17:05:37 by iadjedj          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	propagande

SRCS	= 	main.c get_next_line.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): libft/libft.a $(OBJS)
	gcc -Wall -Wextra -Werror -I libft -L libft -lft -o $(NAME) $(OBJS)

$(OBJS): %.o: %.c
	gcc -Wall -Wextra -Werror -I libft -L libft -lft -c $<

libft/libft.a:
	make -C libft

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
