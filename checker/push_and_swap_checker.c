/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swap_checker.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:17:15 by plashkar          #+#    #+#             */
/*   Updated: 2023/09/11 16:38:42 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa_c(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push(stack_a, stack_b);
}

void	pb_c(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push(stack_b, stack_a);
}

void	sa_c(t_stack_node *tail_a)
{
	swap(tail_a);
}

void	sb_c(t_stack_node *tail_b)
{
	swap(tail_b);
}

void	ss_c(t_stack_node *tail_a, t_stack_node *tail_b)
{
	swap(tail_a);
	swap(tail_b);
}
