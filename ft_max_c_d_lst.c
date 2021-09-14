/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_c_d_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 21:01:53 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/14 13:55:59 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max_circulary_dlst(t_cir_dlst **head)
{
	int			max;
	t_cir_dlst	*tmp;

	max = (*head)->data;
	tmp = (*head)->next;
	while (tmp != *head)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}

void	ft_sort_three_elt(t_cir_dlst **head)
{
	int	max;

	max = ft_max_circulary_dlst(head);
	if ((*head)->prev->prev == *head)
	{
		if ((*head)->data > (*head)->next->data)
			ft_sa(*head);
		return ;
	}
	if ((*head)->data == max)
		ft_ra(head);
	else if ((*head)->prev->data != max)
		ft_rra(head);
	if ((*head)->data > (*head)->next->data)
		ft_sa(*head);
}
