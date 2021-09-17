/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_outils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 13:35:06 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/17 11:09:04 by akhalidy         ###   ########.fr       */
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
