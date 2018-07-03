/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/31 15:45:41 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/31 15:45:58 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

static int				getch(t_list *cur)
{
	if (((t_getch*)(cur->content))->n == 0)
	{
		((t_getch*)cur->content)->bufp = ((t_getch*)cur->content)->buf;
		((t_getch*)cur->content)->n = read(((t_getch*)cur->content)->fd,
			((t_getch*)cur->content)->buf, BUFF_SIZE);
		if (((t_getch*)cur->content)->n == -1)
			return (-2);
	}
	return ((--((t_getch*)cur->content)->n >= 0) ?
			(unsigned char)*((t_getch*)cur->content)->bufp++ : EOF);
}

static t_getch				*set_getch(const int fd)
{
	t_getch	*getch;

	if (!(getch = (t_getch*)malloc(sizeof(*getch))))
		return (NULL);
	getch->fd = fd;
	getch->n = 0;
	getch->bufp = getch->buf;
	return (getch);
}

static t_list				*tog_lst(t_list **lst, const int fd)
{
	t_list	*cur;
	t_getch *track;

	cur = *lst;
	if (*lst == NULL)
	{
		track = set_getch(fd);
		*lst = ft_lstnew(track, sizeof(t_getch));
		free(track);
		return (*lst);
	}
	while (cur)
	{
		if (((t_getch*)(cur->content))->fd == fd)
			return (cur);
		cur = cur->next;
	}
	track = set_getch(fd);
	ft_lstadd(lst, ft_lstnew(track, sizeof(t_getch)));
	free(track);
	return (*lst);
}

int					get_next_line(const int fd, char **line)
{
	char			*s;
	char			c;
	static t_list	*lst = NULL;
	t_list			*cur;
	size_t			i;

	if (fd < 0 || BUFF_SIZE < 1 || line == NULL || read(fd, NULL, 0) < 0)
		return (-1);
	if (((s = ft_strnew(BUFF_SIZE)) == NULL))
		return (-1);
	cur = tog_lst(&lst, fd);
	i = 0;
	while ((c = getch(cur)) != '\n' && c != EOF)
	{
		if (c == -2)
			return (-1);
		if (i % BUFF_SIZE == 0 && (s = ft_strexpand(&s, BUFF_SIZE)) == NULL)
			return (-1);
		s[i++] = c;
	}
	s[i] = '\0';
	*line = s;
	return ((i > 0 || (i == 0 && c == '\n')) ? 1 : 0);
}
