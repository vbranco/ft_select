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
ft_calculate_for_print.c \
ft_signal.c


SOURCES		=	$(addprefix ./, $(FILENAMES))

OBJECTS		=	$(addprefix build/, $(FILENAMES:.c=.o))

L_FT		=	./libft

LIB			=	./libft/libft.a

LIB_LNK		=	-L $(L_FT) -l ft

LIB_INC		=	-I $(L_FT)/libft.h

LAGS		=	-Wall -Wextra -Werror

.PHONY: all clean fclean re build 

all: $(NAME)

$(NAME): $(OBJECTS)
		@$(MAKE) -C $(L_FT)
		@gcc $(FLAGS) -I  $(HEADER) $(SOURCES) $(LIB) -lncurses -o $@
		@echo " Ready to play"

build:
	    @echo "\033[32m Making ft_select"
		@mkdir build/

build/%.o: ./%.c | build
	    @gcc $(FLAGS) $(LIB_INC) -I $(HEADER) -c $< -o $@

clean:
		@echo "\033[31m Cleanning ft_select"
		@$(MAKE) -C $(L_FT) clean
		@rm -rf build/

fclean: clean
		@$(MAKE) -C $(L_FT) fclean
		@rm -f $(NAME)

re:
		@echo "\033[32m RE ft_select"
		@$(MAKE) fclean
		@$(MAKE) all


