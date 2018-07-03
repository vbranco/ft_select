/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_x_prec.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/28 17:31:53 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 19:08:22 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_x_prec(char *str, char *c, t_form *form)
{
	int		len;
	int		i;
	char	*s1;

	i = 0;
	s1 = NULL;
	len = ft_strlen(str);
	if (str[0] == '0')
		form->zero = 1;
	if (form->prec == 0 && str[0] == '0')
	{
		if (form->is_h == 1 && (form->type == 'o' || form->type == 'O'))
			str[0] = '0';
		else
			str[0] = '\0';
	}
	if (form->prec > len)
	{
		s1 = ft_memalloc(form->prec);
		ft_add_str_begin(str, ft_memset(s1, '0', (form->prec - len)));
		if ((form->type == 'x' || form->type == 'X') && form->is_h == 1 &&
				!ft_zero(str))
			ft_add_str_begin(str, c);
	}
	free(s1);
}
