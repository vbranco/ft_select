/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_recup_prec.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 16:59:00 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 18:20:47 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_recup_prec(const char *format, t_form *form, va_list ap)
{
	int		i;

	i = 0;
	while ((i < form->size) && format[i])
	{
		if (format[i] == '.')
		{
			format += i + 1;
			if (*format == '*')
				form->prec = (int)va_arg(ap, int);
			else
				form->prec = ft_atoi(format);
			break ;
		}
		i++;
	}
}
