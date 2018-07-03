/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_base_uintmax.c                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/14 17:23:07 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 17:15:23 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_modif(int nb, char *tmp, t_form *form)
{
	char	c;
	char	*s;

	s = ft_memalloc(2);
	if (nb >= 10 && form->type == 'X')
		c = 'A' + (nb - 10);
	else
		c = 'a' + (nb - 10);
	s[0] = c;
	ft_strcat(tmp, s);
	free(s);
}

void		ft_convert_base_uintmax(uintmax_t nb, int base, t_form *form,
		char *str)
{
	char		*tmp;
	uintmax_t	reste;
	uintmax_t	limit;

	tmp = ft_memalloc(100);
	limit = 8;
	base == 16 ? (limit = 9) : 0;
	while (nb >= (uintmax_t)base)
	{
		reste = nb % base;
		nb /= base;
		if (reste > limit)
			ft_modif(reste, tmp, form);
		else
			ft_my_itoa(reste, tmp);
	}
	if (nb > limit)
		ft_modif(nb, tmp, form);
	else
		ft_my_itoa(nb, tmp);
	tmp = ft_reverse(tmp);
	ft_strcat(str, tmp);
	free(tmp);
}
