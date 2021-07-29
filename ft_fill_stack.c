/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 19:12:02 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/28 15:31:24 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_stack(int argc, char **argv, t_cir_dlst **a, t_cir_dlst **b)
{
	int	i;
	int	num;
	
	i = 0;
	*a = NULL;
	*b = NULL;
	while (++i < argc)
	{
		if (!ft_check_int_range(argv[i], &num))
		{
			if (!ft_check_dup_num(*a, num))
			{
				ft_cer_dlstadd_back(a, ft_cer_dlstnew(num, 0));
			}
			else
				ft_exit(a);
		}
		else
			ft_exit(a);
	}
}