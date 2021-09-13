/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_outils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:55:58 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/13 12:17:28 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_next_num_pos_satck_b(t_cir_dlst *head, int num)
{
	t_cir_dlst	*tmp;
	int			i;

	tmp = head;
	i = 0;
	while (tmp->id == num)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_pb_head_rb_elt_greater_than_mid(t_struct *var, int size)
{
	t_cir_dlst	*tmp;
	int			mid_size;

	ft_pb(var->head, var->stack_b);
	mid_size = (size - var->npush - 1) / 2;
	tmp = *(var->stack_b);
	if ((tmp->next != tmp) && (tmp->id < var->mid))
	{
		if (ft_get_next_num_pos_cpy(*var, size - var->npush - 1) <= mid_size)
			ft_rr(var->head, var->stack_b);
		else
			ft_rb(var->stack_b);
	}
	var->tmp = *(var->head);
	var->tail = (*(var->head))->prev;
	var->npush--;
}

void	ft_pb_tail_rb_elt_greater_than_mid(t_struct *var, int size)
{
	t_cir_dlst	*tmp;
	int			mid_size;

	ft_rra(var->head);
	ft_pb(var->head, var->stack_b);
	mid_size = (size - var->npush - 1) / 2;
	tmp = *(var->stack_b);
	if ((tmp->next != tmp) && (tmp->id < var->mid))
	{
		if (ft_get_next_num_pos_cpy(*var, size - var->npush - 1) <= mid_size)
			ft_rr(var->head, var->stack_b);
		else
			ft_rb(var->stack_b);
	}
	var->tmp = *(var->head);
	var->tail = (*(var->head))->prev;
	var->npush--;
}

void	ft_push_head_stack(t_struct *var, int size)
{
	if (var->tmp->id >= var->min && var->tmp->id <= var->max)
		ft_pb_head_rb_elt_greater_than_mid(var, size);
	else if (var->tail->id >= var->min && var->tail->id <= var->max)
		ft_pb_tail_rb_elt_greater_than_mid(var, size);
	else
	{
		var->tmp = var->tmp->next;
		var->tail = var->tail->prev;
	}
}
