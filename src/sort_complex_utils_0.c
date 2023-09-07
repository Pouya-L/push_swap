/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_utils_0.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:35:21 by plashkar          #+#    #+#             */
/*   Updated: 2023/09/05 17:03:45 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		while(stack_a_curr)
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

void	ft_total_cost(t_stack_node *stack_b)
{
	size_t	upup;
	size_t	downdown;
	size_t	updown;
	size_t	downup;

	while (stack_b)
	{
		 





		stack_b = stack_b->next;
	}
}
