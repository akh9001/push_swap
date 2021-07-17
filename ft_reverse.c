/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 14:00:35 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/17 16:51:59 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse(t_cir_dlst **stack)
{
	if (*stack)
		*stack = (*stack)->prev;
}

void	ft_rrr(t_cir_dlst **stack_a, t_cir_dlst **stack_b)
{
	ft_reverse(stack_a);
	ft_reverse(stack_b);
	ft_putendl_fd("rrr", 1);
}

void	ft_rra(t_cir_dlst **stack)
{
	ft_rotate(stack);
	ft_putendl_fd("rra", 1);
}

void	ft_rrb(t_cir_dlst **stack)
{
	ft_rotate(stack);
	ft_putendl_fd("rrb", 1);
}
