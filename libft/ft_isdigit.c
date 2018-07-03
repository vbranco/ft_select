/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isdigit.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:41:37 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:41:38 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/*
**int	main(void)
**{
**	int	a = 140;
**
**	if (ft_isdigit(a) > 0)
**		ft_putstr("IS DIGIT");
**	else
**		ft_putstr("NOT DIGIT");
**	return (0);
**}
*/
