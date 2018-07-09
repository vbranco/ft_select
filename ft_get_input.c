#include "ft_select.h"

void		ft_select_arg(t_head_arg *head)
{
	t_arg	*tmp;

	tmp = ft_looking_for_position(head);
	if (!tmp)
		return ;
	if (tmp->flag)
		tmp->flag = 0;
	else
		tmp->flag = 1;
	ft_deplace(head, 'r');
	ft_display_size(0);
}

t_arg		*ft_looking_for_position(t_head_arg *head)
{
	t_arg	*tmp;

	tmp = head->start;
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

void		ft_get_input(t_head_arg *head)
{
	char	buf[4];

	while (101)
	{
		read(0, buf, 4);
		if (buf[0] == 4)
			return ;
		(buf[0] == 27 && buf[1] == 91) ? ft_deplace_cursor(head, buf) : 0;
		if (buf[0] == 127 || (buf[0] == 27 && buf[1] == 91 &&
			buf[2] == 51 && buf[3] == 126 ))//delete ou backspace
		{
			if (ft_dell_arg(head))
				return ;
		}
		(buf[0] == 32) ? ft_select_arg(head) : 0;
		if (buf[0] == 10)//return
		{
			ft_print_out(head);
			break ;
		}
		if (buf[0] == 27 && buf[1] == 0)//echap
			return ;
		ft_bzero(buf, 4);
	}
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
