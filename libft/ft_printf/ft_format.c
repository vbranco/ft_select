/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_format.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 17:22:45 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 17:13:34 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_verif_wild(t_form *form)
{
	if (form->min < 0)
	{
		form->min *= -1;
		form->is_n = 1;
	}
	if (form->prec < -1)
		form->prec = -1;
	if (form->prec > -1)
		form->is_z = 0;
}

int			ft_format(const char *format, va_list ap, int *size, t_form *form)
{
	int		len;

	len = 0;
	ft_init_struct(form);
	if ((len = ft_percent(format, form)) != 0)
	{
		*size = form->size;
		return (len);
	}
	ft_init_struct(form);
	if (*format == '%')
	{
		format++;
		ft_recup_type(format, form);
		ft_recup_length(format, form);
		ft_recup_min(format, form, ap);
		ft_recup_prec(format, form, ap);
		ft_recup_flag(format, form);
		ft_verif_wild(form);
		if ((len = (ft_args(form, ap))) == -1)
			return (-1);
		*size = form->size;
	}
	return (len);
}
