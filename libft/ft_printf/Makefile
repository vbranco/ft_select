NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

HEADER = ft_printf.h

FILES = ft_arg_c.c ft_arg_d_i.c ft_arg_p.c ft_arg_s.c ft_arg_x_o.c \
	ft_convert_base_uintmax.c ft_convert_base_intmax.c ft_format.c ft_wchar.c \
	ft_init_struct.c ft_printf.c ft_percent.c\
	ft_args.c ft_recup_flag.c ft_recup_length.c ft_recup_min.c ft_recup_prec.c \
	ft_recup_type.c ft_wstr.c ft_count_size.c ft_my_itoa.c ft_my_itoa2.c\
	ft_size_nb2.c ft_add_str_begin.c ft_p_min.c\
	ft_add_str_end.c ft_buffer_d_i.c ft_arg_b.c ft_buffer_x_o.c ft_buffer_b.c\
	ft_buffer_s.c ft_buffer_c.c ft_d_neg.c ft_d_prec.c ft_zero.c ft_x_prec.c


#SOURCES = $(addprefix ./, $(FILES))

OBJ = $(addprefix ./build/, $(FILES:.c=.o))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)

re: fclean all

build:
	@mkdir build/

build/%.o: ./%.c | build 
	@gcc $(FLAGS) -I $(HEADER) $(SOURCES) -c $^ -o $@

clean:
	@rm -rf build/

fclean: clean
	@rm -rf $(NAME)
