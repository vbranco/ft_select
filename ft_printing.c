/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printing.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/16 15:21:20 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/07/16 15:50:25 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_select.h"

static void	ft_underline(int i)
{
	if (i)
		tputs(tgetstr("us", NULL), 1, my_putchar);
	else
		tputs(tgetstr("ue", NULL), 1, my_putchar);
}

static void	ft_reverse_video(int i)
{
	if (i)
		tputs(tgetstr("mr", NULL), 1, my_putchar);
	else
		tputs(tgetstr("me", NULL), 1, my_putchar);
}

void		ft_print_args(t_head_arg *g_head)
{
	t_arg	*tmp;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!g_head->start)
		return ;
	if (ft_calculate_size(g_head))
		return ;
	tmp = g_head->start;
	while (tmp)
	{
		(tmp->pos) ? ft_underline(1) : 0;
		(tmp->flag) ? ft_reverse_video(1) : 0;
		tputs(tgoto(tgetstr("cm", NULL), x, y), 1, my_putchar);
		write(g_head->fd, tmp->info, ft_strlen(tmp->info));
		ft_calculate_place_print(g_head, &x, &y);
		(tmp->pos) ? ft_underline(0) : 0;
		(tmp->flag) ? ft_reverse_video(0) : 0;
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
}

static int	ft_calculate_spaces(t_head_arg *g_head)
{
	t_arg	*tmp;
	int		spaces;

	spaces = 0;
	tmp = g_head->start;
	while (tmp)
	{
		if (tmp->flag)
			spaces++;
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	return (spaces);
}

void		ft_print_out(t_head_arg *g_head)
{
	t_arg	*tmp;
	int		spaces;

	tmp = g_head->start;
	spaces = ft_calculate_spaces(g_head);
	if (spaces > 0)
		spaces--;
	while (tmp)
	{
		if (tmp->flag)
		{
			write(1, tmp->info, ft_strlen(tmp->info));
			if (spaces)
			{
				write(1, " ", 1);
				spaces--;
			}
		}
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
}
