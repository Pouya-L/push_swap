/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:07:04 by plashkar          #+#    #+#             */
/*   Updated: 2023/09/12 11:39:55 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Checks the command to run of the cheapest node to top, runs the respective ft
void	top(t_stack_node **stack_a, t_stack_node **stack_b, t_stack_node *cheap)
{
	if (cheap->command_to_run == UPUP)
		rtop(stack_a, stack_b, cheap);
	if (cheap->command_to_run == DOWNDOWN)
		rrtop(stack_a, stack_b, cheap);
	if (cheap->command_to_run == UPDOWN)
		updown(stack_a, stack_b, cheap);
	if (cheap->command_to_run == DOWNUP)
		downup(stack_a, stack_b, cheap);
}

//UPUP; brings cheapest and its target to the top by rotating them up
//using rotate functions (ra, rb or rr)
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

//DOWNDOWN; brings cheapest and its target to the top by rotating them down
//using reverse rotate functions (rra, rrb or rr)
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

//Brings the cheapest and its target to the top by moving them down and up each
//uses ra to move the node in stack a to the top
//and uses rrb to move the node in stack b to the top
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

//Brings the cheapest and its target to the top by moving them up and down each
//uses rra to move the node in stack a to the top
//and uses rb to move the node in stack b to the top
void	downup(t_stack_node **stk_a, t_stack_node **stk_b, t_stack_node *cheap)
{
	size_t	stack_a_downcost;
	size_t	stack_b_upcost;

	stack_a_downcost = cheap->target->down_cost;
	stack_b_upcost = cheap->up_cost;
	while (stack_a_downcost > 0)
	{
		rra(stk_a);
		stack_a_downcost--;
	}
	while (stack_b_upcost > 0)
	{
		rb(stk_b);
		stack_b_upcost--;
	}
}
