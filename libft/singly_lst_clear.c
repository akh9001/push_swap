/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singly_lst_clear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:28:17 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/15 16:24:41 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*l;

	if (lst && del)
	{
		l = *lst;
		while (l)
		{
			tmp = l;
			l = l->next;
			ft_lstdelone(tmp, del);
		}
		*lst = NULL;
	}
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
