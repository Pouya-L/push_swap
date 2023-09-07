/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:09:21 by plashkar          #+#    #+#             */
/*   Updated: 2023/09/07 21:41:10 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Checks to see if the list is sorted
int	is_sorted(t_stack_node **stack)
{
	t_stack_node	*curr;

	curr = *stack;
	while (curr && curr->next)
	{
		if (curr->next->value < curr->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	sort_stack(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (ft_count_nodes(*stack_a) > 5)
		complex_sort(stack_a, stack_b);
	else
		simple_sort(stack_a, stack_b);
}

//Frees the momory allocated to the list
void	free_list(t_stack_node **root)
{
	t_stack_node	*curr;
	t_stack_node	*aux;

	curr = *root;
	while (curr != NULL)
	{
		aux = curr;
		curr = curr->next;
		free(aux);
	}
	free(root);
}

void	print_stack(t_stack_node *root)
{
	t_stack_node	*curr;

	curr = root;
	while (curr)
	{
		ft_printf("%d\n", curr->value);
		curr = curr->next;
	}
}

//Free the memoery allocated to the string created by ft_split
void	ft_free_string(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}
