/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_sort_alg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 19:22:56 by asmaa-kh          #+#    #+#             */
/*   Updated: 2021/09/12 19:27:13 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_struct	ft_initize(t_cir_dlst **head, t_cir_dlst **stack_b, int size)
{
	t_struct	var;

	var.head = head;
	var.stack_b = stack_b;
	if (size > 100)
		var.n = (size) / 5;
	else
		var.n = (size) / 3;
	var.npush = var.n + 1;
	var.min = ft_id_min_circulary_dlst(head);
	var.max = var.min + var.n;
	var.mid = (var.min + var.max) / 2;
	var.tmp = *head;
	var.tail = (*head)->prev;
	return (var);
}

int	ft_get_next_num_pos(t_cir_dlst *head, int max, int min)
{
	t_cir_dlst	*tmp;
	int			i;

	tmp = head;
	i = 0;
	while (tmp->id < min || tmp->id > max)
	{
		// printf("id %d, max %d, min %d\n", tmp->id, max, min);
		tmp = tmp->next;
		i++;
	}
	// ft_putnbr_fd(i, 1); 
	return (i);
}

int	ft_get_next_num_pos_satck_b(t_cir_dlst *head, int num)
{
	t_cir_dlst	*tmp;
	int			i;

	tmp = head;
	i = 0;
	while (tmp->id < min || tmp->id > max)
	{
		// printf("id %d, max %d, min %d\n", tmp->id, max, min);
		tmp = tmp->next;
		i++;
	}
	// ft_putnbr_fd(i, 1); 
	return (i);
}

int	ft_get_next_num_pos_cpy(t_struct var, int size)
{
	t_cir_dlst	*tmp;
	int			i;

	tmp = *(var.head);
	i = 0;
	if (!(var.npush - 1))
		var = ft_initize(var.head, var.stack_b, size);
	while (tmp->id < var.min || tmp->id > var.max)
	{
		// printf("id %d, max %d, min %d\n", tmp->id, max, min);
		tmp = tmp->next;
		i++;
	}
	// ft_putnbr_fd(i, 1); 
	return (i);
}


// void	ft_mid_chunk(t_struct var, t_pair *pair, int size_stack)
// {
// 	int	i;
// 	int	stp;
	
// 	i = 1;
// 	stp = size_stack / 2;
// 	pair->x = 0;
// 	pair->y = 0;
// 	var.tmp = (*var.head)->next;
// 	if (var.tmp->id >= var.min && var.tmp->id <= var.mid)
// 		pair->x++;
// 	while (i < stp)
// 	{
// 		if (var.tmp->id >= var.min && var.tmp->id <= var.max)
// 			pair->x++;
// 		var.tmp = var.tmp->next;
// 		i++;
// 	}
// 	pair->y = var.npush - pair->x;
// }

// int		ft_in_range(t_struct var)
// {
// 	if (var)
// }


void	ft_push_head_stack(t_struct *var, int size)
{
	if (var->tmp->id >= var->min && var->tmp->id <= var->max)
	{                                                                                         
		ft_pb(var->head, var->stack_b);
		if (((*(var->stack_b))->next != *(var->stack_b)) && ((*(var->stack_b))->id < var->mid))
		{
			if (ft_get_next_num_pos_cpy(*var, size - var->npush - 1) <= ((size - var->npush - 1) / 2))
			// if ((var->npush - 1) && ft_get_next_num_pos(*(var->head), var->max, var->min) <= ((size - var->npush - 1) / 2))
				ft_rr(var->head, var->stack_b);
			else
				ft_rb(var->stack_b);
		}
		var->tmp = *(var->head);
		var->tail = (*(var->head))->prev;
		var->npush--;
	}
	else if (var->tail->id >= var->min && var->tail->id <= var->max)
	{
		ft_rra(var->head);
		ft_pb(var->head, var->stack_b);
		if (((*(var->stack_b))->next != *(var->stack_b)) && ((*(var->stack_b))->id < var->mid))
		{
			if (ft_get_next_num_pos_cpy(*var, size - var->npush - 1) <= ((size - var->npush - 1) / 2))
			// if ((var->npush - 1) && ft_get_next_num_pos(*(var->head), var->max, var->min) < ((size - var->npush - 1) / 2))
				ft_rr(var->head, var->stack_b);
			else
				ft_rb(var->stack_b);
		}
		var->tmp = *(var->head);
		var->tail = (*(var->head))->prev;
		var->npush--;
	}
	else
	{
		var->tmp = var->tmp->next;
		var->tail = var->tail->prev; 
	}
}

void	ft_sorting_function(t_cir_dlst **head, t_cir_dlst **stack_b, int size)
{
	t_struct	var;
	// t_pair		pair;
	// int			tmp;

	var = ft_initize(head, stack_b, size);
	// ft_mid_chunk(var, &pair, size);
	// if (pair.x > pair.y)
	// {
	// 	var.min
		ft_push_head_stack(&var, size);
	// }
	while (var.npush)
	{
		if (var.tmp->id >= var.min && var.tmp->id <= var.max)
		{
			while (*(var.head) != var.tmp)
				ft_ra(var.head);
			ft_pb(var.head, var.stack_b);
			if (((*var.stack_b)->next != *var.stack_b) && ((*var.stack_b)->id < var.mid))
			{
				if (ft_get_next_num_pos_cpy(var, size - var.npush - 1) <= ((size - var.npush - 1) / 2))
				// if ((var.npush - 1) && ft_get_next_num_pos(*head, var.max, var.min) < ((size - var.npush - 1) / 2))
					ft_rr(var.head, var.stack_b);
				else
				ft_rb(var.stack_b);
			}
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
			if (((*var.stack_b)->next != *var.stack_b) && ((*var.stack_b)->id < var.mid))
			{
				if (ft_get_next_num_pos_cpy(var, size - var.npush - 1) <= ((size - var.npush - 1) / 2))
				// if ((var.npush - 1) && ft_get_next_num_pos(*head, var.max, var.min) < ((size - var.npush - 1) / 2))
					ft_rr(var.head, var.stack_b);
				else
				ft_rb(var.stack_b);
			}
			var.tmp = *var.head;
			var.tail = (*var.head)->prev;
			var.npush--;
			continue ;
		}
		var.tmp = var.tmp->next;
		var.tail = var.tail->prev;
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
				//t9adri fhad la9ta t5admi bi rr
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
				ft_rb(stack_b);
		}
		else if (tail->id == num)
		{
			while (num != (*stack_b)->id)
				ft_rrb(stack_b);
		}
		else
			printf("chi prob tra ash3aybia!\n");
		ft_pa(stack_a, stack_b);
	}
	ft_push_back_right_num(stack_a, stack_b, num - 1);
}

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
