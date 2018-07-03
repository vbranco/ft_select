/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arg_b.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 16:58:08 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 16:58:39 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_binaire(char *str, long nb)
{
	size_t	i;

	i = 0;
	while (nb > 0)
	{
		if (nb % 2 == 0)
			str[i] = '0';
		else
			str[i] = '1';
		nb /= 2;
		i++;
	}
	str = ft_reverse(str);
}

int			ft_arg_b(va_list ap, t_form *form)
{
	char	*str;
	long	nb;
	int		len;

	(void)form;
	nb = va_arg(ap, long);
	str = ft_memalloc(ft_size_nb(nb) + form->min + 1);
	ft_binaire(str, nb);
	ft_buffer_b(str, form);
	len = ft_strlen(str);
	write(1, form->buf, ft_strlen(form->buf));
	free(form->buf);
	form->buf = NULL;
	write(1, str, len);
	free(str);
	return (len);
}
