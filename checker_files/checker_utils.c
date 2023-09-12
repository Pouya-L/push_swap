/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:15:28 by plashkar          #+#    #+#             */
/*   Updated: 2023/09/12 11:03:54 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ok_or_ko(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (is_sorted(stack_a) && !(*stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

// int	ft_strcmp(char *str_1, char *str_2)
// {
// 	while (*str_1 == *str_2 && *str_1)
// 	{
// 		++str_1;
// 		++str_2;
// 	}
// 	return (*str_1 - *str_2);
// }

void	ft_error_checker(t_stack_node **stack_a, t_stack_node **stack_b)
{
	free_list(stack_a);
	free_list(stack_b);
	ft_printf("Error\n");
	exit (1);
}

void	parsing(t_stack_node **stack_a, t_stack_node **stack_b, \
		char *command_to_run)
{
	if (!ft_strcmp(command_to_run, "pa\n"))
		pa_c(stack_a, stack_b);
	else if (!ft_strcmp(command_to_run, "pb\n"))
		pb_c(stack_a, stack_b);
	else if (!ft_strcmp(command_to_run, "sa\n"))
		sa_c(*stack_a);
	else if (!ft_strcmp(command_to_run, "sb\n"))
		sb_c(*stack_b);
	else if (!ft_strcmp(command_to_run, "ss\n"))
		ss_c(*stack_a, *stack_b);
	else if (!ft_strcmp(command_to_run, "ra\n"))
		ra_c(stack_a);
	else if (!ft_strcmp(command_to_run, "rb\n"))
		rb_c(stack_b);
	else if (!ft_strcmp(command_to_run, "rr\n"))
		rr_c(stack_a, stack_b);
	else if (!ft_strcmp(command_to_run, "rra\n"))
		rra_c(stack_a);
	else if (!ft_strcmp(command_to_run, "rrb\n"))
		rrb_c(stack_b);
	else if (!ft_strcmp(command_to_run, "rrr\n"))
		rrr_c(stack_a, stack_b);
	else
		ft_error_checker(stack_a, stack_b);
}
