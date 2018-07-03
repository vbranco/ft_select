/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:39:54 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:39:55 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	size_t	siz;

	i = 0;
	len = ft_strlen(dst);
	if (size <= len)
		return (ft_strlen(src) + size);
	siz = size - len - 1;
	while (src[i] && i < siz)
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = '\0';
	return (len + ft_strlen(src));
}
/*
**#include <stdio.h>
**#include <string.h>
**int		main(void)
**{
**	char	a[] = "tout le monde";
**	char	b[15] = "bonjour ";
**	printf("mine ---- %zu\n", ft_strlcat(b, a, 10));
**	printf("%zu\n", strlcat(b, a, 10));
**	return (0);
**}
*/
