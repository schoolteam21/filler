# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/29 14:25:02 by ijate-bl          #+#    #+#              #
#    Updated: 2019/04/18 13:50:35 by ijate-bl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS= -Wall -Wextra -Werror

SRC_D=src

OBJ_D=obj

INCLUDE=include

NAME=ijate-bl.filler

LIBFT=libft/libft.a

LIBFT_C=libft/*.c

SOURCE=main.c\
	   handler_map.c\
	   filler.c\
	   edit_list.c\
	   create_heat_map.c\

SRC=$(addprefix $(SRC_D)/, $(SOURCE))

OBJ=$(addprefix $(OBJ_D)/, $(SOURCE:.c=.o))

$(NAME): $(OBJ) $(LIBFT)
	cc -o $(NAME) $^

$(LIBFT): $(LIBFT_C)
	make -C libft

$(OBJ): $(SRC)
	mkdir -p $(OBJ_D)
	cc -I $(INCLUDE) -c $(SRC)
	mv *.o $(OBJ_D)

re: clean $(NAME)

run: test $(NAME)
	/Users/ijate-bl/Desktop/demo/filler_vm -f /Users/ijate-bl/Desktop/demo/maps/map01 -p1 /Users/ijate-bl/Desktop/filler/ijate-bl.filler -p2 /Users/ijate-bl/Desktop/demo/players/superjeannot.filler

test:
	touch test

clean:
	rm -rf $(OBJ_D)
	rm -rf $(NAME)
	rm -rf test
	rm -rf filler.trace
