#include "ft_select.h"

int					ft_prepare_term(t_head_arg *head, int i)
{
	if (i)
	{
		if (!isatty(0))
			return (-1);
		if ((head->fd = open(ttyname(0), O_RDWR)) == -1)
			return (-1);
		if (tcgetattr(head->fd, &(head->term)) == -1)
			return (-1);
	}
//	ft_verif_signal();
	ft_config_term(head, 1);
	ft_display_size(0);
	ft_get_input(head);
	ft_config_term(head, 0);
	close(head->fd);
	return (0);
}

void				ft_config_term(t_head_arg *head, int start)
{
	if (start)
	{
		head->term.c_lflag &= ~(ICANON);
		head->term.c_lflag &= ~(ECHO);
		head->term.c_cc[VMIN] = 1;
		head->term.c_cc[VTIME] = 0;
		tcsetattr(head->fd, TCSANOW, &(head->term));
		tputs(tgetstr("ti", NULL), 1, my_putchar);
		tputs(tgetstr("vi", NULL), 1, my_putchar);
	}
	else
	{
		head->term.c_lflag |= (ICANON | ECHO);
		tcsetattr(head->fd, 0, &(head->term));
		tputs(tgetstr("te", NULL), 1, my_putchar);
		tputs(tgetstr("ve", NULL), 1, my_putchar);
	}
}

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
