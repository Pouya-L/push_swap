/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:22:01 by plashkar          #+#    #+#             */
/*   Updated: 2023/09/11 16:38:56 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra_c(t_stack_node **stack_a)
{
	reverse_rotate(stack_a);
}

void	rrb_c(t_stack_node **stack_b)
{
	reverse_rotate(stack_b);
}

void	rrr_c(t_stack_node **stack_a, t_stack_node **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
