# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/07 17:08:49 by vbranco      #+#   ##    ##    #+#        #
#    Updated: 2018/06/27 19:40:15 by vbranco     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME		=	ft_select

HEADER		=	ft_select.h

FILENAMES	=	main.c ft_move_and_dell.c ft_tools_lst.c ft_get_input.c ft_printing.c ft_term.c \

SOURCES		=	$(addprefix ./, $(FILENAMES))

OBJECTS		=	$(addprefix build/, $(FILENAMES:.c=.o))

L_FT		=	./libft

LIB			=	./libft/libft.a

LIB_LNK		=	-L $(L_FT) -l ft

LIB_INC		=	-I $(L_FT)/libft.h

LAGS		=	-Wall -Wextra -Werror -g #penser a enlever le -g

.PHONY: all clean fclean re

all: $(NAME)

clean:
		@echo "\033[31m Cleanning ft_select"
		@rm -rf build/
#		@$(MAKE) -C $(L_FT) clean

fclean: clean
	    @echo "\033[31m FCleanninf ft_select"
		@rm -f $(NAME)
#		@$(MAKE) -C $(L_FT) fclean

re:		fclean all#enlever
#		@echo "\033[32m RE ft_select"
#		@$(MAKE) fclean
#		@$(MAKE) all

build:
	    @echo "\033[32m Making ft_select"
		@mkdir build/

$(NAME): $(OBJECTS)
#		@$(MAKE) -C $(L_FT)
		@gcc $(FLAGS) -I  $(HEADER) $(SOURCES) $(LIB) -lncurses -o $@ #-g
		@echo " Ready to play"

build/%.o: ./%.c | build
	    @gcc $(FLAGS) $(LIB_INC) -I $(HEADER) -c $< -o $@
