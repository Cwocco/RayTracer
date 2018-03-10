# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/24 11:54:00 by rpinoit           #+#    #+#              #
#    Updated: 2018/03/10 14:42:08 by ada-cunh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT ?= rt
WFLAGS = -Werror -Wextra -Wall
WWFLAGS = $(WFLAGS) -Wpedantic -Wshadow -Wconversion -Wcast-align \
  -Wstrict-prototypes -Wmissing-prototypes -Wunreachable-code -Winit-self \
  -Wmissing-declarations -Wfloat-equal -Wbad-function-cast -Wundef \
  -Waggregate-return -Wstrict-overflow=5 -Wold-style-definition -Wpadded \
  -Wredundant-decls -Wall -Werror -Wextra
RCFLAGS = $(WFLAGS) -Ofast
DCFLAGS = $(WFLAGS) -g3 -DDEBUG
SCFLAGS = -fsanitize=address,undefined -ferror-limit=5 $(DCFLAGS)
CC ?= gcc

INC_PATH = incs
SRC_PATH = srcs
OBJ_DIR ?= obj
OBJ_PATH ?= $(OBJ_DIR)/rel
3TH_PATH = .

LIBS = ft
ifneq (,$(findstring dev,$(PROJECT)))
LIB_NAME = $(addsuffix .dev, $(LIBS))
else ifneq (,$(findstring san,$(PROJECT)))
LIB_NAME = $(addsuffix .san, $(LIBS))
else
LIB_NAME = $(LIBS)
endif
LIB_NAME += mlx
3TH_NAME = libft
SRC_NAME = \
	main.c \
	error.c \
	raytracer.c \
	vector_utilities.c \
	intersection.c \
	light.c \
	parser.c \
	parser_obj.c \
	parser_utils.c \
	parser_libft.c \
	math_utilities.c \
	pixel.c \
	obj_normal.c \
	light_phong_shading.c \
	vector_rotate.c \
	draw.c \
	hook.c \
	hook2.c \
	anti_alias.c \
	set_perlin.c \
	set_param_perlin.c \
	inter_perlin.c \
	main_perlin.c \
	ellipse.c \
	set_damier.c 

3TH = $(addprefix $(3TH_PATH)/, $(3TH_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))
LNK = $(addprefix -L, $(3TH))
INC = $(addprefix -I, $(INC_PATH) $(3TH))
LIB = $(addprefix -l, $(LIB_NAME))
DEP = $(OBJ:%.o=%.d)

PRINTF=test $(VERBOSE)$(TRAVIS) || printf

ifneq (,$(findstring dev,$(PROJECT)))
3DE = $(shell echo "$(3TH_NAME)" | sed -E "s|([\.a-zA-Z]+)|$(3TH_PATH)/\1/\1.dev.a|g")
else ifneq (,$(findstring san,$(PROJECT)))
3DE = $(shell echo "$(3TH_NAME)" | sed -E "s|([\.a-zA-Z]+)|$(3TH_PATH)/\1/\1.san.a|g")
else
3DE = $(shell echo "$(3TH_NAME)" | sed -E "s|([\.a-zA-Z]+)|$(3TH_PATH)/\1/\1.a|g")
endif

all:
ifneq ($(3TH_NAME),)
	+$(foreach 3th,$(3TH_NAME),$(MAKE) -C $(3TH_PATH)/$(3th) &&) true
endif
	@$(PRINTF) "%-20s" "$(PROJECT): exe"
	+$(MAKE) -j4 $(PROJECT) "CFLAGS = $(RCFLAGS)" "OBJ_PATH = $(OBJ_DIR)/rel"
	@$(PRINTF) "\r\x1b[20C\x1b[0K\x1b[32m✔\x1b[0m\n"

dev:
ifneq ($(3TH_NAME),)
	+$(foreach 3th,$(3TH_NAME),$(MAKE) -C $(3TH_PATH)/$(3th) dev &&) true
endif
	@$(PRINTF) "%-20s" "$(PROJECT).dev: exe"
	+$(MAKE) -j4 $(PROJECT).dev "PROJECT = $(PROJECT).dev" "CFLAGS = $(DCFLAGS)" \
	  "OBJ_PATH = $(OBJ_DIR)/dev"
	@$(PRINTF) "\r\x1b[20C\x1b[0K\x1b[32m✔\x1b[0m\n"

san:
ifneq ($(3TH_NAME),)
	+$(foreach 3th,$(3TH_NAME),$(MAKE) -C $(3TH_PATH)/$(3th) san &&) true
endif
	@$(PRINTF) "%-20s" "$(PROJECT).san: exe"
	+$(MAKE) -j4 $(PROJECT).san "PROJECT = $(PROJECT).san" "CFLAGS = $(SCFLAGS)" \
	  "OBJ_PATH = $(OBJ_DIR)/san" "CC = clang"
	@$(PRINTF) "\r\x1b[20C\x1b[0K\x1b[32m✔\x1b[0m\n"

mecry:
ifneq ($(3TH_NAME),)
	+$(foreach 3th,$(3TH_NAME),$(MAKE) -C $(3TH_PATH)/$(3th) mecry &&) true
endif
	@$(PRINTF) "%-20s" "$(PROJECT): make me cry.."
	+$(MAKE) -j4 $(PROJECT) "CFLAGS = $(WWFLAGS)" "OBJ_PATH = $(OBJ_DIR)/rel"
	@$(PRINTF) "\r\x1b[20C\x1b[0K\x1b[32m✔\x1b[0m\n"

$(PROJECT): $(3DE) $(OBJ)
	@$(PRINTF) "\r\x1b[20C\x1b[0K$@"
	$(CC) $(CFLAGS) $(INC) $(LNK) $(OBJ) $(LIB) -framework OpenGL -framework Appkit -o $(PROJECT)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@$(PRINTF) "\r\x1b[20C\x1b[0K$<"
	$(CC) $(CFLAGS) $(INC) -MMD -MP -c $< -o $@

$(OBJ_PATH):
	mkdir -p $(dir $(OBJ))

clean:
	rm -rf $(OBJ_DIR)
	@$(PRINTF) "%-20s\033[32m✔\033[0m\n" "$(PROJECT): $@"

fclean: clean
ifneq ($(3TH_NAME),)
	+$(foreach 3th,$(3TH_NAME),$(MAKE) -C $(3TH_PATH)/$(3th) fclean &&) true
endif
	rm -f $(PROJECT){,.san,.dev}
	@$(PRINTF) "%-20s\033[32m✔\033[0m\n" "$(PROJECT): $@"

re: clean all

-include $(DEP)

ifndef VERBOSE
 ifndef TRAVIS
.SILENT:
 endif
endif

.PHONY: all, dev, san, mecry, $(PROJECT), clean, fclean, re
