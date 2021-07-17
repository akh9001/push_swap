/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 16:54:04 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/17 20:30:29 by akhalidy         ###   ########.fr       */
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

void	ft_exit(t_cir_dlst **stack_a)
{
	ft_putendl_fd("ERROR", 2);
	ft_cer_dlstclear(stack_a);
	exit(1);
}
