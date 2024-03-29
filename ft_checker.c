/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 16:17:52 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/16 19:04:11 by akhalidy         ###   ########.fr       */
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
	ft_read_and_execute_instruction(&stack_a, &stack_b);
	ft_cer_dlstclear(&stack_a);
	ft_cer_dlstclear(&stack_b);
	return (0);
}
