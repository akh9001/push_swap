/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_sort_alg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 19:22:56 by asmaa-kh          #+#    #+#             */
/*   Updated: 2021/09/13 19:29:36 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_struct	ft_initize(t_cir_dlst **head, t_cir_dlst **stack_b, int size)
{
	t_struct	var;

	var.head = head;
	var.stack_b = stack_b;
	if (size > 200)
		var.n = (size - 5) / 6;
	else if (size > 100)
		var.n = (size - 5) / 4;
	else
		var.n = (size - 5) / 3;
	var.npush = var.n + 1;
	var.min = ft_id_min_circulary_dlst(head);
	var.max = var.min + var.n;
	var.mid = (var.min + var.max) / 2;
	var.tmp = *head;
	var.tail = (*head)->prev;
	return (var);
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
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_sorting_fct_head_hlp(t_struct *var, int size)
{
	t_cir_dlst	*tmp;
	int			mid_size;	
	
	while (*(var->head) != var->tmp)
		ft_ra(var->head);
	ft_pb(var->head, var->stack_b);
	mid_size = (size - var->npush - 1) / 2;
	tmp = *(var->stack_b);
	if ((tmp->next != tmp) && (tmp->id < var->mid))
	{
		if (ft_get_next_num_pos_cpy(*var, size - var->npush - 1) <= mid_size)
			ft_rr(var->head, var->stack_b);
		else
		ft_rb(var->stack_b);
	}
	var->tmp = *(var->head);
	var->tail = (*(var->head))->prev;
	var->npush--;
}

void	ft_sorting_fct_tail_hlp(t_struct *var, int size)
{
	t_cir_dlst	*tmp;
	int			mid_size;	
	
	while (*(var->head) != var->tail)
		ft_rra(var->head);
	ft_pb(var->head, var->stack_b);
	mid_size = (size - var->npush - 1) / 2;
	tmp = *(var->stack_b);	
	if ((tmp->next != tmp) && (tmp->id < var->mid))
	{
		if (ft_get_next_num_pos_cpy(*var, size - var->npush - 1) <= mid_size)
			ft_rr(var->head, var->stack_b);
		else
		ft_rb(var->stack_b);
	}
	var->tmp = *(var->head);
	var->tail = (*(var->head))->prev;
	var->npush--;
}

void	ft_sorting_function(t_cir_dlst **head, t_cir_dlst **stack_b, int size)
{
	t_struct	var;

	var = ft_initize(head, stack_b, size);
	ft_push_head_stack(&var, size);
	while (var.npush)
	{
		if (var.tmp->id >= var.min && var.tmp->id <= var.max)
		{
			ft_sorting_fct_head_hlp(&var, size);
			continue ;
		}
		else if (var.tail->id >= var.min && var.tail->id <= var.max)
		{
			ft_sorting_fct_tail_hlp(&var, size);
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
	{
		if (ft_get_next_num_pos_satck_b(*stack_b, num - 1) >= (ft_cer_dlst_size(*stack_b) / 2))
			ft_rrr(stack_a, stack_b);
		else
			ft_rra(stack_a);
	}
	else
	{
		head = *stack_b;
		tail = head->prev;
		// printf("stack A \n");
		// ft_cer_dlstprint(*stack_a);
		// printf("stack B \n");
		// ft_cer_dlstprint(*stack_b);
		while (head->id != num && tail->id != num)
		{
			// printf("num = %d, stack A tail num = %d\n", num, (*stack_a)->prev->id);
			if ((((*stack_a)->prev->id == -1) || (head->id < (*stack_a)->prev->id)) && (head->id > num))
			{
				// printf("heeeeyyy %d\n", (*stack_a)->prev->id);
				ft_pa(stack_a, stack_b);
				if (ft_get_next_num_pos_satck_b(*stack_b, num) <= (ft_cer_dlst_size(*stack_b) / 2))
					ft_rr(stack_a, stack_b);
				else
					ft_ra(stack_a);	
				head = *stack_b;
				tail = head->prev;
				// sleep(5);
				continue ;
			}
			// sleep(1);
			// printf("size of tack B %d\n", ft_cer_dlst_size(*stack_b));
			head = head->next;
			tail = tail->prev;
		}
		// printf("fhjgjffghjhgkfhldaghrldjglkjksftghkgtjhskdjhiusdugj");
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
		size = ft_cer_dlst_size(*head);
	}
	ft_sort_five_elt(head, stack_b);
	(*head)->prev->id = -1;
	ft_push_back_right_num(head, stack_b, (*head)->id - 1);
}
