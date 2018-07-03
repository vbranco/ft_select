/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_p_min.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/28 19:03:46 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 19:05:53 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_p_min(const char *format, t_form *form)
{
	int		i;

	i = 0;
	while (format[i] && (i < form->size))
	{
		while (format[i] == '+' || format[i] == '-' || format[i] == '#' ||
				format[i] == '0' || format[i] == ' ')
			i++;
		if (format[i] >= '1' || format[i] <= '9')
		{
			format += i;
			form->min = ft_atoi(format);
			break ;
		}
	}
}
