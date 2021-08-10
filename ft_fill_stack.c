/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmaa-kh <asmaa-kh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 19:12:02 by akhalidy          #+#    #+#             */
/*   Updated: 2021/08/10 01:36:54 by asmaa-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_fill_stack(int argc, char **argv, t_cir_dlst **a, t_cir_dlst **b)
{
	int	i;
	int	num;
	int	*arr;
	
	i = 0;
	*a = NULL;
	*b = NULL;
	arr = (int *)malloc((argc - 1) * sizeof(int));
	while (++i < argc)
	{
		if (!ft_check_int_range(argv[i], &num))
		{
			if (!ft_check_dup_num(*a, num))
			{
				ft_cer_dlstadd_back(a, ft_cer_dlstnew(num, 0));
				arr[i -1] = num;
			}
			else
				ft_exit(a, &arr);
		}
		else
			ft_exit(a, &arr);
	}
	ft_quick_sort(arr, 0, argc - 2);
	return (arr);
}