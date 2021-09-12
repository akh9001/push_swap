/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 13:42:23 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/12 18:13:12 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_cir_dlst	*stack_a;
	t_cir_dlst	*stack_b;
	// int			*arr;

	if (argc <= 1)
		return (0);
	// arr = ft_fill_stack(argc, argv, &stack_a, &stack_b);
	ft_fill_stack(argc, argv, &stack_a, &stack_b);
	// ft_cer_dlstprint(stack_a);
	
	// int a = ft_cer_dlst_size(stack_a);
	// int b = ft_cer_dlst_size(stack_b);
	// printf("a = %d, b = %d\n", a, b);
	// ft_sa(stack_a);
	// ft_pb(&stack_a, &stack_b);
	// ft_pb(&stack_a, &stack_b);
	// ft_pb(&stack_a, &stack_b);
	// ft_sa(stack_a);
	// ft_pa(&stack_a, &stack_b);
	// ft_pa(&stack_a, &stack_b);
	// ft_pa(&stack_a, &stack_b);
	
	
	if (!ft_is_sorted(stack_a))
		return (0);
	if (argc <= 4)
		ft_sort_three_elt(&stack_a);
	else if (argc <= 6)
		ft_sort_five_elt(&stack_a, &stack_b);
	else// if (argc <= 101)
		ft_launch_sort_algo(&stack_a, &stack_b, argc - 1);
		
	// ft_putendl_fd("\n####stack A####\n", 1);
	// ft_cer_dlstprint(stack_a);
	// ft_putendl_fd("\n####stack B####\n", 1);
	// ft_cer_dlstprint(stack_b);

	
	// ft_cer_dlstclear(&stack_a);
	// free(arr);
	// int arr[] = {10, 80, -30, 90, 40,-1, 50, -70};
	// ft_quick_sort(arr, 0, 7);
	
	// printf("\n###########\n");
	// for(int i = 0; i < argc - 1; i++)
	// 	printf("%d- %d\n", i, arr[i]);
	
	// ft_cer_dlstclear(&stack_b);
	return (0);
}
