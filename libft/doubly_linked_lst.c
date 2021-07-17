/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_lst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 11:11:31 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/15 20:59:35 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlst	*ft_dlstnew(void *content, int id)
{
	t_dlst *new;

	if (!(new = (t_dlst *)malloc(sizeof(t_dlst))))
		return (NULL);
	new->id = id;
	new->content = content;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	ft_dlstadd_back(t_dlst **alst, t_dlst *new)
{
	t_dlst *last;

	if (alst && new)
	{
		if (!*alst)
			*alst = new;
		else
		{
			last = ft_dlstlast(*alst);
			last->next = new;
			new->prev = last;
		}
	}
}

t_dlst	*ft_dlstlast(t_dlst *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

void	ft_dlstclear(t_dlst **lst, void (*del)(void *))
{
	t_dlst *tmp;
	t_dlst *l;

	if (lst && del)
	{
		l = *lst;
		while (l)
		{
			tmp = l;
			l = l->next;
			ft_dlstdelone(tmp, del);
		}
		*lst = NULL;
	}
}

void	ft_dlstdelone(t_dlst *lst, void (*del)(void*))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
