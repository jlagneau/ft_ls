#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/21 08:29:58 by jlagneau          #+#    #+#              #
#    Updated: 2014/11/15 00:54:25 by jlagneau         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# Variables
NAME      = ft_ls
DEB_NAME  = debug_ft_ls

ISGIT     := $(shell find . -name ".git" -type d)
HASTAGS   := $(shell git tag)
ifneq (, $(strip $(ISGIT)))
ifneq (, $(strip $(HASTAGS)))
	VER   := $(shell git describe --tags `git rev-list --tags --max-count=1`)
endif
	GDATE := $(shell git show -s --format="%ci" HEAD)
endif

LIB       = libft/

OBJS_PATH = bin/
SRCS_PATH = src/
HEAD_PATH = include/

CC        = gcc
CFLAGS    = -I$(HEAD_PATH) -I$(LIB)$(HEAD_PATH) -Wall -Wextra -Werror
LDFLAGS   = -L$(LIB)

AR        = ar
ARFLAGS   = rcs

RM        = rm
RMFLAGS   = -rf

# Sources files
SRCS      = src/print_link_dest.c src/padding.c src/error.c src/print_link.c \
			src/get_options.c src/get_files.c src/get_directories.c \
			src/get_directory_content.c src/print_size.c src/print_mode.c \
			src/print_total.c src/main.c src/print_date.c src/set_file_path.c \
			src/free_file.c src/print_simple.c src/print_user_group.c \
			src/print_long.c src/init.c src/sort.c src/print_recursive.c \
			src/custom.c src/print_directories.c src/set_file.c src/print.c \
			src/get_params.c src/print_name.c
OBJS      = $(addprefix $(OBJS_PATH), $(notdir $(SRCS:.c=.o)))
DEB_OBJS  = $(addprefix $(OBJS_PATH), $(notdir $(SRCS:.c=_debug.o)))

# Print informations about the library
$(info :: Project: $(NAME))
ifneq (, $(strip $(ISGIT)))
ifneq (, $(strip $(HASTAGS)))
    $(info :: Version : $(VER))
endif
    $(info :: Last modifications : $(GDATE))
endif

# Rules
$(NAME): CFLAGS += -g3
$(NAME): LDFLAGS += -lft
$(NAME): $(OBJS)
	make -C $(LIB)
	printf "[\033[36m%20s\033[0m] Linking and indexing" $(NAME)
	$(CC) $^ $(LDFLAGS) -o $@
	printf " [\033[32mDONE\033[0m]\n"

$(DEB_NAME): $(DEB_OBJS)
	make -C $(LIB) debug
	printf "[\033[36m%20s\033[0m] Linking and indexing" $(DEB_NAME)
	$(CC) $^ $(LDFLAGS) -o $@
	printf " [\033[32mDONE\033[0m]\n"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	if [ ! -d $(OBJS_PATH) ]; then \
	mkdir -p $(OBJS_PATH); \
	printf "[\033[36m%20s\033[0m] Compiling objects" $(NAME); \
	printf "    [\033[32mDONE\033[0m]\n"; \
	fi;
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_PATH)%_debug.o: $(SRCS_PATH)%.c
	if [ ! -d $(OBJS_PATH) ]; then \
	mkdir -p $(OBJS_PATH); \
	printf "[\033[36m%20s\033[0m] Compiling objects" $(NAME); \
	printf "    [\033[32mDONE\033[0m]\n"; \
	fi;
	$(CC) $(CFLAGS) -c $< -o $@

debug: CFLAGS += -g3
debug: LDFLAGS += -lft_debug
debug: $(DEB_NAME)

redebug: fclean debug

norme:
	norminette ./**/*.{h,c}

all: $(NAME)

clean:
	printf "[\033[36m%20s\033[0m] Removing objects" $(NAME)
	$(RM) $(RMFLAGS) $(OBJS_PATH)
	printf "     [\033[32mDONE\033[0m]\n"
	make -C $(LIB) clean

fclean:
	printf "[\033[36m%20s\033[0m] Removing objects" $(NAME)
	$(RM) $(RMFLAGS) $(OBJS_PATH)
	printf "     [\033[32mDONE\033[0m]\n"
	printf "[\033[36m%20s\033[0m] Removing binary" $(NAME)
	$(RM) $(RMFLAGS) $(NAME) $(DEB_NAME)
	printf "      [\033[32mDONE\033[0m]\n"
	make -C $(LIB) fclean

re: fclean all

.PHONY: all clean debug fclean lib lib_debug norme re redebug

.SILENT:
