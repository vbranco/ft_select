#include "libft.h"

static int		ft_nb(char *s)
{
	int			i;
	int			word;

	i = 0;
	word = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while (s[i])
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
			i++;
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
		{
			word++;
			while (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
				i++;
		}
		while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
			i++;
	}
	return (word);
}

char			**ft_split(char *str)
{
	char		**s;
	int			nb_words;
	int			i;
	int			start;
	int			w;

	i = 0;
	w = 0;
	nb_words = 0;
	if (!str)
		return (NULL);
	nb_words = ft_nb(str);
	if (!(s = (char**)malloc(sizeof(char*) * (nb_words + 1))))
		return (NULL);
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		start = i;
		while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			i++;
		if (w < nb_words)
			s[w++] = ft_strsub(str, start, i - start);
	}
	s[w] = NULL;
	return (s);
}
