/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_striter.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:43:45 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:43:47 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	if (!s || !f)
		return ;
	while (*s)
		(f)(s++);
}
/*
**int	main(void)
**{
**	char	s[] = "Bonjour";
**
**	ft_putstr(s);
**	ft_putchar('\n');
**	ft_striter(s, &ft_putchar);
**	ft_putstr(s);
**	ft_putchar('\n');
**	return (0);
**}
*/
