/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arg_d_i.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 19:45:58 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 17:06:51 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_print(char *str, t_form *form)
{
	int			len;

	len = 0;
	ft_buffer_d_i(str, form);
	write(1, form->buf, ft_strlen(form->buf));
	free(form->buf);
	form->buf = NULL;
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}

static void		ft_d_i(intmax_t *nb, t_form *form, va_list ap)
{
	if (form->length == 'h' && form->elength == '\0' && form->type == 'd')
		*nb = (short int)va_arg(ap, int);
	else if (form->elength == 'h' && (form->type == 'd' || form->type == 'i'))
		*nb = (char)va_arg(ap, int);
	else if (form->length == 'l' && form->elength == '\0')
		*nb = (long)va_arg(ap, long);
	else if (form->elength == 'l' || form->type == 'D')
		*nb = (long long)va_arg(ap, long long);
	else if (form->length == 'j' && form->elength == '\0')
		*nb = (intmax_t)va_arg(ap, intmax_t);
	else if (form->length == 'z' && form->elength == '\0')
		*nb = (size_t)va_arg(ap, size_t);
	else
		*nb = (int)va_arg(ap, int);
}

static void		ft_u(uintmax_t *nb2, t_form *form, va_list ap)
{
	if (form->length == 'h' && form->elength == '\0' && form->type == 'u')
		*nb2 = (short unsigned int)va_arg(ap, int);
	else if (form->elength == 'h' && form->type == 'u')
		*nb2 = (unsigned char)va_arg(ap, int);
	else if (form->length == 'l' && form->elength == '\0')
		*nb2 = (unsigned long)va_arg(ap, long);
	else if (form->elength == 'l' || form->type == 'U')
		*nb2 = (unsigned long long)va_arg(ap, long long);
	else if (form->length == 'j' && form->elength == '\0')
		*nb2 = (uintmax_t)va_arg(ap, uintmax_t);
	else if (form->length == 'z' && form->elength == '\0')
		*nb2 = (size_t)va_arg(ap, size_t);
	else
		*nb2 = (unsigned int)va_arg(ap, int);
}

int				ft_arg_d_i(va_list ap, t_form *form)
{
	intmax_t	nb;
	uintmax_t	nb2;
	char		*str;

	if (form->type == 'd' || form->type == 'i' || form->type == 'D')
	{
		ft_d_i(&nb, form, ap);
		str = ft_memalloc(ft_size_nb2(nb) + form->min + form->prec + 2);
		ft_my_itoa(nb, str);
	}
	else
	{
		ft_u(&nb2, form, ap);
		str = ft_memalloc(ft_size_nb2(nb2) + form->min + form->prec + 2);
		ft_my_itoa2(nb2, str);
	}
	return (ft_print(str, form));
}
