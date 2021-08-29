/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 16:14:36 by akhalidy          #+#    #+#             */
/*   Updated: 2021/08/29 16:09:28 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_num_index(int *arr, int num, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == num)
			return (i);
		i++;
	}
	return (i);
}

void	ft_index_list(int *arr, int argc, t_cir_dlst *head)
{
	t_cir_dlst	*tmp;

	tmp = head->next;
	ft_quick_sort(arr, 0, argc - 2);
	head->id = ft_find_num_index(arr, head->data, argc - 1);
	while (tmp != head)
	{
		tmp->id = ft_find_num_index(arr, tmp->data, argc - 1);
		tmp = tmp->next;
	}
}
// jma3t les deux conditions fi if wa7da, i didn tested yet!!
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
		if (!ft_check_int_range(argv[i], &num) && !ft_check_dup_num(*a, num))
		{
			ft_cer_dlstadd_back(a, ft_cer_dlstnew(num, 0));
			arr[i -1] = num;
		}
		else
			ft_exit(a, &arr);
	}
	ft_index_list(arr, argc, *a);
	return (arr);
}
