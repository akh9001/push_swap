/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_db_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmaa-kh <asmaa-kh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:12:12 by akhalidy          #+#    #+#             */
/*   Updated: 2021/08/12 22:39:48 by asmaa-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


t_cir_dlst	*ft_assign(t_cir_dlst **new)
{
	*new = (t_cir_dlst *)malloc(sizeof(t_cir_dlst));
	return (*new);
}

t_cir_dlst	*ft_cer_dlstnew(int data, int id)
{
	t_cir_dlst	*new;

	new = NULL;
	if (!(new = (t_cir_dlst *)malloc(sizeof(t_cir_dlst))))
		return (NULL);
	new->id = id;
	new->data = data;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	ft_cer_dlstadd_back(t_cir_dlst **head, t_cir_dlst *new)
{
	if (head && new)
	{
		if (!*head)
        {
			*head = new;
            (*head)->next = *head;
            (*head)->prev = *head;
        }
		else
		{
            new->next = *head;
            new->prev = (*head)->prev;
            (*head)->prev->next = new;
            (*head)->prev = new;
		}
	}
}

// t_cir_dlst	*ft_dlstlast(t_cir_dlst *lst)
// {
//     return (lst->prev);
// }

// void	ft_dlstclear(t_cir_dlst **lst, void (*del)(void *))
// {
// 	t_cir_dlst *tmp;
// 	t_cir_dlst *l;

// 	if (lst && del)
// 	{
// 		l = *lst;
// 		while (l)
// 		{
// 			tmp = l;
// 			l = l->next;
// 			ft_dlstdelone(tmp, del);
// 		}
// 		*lst = NULL;
// 	}
// }

// t_dlst	*ft_dlstlast(t_dlst *lst)
// {
// 	if (lst)
// 	{
// 		while (lst->next)
// 			lst = lst->next;
// 	}
// 	return (lst);
// }

void	ft_cer_dlstclear(t_cir_dlst **lst)
{
	t_cir_dlst	*tmp;
	t_cir_dlst	*l;

	if (lst && *lst)
	{
		(*lst)->prev->next = NULL;
		(*lst)->prev = NULL;
		l = (*lst);
		while (l)
		{
			tmp = l;
			l = l->next;
			free(tmp);
			tmp = NULL;
		}
		*lst = NULL;
	}
}

void	ft_cer_dlstdelone(t_cir_dlst *lst, void (*del)(void*))
{
	if (lst && del)
	{
		del(lst);
		lst = NULL;
	}
}

void	ft_cer_dlstprint(t_cir_dlst *lst)
{
	char		*num;
	t_cir_dlst	*tmp;

	if (lst == NULL)
		return ;
	tmp = lst;
	num = ft_itoa(tmp->id);
	ft_putstr_fd(num, 1);
	ft_putstr_fd(" ", 1);
	free (num);
	num = ft_itoa(tmp->data);
	ft_putendl_fd(ft_itoa(tmp->data), 1);
	free (num);
	tmp = tmp->next;
	while (tmp != lst)
	{
		num = ft_itoa(tmp->id);
		ft_putstr_fd(num, 1);
		ft_putstr_fd(" ", 1);
		free (num);
		num = ft_itoa(tmp->data);
		ft_putendl_fd(num, 1);
		free (num);
		num = NULL;
		tmp = tmp->next;
	}
}

int	ft_cer_dlst_size(t_cir_dlst *head)
{
	t_cir_dlst	*tmp;
	int			len;
	
	if (!head)
		return (0); 
	tmp = head->next;
	len = 1;
	while (tmp != head)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}
