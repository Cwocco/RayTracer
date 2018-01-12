# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nboste <nboste@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 12:55:14 by nboste            #+#    #+#              #
#    Updated: 2018/01/08 17:11:05 by rpinoit          ###   ########.fr        #
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
	  srcs/camera.c \
	  srcs/vector_utility.c \
	  srcs/intersection.c \
	  srcs/light.c \
	  srcs/parser.c \
	  srcs/parser_obj.c \
	  srcs/parser_utils.c \
	  srcs/parser_libft.c

OBJ = $(SRC:%.c=%.o)

INC = -I./incs \
	  -I./libft/includes \
	  -I/usr/include \
	  -I ~/Library/Frameworks/SDL2.framework/Headers \

LIB = -L./libft \
	  -F ~/Library/Frameworks/SDL2.framework/Versions/Current \

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(FLG) $(LIB) $(INC) $(SRC) -lm -lft -framework SDL2 -o $(NAME)

debug:
	make -C libft
	gcc $(FLG) $(LIB) $(INC) $(SRC) -lm -lft -framework SDL2 -o $(NAME) -g

linux:
	make -C libft
	gcc $(FLG) $(INC) $(SRC) $(LIB) -lm -lft -lSDL2 -o $(NAME) -O3 -flto

linuxd:
	make -C libft
	gcc $(FLG) $(LIB) $(INC) $(SRC) -lm -lft -lSDL2 -o $(NAME) -O3 -g -pg

clean:
	make -C libft clean
	rm -f $(NAME)

fclean: clean
	make -C libft fclean
	rm -rf $(OBJ)

re: clean all
