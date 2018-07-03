/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_struct.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 18:38:31 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/17 17:09:33 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_struct(t_form *form)
{
	form->size = 0;
	form->type = '\0';
	form->length = '\0';
	form->elength = '\0';
	form->is_h = 0;
	form->is_z = 0;
	form->is_n = 0;
	form->is_p = 0;
	form->is_s = 0;
	form->min = 0;
	form->prec = -1;
	form->zero = 0;
}
