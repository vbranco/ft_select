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
			{
				tmp = head->start;
				tmp->pos = 1;
			}
			else
				tmp->next->pos = 1;
		}
		if (dire == 'l')
		{
			if (!tmp->prev)//debut de la liste
			{
				tmp = head->end;
				tmp->pos = 1;
			}
			else
				tmp->prev->pos = 1;
		}
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

int			ft_dell_arg(t_head_arg *head, int fd)
{
	t_arg	*del;
	t_arg	*tmp;


	del = ft_looking_for_position(head);
	if (!del)
	{
		if (head->start)
			return (0);
		else
			return (1);
	}
	free(del->info);
	tmp = del->prev;
	if (!tmp)
	{
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
	}
	else
	{
		tmp->next = del->next;
		if (!tmp->next)
			head->end = tmp;
		else
			del->next->prev = tmp;
		tmp->pos = 1;
		free(del);
	}
	write(fd, tgetstr("cl", NULL), ft_strlen(tgetstr("cl", NULL)));
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, my_putchar);
	ft_print_args(head, fd);
	return (0);
}
