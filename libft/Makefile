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
NAME      = libft.a
DEB_NAME  = libft_debug.a

LIB_PATH  = /usr/lib
INC_PATH  = /usr/include

OBJS_PATH = bin/
SRCS_PATH = src/
HEAD_PATH = include/

CC        = clang
CFLAGS    = -I$(HEAD_PATH) -Wall -Wextra -Werror -pedantic -ansi

AR        = ar
ARFLAGS   = rcs

RM        = rm
RMFLAGS   = -rf

# Sources files (find src -type f | tr "\n" " " to get the list).
SRCS      = src/ft_putstr_fd.c src/ft_isalpha.c src/ft_memcpy.c \
			src/ft_strsplit.c src/ft_strlcat.c src/ft_lstdel.c \
			src/ft_strjoin.c src/ft_memalloc.c src/ft_isalnum.c \
			src/ft_strncpy.c src/ft_strcmp.c src/ft_putstr.c \
			src/ft_strsub.c src/ft_strequ.c src/ft_lstlast.c \
			src/ft_putendl.c src/ft_lstaddend.c src/ft_strmap.c \
			src/ft_memcmp.c src/ft_itoa.c src/ft_strncmp.c src/ft_bzero.c \
			src/ft_isdigit.c src/ft_strdup.c src/ft_strmapi.c \
			src/ft_lstadd.c src/ft_isprint.c src/ft_lstnew.c \
			src/ft_putendl_fd.c src/ft_strdel.c src/ft_strcat.c \
			src/ft_memdel.c src/get_next_line.c src/ft_memccpy.c \
			src/ft_strnew.c src/ft_strtrim.c src/ft_striteri.c \
			src/ft_strchr.c src/ft_strncat.c src/ft_stradel.c \
			src/ft_strlen.c src/ft_lstiter.c src/ft_strstr.c \
			src/ft_striter.c src/ft_atoi.c src/ft_toupper.c \
			src/ft_lstlen.c src/ft_putchar.c src/ft_putnbr.c \
			src/ft_putchar_fd.c src/ft_memmove.c src/ft_strrealloc.c \
			src/ft_tolower.c src/ft_strcpy.c src/ft_memset.c \
			src/ft_lstdelone.c src/ft_strrchr.c src/ft_memchr.c \
			src/ft_putnbr_fd.c src/ft_isspace.c src/ft_lstmap.c \
			src/ft_strnstr.c src/ft_strclr.c src/ft_strnequ.c \
			src/ft_isascii.c src/ft_stralen.c
OBJS      = $(addprefix $(OBJS_PATH), $(notdir $(SRCS:.c=.o)))

# Rules
$(NAME): CFLAGS += -O3
$(NAME): $(OBJS)
	printf "    [\033[32mDONE\033[0m]\n"
	printf "[\033[36m%20s\033[0m] Linking and indexing" $(NAME)
	$(AR) $(ARFLAGS) $@ $^
	ranlib $@
	printf " [\033[32mDONE\033[0m]\n"

$(DEB_NAME): $(OBJS)
	printf "    [\033[32mDONE\033[0m]\n"
	printf "[\033[36m%20s\033[0m] Linking and indexing" $(NAME)
	$(AR) $(ARFLAGS) $@ $^
	ranlib $@
	printf " [\033[32mDONE\033[0m]\n"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	if [ ! -d $(OBJS_PATH) ]; then \
	mkdir -p $(OBJS_PATH); \
	printf "[\033[36m%20s\033[0m] Compiling objects" $(NAME); \
	fi;
	$(CC) $(CFLAGS) -c $< -o $@

debug: CFLAGS += -g3
debug: clean $(DEB_NAME)

redebug: fclean debug

norme:
	norminette ./**/*.{h,c}

all: $(NAME)

clean:
	printf "[\033[36m%20s\033[0m] Removing objects" $(NAME)
	$(RM) $(RMFLAGS) $(OBJS_PATH)
	printf "     [\033[32mDONE\033[0m]\n"

fclean: clean
	printf "[\033[36m%20s\033[0m] Removing binary" $(NAME)
	$(RM) $(RMFLAGS) $(NAME) $(DEB_NAME)
	printf "      [\033[32mDONE\033[0m]\n"

re: fclean all

.PHONY: all clean debug fclean re redebug

.SILENT:
