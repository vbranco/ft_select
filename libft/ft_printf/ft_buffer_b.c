/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_buffer_b.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 16:56:58 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 16:57:12 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_buffer_b(char *str, t_form *form)
{
	char	*s1;
	int		len;

	len = ft_strlen(str);
	s1 = ft_memalloc(form->min);
	if (form->min > len)
	{
		if (form->is_z == 1)
			ft_add_str_begin(str, ft_memset(s1, '0',
			(form->min - len)));
	}
	free(s1);
}
