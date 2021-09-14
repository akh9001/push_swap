/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_correpted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:48:38 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/14 16:48:57 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_num_in_tail_of_stack_a(t_cir_dlst **stack_a, t_cir_dlst **stack_b, int num)
{
	t_cir_dlst	*tail;
	
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

void	ft_pa_the_next_num(t_cir_dlst **stack_a, t_cir_dlst **stack_b, int num)
{
	t_cir_dlst	*head;
	t_cir_dlst	*tail;
	int			mid_size;

	ft_pa(stack_a, stack_b);
	mid_size = ft_cer_dlst_size(*stack_b) / 2;
	if (ft_get_next_num_pos_satck_b(*stack_b, num) <= mid_size)
		ft_rr(stack_a, stack_b);
	else
		ft_ra(stack_a);	
	head = *stack_b;
	tail = head->prev;
}

int	ft_stop_recursion_and_pa(t_cir_dlst **stack_a, t_cir_dlst **stack_b, int num)
{
	if (num == 0)
	{
		if ((*stack_a)->prev->id == num)
			ft_rra(stack_a);
		else	
			ft_pa(stack_a, stack_b);
		return (0);
	}
	return (18);
}

void	ft_search_for_num_stack_b(t_cir_dlst *head, t_cir_dlst *tail, t_cir_dlst **stack_b, int num)
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
		printf("chi prob tra ash3aybia!\n");
}

void	ft_push_back_right_num(t_cir_dlst **stack_a, t_cir_dlst **stack_b, int num)
{
	t_cir_dlst	*head;
	t_cir_dlst	*tail;

	if (!ft_stop_recursion_and_pa(stack_a, stack_b, num))
		return ;
	if (!ft_num_in_tail_of_stack_a(stack_a, stack_b, num))
	{
		head = *stack_b;
		tail = head->prev;
		while (head->id != num && tail->id != num)
		{
			if (head->id == num -1)
			{
				ft_pa_the_next_num(stack_a, stack_b, num);
				continue ;
			}
			head = head->next;
			tail = tail->prev;
		}
		ft_search_for_num_stack_b(head, tail, stack_b, num);
		ft_pa(stack_a, stack_b);
	}
	ft_push_back_right_num(stack_a, stack_b, num - 1);
}

void	ft_launch_sort_algo(t_cir_dlst **head, t_cir_dlst **stack_b, int size)
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
