/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wstr.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 18:44:46 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 15:54:46 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size(wchar_t c)
{
	if (c <= 127)
		return (1);
	else if (c < 0x800)
		return (2);
	else if (c < 0x10000)
		return (3);
	else
		return (4);
}

int			ft_wstr(wchar_t *wstr, char *str, t_form *form)
{
	size_t	i;
	char	*tmp;
	int		size;

	size = 0;
	i = 0;
	while (wstr[i])
	{
		size += ft_size(wstr[i]);
		if (size > form->prec && form->prec > -1 && MB_CUR_MAX != 1)
			break ;
		tmp = ft_memalloc(65);
		if ((ft_wchar(wstr[i], tmp)) == -1)
		{
			if ((int)i == form->prec)
				break ;
			free(tmp);
			return (-1);
		}
		ft_strcat(str, tmp);
		i++;
		free(tmp);
	}
	return (0);
}
