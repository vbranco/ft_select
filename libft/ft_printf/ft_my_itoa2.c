/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_my_itoa2.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 18:58:30 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 20:16:06 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_my_itoa2(uintmax_t nb, char *tmp)
{
	char				*s;
	size_t				i;

	i = 0;
	s = ft_memalloc(ft_size_nb2(nb) + 1);
	while (nb > 9)
	{
		s[i] = ((nb % 10) + '0');
		nb /= 10;
		i++;
	}
	s[i] = ((nb % 10) + '0');
	s = ft_reverse(s);
	ft_strcat(tmp, s);
	free(s);
}
