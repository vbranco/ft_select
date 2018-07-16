/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_term.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/16 15:21:34 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/07/16 15:52:14 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_select.h"

int			ft_prepare_term(t_head_arg *g_head, int i)
{
	if (i)
	{
		if (!isatty(0))
			return (-1);
		if ((g_head->fd = open(ttyname(0), O_RDWR)) == -1)
			return (-1);
		if (tcgetattr(g_head->fd, &(g_head->term)) == -1)
			return (-1);
	}
	ft_config_term(g_head, 1);
	ft_display_size(0);
	ft_get_input(g_head);
	ft_config_term(g_head, 0);
	close(g_head->fd);
	return (0);
}

void		ft_config_term(t_head_arg *g_head, int start)
{
	if (start)
	{
		g_head->term.c_lflag &= ~(ICANON);
		g_head->term.c_lflag &= ~(ECHO);
		g_head->term.c_cc[VMIN] = 1;
		g_head->term.c_cc[VTIME] = 0;
		tcsetattr(g_head->fd, TCSANOW, &(g_head->term));
		tputs(tgetstr("ti", NULL), 1, my_putchar);
		tputs(tgetstr("vi", NULL), 1, my_putchar);
	}
	else
	{
		g_head->term.c_lflag |= (ICANON | ECHO);
		tcsetattr(g_head->fd, 0, &(g_head->term));
		tputs(tgetstr("te", NULL), 1, my_putchar);
		tputs(tgetstr("ve", NULL), 1, my_putchar);
	}
}

int			ft_init_term(void)
{
	int		ret;
	char	*term_type;

	term_type = getenv("TERM");
	if (!term_type)
	{
		ft_putendl_fd("TERM environment variable not set.", 2);
		return (-1);
	}
	ret = tgetent(NULL, term_type);
	if (ret == -1)
	{
		ft_putendl_fd("Could not access to termcap database\n", 2);
		return (-1);
	}
	else if (ret == 0)
	{
		ft_putendl_fd("Terminal type is not defined", 2);
		return (-1);
	}
	return (0);
}
