# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/23 16:47:01 by vbranco      #+#   ##    ##    #+#        #
#    Updated: 2018/06/18 15:54:54 by vbranco     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME	 = libft.a

HEADER	 = libft.h

SRCS	 = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	   ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
	   ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
	   ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
	   ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	   ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c \
	   ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
	   ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
	   ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
	   ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c	ft_putstr_fd.c \
	   ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c \
	   ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
	   ft_isblank.c ft_isupper.c ft_isxdigit.c ft_isspace.c ft_islower.c \
	   ft_size_nb.c ft_reverse.c ft_count_words.c ft_realloc.c get_next_line.c \
	   ft_strexpand.c ft_free_2char.c

OBJ 	= $(addprefix build/, $(SRCS:.c=.o))

PF 		= ./ft_printf

PFOBJ 	= ft_printf/build/*

CFLAGS 	= -Wall -Wextra -Werror

.PHONY: all clean fclean re build message

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(PF)
	@ar -rc $@ $^ $(PFOBJ)
	@ranlib $(NAME)

build:
	@mkdir build/
	@echo "\033[32m Making libft"

build/%.o: ./%.c | build
	@gcc $(CFLAGS) -I $(HEADER) -c $< -o $@

clean:
	@$(MAKE) -C $(PF) clean
	@/bin/rm -rf build/
	@echo "\033[31m Cleanning libft"

fclean: clean
	@echo "\033[31m FCleanning libft"
	@$(MAKE) -C $(PF) fclean
	@/bin/rm -rf $(NAME)

re:
	@echo "\033[32m RE libft"
	@$(MAKE) fclean
	@$(MAKE) all
