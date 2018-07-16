/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_input.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/16 15:21:43 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/07/16 15:47:51 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_select_arg(t_head_arg *g_head)
{
	t_arg	*tmp;

	tmp = ft_looking_for_position(g_head);
	if (!tmp)
		return ;
	if (tmp->flag)
		tmp->flag = 0;
	else
		tmp->flag = 1;
	ft_deplace(g_head, 'r');
	ft_display_size(0);
}

t_arg		*ft_looking_for_position(t_head_arg *g_head)
{
	t_arg	*tmp;

	tmp = g_head->start;
	while (tmp && !tmp->pos)
	{
		if (!tmp->next)
		{
			tmp = NULL;
			break ;
		}
		tmp = tmp->next;
	}
	return (tmp);
}

void		ft_get_input(t_head_arg *g_head)
{
	char	buf[4];

	while (101)
	{
		read(0, buf, 4);
		if (buf[0] == 4)
			return ;
		(buf[0] == 27 && buf[1] == 91) ? ft_deplace_cursor(g_head, buf) : 0;
		if (buf[0] == 127 || (buf[0] == 27 && buf[1] == 91 &&
			buf[2] == 51 && buf[3] == 126))
		{
			if (ft_dell_arg(g_head))
				return ;
		}
		(buf[0] == 32) ? ft_select_arg(g_head) : 0;
		if (buf[0] == 10)
		{
			g_head->print = 1;
			break ;
		}
		if (buf[0] == 27 && buf[1] == 0)
			return ;
		ft_bzero(buf, 4);
	}
}

void		ft_get_args(t_head_arg *g_head, int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		add_arg(g_head, av[i]);
		i++;
	}
}
