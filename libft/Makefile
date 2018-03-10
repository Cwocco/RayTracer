# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 17:44:25 by rpinoit           #+#    #+#              #
#    Updated: 2018/03/08 17:58:17 by rpinoit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
RM = rm -f
CFLAGS = -c -Wall -Werror -Wextra
FILES = ft_lstdel.c \
		ft_memmove.c \
		ft_strchr.c \
		ft_strlen.c \
		ft_strstr.c \
		ft_lstdelone.c \
		ft_memset.c \
		ft_strclr.c \
		ft_strmap.c \
		ft_strsub.c \
		ft_atoi.c \
		ft_lstiter.c \
		ft_putchar.c \
		ft_strcmp.c \
		ft_strmapi.c \
		ft_strtrim.c \
		ft_bzero.c \
		ft_lstmap.c \
		ft_putchar_fd.c \
		ft_strcpy.c \
		ft_strncat.c \
		ft_tolower.c \
		ft_isalnum.c \
		ft_lstnew.c \
		ft_putendl.c \
		ft_strdel.c \
		ft_strncmp.c \
		ft_toupper.c \
		ft_isalpha.c \
		ft_memalloc.c \
		ft_putendl_fd.c \
		ft_strdup.c \
		ft_strncpy.c \
		ft_isascii.c \
		ft_memccpy.c \
		ft_putnbr.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_isdigit.c \
		ft_memchr.c \
		ft_putnbr_fd.c \
		ft_striter.c \
		ft_strnew.c \
		ft_isprint.c \
		ft_memcmp.c \
		ft_putstr.c \
		ft_striteri.c \
		ft_strnstr.c \
		ft_itoa.c \
		ft_memcpy.c \
		ft_putstr_fd.c \
		ft_strjoin.c \
		ft_strrchr.c \
		ft_lstadd.c \
		ft_memdel.c \
		ft_strcat.c \
		ft_strlcat.c \
		ft_strsplit.c \
		ft_count_words.c \
		ft_atoi_base.c \
		ft_isspace.c \
		ft_print_words_tables.c \
		ft_itoa_base.c \
		ft_swap.c \
		ft_sqrt.c \
		ft_find_next_prime.c \
		ft_isnegative.c \
		get_next_line.c \
		ft_degtorad.c \
		ft_radtodeg.c \
		ft_atod.c \
		ft_pow.c \
		ft_tablen.c \
		ft_deltab.c \
		ft_lstrev.c \
		ft_strdigit.c

O_DIR = ft_lstdel.o \
		ft_memmove.o \
		ft_strchr.o \
		ft_strlen.o \
		ft_strstr.o \
		ft_lstdelone.o \
		ft_memset.o \
		ft_strclr.o \
		ft_strmap.o \
		ft_strsub.o \
		ft_atoi.o \
		ft_lstiter.o \
		ft_putchar.o \
		ft_strcmp.o \
		ft_strmapi.o \
		ft_strtrim.o \
		ft_bzero.o \
		ft_lstmap.o \
		ft_putchar_fd.o \
		ft_strcpy.o \
		ft_strncat.o \
		ft_tolower.o \
		ft_isalnum.o \
		ft_lstnew.o \
		ft_putendl.o \
		ft_strdel.o \
		ft_strncmp.o \
		ft_toupper.o \
		ft_isalpha.o \
		ft_memalloc.o \
		ft_putendl_fd.o \
		ft_strdup.o \
		ft_strncpy.o \
		ft_isascii.o \
		ft_memccpy.o \
		ft_putnbr.o \
		ft_strequ.o \
		ft_strnequ.o \
		ft_isdigit.o \
		ft_memchr.o \
		ft_putnbr_fd.o \
		ft_striter.o \
		ft_strnew.o \
		ft_isprint.o \
		ft_memcmp.o \
		ft_putstr.o \
		ft_striteri.o \
		ft_strnstr.o \
		ft_itoa.o \
		ft_memcpy.o \
		ft_putstr_fd.o \
		ft_strjoin.o \
		ft_strrchr.o \
		ft_lstadd.o \
		ft_memdel.o \
		ft_strcat.o \
		ft_strlcat.o \
		ft_strsplit.o \
		ft_count_words.o \
		ft_atoi_base.o \
		ft_isspace.o \
		ft_print_words_tables.o \
		ft_itoa_base.o \
		ft_swap.o \
		ft_sqrt.o \
		ft_find_next_prime.o \
		ft_isnegative.o \
		get_next_line.o \
		ft_degtorad.o \
		ft_radtodeg.o \
		ft_atod.o \
	   	ft_pow.o \
		ft_tablen.o \
		ft_deltab.o \
		ft_lstrev.o \
		ft_strdigit.o

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(FILES)
	ar rc libft.a $(O_DIR)

clean:
	$(RM) $(O_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
