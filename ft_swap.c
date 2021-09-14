/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 11:01:06 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/14 13:50:13 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_cir_dlst *stack)
{
	int	tmp;

	if (!stack || stack == stack->next)
		return ;
	tmp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = tmp;
}

void	ft_ss(t_cir_dlst *stack_a, t_cir_dlst *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_putendl_fd("ss", 1);
}

void	ft_sa(t_cir_dlst *stack)
{
	ft_swap(stack);
	ft_putendl_fd("sa", 1);
}

void	ft_sb(t_cir_dlst *stack)
{
	ft_swap(stack);
	ft_putendl_fd("sb", 1);
}
