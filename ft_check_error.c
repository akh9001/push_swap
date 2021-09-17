/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 16:14:12 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/17 19:31:17 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_dup_num(t_cir_dlst *stack, int num)
{
	t_cir_dlst	*tmp;

	if (!stack)
		return (0);
	tmp = stack;
	if (tmp->data == num)
		return (1);
	tmp = tmp->next;
	while (tmp != stack)
	{
		if (tmp->data == num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

// I should also free stack_b !!!
void	ft_exit(t_cir_dlst **stack_a, t_cir_dlst **stack_b, int **arr)
{
	ft_putendl_fd("ERROR", 2);
	ft_cer_dlstclear(stack_a);
	ft_cer_dlstclear(stack_b);
	free(*arr);
	exit(1);
}
