/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:05:45 by plashkar          #+#    #+#             */
/*   Updated: 2023/08/16 14:47:10 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	t_stack_node	*new_root;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		last_node = ft_find_last_node(*stack);
		new_root = (*stack)->next;
		(*stack)->next = NULL;
		last_node->next = *stack;
		*stack = new_root;
	}
}

void	ra(t_stack_node **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_stack_node **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("ra\n");
}
