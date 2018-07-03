/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_toupper.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:42:17 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:42:18 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}
/*
**int	main(void)
**{
**	char	str[] = "TutO A 2 Faire!";
**	int	i;
**
**	i = 0;
**	while (str[i])
**	{
**		ft_putchar(ft_toupper(str[i]));
**		i++;
**	}
**	return (0);
**}
*/
