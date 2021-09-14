/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 12:14:42 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/14 13:54:29 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_cir_dlst **stack_dst, t_cir_dlst **stack_src)
{
	t_cir_dlst	*first_elt;
	t_cir_dlst	*last_elt;

	if (*stack_src)
	{
		first_elt = *stack_src;
		if (*stack_src == (*stack_src)->next)
			*stack_src = NULL;
		else
		{
			last_elt = first_elt->prev;
			first_elt->next->prev = last_elt;
			last_elt->next = first_elt->next;
			*stack_src = first_elt->next;
		}	
		if (*stack_dst)
		{
			last_elt = (*stack_dst)->prev;
			first_elt->next = *stack_dst;
			first_elt->prev = last_elt;
			last_elt->next = first_elt;
			(*stack_dst)->prev = first_elt;
			*stack_dst = first_elt;
		}
		else
		{
			*stack_dst = first_elt;
			(*stack_dst)->next = first_elt;
			(*stack_dst)->prev = first_elt;
		}
	}
}

void	ft_pa(t_cir_dlst **stack_dst, t_cir_dlst **stack_src)
{
	ft_push(stack_dst, stack_src);
	ft_putendl_fd("pa", 1);
}

void	ft_pb(t_cir_dlst **stack_dst, t_cir_dlst **stack_src)
{
	ft_push(stack_src, stack_dst);
	ft_putendl_fd("pb", 1);
}
