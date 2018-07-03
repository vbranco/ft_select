/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_reverse.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 19:02:35 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/28 19:02:37 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_reverse(char *str)
{
	char	a;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str) - 1;
	if (str[i] == '-')
		i++;
	while (i < len)
	{
		a = str[i];
		str[i] = str[len];
		str[len] = a;
		i++;
		len--;
	}
	return (str);
}
