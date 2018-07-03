/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arg_p.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 20:26:50 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 17:03:55 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_min(char *str, t_form *form, int len)
{
	char		*s1;

	s1 = NULL;
	if (form->min > len || form->is_z == 1)
	{
		s1 = ft_memalloc(form->min);
		if (form->is_n == 1)
			ft_add_str_end(str, ft_memset(s1, ' ', (form->min - len)));
		else if (form->is_z == 1)
		{
			if (form->min > len)
				ft_add_str_begin(str, ft_memset(s1, '0',
							(form->min - (len + 2))));
			ft_add_str_begin(str, "0x");
		}
		else if (form->is_n == 0)
			ft_add_str_begin(str, ft_memset(s1, ' ', (form->min - len)));
		free(s1);
	}
}

static void		ft_buffer_p(char *str, t_form *form)
{
	int			len;
	char		*s1;

	s1 = NULL;
	if (str[0] == '0' && form->prec == 0)
	{
		form->zero = 1;
		str[0] = '\0';
	}
	len = ft_strlen(str);
	if (form->prec > len)
	{
		s1 = ft_memalloc(form->prec);
		ft_add_str_begin(str, ft_memset(s1, '0', (form->prec - len)));
		free(s1);
	}
	if (form->is_z == 0)
		ft_add_str_begin(str, "0x");
	len = ft_strlen(str);
	ft_min(str, form, len);
}

int				ft_arg_p(va_list ap, t_form *form)
{
	char		*str;
	void		*ptr;
	uintmax_t	nb;
	int			len;

	ptr = va_arg(ap, void*);
	nb = (unsigned long)ptr;
	str = ft_memalloc(ft_size_nb(nb) + form->min + form->prec + 3);
	ft_convert_base_uintmax(nb, 16, form, str);
	ft_buffer_p(str, form);
	len = ft_strlen(str);
	write(1, form->buf, ft_strlen(form->buf));
	free(form->buf);
	form->buf = NULL;
	write(1, str, len);
	free(str);
	return (len);
}
