/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:40:19 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:40:21 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	cara;
	int		len;

	str = (char*)s;
	cara = (char)c;
	len = ft_strlen(str);
	while (len >= 0)
	{
		if (str[len] == cara)
			return (str + len);
		len--;
	}
	return (NULL);
}
/*
**#include <stdio.h>
**#include <string.h>
**int		main(void)
**{
**	char	a[] = "bonjour";
**	char	b = 'r';
**
**	printf("%s\n", ft_strrchr(a, b));
**	printf("%s", strrchr(a, b));
**	return (0);
**}
*/
