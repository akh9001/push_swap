/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_c_d_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 18:44:46 by akhalidy          #+#    #+#             */
/*   Updated: 2021/08/28 16:15:43 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min_circulary_dlst(t_cir_dlst **head)
{
	int			min;
	t_cir_dlst	*tmp;

	min = (*head)->data;
	tmp = (*head)->next;
	while (tmp != *head)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}

int	ft_id_min_circulary_dlst(t_cir_dlst **head)
{
	int			min;
	t_cir_dlst	*tmp;

	min = (*head)->id;
	tmp = (*head)->next;
	while (tmp != *head)
	{
		if (tmp->id < min)
			min = tmp->id;
		tmp = tmp->next;
	}
	return (min);
}
