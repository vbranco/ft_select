#include "ft_select.h"

int			ft_init_term(void)
{
	int		ret;
	char	*term_type;

	term_type = getenv("TERM");
	if (!term_type)
	{
		ft_putendl_fd("TERM environment variable not set.", 2);
		return (-1);
	}
	ret = tgetent(NULL, term_type);
	if (ret == -1)
	{
		ft_putendl_fd("Could not access to termcap database\n", 2);
		return (-1);
	}
	else if (ret == 0)
	{
		ft_putendl_fd("Terminal type is not defined", 2);
		return (-1);
	}
	return (0);
}

void		ft_get_args(t_head_arg *head, int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		add_arg(head, av[i]);
		i++;
	}
}

int					ft_prepare_term(t_head_arg *head)
{
	int				fd;
	struct termios	term;
	struct termios	term_backup;

	fd = open("/dev/tty", O_RDWR);
	if (fd == -1)
		return (-1);
	if (tcgetattr(fd, &term) == -1)
		return (-1);
	if (tcgetattr(fd, &term_backup) == -1)
		return (-1);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	tcsetattr(fd, TCSADRAIN, &term);
	tputs(tgetstr("ti", NULL), 1, my_putchar);
	tputs(tgetstr("vi", NULL), 1, my_putchar);
	ft_print_args(head, fd);
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, my_putchar);
	ft_get_input(head, fd);
	tputs(tgetstr("te", NULL), 1, my_putchar);
	tputs(tgetstr("ve", NULL), 1, my_putchar);
	tcsetattr(fd, TCSADRAIN, &term_backup);
	close(fd);
	return (0);
}

int			main(int ac, char **av)
{
	t_head_arg		*head;
	t_arg			*tmp;

	if (ac == 1)
		return (ft_printf("Usage: ./ft_select [arg1] [arg2] [...]\n"));
	if (ft_init_term())
		return (-1);
	head = initialise_head();
	ft_get_args(head, ac, av);
	tmp = head->start;
	tmp->pos = 1;
	if (ft_prepare_term(head))
	{
		ft_putendl_fd("Cannot initialise TERM", 2);
		return (1);
	}
	ft_dell_args(&head);
	return (0);
}
