/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncmp.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:41:06 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:41:07 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	if (n == 0)
		return (0);
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	n--;
	while ((*str1 || *str2) && *str1 == *str2 && n--)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
/*
**#include <stdio.h>
**#include <string.h>
**int		main(void)
**{
**	char	a[] = "abcdefg";
**	char	b[] = "abcderg";
**
**	printf("mine ---->%d\n", ft_strncmp(a, b, 6));
**	printf("%d\n", strncmp(a, b, 6));
**	return (0);
**}
*/
