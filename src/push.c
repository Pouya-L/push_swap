/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:04:36 by plashkar          #+#    #+#             */
/*   Updated: 2023/08/16 14:47:06 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*new_root_a;
	t_stack_node	*new_root_b;

	if (*stack_b == NULL)
		return ;
	new_root_a = *stack_b;
	new_root_b = (*stack_b)->next;
	if (*stack_a != NULL)
		new_root_a->next = *stack_a;
	else
		new_root_a->next = NULL;
	*stack_a = new_root_a;
	*stack_b = new_root_b;
}

void	pa(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	pb(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
}
