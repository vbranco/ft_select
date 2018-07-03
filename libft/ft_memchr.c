/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:30:59 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:31:04 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tab;
	unsigned char	a;
	size_t			num;

	tab = (unsigned char*)s;
	a = (unsigned char)c;
	num = 0;
	while (num < n)
	{
		if (tab[num] == a)
			return (tab + num);
		num++;
	}
	return (NULL);
}
/*
**int	main(void)
**{
**	char	a[] = "bordel";
**	char	b = 'r';
**	char	c = 'z';
**	char	*z;
**	char	*y;
**	z = ft_memchr(a, c, 4);
**	y = memchr(a, b, 2);
**	printf("%s\n", z);
**	printf("%s\n", y);
**	return (0);
**}
*/
