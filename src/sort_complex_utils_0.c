/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_utils_0.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:35:21 by plashkar          #+#    #+#             */
/*   Updated: 2023/09/12 11:50:25 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Finds the smallest bigger element in the stack_a to help find the targets
void	ft_smallest_bigger(t_stack_node *stack_a_curr, t_stack_node *stack_b)
{
	while (stack_a_curr)
	{
		if (stack_a_curr->value < stack_b->target->value && \
			stack_a_curr->value > stack_b->value)
			stack_b->target = stack_a_curr;
		stack_a_curr = stack_a_curr->next;
	}
}

//Sets the target node in stack_a for each of the elements in stack_b
//we find the target so we can later send both the element and target
//to the top to sort the stack.
void	get_target(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*stack_a_curr;

	while (stack_b)
	{
		stack_a_curr = stack_a;
		stack_b->target = ft_get_smallest(stack_a);
		if (stack_b->target->value > stack_b->value)
		{
			stack_b = stack_b->next;
			continue ;
		}
		while (stack_a_curr)
		{
			if (stack_a_curr->value < stack_b->value)
				stack_a_curr = stack_a_curr->next;
			else
			{
				stack_b->target = stack_a_curr;
				stack_a_curr = stack_a_curr->next;
				ft_smallest_bigger(stack_a_curr, stack_b);
				break ;
			}
		}
		stack_b = stack_b->next;
	}
}

//Calculates the individual cost of bringing a node in stack_b to top
//it sets up_cost and down_cost
void	ft_cost(t_stack_node *stack)
{
	int	list_len;

	list_len = ft_count_nodes(stack);
	while (stack)
	{
		stack->up_cost = stack->position - 1;
		stack->down_cost = list_len - stack->position + 1;
		stack = stack->next;
	}
}

//Calculates the total cost of bringing node in stack_b and its target to top
//checks if cheaper to bring them to the top using rotate vs reverse rotate
void	ft_total_cost(t_stack_node *stack_b)
{
	size_t	unu;
	size_t	dnd;
	size_t	updown;
	size_t	downup;

	while (stack_b)
	{
		unu = compare_big(2, stack_b->target->up_cost, stack_b->up_cost);
		dnd = compare_big(2, stack_b->target->down_cost, stack_b->down_cost);
		updown = stack_b->target->up_cost + stack_b->down_cost;
		downup = stack_b->target->down_cost + stack_b->up_cost;
		stack_b->total_cost = compare_small(4, unu, dnd, updown, downup);
		if (stack_b->total_cost == unu)
			stack_b->command_to_run = UPUP;
		else if (stack_b->total_cost == dnd)
			stack_b->command_to_run = DOWNDOWN;
		else if (stack_b->total_cost == updown)
			stack_b->command_to_run = UPDOWN;
		else if (stack_b->total_cost == downup)
			stack_b->command_to_run = DOWNUP;
		stack_b = stack_b->next;
	}
}
