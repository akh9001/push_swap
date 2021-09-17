/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 18:44:10 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/17 18:46:16 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr_bonus(t_cir_dlst **stack_a, t_cir_dlst **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}

void	ft_ra_bonus(t_cir_dlst **stack)
{
	ft_rotate(stack);
}

void	ft_rb_bonus(t_cir_dlst **stack)
{
	ft_rotate(stack);
}
