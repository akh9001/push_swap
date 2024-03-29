/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 13:41:54 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/17 18:59:17 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef t_cir_dlst	t_dcl;
typedef struct s_struct
{
	t_cir_dlst	**head;
	t_cir_dlst	**stack_b;
	t_cir_dlst	*tmp;
	t_cir_dlst	*tail;
	int			min;
	int			mid;
	int			max;
	int			n;
	int			npush;
}				t_struct;

typedef struct s_pair
{
	int			x;
	int			y;
}				t_pair;

void	ft_swap(t_cir_dlst *stack);
void	ft_ss(t_cir_dlst *stack_a, t_cir_dlst *stack_b);
void	ft_push(t_cir_dlst **stack_a, t_cir_dlst **stack_b);
void	ft_rotate(t_cir_dlst **stack);
void	ft_rr(t_cir_dlst **stack_a, t_cir_dlst **stack_b);
void	ft_reverse(t_cir_dlst **stack);
void	ft_rrr(t_cir_dlst **stack_a, t_cir_dlst **stack_b);
void	ft_pa(t_cir_dlst **stack_dst, t_cir_dlst **stack_src);
void	ft_pb(t_cir_dlst **stack_dst, t_cir_dlst **stack_src);
void	ft_sa(t_cir_dlst *stack);
void	ft_sb(t_cir_dlst *stack);
void	ft_ra(t_cir_dlst **stack);
void	ft_rb(t_cir_dlst **stack);
void	ft_rra(t_cir_dlst **stack);
void	ft_rrb(t_cir_dlst **stack);
int		*ft_fill_stack(int argc, char **argv, t_cir_dlst **a, t_cir_dlst **b);
int		ft_check_dup_num(t_cir_dlst *stack, int num);
void	ft_exit(t_cir_dlst **stack_a, t_cir_dlst **stack_b, int **arr);
int		ft_max_circulary_dlst(t_cir_dlst **head);
void	ft_sort_three_elt(t_cir_dlst **head);
void	ft_sort_five_elt(t_cir_dlst **head, t_cir_dlst **stack_b);
int		ft_min_circulary_dlst(t_cir_dlst **head);
int		ft_is_sorted(t_cir_dlst *head);
void	ft_quick_sort(int arr[], int low, int high);
void	ft_launch_sort_algo(t_cir_dlst **head, t_cir_dlst **stack_b, int size);
int		ft_id_min_circulary_dlst(t_cir_dlst **head);
void	ft_pb_head_rb_elt_greater_than_mid(t_struct *var, int size);
void	ft_pb_tail_rb_elt_greater_than_mid(t_struct *var, int size);
int		ft_get_next_num_pos_cpy(t_struct var, int size);
int		ft_get_next_num_pos_satck_b(t_cir_dlst *head, int num);
void	ft_push_head_stack(t_struct *var, int size);
void	ft_sorting_function(t_cir_dlst **head, t_cir_dlst **stack_b, int size);

/*
**	Checker Functions
*/

void	ft_read_and_execute_instruction(t_dcl **a, t_dcl **b);
void	ft_rrr_bonus(t_cir_dlst **stack_a, t_cir_dlst **stack_b);
void	ft_rra_bonus(t_cir_dlst **stack);
void	ft_rrb_bonus(t_cir_dlst **stack);
void	ft_pa_bonus(t_cir_dlst **stack_dst, t_cir_dlst **stack_src);
void	ft_pb_bonus(t_cir_dlst **stack_dst, t_cir_dlst **stack_src);
void	ft_sa_bonus(t_cir_dlst *stack);
void	ft_sb_bonus(t_cir_dlst *stack);
void	ft_ra_bonus(t_cir_dlst **stack);
void	ft_rb_bonus(t_cir_dlst **stack);
void	ft_rr_bonus(t_cir_dlst **stack_a, t_cir_dlst **stack_b);
void	ft_ss_bonus(t_cir_dlst *stack_a, t_cir_dlst *stack_b);

#endif