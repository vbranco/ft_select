#include "ft_select.h"

void		ft_select_arg(t_head_arg *head, int fd)
{
	t_arg	*tmp;

	tmp = ft_looking_for_position(head);
	if (!tmp)
		return ;
	if (tmp->flag)
		tmp->flag = 0;
	else
		tmp->flag = 1;
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, my_putchar);
	ft_print_args(head, fd);
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

void		ft_get_input(t_head_arg *head, int fd)
{
	char	buf[4];

	while (101)
	{
		read(0, buf, 4);
		if (buf[0] == 4)
			return ;
		if (buf[0] == 27 && buf[1] == 91)//deplacer
			ft_deplace_cursor(head, buf, fd);
		if (buf[0] == 127 || (buf[0] == 27 && buf[1] == 91 &&
			buf[2] == 51 && buf[3] == 126 ))//delete ou backspace
		{
			if (ft_dell_arg(head, fd))
				return ;
		}
		if (buf[0] == 32)//espace
			ft_select_arg(head, fd);
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
