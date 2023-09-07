/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:27:06 by plashkar          #+#    #+#             */
/*   Updated: 2023/09/07 21:48:31 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//gets the distance of the node from the node with the minmum value
int	distance_from_min(t_stack_node **stack, int index)
{
	t_stack_node	*curr;
	int				distance;

	distance = 0;
	curr = *stack;
	while (curr)
	{
		if (curr->index == index)
			break ;
		distance++;
		curr = curr->next;
	}
	return (distance);
}

int	distance_from_max(t_stack_node **stack)
{
	t_stack_node	*curr;
	t_stack_node	*highest_value_node;
	int				distance;

	distance = 0;
	curr = *stack;
	while (curr)
	{
		if (curr->index == (int)ft_count_nodes(*stack))
			break ;
		curr = curr->next;
	}
	highest_value_node = curr;
	curr = *stack;
	while (curr)
	{
		if (curr->index == highest_value_node->index)
			break ;
		distance++;
		curr = curr->next;
	}
	return (distance);
}

//this function is used to find the smallest node, and if we run it again -
//we can find the second smallest value, but that's it.
int	get_min_top_two(t_stack_node **stack, int previous_min)
{
	t_stack_node	*curr;
	int				min;

	curr = *stack;
	min = curr->index;
	while (curr->next)
	{
		curr = curr->next;
		if ((curr->index < min) && curr->index != previous_min)
			min = curr->index;
	}
	return (min);
}

t_stack_node	*ft_get_biggest(t_stack_node *stack)
{
	t_stack_node	*biggest;

	biggest = stack;
	while (stack && stack->next)
	{
		if (stack->next->value > biggest->value)
			biggest = stack->next;
		stack = stack->next;
	}
	return (biggest);
}

t_stack_node	*ft_get_smallest(t_stack_node *stack)
{
	t_stack_node	*smallest;

	smallest = stack;
	while (stack && stack->next)
	{
		if (stack->next->value < smallest->value)
			smallest = stack->next;
		stack = stack->next;
	}
	return (smallest);
}
