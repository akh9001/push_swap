/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmaa-kh <asmaa-kh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 13:41:54 by akhalidy          #+#    #+#             */
/*   Updated: 2021/08/10 01:27:45 by asmaa-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_struct
{
	t_cir_dlst	**head;
	t_cir_dlst	**stack_b;
	t_cir_dlst	*tmp;
	t_cir_dlst	*tail;
	int			min;
	int			max;
}				t_struct;


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
void	ft_ra(t_cir_dlst **stack);
void	ft_rb(t_cir_dlst **stack);
void	ft_rra(t_cir_dlst **stack);
void	ft_rrb(t_cir_dlst **stack);
int		*ft_fill_stack(int argc, char **argv, t_cir_dlst **a, t_cir_dlst **b);
int		ft_check_dup_num(t_cir_dlst *stack, int num);
void	ft_exit(t_cir_dlst **stack_a, int **arr);
int		ft_max_circulary_dlst(t_cir_dlst **head);
void	ft_sort_three_elt(t_cir_dlst **head);
void	ft_sort_five_elt(t_cir_dlst **head, t_cir_dlst **stack_b);
int		ft_min_circulary_dlst(t_cir_dlst **head);
int		ft_is_sorted(t_cir_dlst *head);
void	ft_quick_sort(int arr[], int low, int high);

#endif