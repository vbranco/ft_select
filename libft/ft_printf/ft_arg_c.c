/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arg_c.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 19:22:22 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 15:53:05 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_test(t_form *form)
{
	if ((form->type == 'c' && form->length == '\0') || (form->type == 'C' &&
				form->length == 'h' && form->elength == '\0'))
		return (1);
	else if ((form->type == 'C' && form->length == '\0') || (form->type == 'c'
				&& form->length == 'l') || (form->type == 'C' &&
					form->elength == 'h'))
		return (2);
	return (0);
}

static int		ft_print(char *str, t_form *form)
{
	int		len;

	len = 0;
	write(1, form->buf, ft_strlen(form->buf));
	free(form->buf);
	form->buf = NULL;
	len = ft_buffer_c(str, form);
	write(1, str, ft_strlen(str));
	if (form->zero == 1)
		write(1, "\0", 1);
	free(str);
	return (len);
}

static void		ft_free(char *str, t_form *form)
{
	free(str);
	free(form->buf);
	form->buf = NULL;
}

int				ft_arg_c(va_list ap, t_form *form)
{
	char	c;
	char	*str;
	wchar_t	ca;

	str = ft_memalloc(4 + form->min + 1);
	if (ft_test(form) == 1)
	{
		c = (char)va_arg(ap, int);
		str[0] = c;
	}
	if (ft_test(form) == 2)
	{
		ca = (wchar_t)va_arg(ap, wint_t);
		if ((ft_wchar(ca, str)) == -1)
		{
			ft_free(str, form);
			return (-1);
		}
	}
	return (ft_print(str, form));
}
