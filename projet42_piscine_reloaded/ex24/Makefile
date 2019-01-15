# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hebernar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 12:32:50 by hebernar          #+#    #+#              #
#    Updated: 2018/11/07 14:46:32 by hebernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

RM = /bin/rm -f

FLAG = -Wall\
	   -Werror\
	   -Wextra\

DIRSRC = ./srcs/

SRC = $(DIRSRC)ft_putchar.c\
	  $(DIRSRC)ft_putstr.c\
	  $(DIRSRC)ft_strcmp.c\
	  $(DIRSRC)ft_strlen.c\
	  $(DIRSRC)ft_swap.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	ar rc $@ $^  

%.o: %.c 
	$(CC) $(FLAG) -o $@ -c $^

clean : 
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all
