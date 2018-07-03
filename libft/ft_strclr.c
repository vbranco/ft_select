/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strclr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:43:27 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:43:28 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		s[i] = '\0';
		i++;
	}
}
/*
**int	main(void)
**{
**	char	s[] = "bonjour";
**	ft_putstr(s);
**	ft_putchar('\n');
**	ft_strclr(s);
**	ft_putstr(s);
**	ft_putchar('\n');
**	return (0);
**}
*/
