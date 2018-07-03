/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:32:09 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:32:10 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (src[i] == '\0')
		{
			while (i < len)
			{
				dst[i] = '\0';
				i++;
			}
		}
		else
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (dst);
}
/*
**#include <stdio.h>
**#include <string.h>
**int		main(void)
**{
**	char	a[] = "bonj\0our";
**	char	b[15];
**	char	c[15];
**
**	ft_strncpy(b, a, 9);
**	printf("la mienne ----- %s\n", b);
**	strncpy(c, a , 4);
**	printf("%s\n", c);
**	return (0);
**}
*/
