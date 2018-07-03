/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_recup_type.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 17:19:43 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 18:36:47 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_recup_type(const char *format, t_form *form)
{
	int	i;

	i = 0;
	while ((format[i] != 's' && format[i] != 'S' && format[i] != 'p' &&
		format[i] != 'd' && format[i] != 'D' && format[i] != 'i' &&
		format[i] != 'o' && format[i] != 'O' && format[i] != 'u' &&
		format[i] != 'U' && format[i] != 'x' && format[i] != 'X' &&
		format[i] != 'c' && format[i] != 'C' && format[i] != 'b') &&
		format[i])
		i++;
	form->type = format[i];
	form->size = i + 2;
}
