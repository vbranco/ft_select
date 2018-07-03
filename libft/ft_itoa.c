/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:45:54 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/28 19:10:38 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	nb;

	nb = n;
	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (ft_size_nb(nb) + 1))))
		return (NULL);
	if (nb < 0)
	{
		str[i] = '-';
		nb = nb * -1;
		i++;
	}
	while (nb > 9)
	{
		str[i] = ((nb % 10) + '0');
		nb = nb / 10;
		i++;
	}
	str[i] = ((nb % 10) + '0');
	i++;
	str[i] = '\0';
	ft_reverse(str);
	return (str);
}
/*
**#include <stdio.h>
**int		main(void)
**{
**	int		a = -2147483648;
**	ft_itoa(a);
**	printf("%s", ft_itoa(a));
**	return (0);
**}
*/
