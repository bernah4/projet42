# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcherret <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/24 14:24:20 by tcherret          #+#    #+#              #
#    Updated: 2018/11/07 14:26:13 by hebernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file 

CC = gcc

FLAG = -Wall \
	   -Werror \
	   -Wextra \

SRC_DIR = ./srcs/

INC_DIR = ./includes/

SRC =  ft_display_file.c \

RM = /bin/rm -f

OBJ = $(SRC:%.c=%.o)


all: $(NAME)

$(NAME): $(OBJ)  
	$(CC) $(FLAG) -o $@  $^ -I $(INC_DIR)

%.o: %.c 
	$(CC) $(FLAG) -o $@ -c $^ -I $(INC_DIR)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re : fclean all
