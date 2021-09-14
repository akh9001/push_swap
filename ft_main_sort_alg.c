/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_sort_alg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 19:22:56 by asmaa-kh          #+#    #+#             */
/*   Updated: 2021/09/14 18:29:06 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_num_in_tail_of_stack_a(t_dcl **stack_a, t_dcl **stack_b, int num)
{
	t_dcl	*tail;

	tail = (*stack_a)->prev;
	while (tail->id != -1)
	{
		if (tail->id == num)
		{
			while (*stack_a != tail)
			{
				ft_rra(stack_a);
				if (*stack_a != tail)
					ft_pb(stack_a, stack_b);
			}
			return (1);
		}
		tail = tail->prev;
	}
	return (0);
}

t_dcl	*ft_num_stack_b(t_dcl **head, t_dcl **stack_a, t_dcl **stack_b, int num)
{
	t_dcl	*tail;
	int		mid_size;

	*head = *stack_b;
	tail = (*head)->prev;
	while ((*head)->id != num && tail->id != num)
	{
		if ((*head)->id == num - 1)
		{
			ft_pa(stack_a, stack_b);
			mid_size = ft_cer_dlst_size(*stack_b) / 2;
			if (ft_get_next_num_pos_satck_b(*stack_b, num) <= mid_size)
				ft_rr(stack_a, stack_b);
			else
				ft_ra(stack_a);
			*head = *stack_b;
			tail = (*head)->prev;
			continue ;
		}
		*head = (*head)->next;
		tail = tail->prev;
	}
	return (tail);
}

void	get_num_head_stack(t_dcl *head, t_dcl *tail, t_dcl **stack_b, int num)
{
	if (head->id == num)
	{
		while (num != (*stack_b)->id)
			ft_rb(stack_b);
	}
	else if (tail->id == num)
	{
		while (num != (*stack_b)->id)
			ft_rrb(stack_b);
	}
	else
		printf("Error!\n");
}

void	ft_push_back_right_num(t_dcl **stack_a, t_dcl **stack_b, int num)
{
	t_dcl	*head;
	t_dcl	*tail;

	if (num == 0)
	{
		if ((*stack_a)->prev->id == num)
			ft_rra(stack_a);
		else
			ft_pa(stack_a, stack_b);
		return ;
	}
	if (!ft_num_in_tail_of_stack_a(stack_a, stack_b, num))
	{
		tail = ft_num_stack_b(&head, stack_a, stack_b, num);
		get_num_head_stack(head, tail, stack_b, num);
		ft_pa(stack_a, stack_b);
	}
	ft_push_back_right_num(stack_a, stack_b, num - 1);
}

void	ft_launch_sort_algo(t_dcl **head, t_dcl **stack_b, int size)
{
	while (size > 5)
	{
		ft_sorting_function(head, stack_b, size);
		size = ft_cer_dlst_size(*head);
	}
	ft_sort_five_elt(head, stack_b);
	(*head)->prev->id = -1;
	ft_push_back_right_num(head, stack_b, (*head)->id - 1);
}
