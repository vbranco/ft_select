/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/16 15:20:14 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/07/16 15:56:30 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_select.h"

int			my_putchar(int c)
{
	char	ca;

	ca = (char)c;
	write(0, &ca, 1);
	return (1);
}

int			main(int ac, char **av)
{
	t_arg			*tmp;

	if (ac == 1)
		return (ft_printf("Usage: ./ft_select [arg1] [arg2] [...]\n"));
	if (ft_init_term())
		return (-1);
	ft_verif_signal_1();
	ft_verif_signal_2();
	g_head = initialise_head();
	ft_get_args(g_head, ac, av);
	tmp = g_head->start;
	tmp->pos = 1;
	if (ft_prepare_term(g_head, 1))
	{
		ft_putendl_fd("Cannot initialise TERM", 2);
		ft_dell_args(&g_head);
		return (-1);
	}
	if (g_head->print)
		ft_print_out(g_head);
	ft_dell_args(&g_head);
	return (0);
}
