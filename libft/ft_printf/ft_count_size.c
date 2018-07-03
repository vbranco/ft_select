/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_count_size.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 19:22:30 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 19:46:37 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count_size(wchar_t *wstr)
{
	size_t	size;
	size_t	i;

	size = 0;
	i = 0;
	while (wstr[i])
	{
		if (wstr[i] <= 127)
			size += 1;
		else if (wstr[i] < 0x800)
			size += 2;
		else if (wstr[i] < 0x10000)
			size += 3;
		else
			size += 4;
		i++;
	}
	return (size);
}
