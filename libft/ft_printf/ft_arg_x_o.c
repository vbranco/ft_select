/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arg_x_o.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 20:28:25 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 17:23:26 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_size_nbo2(uintmax_t nb, t_form *form)
{
	int			size;
	int			div;

	size = 0;
	if (form->type == 'o')
		div = 8;
	else
		div = 10;
	while (nb > 9)
	{
		size++;
		nb /= div;
	}
	return (size + 1);
}

static void		ft_x(uintmax_t *nb, t_form *form, va_list ap)
{
	if (form->length == 'h' && form->elength == 'h')
		*nb = (unsigned char)va_arg(ap, int);
	else if (form->length == 'h' && form->elength == '\0')
		*nb = (short unsigned int)va_arg(ap, long);
	else if (form->length == 'j' && form->elength == '\0')
		*nb = (uintmax_t)va_arg(ap, uintmax_t);
	else if (form->length == 'l' && form->elength == '\0')
		*nb = (unsigned long)va_arg(ap, long long);
	else if (form->length == 'l' && form->elength == 'l')
		*nb = (unsigned long long)va_arg(ap, unsigned long long);
	else if (form->length == 'z' && form->elength == '\0')
		*nb = (size_t)va_arg(ap, size_t);
	else
		*nb = (unsigned int)va_arg(ap, long);
}

static void		ft_o(uintmax_t *nb, t_form *form, va_list ap)
{
	if (form->length == 'h' && form->elength == 'h' && form->type == 'o')
		*nb = (unsigned char)va_arg(ap, int);
	else if (form->length == 'h' && form->elength == '\0')
		*nb = (short unsigned int)va_arg(ap, long);
	else if (form->length == 'j' && form->elength == '\0')
		*nb = (uintmax_t)va_arg(ap, uintmax_t);
	else if (form->length == 'l' && form->elength == '\0')
		*nb = (unsigned long)va_arg(ap, long long);
	else if ((form->length == 'l' && form->elength == 'l') || form->type == 'O')
		*nb = (unsigned long long)va_arg(ap, unsigned long long);
	else if (form->length == 'z' && form->elength == '\0')
		*nb = (size_t)va_arg(ap, size_t);
	else
		*nb = (unsigned int)va_arg(ap, long);
}

int				ft_arg_x_o(va_list ap, t_form *form)
{
	uintmax_t	nb;
	char		*str;
	int			len;

	if (form->type == 'x' || form->type == 'X')
		ft_x(&nb, form, ap);
	else
		ft_o(&nb, form, ap);
	str = ft_memalloc(ft_size_nbo2(nb, form) + form->min + form->prec + 2);
	if (form->type == 'x' || form->type == 'X')
		ft_convert_base_uintmax(nb, 16, form, str);
	else
		ft_convert_base_uintmax(nb, 8, form, str);
	ft_buffer_x_o(str, form);
	write(1, form->buf, ft_strlen(form->buf));
	free(form->buf);
	form->buf = NULL;
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}
