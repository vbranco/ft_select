#include "ft_select.h"

int		my_putchar(int c)
{
	char ca;

	ca = (char)c;
	write(0, &ca, 1);
	return (1);
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
			ft_underline(1);
		if (tmp->flag)
			ft_reverse_video(1);
		write(fd, tmp->info, ft_strlen(tmp->info));
		if (tmp->flag)
			ft_reverse_video(0);
		if (tmp->pos)
			ft_underline(0);
		if (!tmp->next)
			break ;
		write(fd, " ", 1);
		tmp = tmp->next;
	}
}

void		ft_print_out(t_head_arg *head)
{
	t_arg	*tmp;

	tmp = head->start;
	while (tmp)
	{
		if (tmp->flag)
			write(1, tmp->info, ft_strlen(tmp->info));
		if (!tmp->next)
			break ;
		write(1, " ", 1);
		tmp = tmp->next;
	}
}

