/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_add_str_begin.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 16:59:28 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/10 13:43:27 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_add_str_begin(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_strcpy(tmp, s2);
	ft_strcat(tmp, s1);
	ft_strcpy(s1, tmp);
	free(tmp);
}
