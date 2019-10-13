# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hebernar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/04 15:20:14 by hebernar          #+#    #+#              #
#    Updated: 2019/10/05 16:07:46 by hebernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS =-Wall -Wextra -Werror

SRC_DIR =

RM = /bin/rm -f

SRC = 	$(SRC_DIR)convert.c \
	 	$(SRC_DIR)convert_itoa_schar.c \
		$(SRC_DIR)convert_itoa_sint.c \
		$(SRC_DIR)convert_itoa_slong.c \
		$(SRC_DIR)convert_itoa_slonglong.c \
		$(SRC_DIR)convert_itoa_sshort.c \
		$(SRC_DIR)convert_itoa_uchar.c \
		$(SRC_DIR)convert_itoa_uint.c \
		$(SRC_DIR)convert_itoa_ulong.c \
		$(SRC_DIR)convert_itoa_ulonglong.c \
		$(SRC_DIR)convert_itoa_ushort.c \
		$(SRC_DIR)ft_printf.c \
		$(SRC_DIR)init_structure.c \
		$(SRC_DIR)utils.c \
		$(SRC_DIR)verif_char.c \
		$(SRC_DIR)verif_parse.c \
		$(SRC_DIR)verif_valid.c 

LIB_SRC =	ft_atoi.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_itoa.c\
			ft_memalloc.c\
			ft_memdel.c\
			ft_putendl.c\
			ft_putendl_fd.c\
			ft_putnbr.c\
			ft_putnbr_fd.c\
			ft_strcat.c\
			ft_strclr.c\
			ft_strcmp.c\
			ft_strcpy.c\
			ft_strdel.c\
			ft_strdup.c\
			ft_strequ.c\
			ft_striter.c\
			ft_striteri.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlen.c\
			ft_strmap.c\
			ft_strmapi.c\
			ft_strncat.c\
			ft_strncmp.c\
			ft_strncpy.c\
			ft_strnequ.c\
			ft_strnew.c\
			ft_strnstr.c\
			ft_strsplit.c\
			ft_strstr.c\
			ft_strsub.c\
			ft_strtrim.c\
			ft_tolower.c\
			ft_toupper.c\
			ft_putchar.c\
			ft_putchar_fd.c\
			ft_putstr.c\
			ft_putstr_fd.c\
			ft_memset.c\
			ft_bzero.c\
			ft_memmove.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memccpy.c\
			ft_memcpy.c\
			ft_strchr.c\
			ft_strrchr.c\
			ft_lstnew.c\
			ft_lstdel.c\
			ft_lstdelone.c\
			ft_lstadd.c\
			ft_lstiter.c\
			ft_lstmap.c\
			ft_lstlast.c\
			ft_count_words.c\
			ft_sort_integer_table.c\
			ft_sort_wordtab.c\
			ft_strrev.c

LOBJ = $(LIB_SRC:%.c=%.o)
OBJ = $(addprefix libft/, $(LOBJ))

OBJ += $(SRC:%.c=%.o)

fast:
	make -j8 all

all: $(NAME)

$(NAME): $(OBJ) #$(LIBOBJ)
	ar rc $(NAME) $^
	ranlib $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $< -I ft_printf.h -I ./libft/libft.h

clean:
	$(RM) $(OBJ) 

fclean: clean
	$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re
