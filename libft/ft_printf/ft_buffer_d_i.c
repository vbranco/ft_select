/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_buffer_d_i.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 16:54:27 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 17:29:21 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_space(char *str, t_form *form)
{
	if (form->is_s == 1 && str[0] != '-')
	{
		ft_add_str_begin(str, " ");
		return (1);
	}
	return (0);
}

static void	ft_min(char *str, char *c, t_form *form, int len)
{
	char	*s1;

	s1 = ft_memalloc(form->min);
	if (form->is_n == 1)
	{
		ft_add_str_begin(str, c);
		ft_add_str_end(str, ft_memset(s1, ' ', (form->min - len)));
	}
	else if (form->is_z == 1)
	{
		if (form->is_s == 1 && str[0] != '-')
			len++;
		ft_add_str_begin(str, ft_memset(s1, '0', (form->min - len)));
		ft_add_str_begin(str, c);
		ft_space(str, form);
	}
	else if (form->is_n == 0)
	{
		ft_add_str_begin(str, c);
		ft_add_str_begin(str, ft_memset(s1, ' ', (form->min - len)));
	}
	free(s1);
}

static void	ft_signe(char *str, t_form *form)
{
	char	c[2];
	int		len;

	c[0] = '\0';
	c[1] = '\0';
	str[0] == '-' ? ft_d_neg(str, form) : ft_d_prec(str, form);
	len = ft_strlen(str);
	if ((form->is_n == 1 && str[0] == '-') || form->is_p == 1)
	{
		if (form->is_n == 1 && str[0] == '-')
			c[0] = '-';
		else
			c[0] = '+';
		if (!ft_strchr(str, '-'))
			form->min--;
	}
	if (form->min > len)
		ft_min(str, c, form, len);
	else
		ft_space(str, form);
	if (c[0] == '-' && !ft_strchr(str, '-'))
		ft_add_str_begin(str, "-");
	else if (c[0] == '+' && !ft_strchr(str, '-') && !ft_strchr(str, '+'))
		ft_add_str_begin(str, "+");
}

void		ft_buffer_d_i(char *str, t_form *form)
{
	int		len;

	len = ft_strlen(str);
	if (form->is_s == 1 && form->is_p == 1)
		form->is_s = 0;
	if (form->is_z == 1 && form->is_n == 1)
		form->is_z = 0;
	if (form->type == 'u' || form->type == 'U')
	{
		if (form->is_s == 1)
			form->is_s = 0;
		if (form->is_p == 1)
			form->is_p = 0;
	}
	ft_signe(str, form);
}
