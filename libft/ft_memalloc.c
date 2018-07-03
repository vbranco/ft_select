/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:42:42 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:42:45 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	int		*a;
	size_t	i;

	i = 0;
	if (!(a = (int*)malloc(sizeof(int) * size)))
		return (NULL);
	while (i < size)
	{
		a[i] = '\0';
		i++;
	}
	return (a);
}
/*
**int	main(void)
**{
**	int	*a;
**	int	i;
**
**	i = 0;
**	a = ft_memalloc(10);
**	while (i < 10)
**	{
**		ft_putnbr(a[i]);
**		i++;
**	}
**	return (0);
**}
*/
