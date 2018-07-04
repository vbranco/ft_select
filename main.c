#include "ft_select.h"

int			init_term(void)
{
	int		ret;
	char	*term_type;

	//verifier avec un env vide
	term_type = getenv("TERM");
	if (!term_type)
	{
		printf("TERM must be set\n");
		return (-1);
	}
	ret = tgetent(NULL, term_type);
	if (ret == -1)
	{
		printf("Could not access to termcap database\n");
		return (-1);
	}
	else if (ret == 0)
	{
		printf("Terminal type %s is not defined\n", term_type);
		return (-1);
	}
	return (0);
}

int		my_putchar(int c)
{
	char ca;

	ca = (char)c;
	write(1, &ca, 1);
	return (1);
}

void		print(char *s)
{
	int		i = 0;

	while (s[i])
	{
		if (s[i] == '\x1b')
			printf("ESC");
		else
			putchar(s[i]);
		i++;
	}
	putchar('\n');
}

void	gotoxy(int x, int y)
{
	printf("%c[%d;%df", 0x1B, y, x);
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

void		ft_underline(int i)
{
	if (i)
		tputs(tgetstr("us", NULL), 1, my_putchar);
	else
		tputs(tgetstr("ue", NULL), 1, my_putchar);
}

void		ft_reverse_video(int i)
{
	if (i)
		tputs(tgetstr("mr", NULL), 1, my_putchar);
	else
		tputs(tgetstr("me", NULL), 1, my_putchar);

}

void		ft_print_args(t_head_arg *head, int fd)
{
	t_arg	*tmp;

	if (!head->start)
		return ;
	tmp = head->start;
	while (tmp)
	{
		if (tmp->pos)
		{
			write(fd, "posi>", 5);
			ft_underline(1);
		}
		write(fd, tmp->info, ft_strlen(tmp->info));
		if (tmp->pos)
			ft_underline(0);
		write(fd, " ", 2);
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
}

int			ft_prepare_term(t_head_arg *head)
{
	int		fd;
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
	write(fd, tgetstr("ti", NULL), ft_strlen(tgetstr("ti", NULL)));
	write(fd, tgetstr("vi", NULL), ft_strlen(tgetstr("vi", NULL)));
	ft_print_args(head, fd);
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, my_putchar);
	ft_get_input(head, fd);
	write(fd, tgetstr("te", NULL), ft_strlen(tgetstr("te", NULL)));
	write(fd, tgetstr("ve", NULL), ft_strlen(tgetstr("ve", NULL)));
	tcsetattr(fd, TCSADRAIN, &term_backup);
	close(fd);
	return (0);
}

int			main(int ac, char **av)
{
	t_head_arg		*head;
	int				ret;

	head = initialise_head();
	ft_get_args(head, ac, av);
	if (!head->start)
	{
		ft_printf("Usage: ./ft_select [arg1] [arg2] [...]\n");
		return (1);
	}
	
	ret = init_term();
	if (ft_prepare_term(head))
	{
		ft_putendl_fd("Bordel dans l'initialisation du TERM", 2);
		return (1);
	}
/*	if (tcgetattr(0, &term) == -1)
		return (-1);
	if (tcgetattr(0, &term_backup) == -1)
		return (-1);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	tcsetattr(0,0, &term);*/
/*	int	fd = open("/dev/tty", O_RDWR);
	write(fd, tgetstr("ti", NULL), ft_strlen(tgetstr("ti", NULL)));
	write(fd, tgetstr("vi", NULL), ft_strlen(tgetstr("vi", NULL)));
	ft_print_args(head);
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, my_putchar);
	deplacer_cursor();
//	tcsetattr(0,0, &term_backup);
	write(fd, tgetstr("te", NULL), ft_strlen(tgetstr("te", NULL)));
	write(fd, tgetstr("ve", NULL), ft_strlen(tgetstr("ve", NULL)));
	close(fd);*/
	ft_dell_args(&head);



	return (ret);
}
