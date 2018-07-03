/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:30:12 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:30:14 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*ds;
	char	*sr;

	i = 0;
	ds = (char*)dst;
	sr = (char*)src;
	while (i < n)
	{
		ds[i] = sr[i];
		i++;
	}
	return (ds);
}
/*
**#include <stdio.h>
**int main () {
**	const char src[50] = "http://www.tutorialspoint.com";
**	char dest[50];
**
**	printf("Before memcpy dest = %s\n", dest);
**	memcpy(dest, src, strlen(src)+1);
**	printf("After memcpy dest = %s\n", dest);
**	return(0);
**}
*/
