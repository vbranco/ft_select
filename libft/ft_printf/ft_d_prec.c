/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_d_prec.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/28 17:14:09 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 17:14:49 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_d_prec(char *str, t_form *form)
{
	int		len;
	int		i;
	char	*s1;

	i = 0;
	s1 = NULL;
	len = ft_strlen(str);
	if (form->prec == 0 && str[0] == '0')
		str[0] = '\0';
	if (form->prec > len)
	{
		s1 = ft_memalloc(form->prec);
		ft_add_str_begin(str, ft_memset(s1, '0', (form->prec - len)));
	}
	free(s1);
}
