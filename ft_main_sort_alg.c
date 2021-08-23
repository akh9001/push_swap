/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_sort_alg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmaa-kh <asmaa-kh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 19:22:56 by asmaa-kh          #+#    #+#             */
/*   Updated: 2021/08/18 04:02:02 by asmaa-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_struct	ft_initize(t_cir_dlst **head, t_cir_dlst **stack_b, int size)
{
	t_struct	var;

	var.head = head;
	var.stack_b = stack_b;
	var.n = (size - 5) / 4;
	var.npush = var.n + 1;
	var.min = ft_id_min_circulary_dlst(head);
	var.max = var.min + var.n;
	var.tmp = *head;
	var.tail = (*head)->prev;
	return (var);
}

void	ft_sorting_function(t_cir_dlst **head, t_cir_dlst **stack_b, int size)
{
	t_struct	var;

	var = ft_initize(head, stack_b, size);
	if (var.tmp->id >= var.min && var.tmp->id <= var.max)
	{
		ft_pb(var.head, var.stack_b);
		var.tmp = *var.head;
		var.tail = (*var.head)->prev;
		var.npush--;
	}	
	else if (var.tail->id >= var.min && var.tail->id <= var.max)
	{
		ft_rra(var.head);
		ft_pb(var.head, var.stack_b);
		var.tmp = *var.head;
		var.tail = (*var.head)->prev;
		var.npush--;
	}
	else
	{
		var.tmp = var.tmp->next;
		var.tail = var.tail->prev; 
	}
	while (var.npush)
	{
		// printf("Heey %d\n", var.npush);
		if (var.tmp->id >= var.min && var.tmp->id <= var.max)
		{
			while (*(var.head) != var.tmp)
				ft_ra(var.head);
			ft_pb(var.head, var.stack_b);
			var.tmp = *var.head;
			var.tail = (*var.head)->prev;
			var.npush--;
			continue ;
		}
		else if (var.tail->id >= var.min && var.tail->id <= var.max)
		{
			while (*(var.head) != var.tail)
				ft_rra(var.head);
			ft_pb(var.head, var.stack_b);
			var.tmp = *var.head;
			var.tail = (*var.head)->prev;
			var.npush--;
			continue ;
		}
		var.tmp = var.tmp->next;
		var.tail = var.tail->prev;
		// var.npush--;
	}
}

void	ft_push_back_right_num(t_cir_dlst **stack_a, t_cir_dlst **stack_b, int num)
{
	t_cir_dlst	*head;
	t_cir_dlst	*tail;

	if (num == 0)
	{
		if ((*stack_a)->prev->id == num)
			ft_rra(stack_a);
		else	
			ft_pa(stack_a, stack_b);
		return ;
	}
	if ((*stack_a)->prev->id == num)
		ft_rra(stack_a);
	else
	{
		head = *stack_b;
		tail = head->prev;
		while (head->id != num && tail->id != num)
		{
			if (head->id < (*stack_a)->prev->id)
			{
				ft_pa(stack_a, stack_b);
				ft_ra(stack_a);	
				head = *stack_b;
				tail = head->prev;
				continue ;
			}
			head = head->next;
			tail = tail->prev;
		}
		if (head->id == num)
		{
			while (num != (*stack_b)->id)
			{
				// head = head->next;
				ft_rb(stack_b);
			}
		}
		else if (tail->id == num)
		{
			while (num != (*stack_b)->id)
			{
				// tail = tail->prev;
				ft_rrb(stack_b);
			}
		}
		else
			printf("chi prob tra ash3aybia!\n");
		ft_pa(stack_a, stack_b);
	}
	ft_push_back_right_num(stack_a, stack_b, num - 1);
}

// void	ft_push_back(t_cir_dlst **head, t_cir_dlst **stack_b)
// {
// 	t_cir_dlst	*ptr_a;
// 	t_cir_dlst	*ptr_b;
// 	int			var;

// 	ptr_a = *head;
// 	ptr_b = *stack_b;
// 	ptr_a->prev->id = -1;
// 	var = ptr_a->id - 1;
// 	while (var > 0)
// 	{
// 		if ()
// 	}
// }

void	ft_launch_sort_algo(t_cir_dlst **head, t_cir_dlst **stack_b, int size)
{
	while (size > 5)
	{
		ft_sorting_function(head, stack_b, size);
		// sleep(4);
		// ft_cer_dlstprint(*head);
		// printf("Heey %d\n", size);
		// ft_cer_dlstprint(*stack_b);
		size = ft_cer_dlst_size(*head);
	}
	ft_sort_five_elt(head, stack_b);
	(*head)->prev->id = -1;
	ft_push_back_right_num(head, stack_b, (*head)->id - 1);
	// ft_putstr_fd("Stack A\n", 1);
	// ft_cer_dlstprint(*head);
	// ft_putstr_fd("Stack B\n", 1);
	// ft_cer_dlstprint(*stack_b);
}
