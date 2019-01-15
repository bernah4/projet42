# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hebernar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 12:32:50 by hebernar          #+#    #+#              #
#    Updated: 2018/11/22 12:54:18 by hebernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

RM = /bin/rm -f

FLAG = -Wall\
	   -Werror\
	   -Wextra\

DIRSRC = ./

SRC = $(DIRSRC)ft_atoi.c\
	  $(DIRSRC)ft_isalnum.c\
	  $(DIRSRC)ft_isalpha.c\
	  $(DIRSRC)ft_isascii.c\
	  $(DIRSRC)ft_isdigit.c\
	  $(DIRSRC)ft_isprint.c\
	  $(DIRSRC)ft_itoa.c\
	  $(DIRSRC)ft_memalloc.c\
	  $(DIRSRC)ft_memdel.c\
	  $(DIRSRC)ft_putendl.c\
	  $(DIRSRC)ft_putendl_fd.c\
	  $(DIRSRC)ft_putnbr.c\
	  $(DIRSRC)ft_putnbr_fd.c\
	  $(DIRSRC)ft_strcat.c\
	  $(DIRSRC)ft_strclr.c\
	  $(DIRSRC)ft_strcmp.c\
	  $(DIRSRC)ft_strcpy.c\
	  $(DIRSRC)ft_strdel.c\
	  $(DIRSRC)ft_strdup.c\
	  $(DIRSRC)ft_strequ.c\
	  $(DIRSRC)ft_striter.c\
	  $(DIRSRC)ft_striteri.c\
	  $(DIRSRC)ft_strjoin.c\
	  $(DIRSRC)ft_strlcat.c\
	  $(DIRSRC)ft_strlen.c\
	  $(DIRSRC)ft_strmap.c\
	  $(DIRSRC)ft_strmapi.c\
	  $(DIRSRC)ft_strncat.c\
	  $(DIRSRC)ft_strncmp.c\
	  $(DIRSRC)ft_strncpy.c\
	  $(DIRSRC)ft_strnequ.c\
	  $(DIRSRC)ft_strnew.c\
	  $(DIRSRC)ft_strnstr.c\
	  $(DIRSRC)ft_strsplit.c\
	  $(DIRSRC)ft_strstr.c\
	  $(DIRSRC)ft_strsub.c\
	  $(DIRSRC)ft_strtrim.c\
	  $(DIRSRC)ft_tolower.c\
	  $(DIRSRC)ft_toupper.c\
	  $(DIRSRC)ft_putchar.c\
	  $(DIRSRC)ft_putchar_fd.c\
	  $(DIRSRC)ft_putstr.c\
	  $(DIRSRC)ft_putstr_fd.c\
	  $(DIRSRC)ft_memset.c\
	  $(DIRSRC)ft_bzero.c\
	  $(DIRSRC)ft_memmove.c\
	  $(DIRSRC)ft_memchr.c\
	  $(DIRSRC)ft_memcmp.c\
	  $(DIRSRC)ft_memccpy.c\
	  $(DIRSRC)ft_memcpy.c\
	  $(DIRSRC)ft_strchr.c\
	  $(DIRSRC)ft_strrchr.c\
	  $(DIRSRC)ft_lstnew.c\
	  $(DIRSRC)ft_lstdel.c\
	  $(DIRSRC)ft_lstdelone.c\
	  $(DIRSRC)ft_lstadd.c\
	  $(DIRSRC)ft_lstiter.c\
	  $(DIRSRC)ft_lstmap.c\
	  $(DIRSRC)ft_lstlast.c\
	  $(DIRSRC)ft_count_words.c\
	  $(DIRSRC)ft_sort_integer_table.c\
	  $(DIRSRC)ft_sort_wordtab.c\
	  $(DIRSRC)ft_strrev.c\

OBJ = $(SRC:.c=.o)


.PHONY : all 
all: $(NAME)

$(NAME) : $(OBJ)
	ar rc $@ $^  

%.o: %.c 
	$(CC) $(FLAG) -o $@ -c $^

.PHONY : clean
clean : 
	$(RM) $(OBJ)

.PHONY : fclean
fclean : clean
	$(RM) $(NAME)

.PHONY : re 
re : fclean all
