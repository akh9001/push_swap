/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:55:47 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/14 13:51:16 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_struct	ft_initize(t_cir_dlst **head, t_cir_dlst **stack_b)
{
	t_struct	var;

	var.head = head;
	var.stack_b = stack_b;
	var.max = ft_max_circulary_dlst(head);
	var.min = ft_min_circulary_dlst(head);
	var.tmp = *head;
	var.tail = (*head)->prev;
	return (var);
}

void	ft_push_min_max(t_struct *src, int tail)
{
	if (!tail)
	{
		while (*(src->head) != src->tmp)
			ft_ra(src->head);
	}
	else
	{
		while (*(src->head) != src->tail)
			ft_rra(src->head);
	}
	ft_pb(src->head, src->stack_b);
	src->tmp = *(src->head);
	src->tail = (*(src->head))->prev;
}

void	ft_help(t_struct *src)
{
	if (src->tmp->data == src->max || src->tmp->data == src->min)
	{
		while (*(src->head) != src->tmp)
			ft_ra(src->head);
		ft_pb(src->head, src->stack_b);
	}
	ft_sort_three_elt(src->head);
	ft_pa(src->head, src->stack_b);
	if ((*(src->head))->data == src->max)
	{
		ft_ra(src->head);
		ft_pa(src->head, src->stack_b);
	}
	else
	{
		ft_pa(src->head, src->stack_b);
		ft_ra(src->head);
	}	
}

void	ft_sort_five_elt(t_cir_dlst **head, t_cir_dlst **stack_b)
{
	t_struct	var;

	var = ft_initize(head, stack_b);
	while (var.tmp != var.tail
		&& !(var.tmp->next == var.tail && var.tail->next == var.tmp))
	{
		if (var.tmp->data == var.max || var.tmp->data == var.min)
		{
			ft_push_min_max(&var, 0);
			continue ;
		}
		else if (var.tail->data == var.max || var.tail->data == var.min)
		{
			ft_push_min_max(&var, 1);
			continue ;
		}
		var.tmp = var.tmp->next;
		var.tail = var.tail->prev;
	}
	ft_help(&var);
}
