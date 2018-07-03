/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:40:05 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:40:07 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	car;
	size_t	i;

	str = (char*)s;
	car = (char)c;
	i = 0;
	while (str[i] != car)
	{
		if (str[i] == '\0' && car != '\0')
			return (NULL);
		i++;
	}
	return (str + i);
}
/*
**#include <stdio.h>
**int		main(void)
**{
**	char	a[] = "asd";
**	char	b = 'z';
**
**	printf("%s\n", ft_strchr(a, b));
**	return (0);
**}
*/
