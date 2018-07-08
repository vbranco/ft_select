#include "ft_select.h"

int		my_putchar(int c)
{
	char ca;

	ca = (char)c;
	write(0, &ca, 1);
	return (1);
}

static void		ft_underline(int i)
{
	if (i)
		tputs(tgetstr("us", NULL), 1, my_putchar);
	else
		tputs(tgetstr("ue", NULL), 1, my_putchar);
}

static void		ft_reverse_video(int i)
{
	if (i)
		tputs(tgetstr("mr", NULL), 1, my_putchar);
	else
		tputs(tgetstr("me", NULL), 1, my_putchar);
}

void		ft_print_args(t_head_arg *head)
{
	t_arg	*tmp;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!head->start)
		return ;
	if (ft_calculate_size(head))
		return ;
	tmp = head->start;
	while (tmp)
	{
		(tmp->pos) ? ft_underline(1) : 0;
		(tmp->flag) ? ft_reverse_video(1) : 0;
		tputs(tgoto(tgetstr("cm", NULL), x, y), 1, my_putchar);
		write(head->fd, tmp->info, ft_strlen(tmp->info));
		ft_calculate_place_print(head, &x, &y);
		(tmp->pos) ? ft_underline(0) : 0;
		(tmp->flag) ? ft_reverse_video(0) : 0;
		if (!tmp->next)
			break ;
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

