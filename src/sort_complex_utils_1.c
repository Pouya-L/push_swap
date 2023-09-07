/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_utils_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:37:11 by plashkar          #+#    #+#             */
/*   Updated: 2023/09/07 17:45:47 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	refresh_stacks(t_stack_node *stack_a, t_stack_node *stack_b)
{
	ft_set_position(stack_a);
	ft_set_position(stack_b);
	ft_cost(stack_a);
	ft_cost(stack_b);
	get_target(stack_a, stack_a);
	ft_total_cost(stack_b);
}

size_t	ft_compare_and_get_biggest(size_t args, ...)
{
	va_list	variable_list;
	size_t	biggest;
	size_t	temp_compare;

	va_start(variable_list, args);
	biggest = va_arg(variable_list, size_t);
	while(--args > 0)
	{
		temp_compare = va_arg(variable_list, size_t);
		if (temp_compare > biggest)
			biggest = temp_compare;
	}
	return (biggest);
}

size_t	ft_compare_and_get_smallest(size_t args, ...)
{
	va_list	variable_list;
	size_t	smallest;
	size_t	temp_compare;

	va_start(variable_list, args);
	smallest = va_arg(variable_list, size_t);
	while (--args > 0)
	{
		temp_compare = va_arg(variable_list, size_t);
		if (temp_compare < smallest)
			smallest = temp_compare;
	}
	return (smallest);
}
