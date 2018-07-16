/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_move_and_dell.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/16 15:21:46 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/07/16 15:49:22 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_select.h"

void				ft_deplace(t_head_arg *g_head, char dire)
{
	t_arg			*tmp;

	tmp = ft_looking_for_position(g_head);
	if (tmp)
	{
		tmp->pos = 0;
		if (dire == 'r')
		{
			if (!tmp->next)
				tmp = g_head->start;
			else
				tmp = tmp->next;
		}
		if (dire == 'l')
		{
			if (!tmp->prev)
				tmp = g_head->end;
			else
				tmp = tmp->prev;
		}
		tmp->pos = 1;
	}
}

void				ft_deplace_cursor(t_head_arg *g_head, char *buf)
{
	if (buf[2] == 67 || buf[2] == 66)
		ft_deplace(g_head, 'r');
	if (buf[2] == 68 || buf[2] == 65)
		ft_deplace(g_head, 'l');
	ft_display_size(0);
}

static int			ft_dell_arg_1(t_head_arg *g_head)
{
	t_arg			*del;

	del = ft_looking_for_position(g_head);
	g_head->start = del->next;
	if (!del->next)
	{
		free(del);
		g_head->end = del->next;
		return (1);
	}
	del->next->prev = NULL;
	del->next->pos = 1;
	free(del);
	return (0);
}

static	void		ft_dell_arg_2(t_head_arg *g_head)
{
	t_arg			*del;
	t_arg			*tmp;

	del = ft_looking_for_position(g_head);
	tmp = del->prev;
	tmp->next = del->next;
	if (!tmp->next)
		g_head->end = tmp;
	else
		del->next->prev = tmp;
	if (tmp->next)
		tmp->next->pos = 1;
	else
		tmp->pos = 1;
	free(del);
}

int					ft_dell_arg(t_head_arg *g_head)
{
	t_arg			*del;
	t_arg			*tmp;

	del = ft_looking_for_position(g_head);
	if (!del)
		return (1);
	free(del->info);
	tmp = del->prev;
	if (!tmp)
	{
		if (ft_dell_arg_1(g_head))
			return (1);
	}
	else
		ft_dell_arg_2(g_head);
	ft_display_size(0);
	return (0);
}
