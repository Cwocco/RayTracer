# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 09:52:36 by alucas-           #+#    #+#              #
#    Updated: 2018/03/04 17:39:11 by alucas-          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT ?= libft
WFLAGS = -Werror -Wextra -Wall
WWFLAGS = $(WFLAGS) -Wpedantic -Wshadow -Wconversion -Wcast-align \
  -Wstrict-prototypes -Wmissing-prototypes -Wunreachable-code -Winit-self \
  -Wmissing-declarations -Wfloat-equal -Wbad-function-cast -Wundef \
  -Waggregate-return -Wstrict-overflow=5 -Wold-style-definition -Wpadded \
  -Wredundant-decls -Wall -Werror -Wextra
RCFLAGS = $(WFLAGS) -Ofast
DCFLAGS = $(WFLAGS) -g3 -DDEBUG
SCFLAGS = $(DCFLAGS) -fsanitize=address,undefined -ferror-limit=5
CC ?= gcc

INC_PATH = .
SRC_PATH = .
OBJ_DIR ?= obj
OBJ_PATH ?= $(OBJ_DIR)/rel
3TH_PATH =

LIBS =
ifneq (,$(findstring dev,$(PROJECT)))
LIB_NAME = $(addsuffix .dev, $(LIBS))
else ifneq (,$(findstring san,$(PROJECT)))
LIB_NAME = $(addsuffix .san, $(LIBS))
else
LIB_NAME = $(LIBS)
endif
3TH_NAME =
SRC_NAME = \
	ft_lstdel.c \
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
	ft_radtodeg.c 

3TH = $(addprefix $(3TH_PATH)/, $(3TH_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))
LNK = $(addprefix -L, $(3TH))
INC = $(addprefix -I, $(INC_PATH) $(addsuffix /include, $(3TH)))
LIB = $(addprefix -l, $(LIB_NAME))
DEP = $(OBJ:%.o=%.d)

PRINTF=test $(VERBOSE)$(TRAVIS) || printf

all:
ifneq ($(3TH_NAME),)
	+$(foreach 3th,$(3TH_NAME),$(MAKE) -C $(3TH_PATH)/$(3th) &&) true
endif
	@$(PRINTF) "%-20s" "$(PROJECT).a: lib"
	+$(MAKE) -j4 $(PROJECT).a "CFLAGS = $(RCFLAGS)" "OBJ_PATH = $(OBJ_DIR)/rel"
	@$(PRINTF) "\r\x1b[20C\x1b[0K\x1b[32m✔\x1b[0m\n"

dev:
ifneq ($(3TH_NAME),)
	+$(foreach 3th,$(3TH_NAME),$(MAKE) -C $(3TH_PATH)/$(3th) dev &&) true
endif
	@$(PRINTF) "%-20s" "$(PROJECT).dev: exe"
	+$(MAKE) -j4 $(PROJECT).dev.a "PROJECT = $(PROJECT).dev" "CFLAGS = $(DCFLAGS)" \
	  "OBJ_PATH = $(OBJ_DIR)/dev"
	@$(PRINTF) "\r\x1b[20C\x1b[0K\x1b[32m✔\x1b[0m\n"

san:
ifneq ($(3TH_NAME),)
	+$(foreach 3th,$(3TH_NAME),$(MAKE) -C $(3TH_PATH)/$(3th) san &&) true
endif
	@$(PRINTF) "%-20s" "$(PROJECT).san: exe"
	+$(MAKE) -j4 $(PROJECT).san.a "PROJECT = $(PROJECT).san" "CFLAGS = $(SCFLAGS)" \
	  "OBJ_PATH = $(OBJ_DIR)/san" "CC = clang"
	@$(PRINTF) "\r\x1b[20C\x1b[0K\x1b[32m✔\x1b[0m\n"

mecry:
ifneq ($(3TH_NAME),)
	+$(foreach 3th,$(3TH_NAME),$(MAKE) -C $(3TH_PATH)/$(3th) mecry &&) true
endif
	@$(PRINTF) "%-20s" "$(PROJECT).a: make me cry.."
	+$(MAKE) -j4 $(PROJECT).a "CFLAGS = $(WWFLAGS)" "OBJ_PATH = $(OBJ_DIR)/rel"
	@$(PRINTF) "\r\x1b[20C\x1b[0K\x1b[32m✔\x1b[0m\n"

$(PROJECT).a: $(OBJ)
	@$(PRINTF) "\r\x1b[20C\x1b[0K$@"
	ar -rc $(PROJECT).a $(OBJ)
	ranlib $(PROJECT).a

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
	rm -f $(PROJECT){,.san,.dev}.a
	@$(PRINTF) "%-20s\033[32m✔\033[0m\n" "$(PROJECT): $@"

re: clean all

-include $(DEP)

ifndef VERBOSE
 ifndef TRAVIS
.SILENT:
 endif
endif

.PHONY: all, dev, san, mecry, $(PROJECT).a, clean, fclean, re
