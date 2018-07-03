/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:31:27 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:31:28 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
**#include <stdio.h>
**#include <string.h>
**int	main(void)
**{
**	char	a[] = "bonjour";
**	printf("%d\n", strlen(a));
**	printf("%d\n", ft_strlen(a));
**	return (0);
**}
*/
