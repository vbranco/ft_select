/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:40:30 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:40:31 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	char	*str1;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(needle);
	str1 = (char*)haystack;
	if (len == 0)
		return (str1);
	while (str1[i])
	{
		j = 0;
		while (str1[i + j] == needle[j])
		{
			j++;
			if (needle[j] == '\0')
				return (str1 + i);
		}
		i++;
	}
	return (NULL);
}
/*
**#include <stdio.h>
**#include <string.h>
**int		main(void)
**{
**	char	a[] = "see F your F return FF now FF";
**	char	b[] = "FF";
**	printf("mine ---- %s\n", ft_strstr(a, b));
**	printf("%s", strstr(a, b));
**	return (0);
**}
*/
