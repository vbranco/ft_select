/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_args.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 19:19:45 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 19:57:29 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_args(t_form *form, va_list ap)
{
	int	len;

	len = 0;
	if (form->type == 'c' || form->type == 'C')
		len = ft_arg_c(ap, form);
	else if (form->type == 's' || form->type == 'S')
		len = ft_arg_s(ap, form);
	else if (form->type == 'd' || form->type == 'D' || form->type == 'i' ||
		form->type == 'u' || form->type == 'U')
		len = ft_arg_d_i(ap, form);
	else if (form->type == 'x' || form->type == 'X' || form->type == 'o' ||
		form->type == 'O')
		len = ft_arg_x_o(ap, form);
	else if (form->type == 'p')
		len = ft_arg_p(ap, form);
	else if (form->type == 'b')
		len = ft_arg_b(ap, form);
	return (len);
}
