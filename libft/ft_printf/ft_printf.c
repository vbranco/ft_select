/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 20:07:34 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 17:01:12 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_buff(const char *format, int *len, t_form *form)
{
	int		i;

	i = 0;
	while (format[i] != '%' && format[i])
		i++;
	form->buf = ft_memalloc(i + 1);
	i = 0;
	while (format[i] != '%' && format[i])
	{
		form->buf[i] = format[i];
		i++;
	}
	*len += i;
	return (i);
}

static int	ft_flag(const char *format, va_list ap, t_form *form)
{
	int		size;
	int		len;
	int		ln;

	len = 0;
	size = 0;
	while (*format)
	{
		format += ft_buff(format, &len, form);
		if (*format == '%')
		{
			if ((ln = ft_format(format, ap, &size, form)) == -1)
				return (-1);
			else
				len += ln;
			format = format + size;
		}
	}
	if (form->buf != NULL)
	{
		write(1, form->buf, ft_strlen(form->buf));
		free(form->buf);
		form->buf = NULL;
	}
	return (len);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	t_form	form;
	int		len;

	if (ft_strchr(format, '%') == 0)
		return (write(1, format, ft_strlen(format)));
	else
	{
		va_start(ap, format);
		len = ft_flag(format, ap, &form);
		va_end(ap);
		return (len);
	}
}
