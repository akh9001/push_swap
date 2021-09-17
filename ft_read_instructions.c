/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:49:59 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/17 19:01:29 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit_checker(char **str, t_dcl **a, t_dcl **b)
{
	ft_putendl_fd("Error", 2);
	free(*str);
	ft_cer_dlstclear(a);
	ft_cer_dlstclear(b);
	exit (1);
}

void	ft_is_valid_instruction(char **str, t_dcl **a, t_dcl **b)
{
	if (!ft_strncmp(*str, "sa", 3))
		ft_sa_bonus(*a);
	else if (!ft_strncmp(*str, "sb", 3))
		ft_sb_bonus(*b);
	else if (!ft_strncmp(*str, "ss", 3))
		ft_ss_bonus(*a, *b);
	else if (!ft_strncmp(*str, "pa", 3))
		ft_pa_bonus(a, b);
	else if (!ft_strncmp(*str, "pb", 3))
		ft_pb_bonus(a, b);
	else if (!ft_strncmp(*str, "ra", 3))
		ft_ra_bonus(a);
	else if (!ft_strncmp(*str, "rb", 3))
		ft_rb_bonus(b);
	else if (!ft_strncmp(*str, "rr", 3))
		ft_rr_bonus(a, b);
	else if (!ft_strncmp(*str, "rra", 4))
		ft_rra_bonus(a);
	else if (!ft_strncmp(*str, "rrb", 4))
		ft_rrb_bonus(b);
	else if (!ft_strncmp(*str, "rrr", 4))
		ft_rrr_bonus(a, b);
	else
		ft_exit_checker(str, a, b);
}

void	ft_read_and_execute_instruction(t_dcl **a, t_dcl **b)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		ft_is_valid_instruction(&line, a, b);
		free(line);
	}
	if (*b || ft_is_sorted(*a))
		ft_putendl_fd("KO", 1);
	else
		ft_putendl_fd("OK", 1);
}
