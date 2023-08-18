/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:39:34 by plashkar          #+#    #+#             */
/*   Updated: 2023/08/16 14:47:14 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack_node *root)
{
	int	temp_val;
	int	temp_index;

	if (root != NULL && root->next != NULL)
	{
		temp_val = root->value;
		temp_index = root->index;
		root->value = root->next->value;
		root->next->value = temp_val;
		root->index = root->next->index;
		root->next->index = temp_index;
	}
}

void	sa(t_stack_node *tail_a)
{
	swap(tail_a);
	ft_printf("sa\n");
}

void	sb(t_stack_node *tail_b)
{
	swap(tail_b);
	ft_printf("sb\n");
}

void	ss(t_stack_node *tail_a, t_stack_node *tail_b)
{
	swap(tail_a);
	swap(tail_b);
	ft_printf("ss\n");
}
