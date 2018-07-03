/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memset.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:29:23 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:29:38 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	a;
	unsigned char	*tab;

	a = (unsigned char)c;
	tab = (unsigned char*)b;
	i = 0;
	while (i < len)
	{
		tab[i] = a;
		i++;
	}
	return (tab);
}
/*
**#include <stdio.h>
**int main ()
**{
**	char str[50];
**
**	strcpy(str,"This is string.h library function");
**	puts(str);
**	memset(str,'$',7);
**	puts(str);
**	return(0);
**}
*/
