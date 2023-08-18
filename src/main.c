/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:56:45 by plashkar          #+#    #+#             */
/*   Updated: 2023/08/16 19:07:03 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	**stack_a;
	t_stack_node	**stack_b;

	if (argc < 2)
		return (-1);
	ft_check_args(argc, argv);
	stack_a = malloc(sizeof(t_stack_node));
	stack_b = malloc(sizeof(t_stack_node));
	*stack_a = NULL;
	*stack_b = NULL;
	stack_init(stack_a, argc, argv);
												print_stack(*stack_a);
												ft_printf("\n");
	if (is_sorted(stack_a))
	{
		free_list(stack_a);
		free_list(stack_b);
		return (0);
	}
	sort_stack(stack_a, stack_b);
												print_stack(*stack_a);
												ft_printf("\n");
	free_list(stack_a);
	free_list(stack_b);
	return (0);
}

// static void remove_extra_zero(t_stack_node **stack)
// {
// 	if (*stack && (*stack)->value == 0 && (*stack)->index == 0)
// 	{
// 		t_stack_node *old_head = *stack;
// 		*stack = (*stack)->next;
// 		free(old_head);
// 	}
// }

// int	main(int argc, char **argv)
// {
// 	t_stack_node	**stack_a;
// 	t_stack_node	**stack_b;

// 	if (argc < 2)
// 		return (-1);
// 	ft_check_args(argc, argv);
// 	stack_a = malloc(sizeof(t_stack_node));
// 	stack_b = malloc(sizeof(t_stack_node));
// 	*stack_a = NULL;
// 	*stack_b = NULL;
// 	stack_init(stack_a, argc, argv);

// //	remove_extra_zero(stack_a);
// 	print_stack(*stack_a);
// 	ft_printf("\n");

// 	////to check indexs////
// 	// t_stack_node	*curr;
// 	// curr = *stack_a;
// 	// while(curr)
// 	// {
// 	// 	ft_printf("%d\n", curr->index);
// 	// 	curr = curr->next;
// 	// }

// 	// if (is_sorted(stack_a))
// 	// {
// 	// 	free_stack(stack_a);
// 	// 	free_stack(stack_b);
// 	// 	return (0);
// 	// }
// 	// sort_stack(stack_a, stack_b);
// 	free_list(stack_a);
// 	free_list(stack_b);
// 	return (0);
// }
