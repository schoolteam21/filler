# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/07 16:35:16 by ijate-bl          #+#    #+#              #
#    Updated: 2019/03/29 16:03:35 by ijate-bl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
OBJ = *.o
SRCS = *.c

$(NAME): $(SRCS)
	gcc -Wall -Werror -Wextra -c $(SRCS) -I.
	ar rc $(NAME) $(OBJ) 
	ranlib $(NAME)
all: $(NAME)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
