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

static void		ft_calculate_size(t_head_arg *head)
{
	t_arg	*tmp;
	int		len_args;
	int		line;

	len_args = 0;
	line = 1;
	tmp = head->start;
	while (tmp)
	{
		len_args += (int)ft_strlen(tmp->info);
		if ((int)ft_strlen(tmp->info) > head->nb_col)
			head->nb_col = (int)ft_strlen(tmp->info);
		if (!tmp->next)
			break;
		len_args += 1; 
		tmp = tmp->next;
	}
	while (len_args > head->co)
	{
		len_args /= 2;
		line++;
	}
	head->nb_lines = line;
//	printf("head->co %i || size total %i || lines %i || max colone %i\n", head->co, len_args, head->nb_lines, head->nb_col);
}

static void	ft_place_for_printf(t_head_arg *head, int *x, int *y)
{
//	while (head->nb_lines > 0)
//	{
//		(*y)++;
		tputs(tgoto(tgetstr("cm", NULL), *x, *y), 1, my_putchar);
//		head->nb_lines--;
//	}
}

void		ft_print_args(t_head_arg *head)
{
	t_arg	*tmp;
	int		x;//nb colones
	int		y;//nb lines

	x = 0;
	y = 0;
	if (!head->start)
		return ;
	ft_calculate_size(head);
	tmp = head->start;
	while (tmp)
	{
		(tmp->pos) ? ft_underline(1) : 0;
		(tmp->flag) ? ft_reverse_video(1) : 0;
//		ft_place_for_printf(head, &x, &y);
		tputs(tgoto(tgetstr("cm", NULL), x, y), 1, my_putchar);
		write(head->fd, tmp->info, ft_strlen(tmp->info));
//		x++;
		y++;
		if (y == head->nb_lines)
		{
			y = 0;
			x += head->nb_col + 1;
		}
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

