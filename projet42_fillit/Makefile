# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcherret <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 18:55:44 by tcherret          #+#    #+#              #
#    Updated: 2018/12/19 16:16:09 by hebernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

NAMELIB = ./libft/libft.a

CC = gcc

CFLAGS =-Wall -Wextra -Werror 

SRC_DIR = ./

RM = /bin/rm -f

SRC = 	$(SRC_DIR)main.c \
	 	$(SRC_DIR)map_generator.c \
		$(SRC_DIR)solve_tet.c \
   		$(SRC_DIR)verif_take_tet.c \
		$(SRC_DIR)take_tet.c \
		$(SRC_DIR)get_size.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(NAMELIB)

clean:
	make clean -C ./libft/
	$(RM) $(OBJ) 

fclean: clean
	make fclean -C ./libft/
	$(RM) $(NAME) $(NAMELIB)

re: fclean all

.PHONY: all clean fclean re
