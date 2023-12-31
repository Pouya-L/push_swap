/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_utils_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:37:11 by plashkar          #+#    #+#             */
/*   Updated: 2023/09/12 11:43:17 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Resreshes the stacks and sets the correct info to the nodes.
//It MUST be run after any change in the order of the nodes in stacks
void	refresh_stacks(t_stack_node *stack_a, t_stack_node *stack_b)
{
	ft_set_position(stack_a);
	ft_set_position(stack_b);
	ft_cost(stack_a);
	ft_cost(stack_b);
	get_target(stack_a, stack_b);
	ft_total_cost(stack_b);
}

//Compares however many arguments you put in it and returns the biggest.
//args is the number of argumetns you want to compare
size_t	compare_big(size_t args, ...)
{
	va_list	variable_list;
	size_t	biggest;
	size_t	temp_compare;

	va_start(variable_list, args);
	biggest = va_arg(variable_list, size_t);
	while (--args > 0)
	{
		temp_compare = va_arg(variable_list, size_t);
		if (temp_compare > biggest)
			biggest = temp_compare;
	}
	return (biggest);
}

//Compares however many arguments you put in it and returns the smallest.
//args is the number of argumetns you want to compare
size_t	compare_small(size_t args, ...)
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
