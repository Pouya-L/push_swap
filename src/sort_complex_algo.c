/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_algo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:59:00 by plashkar          #+#    #+#             */
/*   Updated: 2023/09/11 13:34:48 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	complex_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	size_t	i;

	i = ft_count_nodes(*stack_a);
	while (i > 3)
	{
		pb(stack_a, stack_b);
		i--;
	}
	sort_3(stack_a);
	refresh_stacks(*stack_a, *stack_b);
	while (*stack_b)
	{
		top(stack_a, stack_b, cheapest_to_top(*stack_b));
		pa (stack_a, stack_b);
		refresh_stacks(*stack_a, *stack_b);
	}
	final_sort_a(stack_a);
	print_stack(*stack_a);
}

t_stack_node	*cheapest_to_top(t_stack_node *stack_b)
{
	t_stack_node	*cheapest;

	cheapest = stack_b;
	while (stack_b)
	{
		if (stack_b->total_cost < cheapest->total_cost)
			cheapest = stack_b;
		stack_b = stack_b->next;
	}
	return (cheapest);
}

void	final_sort_a(t_stack_node **stack_a)
{
	t_stack_node	*smallest;
	size_t			smallest_pos;

	smallest = ft_get_smallest(*stack_a);
	smallest_pos = smallest->position;
	if (smallest_pos <= ft_count_nodes(*stack_a) / 2)
	{
		while (smallest_pos > 1)
		{
			ra(stack_a);
			smallest_pos--;
		}
	}
	else
	{
		while (smallest_pos <= ft_count_nodes(*stack_a))
		{
			rra(stack_a);
			smallest_pos++;
		}
	}
}

// void	final_sort_a(t_stack_node **stack_a)
// {
// 	t_stack_node	*smallest;

// 	smallest = ft_get_smallest(*stack_a);
// 	if (smallest->up_cost <= smallest->down_cost)
// 		while (smallest->up_cost-- > 0)
// 			ra(stack_a);
// 	else
// 		while(smallest->down_cost-- > 0)
// 			rra(stack_a);
// }
