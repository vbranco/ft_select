#include "ft_select.h"

int			main(int ac, char **av)
{
	t_arg			*tmp;

	if (ac == 1)
		return (ft_printf("Usage: ./ft_select [arg1] [arg2] [...]\n"));
	if (ft_init_term())
		return (-1);
	ft_verif_signal_1();
	ft_verif_signal_2();
	head = initialise_head();
	ft_get_args(head, ac, av);
	tmp = head->start;
	tmp->pos = 1;
	if (ft_prepare_term(head, 1))
	{
		ft_putendl_fd("Cannot initialise TERM", 2);
		ft_dell_args(&head);
		return (-1);
	}
	ft_dell_args(&head);
	return (0);
}
