#include "ft_select.h"

static void		ft_calculate_col_max(t_head_arg *head)
{
	t_arg		*tmp;

	tmp = head->start;
	while (tmp)
	{
		if ((int)ft_strlen(tmp->info) > head->nb_col)
			head->nb_col = (int)ft_strlen(tmp->info);
		if (!tmp->next)
			break;
		tmp = tmp->next;
	}
}

static int		ft_calculate_total_len(t_head_arg *head)
{
	t_arg		*tmp;
	int			total_len;

	total_len = 0;
	tmp = head->start;
	while (tmp)
	{
		total_len += head->nb_col;
		if (!tmp->next)
			break;
		total_len += 1;
		tmp = tmp->next;
	}
	return (total_len);
}

int			ft_calculate_size(t_head_arg *head)
{
	t_arg	*tmp;
	int		len_args;
	int		line;
	int		nb_max_col;
	int		nb_args;

	len_args = 0;
	line = 1;
	tmp = head->start;
	ft_calculate_col_max(head);
	if (head->nb_col > head->co)
		return (write(head->fd, "Screen size too small", 21));
	len_args = ft_calculate_total_len(head);
	nb_max_col = len_args / head->nb_col;
	nb_args = nb_max_col;
	while (len_args > head->co)
	{
		line++;
		nb_max_col = ((nb_args - 1) / line ) + 1;
		len_args = (head->nb_col * nb_max_col) + (nb_max_col - 1);
	}
	head->nb_lines = line;
	if (head->nb_lines > head->li)
		return (write(head->fd, "Screen size too small", 21));
	return (0);
}

void		ft_calculate_place_print(t_head_arg *head, int *x, int *y)
{
	(*y)++;
	if (*y == head->nb_lines)
	{
		*y = 0;
		(*x) += head->nb_col + 1;
	}
}
