/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:42:52 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:42:55 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdel(void **ap)
{
	if (!ap)
		return ;
	while (*ap)
	{
		free(*ap);
		*ap = NULL;
	}
}
/*
**#include "libft.h"
**int	main(void)
**{
**	int	**a;
**	int	i;
**	int	j;
**
**	i = 0;
**	a = ft_memalloc(10);
**	while (i < 10)
**	{
**		a[i] = ft_memalloc(10);
**		i++;
**	}
**	i = 0;
**	while (i < 10)
**	{
**		j = 0;
**		while (j < 10)
**		{
**			ft_putnbr(a[i][j]);
**			j++;
**		}
**		ft_putchar('\n');
**		i++;
**	}
**	ft_memdel(a);
**	while (i < 10)
**	{
**		free(a[i]);
**		i++;
**	}
**	free(a);
**	a = NULL;
**	printf("%d", a);
**	return (0);
**}
*/
