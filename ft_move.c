#include "ft_select.h"

/*void		ft_dell_arg(t_head_arg *head);
{
}*/

void		ft_deplace(t_head_arg *head, char dire)
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
			if (!tmp->prev)
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
//	write(fd, "ici\n", 4);
	printf("ici\n");
	if (buf[2] == 67)
		ft_deplace(head, 'r');
	if (buf[2] == 68)
		ft_deplace(head, 'l');
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, my_putchar);
	ft_print_args(head, fd);
}

void		ft_get_input(t_head_arg *head, int fd)
{
	char	buf[4];

	while (101)
	{
		read(0, buf, 4);
		if (buf[0] == 4)
			return ;
		printf("buf > |%i| |%i| |%i| |%i|\n", buf[0], buf[1], buf[2], buf[3]);
		if (buf[0] == 27 && buf[1] == 91)//deplacer
			ft_deplace_cursor(head, buf, fd);
/*		if (buf[0] == 127 || (buf[0] == 27 && buf[1] == 91 && buf[2] == 51 && buf[3] == 126 ))//delete ou backspace
			ft_dell_arg(head);
		if (buf[0] == 32)//espace
			ft_select_arg(head);
		if (buf[0] == 10)//return
		{
			ft_print_args(head, 1);
			break ;
		}
		if (buf[0] == 27 && buf[1] == 0)//echap
			stop_program*/
		ft_bzero(buf, 4);
	}
}
