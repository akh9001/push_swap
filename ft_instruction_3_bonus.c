/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 18:47:02 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/17 18:48:14 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss_bonus(t_cir_dlst *stack_a, t_cir_dlst *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
}

void	ft_sa_bonus(t_cir_dlst *stack)
{
	ft_swap(stack);
}

void	ft_sb_bonus(t_cir_dlst *stack)
{
	ft_swap(stack);
}
