/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:35:21 by plashkar          #+#    #+#             */
/*   Updated: 2023/08/31 17:09:07 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_target(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*og_stack_a;

	og_stack_a = stack_a;
	while (stack_b)
	{
		stack_a = og_stack_a;
		while(stack_a)
		{
			if (stack_b->index > (ft_get_biggest(stack_a))->index)
			{
				stack_b->target = ft_get_smallest(stack_a);
				break ;
			}
			if (stack_a->index == (stack_b->index)+1)
			{
				stack_b->target = stack_a;
				break ;
			}
			stack_a = stack_a->next;
		}
		stack_b = stack_b->next;
	}
}
