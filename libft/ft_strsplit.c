/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:45:44 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/28 19:02:21 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	char		**str;
	size_t		i;
	size_t		words;
	int			size_words;
	int			start;

	str = NULL;
	i = 0;
	words = 0;
	if (s && (str = (char**)malloc(sizeof(char*) * (ft_count_words(s, c) + 1))))
	{
		while (s[i])
		{
			while (s[i] && s[i] == c)
				i++;
			start = i;
			while (s[i] != c && s[i])
				i++;
			size_words = i;
			if (size_words > start)
				str[words++] = ft_strsub(s, start, size_words - start);
		}
		str[words] = NULL;
	}
	return (str);
}
/*
**int		main(void)
**{
**	char	a[] = "i frgerg    salut |les |etudiants         ?    ";
**	char	b[] = "0 0 0 0 0 0";
**	char	c[] = "asd | dsf sdf||| SDF||||?|";
**	char	**str;
**	int		i;
**
**	i = 0;
**	//	ft_count_words(a, ' ');
**	str = ft_strsplit(a, ' ');
**	//	str = ft_strsplit(b, ' ');
**	//	str = ft_strsplit(c, '|');
**	while (str[i])
**	{
**		ft_putstr(str[i]);
**		ft_putchar('\n');
**		i++;
**	}
**	ft_putstr(a);
**	return (0);
**}
*/
