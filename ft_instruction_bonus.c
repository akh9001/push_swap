/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 18:14:42 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/17 18:43:31 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa_bonus(t_cir_dlst **stack_dst, t_cir_dlst **stack_src)
{
	ft_push(stack_dst, stack_src);
}

void	ft_pb_bonus(t_cir_dlst **stack_dst, t_cir_dlst **stack_src)
{
	ft_push(stack_src, stack_dst);
}

void	ft_rrr_bonus(t_cir_dlst **stack_a, t_cir_dlst **stack_b)
{
	ft_reverse(stack_a);
	ft_reverse(stack_b);
}

void	ft_rra_bonus(t_cir_dlst **stack)
{
	ft_reverse(stack);
}

void	ft_rrb_bonus(t_cir_dlst **stack)
{
	ft_reverse(stack);
}
