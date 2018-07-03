/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free_2char.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/31 16:30:33 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/31 16:30:35 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		ft_free_2char(char ***s)
{
	size_t	i;
	char	**tmp;

	tmp = *s;
	i = 0;
	if (s && tmp)
	{
		while (tmp[i])
		{
			free(tmp[i]);
			i++;
		}
		free(tmp); //ceci cree des erreurs avec valgrind
	}
	*s = NULL;
}
