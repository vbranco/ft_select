/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/25 10:59:17 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/25 11:42:55 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*start;

	if (!lst)
		return (NULL);
	else
	{
		tmp = (*f)(lst);
		new = NULL;
		new = ft_lstnew(tmp->content, tmp->content_size);
		if (new == NULL)
			return (NULL);
		start = new;
		lst = lst->next;
		while (lst)
		{
			tmp = (*f)(lst);
			new->next = ft_lstnew(tmp->content, tmp->content_size);
			lst = lst->next;
			new = new->next;
		}
		free(tmp);
		return (start);
	}
}
