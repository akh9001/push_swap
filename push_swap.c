/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmaa-kh <asmaa-kh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 13:42:23 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/31 22:43:43 by asmaa-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_cir_dlst	*stack_a;
	t_cir_dlst	*stack_b;

	if (argc <= 1)
		return (0);
	ft_fill_stack(argc, argv, &stack_a, &stack_b);
	ft_cer_dlstprint(stack_a);
	// ft_sa(stack_a);
	// ft_pb(&stack_a, &stack_b);
	// ft_pb(&stack_a, &stack_b);
	// ft_pb(&stack_a, &stack_b);
	// ft_sa(stack_a);
	// ft_pa(&stack_a, &stack_b);
	// ft_pa(&stack_a, &stack_b);
	// ft_pa(&stack_a, &stack_b);
	if (argc <= 4)
		ft_sort_three_elt(&stack_a);
	else if (argc <= 6)
		ft_sort_five_elt(&stack_a, &stack_b);
	ft_putendl_fd("\n####stack A####\n", 1);
	ft_cer_dlstprint(stack_a);
	// ft_putendl_fd("\n####stack B####\n", 1);
	// ft_cer_dlstprint(stack_b);
	ft_cer_dlstclear(&stack_a);
	// ft_cer_dlstclear(&stack_b);
	return (0);
}