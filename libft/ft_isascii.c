/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isascii.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:41:57 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:41:58 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
**int	main(void)
**{
**	int	a = 0;
**	if (ft_isascii(a) > 0)
**		ft_putstr("IS ASCII");
**	else
**		ft_putstr("NOT ASCII");
**	return (0);
**}
*/
