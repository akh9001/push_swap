/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 13:42:23 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/17 19:30:00 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_cir_dlst	*stack_a;
	t_cir_dlst	*stack_b;
	int			*arr;

	if (argc <= 1)
		return (0);
	arr = ft_fill_stack(argc, argv, &stack_a, &stack_b);
	if (!ft_is_sorted(stack_a))
		return (0);
	if (argc <= 4)
		ft_sort_three_elt(&stack_a);
	else if (argc <= 6)
		ft_sort_five_elt(&stack_a, &stack_b);
	else
		ft_launch_sort_algo(&stack_a, &stack_b, argc - 1);
	ft_cer_dlstclear(&stack_a);
	ft_cer_dlstclear(&stack_b);
	free(arr);
	return (0);
}
