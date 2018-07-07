#include "ft_select.h"

t_head_arg	*head;

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

void		ft_display_size(int sig)
{
	struct winsize	wind;

	(void)sig;
	ioctl(0, TIOCGWINSZ, &wind);
	head->li = wind.ws_row;
	head->co = wind.ws_col;
	write(head->fd, tgetstr("cl", NULL), ft_strlen(tgetstr("cl", NULL)));
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, my_putchar);
	ft_print_args(head);
}

void		ft_frontground(int sig)//problem quand fait 2x
{
	if (ft_prepare_term(head, 0))
	{
		ft_putendl_fd("Cannot initialise TERM", 2);
		ft_dell_args(&head);
		return ;
	}
}

void		ft_background(int sig)//problem quand fait 2x
{
	ft_config_term(head, 0);
//	close(head->fd);
	if (sig == SIGTSTP)
	{
		signal(SIGTSTP, SIG_DFL);
		ioctl(0, TIOCSTI, "\x1A");
	}
}

void		ft_stop(int sig)
{
	ft_background(sig);
	ft_dell_args(&head);
	exit(EXIT_SUCCESS);
}

void		ft_verif_signal(void)
{
	signal(SIGWINCH, ft_display_size);
	signal(SIGCONT, ft_frontground);
	signal(SIGTSTP, ft_background);
	signal(SIGINT, ft_stop);
	signal(SIGHUP, ft_stop);
	signal(SIGTERM, ft_stop);
	signal(SIGSEGV, ft_stop);
	signal(SIGQUIT, ft_stop);
	signal(SIGFPE, ft_stop);
	signal(SIGALRM, ft_stop);
	signal(SIGKILL, ft_stop);
	signal(SIGABRT, ft_stop);
	signal(SIGUSR1, ft_stop);
	signal(SIGUSR2, ft_stop);
}

int			main(int ac, char **av)
{
	t_arg			*tmp;

	if (ac == 1)
		return (ft_printf("Usage: ./ft_select [arg1] [arg2] [...]\n"));
	if (ft_init_term())
		return (-1);
	ft_verif_signal();
	head = initialise_head();
	ft_get_args(head, ac, av);
	tmp = head->start;
	tmp->pos = 1;
	if (ft_prepare_term(head, 1))
	{
		ft_putendl_fd("Cannot initialise TERM", 2);
		ft_dell_args(&head);
		return (-1);
	}
	ft_dell_args(&head);
//	close(head->fd);
	return (0);
}
