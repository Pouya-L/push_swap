/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:07:04 by plashkar          #+#    #+#             */
/*   Updated: 2023/09/07 21:43:34 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	top(t_stack_node **stack_a, t_stack_node **stack_b, t_stack_node *cheap)
{
	if (cheap->command_to_run == UPUP)
		rtop(stack_a, stack_b, cheap);
	if (cheap->command_to_run == DOWNDOWN)
		rrtop(stack_a, stack_b, cheap);
	if (cheap->command_to_run == UPDOWN)
		updown(stack_a, stack_a, cheap);
	if (cheap->command_to_run == DOWNUP)
		downup(stack_a, stack_b, cheap);
}

void	rtop(t_stack_node **stk_a, t_stack_node **stk_b, t_stack_node *cheap)
{
	size_t	stack_a_upcost;
	size_t	stack_b_upcost;

	stack_a_upcost = cheap->target->up_cost;
	stack_b_upcost = cheap->up_cost;
	while (stack_a_upcost > 0 && stack_b_upcost > 0)
	{
		rr(stk_a, stk_b);
		stack_a_upcost--;
		stack_b_upcost--;
	}
	while (stack_a_upcost > 0)
	{
		ra(stk_a);
		stack_a_upcost--;
	}
	while (stack_b_upcost > 0)
	{
		rb(stk_b);
		stack_b_upcost--;
	}
}

void	rrtop(t_stack_node **stk_a, t_stack_node **stk_b, t_stack_node *cheap)
{
	size_t	stack_a_downcost;
	size_t	stack_b_downcost;

	stack_a_downcost = cheap->target->down_cost;
	stack_b_downcost = cheap->down_cost;
	while (stack_a_downcost > 0 && stack_b_downcost > 0)
	{
		rrr(stk_a, stk_b);
		stack_a_downcost--;
		stack_b_downcost--;
	}
	while (stack_a_downcost > 0)
	{
		rra(stk_a);
		stack_a_downcost--;
	}
	while (stack_b_downcost > 0)
	{
		rrb(stk_b);
		stack_b_downcost--;
	}
}

void	updown(t_stack_node **stk_a, t_stack_node **stk_b, t_stack_node *cheap)
{
	size_t	stack_a_upcost;
	size_t	stack_b_downcost;

	stack_a_upcost = cheap->target->up_cost;
	stack_b_downcost = cheap->down_cost;
	while (stack_a_upcost > 0)
	{
		ra(stk_a);
		stack_a_upcost--;
	}
	while (stack_b_downcost > 0)
	{
		rrb(stk_b);
		stack_b_downcost--;
	}
}

void	downup(t_stack_node **stk_a, t_stack_node **stk_b, t_stack_node *cheap)
{
	size_t	stack_a_downcost;
	size_t	stack_b_upcost;

	stack_a_downcost = cheap->target->down_cost;
	stack_b_upcost = cheap->up_cost;
	while (stack_a_downcost < 0)
	{
		ra(stk_a);
		stack_a_downcost--;
	}
	while (stack_b_upcost < 0)
	{
		rb(stk_b);
		stack_b_upcost--;
	}
}
