/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:05:06 by plashkar          #+#    #+#             */
/*   Updated: 2023/08/16 16:29:07 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_init(t_stack_node **stack, int argc, char **argv)
{
	t_stack_node	*new;
	char			**args;
	int				i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_new_list(ft_atoi(args[i]));
		ft_list_addend(stack, new);
		i++;
	}
	index_stack(stack);
	if (argc == 2)
		ft_free_string(args);
}

//indexes the list from the smallest to the largest value on the init phase.
void	index_stack(t_stack_node **stack)
{
	int				index;
	t_stack_node	*curr;

	index = 0;
	curr = get_next_min(stack);
	while (curr)
	{
		curr->index = index++;
		curr = get_next_min(stack);
	}
}

//find the node with the minimum value and return a pointer to it,
// int has_min is to keep it going in the very first step -
//- since we can not compare anything with NULL./
t_stack_node	*get_next_min(t_stack_node **stack)
{
	t_stack_node	*curr;
	t_stack_node	*min;
	int				has_min;

	has_min = 0;
	min = NULL;
	curr = *stack;
	if (curr)
	{
		while (curr)
		{
			if ((curr->index == -1) && (!has_min || curr->value < min->value))
			{
				has_min = 1;
				min = curr;
			}
			curr = curr->next;
		}
	}
	return (min);
}
