/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 13:55:49 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/14 13:52:26 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_cir_dlst **stack)
{
	if (*stack)
		*stack = (*stack)->next;
}

void	ft_rr(t_cir_dlst **stack_a, t_cir_dlst **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_putendl_fd("rr", 1);
}

void	ft_ra(t_cir_dlst **stack)
{
	ft_rotate(stack);
	ft_putendl_fd("ra", 1);
}

void	ft_rb(t_cir_dlst **stack)
{
	ft_rotate(stack);
	ft_putendl_fd("rb", 1);
}
