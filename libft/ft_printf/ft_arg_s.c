/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arg_s.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 19:51:43 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 15:54:07 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_print(char *str, t_form *form)
{
	int		len;

	len = 0;
	ft_buffer_s(str, form);
	write(1, form->buf, ft_strlen(form->buf));
	free(form->buf);
	form->buf = NULL;
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}

static char		*ft_s(t_form *form, va_list ap)
{
	char	*tmp;
	char	*str;

	tmp = va_arg(ap, char*);
	if (tmp == NULL)
	{
		str = ft_memalloc(7 + form->min);
		ft_add_str_begin(str, "(null)");
	}
	else
	{
		str = ft_memalloc(ft_strlen(tmp) + form->min + form->prec + 2);
		ft_strcat(str, tmp);
	}
	return (str);
}

static void		ft_free(char *str, t_form *form)
{
	free(str);
	free(form->buf);
	form->buf = NULL;
}

int				ft_arg_s(va_list ap, t_form *form)
{
	char	*str;
	wchar_t	*wstr;

	if ((form->type == 's' && form->length == '\0') || (form->type == 'S' &&
				form->length == 'h' && form->elength == '\0'))
		str = ft_s(form, ap);
	else
	{
		wstr = va_arg(ap, wchar_t*);
		if (wstr == NULL)
		{
			str = ft_memalloc(7 + form->min);
			ft_add_str_begin(str, "(null)");
		}
		else
		{
			str = ft_memalloc(ft_count_size(wstr) + form->min + 1);
			if ((ft_wstr(wstr, str, form)) == -1)
			{
				ft_free(str, form);
				return (-1);
			}
		}
	}
	return (ft_print(str, form));
}
