/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:55:47 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/29 21:16:49 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_sort_five_elt(t_cir_dlst **head, t_cir_dlst **stack_b)
{
	int			max;
	int			min;
	t_cir_dlst	*tmp;
	t_cir_dlst	*tail;

	max = ft_max_circulary_dlst(head);
	min = ft_min_circulary_dlst(head);
	tmp = *head;
	tail = (*head)->prev;
	while (tmp != tail)
	{
		// printf("head->data: %d, tmp->data: %d\n",(*head)->data, tmp->data);
		// sleep(5);
		if (tmp->data == max || tmp->data == min)
		{
			while (*head != tmp)
			{
				ft_ra(head);
				// sleep(5);
				// printf("head->data: %d\n",(*head)->data);
			}
			ft_pb(head, stack_b);
			tmp = *head;
			tail = (*head)->prev;
			continue ;
		}
		else if (tail->data == max || tail->data == min)
		{
			while (*head != tail)
				ft_rra(head);
			ft_pb(head, stack_b);
			tmp = *head;
			tail = (*head)->prev;
			continue ;
		}
		tmp = tmp->next;
		tail = tail->prev;
	}
	if (tmp->data == max || tmp->data == min)
	{
		while (*head != tmp)
			ft_pb(head, stack_b);
	}
	ft_sort_three_elt(head);
	ft_pa(head, stack_b);
	if ((*head)->data == max)
	{
		ft_ra(head);
		ft_pa(head, stack_b);
	}
	else
	{
		ft_pa(head, stack_b);
		ft_ra(head);
	}
}
