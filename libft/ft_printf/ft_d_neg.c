/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_d_neg.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/28 17:01:59 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 17:02:23 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_modif_str(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		str[i] = str[i + 1];
		i++;
	}
}

static void	ft_min(char *str, t_form *form, int len)
{
	char	*s1;

	len++;
	s1 = ft_memalloc(form->min);
	if (form->is_n == 1)
	{
		ft_add_str_begin(str, "-");
		ft_add_str_end(str, ft_memset(s1, ' ', (form->min - len)));
	}
	else if (form->is_z == 1)
	{
		ft_add_str_begin(str, ft_memset(s1, '0', (form->min - len)));
		ft_add_str_begin(str, "-");
	}
	else if (form->is_n == 0)
	{
		ft_add_str_begin(str, "-");
		ft_add_str_begin(str, ft_memset(s1, ' ', (form->min - len)));
	}
	free(s1);
}

void		ft_d_neg(char *str, t_form *form)
{
	char	*s1;
	int		len;

	s1 = NULL;
	ft_modif_str(str);
	len = ft_strlen(str);
	if (form->prec > len)
	{
		s1 = ft_memalloc(form->prec);
		ft_add_str_begin(str, ft_memset(s1, '0', (form->prec - len)));
		free(s1);
	}
	len = ft_strlen(str);
	if (form->min > len)
		ft_min(str, form, len);
	else
		ft_add_str_begin(str, "-");
}
