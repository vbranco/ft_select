/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_my_itoa.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 16:50:10 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 19:40:06 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_uintmax(uintmax_t n, intmax_t nb, char *s)
{
	size_t	i;

	i = 0;
	if (nb < 0)
	{
		s[i] = '-';
		i++;
	}
	while (n > 9)
	{
		s[i] = ((n % 10) + '0');
		n /= 10;
		i++;
	}
	s[i] = ((n % 10) + '0');
}

static void	ft_intmax(intmax_t nb, char *s)
{
	size_t	i;

	i = 0;
	if (nb < 0)
	{
		s[i] = '-';
		nb *= -1;
		i++;
	}
	while (nb > 9)
	{
		s[i] = ((nb % 10) + '0');
		nb /= 10;
		i++;
	}
	s[i] = ((nb % 10) + '0');
}

void		ft_my_itoa(intmax_t nb, char *tmp)
{
	uintmax_t	n;
	char		*s;

	n = (uintmax_t)nb;
	s = ft_memalloc(ft_size_nb2(nb) + 1);
	if (nb < 0 && nb < -9223372036854775807)
		ft_uintmax(n, nb, s);
	else
		ft_intmax(nb, s);
	s = ft_reverse(s);
	ft_strcat(tmp, s);
	free(s);
}
