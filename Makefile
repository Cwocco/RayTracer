# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/24 11:54:00 by rpinoit           #+#    #+#              #
#    Updated: 2018/02/05 08:50:57 by rpinoit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

FLG = -Wall -Wextra -Werror

SRC = srcs/main.c \
	  srcs/rtv1.c \
	  srcs/error.c \
	  srcs/drawer.c \
	  srcs/event.c \
	  srcs/raytracer.c \
	  srcs/vector_utilities.c \
	  srcs/intersection.c \
	  srcs/light.c \
	  srcs/parser.c \
	  srcs/parser_obj.c \
	  srcs/parser_utils.c \
	  srcs/parser_libft.c \
	  srcs/math_utilities.c \
	  srcs/pixel.c \
	  srcs/obj_normal.c \
	  srcs/light_phong_shading.c \
	  srcs/vector_rotate.c

OBJ = $(SRC:%.c=%.o)

INC = -I./incs \
	  -I./libft/ \
	  -I/usr/include \
	  -I ~/Library/Frameworks/SDL2.framework/Headers \

LIB = -L./libft \
	  -F ~/Library/Frameworks/SDL2.framework/Versions/Current \

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(FLG) $(LIB) $(INC) $(SRC) -lm -lft -framework SDL2 -o $(NAME)

clean:
	make -C libft clean
	rm -f $(NAME)

fclean: clean
	make -C libft fclean
	rm -rf $(OBJ)

re: clean all
