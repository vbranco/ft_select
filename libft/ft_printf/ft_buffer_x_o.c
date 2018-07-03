/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_buffer_x_o.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 16:53:24 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 18:14:37 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_space(char *str, t_form *form)
{
	if (form->is_s == 1)
	{
		ft_add_str_begin(str, " ");
		return (1);
	}
	return (0);
}

static void	ft_min(char *str, char *c, t_form *form)
{
	char	*s1;
	int		len;

	s1 = ft_memalloc(form->min);
	len = ft_strlen(str);
	if (form->is_n == 1)
	{
		if (form->is_h == 1 && (size_t)form->prec > ft_strlen(str))
			ft_add_str_begin(str, c);
		ft_add_str_end(str, ft_memset(s1, ' ', (form->min - len)));
	}
	else if (form->is_z == 1)
	{
		ft_add_str_begin(str, ft_memset(s1, '0', (form->min - len)));
		if (form->is_h == 1 && !ft_zero(str))
			ft_add_str_begin(str, c);
		ft_space(str, form);
	}
	else if (form->is_n == 0)
	{
		if (form->is_h == 1 && str[0] != '0')
			ft_add_str_begin(str, c);
		ft_add_str_begin(str, ft_memset(s1, ' ', (form->min - len)));
	}
	free(s1);
}

static void	ft_type(t_form *form, char *c)
{
	if (form->type == 'o' || form->type == 'O')
	{
		c[0] = '0';
		c[1] = '\0';
	}
	if (form->type == 'x' || form->type == 'X')
	{
		c[0] = '0';
		c[2] = '\0';
		if (form->type == 'x')
			c[1] = 'x';
		else
			c[1] = 'X';
	}
}

void		ft_buffer_x_o(char *str, t_form *form)
{
	int		len;
	char	c[3];

	ft_type(form, c);
	ft_x_prec(str, c, form);
	len = ft_strlen(str);
	if (form->is_h == 1)
	{
		if ((form->type == 'x' || form->type == 'X') && !ft_zero(str))
			form->min -= 2;
		else
		{
			if (str[0] != '0')
				form->min--;
		}
	}
	if (form->min > len)
		ft_min(str, c, form);
	else if (form->is_h == 1 && str[0] != '0' && form->zero == 0)
		ft_add_str_begin(str, c);
}
