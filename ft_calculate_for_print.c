/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_calculate_for_print.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/16 15:21:39 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/07/16 15:46:48 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_select.h"

static void	ft_calculate_col_max(t_head_arg *g_head)
{
	t_arg	*tmp;

	tmp = g_head->start;
	while (tmp)
	{
		if ((int)ft_strlen(tmp->info) > g_head->nb_col)
			g_head->nb_col = (int)ft_strlen(tmp->info);
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
}

static int	ft_calculate_total_len(t_head_arg *g_head)
{
	t_arg	*tmp;
	int		total_len;

	total_len = 0;
	tmp = g_head->start;
	while (tmp)
	{
		total_len += g_head->nb_col;
		if (!tmp->next)
			break ;
		total_len += 1;
		tmp = tmp->next;
	}
	return (total_len);
}

int			ft_calculate_size(t_head_arg *g_head)
{
	t_arg	*tmp;
	int		len_args;
	int		line;
	int		nb_max_col;
	int		nb_args;

	len_args = 0;
	line = 1;
	tmp = g_head->start;
	ft_calculate_col_max(g_head);
	if (g_head->nb_col > g_head->co)
		return (write(g_head->fd, "Screen size too small", 21));
	len_args = ft_calculate_total_len(g_head);
	nb_max_col = len_args / g_head->nb_col;
	nb_args = nb_max_col;
	while (len_args > g_head->co)
	{
		line++;
		nb_max_col = ((nb_args - 1) / line) + 1;
		len_args = (g_head->nb_col * nb_max_col) + (nb_max_col - 1);
	}
	g_head->nb_lines = line;
	if (g_head->nb_lines > g_head->li)
		return (write(g_head->fd, "Screen size too small", 21));
	return (0);
}

void		ft_calculate_place_print(t_head_arg *g_head, int *x, int *y)
{
	(*y)++;
	if (*y == g_head->nb_lines)
	{
		*y = 0;
		(*x) += g_head->nb_col + 1;
	}
}

void		ft_display_size(int sig)
{
	struct winsize	wind;

	(void)sig;
	ioctl(0, TIOCGWINSZ, &wind);
	g_head->li = wind.ws_row;
	g_head->co = wind.ws_col;
	write(g_head->fd, tgetstr("cl", NULL), ft_strlen(tgetstr("cl", NULL)));
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, my_putchar);
	ft_print_args(g_head);
}
