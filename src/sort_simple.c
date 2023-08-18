/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:13:15 by plashkar          #+#    #+#             */
/*   Updated: 2023/08/16 21:15:22 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3(t_stack_node **stack)
{
	t_stack_node	*curr;
	int				min;
	int				next_min;

	curr = *stack;
	min = get_min_top_two(&curr, -1);
	next_min = get_min_top_two(&curr, min);
	if (is_sorted(stack))
		return ;
	if (curr->index == min && curr->next->index != next_min)
	{
		rra(stack);
		sa(*stack);
	}
	else if (curr->index == next_min)
	{
		if (curr->next->index == min)
			sa(*stack);
		else
			rra(stack);
	}
	else
	{
		if (curr->next->index == min)
			ra(stack);
		else
		{
			sa(*stack);
			rra(stack);
		}
	}
}

void	sort_4(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	distance;

	if (is_sorted(stack_a))
		return ;
	distance = distance_from_min(stack_a, get_min_top_two(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
		{
			ra(stack_a);
			ra(stack_a);
		}
	else if (distance == 3)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	distance;
	if (is_sorted(stack_a))
		return ;
	distance = distance_from_min(stack_a, get_min_top_two(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void			simple_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	size;

	if (is_sorted(stack_a) || ft_count_nodes(*stack_a) < 2)
		return ;
	size = ft_count_nodes(*stack_a);
	if (size == 2)
	{
		sa(*stack_a);
	}
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}
