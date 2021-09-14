/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 20:19:00 by asmaa-kh          #+#    #+#             */
/*   Updated: 2021/09/14 18:52:16 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_partion(int arr[], int low, int high)
{
	int	i;
	int	j;
	int	pivot;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			ft_swap_int(arr + i, arr + j);
		}
		j++;
	}
	ft_swap_int(arr + i + 1, arr + high);
	return (i + 1);
}

void	ft_quick_sort(int arr[], int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = ft_partion(arr, low, high);
		ft_quick_sort(arr, low, pi - 1);
		ft_quick_sort(arr, pi + 1, high);
	}
}
