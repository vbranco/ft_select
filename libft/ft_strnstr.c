/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:40:42 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 17:34:22 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	need_len;
	size_t	i;

	need_len = ft_strlen(needle);
	if (need_len == 0)
		return ((char *)haystack);
	while (len != 0 && *haystack)
	{
		i = 0;
		while (i < len && i < need_len && *(haystack + i) == *(needle + i))
			i++;
		if (i == need_len)
			return ((char *)(haystack));
		haystack++;
		len--;
	}
	return (NULL);
}
/*
**#include <stdio.h>
**#include <bsd/string.h>
**int		main(void)
**{
**	char	a[] = "MZIRIBMZIRIBMZE123";
**	char	b[] = "MZIRIBMZE";
**	printf("mine --->%s\n", ft_strnstr(a, b, 20));
**	printf("%s\n", strnstr(a, b, 20));
**	return (0);
**}
*/
