/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:52:35 by plashkar          #+#    #+#             */
/*   Updated: 2023/08/16 16:07:29 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Counts the number of elements in the list and returns is as an int.
int	ft_count_nodes(t_stack_node *root)
{
	t_stack_node	*curr;
	int				i;

	i = 0;
	curr = root;
	while (curr != NULL)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}

//Returns the last node of the list
t_stack_node	*ft_find_last_node(t_stack_node *root)
{
	t_stack_node	*curr;

	curr = root;
	while (curr != NULL && curr->next != NULL)
		curr = curr->next;
	return (curr);
}

//Creats a new node and returns a pointer to it.
t_stack_node	*ft_new_list(int value)
{
	t_stack_node	*new_list;

	new_list = malloc(sizeof(t_stack_node));
	if (new_list == NULL)
		return (NULL);
	new_list->value = value;
	new_list->index = -1;
	new_list->next = NULL;
	return (new_list);
}

//Adds a new node to the top of the stack.
void	ft_list_addfront(t_stack_node **stack, t_stack_node *new_node)
{
	new_node->next = *stack;
	*stack = new_node;
}

//Adds a new node to the bottom of the stack.
void	ft_list_addend(t_stack_node **stack, t_stack_node *new_node)
{
	t_stack_node	*last_node;

	last_node = NULL;
	if (*stack)
	{
		last_node = ft_find_last_node(*stack);
		last_node->next = new_node;
		new_node->next = NULL;
	}
	else
	{
		*stack = new_node;
		(*stack)->next = NULL;
	}
}
