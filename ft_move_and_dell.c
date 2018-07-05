#include "ft_select.h"

void		ft_deplace(t_head_arg *head, char dire)
{
	t_arg	*tmp;
	
	tmp = ft_looking_for_position(head);
	if (tmp)
	{
		tmp->pos = 0;
		if (dire == 'r')
		{
			if (!tmp->next)//fin de la liste
				tmp = head->start;
			else
				tmp = tmp->next;
		}
		if (dire == 'l')
		{
			if (!tmp->prev)//debut de la liste
				tmp = head->end;
			else
				tmp = tmp->prev;
		}
		tmp->pos = 1;
	}
}

void		ft_deplace_cursor(t_head_arg *head, char *buf, int fd)
{
	if (buf[2] == 67)
		ft_deplace(head, 'r');
	if (buf[2] == 68)
		ft_deplace(head, 'l');
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, my_putchar);
	ft_print_args(head, fd);
}

/*
** 1st node of list
*/
static int		ft_dell_arg_1(t_head_arg *head)
{
	t_arg		*del;

	del = ft_looking_for_position(head);
	head->start = del->next;
	if (!del->next)
	{
		free(del);
		head->end = del->next;
		return (1);
	}
	del->next->prev = NULL;
	del->next->pos = 1;
	free(del);
	return (0);
}

/*
** node of list
*/
static void		ft_dell_arg_2(t_head_arg *head)
{
	t_arg		*del;
	t_arg		*tmp;

	del = ft_looking_for_position(head);
	tmp = del->prev;
	tmp->next = del->next;
	if (!tmp->next)
		head->end = tmp;
	else
		del->next->prev = tmp;
	if (tmp->next)
		tmp->next->pos = 1;
	else
		tmp->pos = 1;
	free(del);

}

int			ft_dell_arg(t_head_arg *head, int fd)
{
	t_arg	*del;
	t_arg	*tmp;


	del = ft_looking_for_position(head);
	if (!del)
		return (1);
	free(del->info);
	tmp = del->prev;
	if (!tmp)
	{
		if (ft_dell_arg_1(head))
			return (1);
	}
	else
		ft_dell_arg_2(head);
	write(fd, tgetstr("cl", NULL), ft_strlen(tgetstr("cl", NULL)));
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, my_putchar);
	ft_print_args(head, fd);
	return (0);
}
