#include "ft_select.h"

t_head_arg	*initialise_head(void)
{
	t_head_arg	*head;

	if (!(head = (t_head_arg*)malloc(sizeof(t_head_arg))))
		return (NULL);
	head->start = NULL;
	head->end = NULL;
	head->fd = 0;
	head->li = 0;
	head->co = 0;
	head->nb_lines = 0;
	head->nb_col = 0;
	head->print = 0;
	return (head);
}

t_arg		*initialise_arg(char *inf)
{
	t_arg	*arg;

	if (!(arg = (t_arg*)malloc(sizeof(t_arg))))
		return (NULL);
	arg->info = ft_strdup(inf);
	arg->next = NULL;
	arg->prev = NULL;
	arg->flag = 0;
	arg->pos = 0;
	return (arg);
}

void		add_arg(t_head_arg *head, char *info)
{
	t_arg	*add;
	t_arg	*tmp;

	add = initialise_arg(info);
	tmp = head->start;
	if (!tmp)
	{
		head->start = add;
		head->end = add;
	}
	else
	{
		while (tmp)
		{
			if (tmp->next == NULL)
				break ;
			tmp = tmp->next;
		}
		tmp->next = add;
		add->prev = tmp;
		head->end = add;
	}
}

void		remove_arg(t_head_arg *head, char *inf)
{
	t_arg	*tmp;
	t_arg	*prev;

	prev = NULL;
	tmp = head->start;
	if (!tmp)
		return ;
	while (tmp && ft_strcmp(tmp->info, inf))
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp && !ft_strcmp(tmp->info, inf))
	{
		free(tmp->info);
		if (!prev)
			head->start = tmp->next;
		else
			prev->next = tmp->next;
		free(tmp);
		tmp = NULL;
	}
}

void		ft_dell_args(t_head_arg **head)
{
	t_arg	*tmp;
	t_arg	*s;

	s = (*head)->start;
	while (s)
	{
		tmp = (s)->next;
		free((s)->info);
		free(s);
		(s) = tmp;
	}
	s = NULL;
	free(*head);
	head = NULL;
}
