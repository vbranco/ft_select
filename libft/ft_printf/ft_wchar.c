/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wchar.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 17:33:55 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 18:32:42 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put2wchar(wchar_t wc, char *str)
{
	str[0] = (wc >> 6) + 0xc0;
	str[1] = (wc & 0x3f) + 0x80;
}

static void	ft_put3wchar(wchar_t wc, char *str)
{
	str[0] = (wc >> 12) + 0xe0;
	str[1] = ((wc >> 6) & 0x3f) + 0x80;
	str[2] = (wc & 0x3f) + 0x80;
}

static void	ft_put4wchar(wchar_t wc, char *str)
{
	str[0] = (wc >> 18) + 0xf0;
	str[1] = ((wc >> 12) & 0x3f) + 0x80;
	str[2] = ((wc >> 6) & 0x3f) + 0x80;
	str[3] = (wc & 0x3f) + 0x80;
}

int			ft_wchar(wchar_t wc, char *str)
{
	if ((wc < 0 || wc > 0x10ffff) || (wc >= 0xd800 && wc <= 0xdfff))
		return (-1);
	if (wc <= 127)
		str[0] = wc;
	else if (wc <= 255 && MB_CUR_MAX == 1)
		str[0] = (char)wc;
	else if (wc > 127 && MB_CUR_MAX > 1)
	{
		if (wc < 0x800)
			ft_put2wchar(wc, str);
		else if (wc < 0x10000)
			ft_put3wchar(wc, str);
		else if (wc < 0x110000)
			ft_put4wchar(wc, str);
	}
	else
		return (-1);
	return (ft_strlen(str));
}
