/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isalpha.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:41:28 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:41:29 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
/*
**int	main(void)
**{
**	int	a = '\0';
**
**	if (ft_isalpha(a) > 0)
**		ft_putstr("IS ALPHA");
**	else
**		ft_putstr("NOT ALPHA");
**	return (0);
**}
*/
