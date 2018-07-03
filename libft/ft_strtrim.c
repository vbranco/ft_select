/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:45:30 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:45:32 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		size;
	int		len;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	size = ft_strlen(s) - 1;
	len = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (ft_strdup(s + i));
	while (s[size] == ' ' || s[size] == '\n' || s[size] == '\t')
	{
		size--;
		len++;
	}
	size = ft_strlen(s);
	size = size - len - i;
	str = ft_strsub(s, i, size);
	return (str);
}
/*
**int		main(void)
**{
**	char	a[] = "  	bonjour  qwe  	 ";
**	char	*b;
**
**	b = ft_strtrim(a);
**	ft_putstr(b);
**	return (0);
**}
*/
