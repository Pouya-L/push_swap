/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:56:45 by plashkar          #+#    #+#             */
/*   Updated: 2023/08/31 16:46:31 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
// 												print_stack(*stack_a);
// 												ft_printf("\n");
// 	if (is_sorted(stack_a))
// 	{
// 		free_list(stack_a);
// 		free_list(stack_b);
// 		return (0);
// 	}
// 	sort_stack(stack_a, stack_b);
// 												ft_printf("stack a\n");
// 												print_stack(*stack_a);
// 												ft_printf("stack b\n");
// 												print_stack(*stack_b);
// 												// t_stack_node	*curr;

// 												// curr = *stack_b;
// 												// ft_printf("stack b's targets values\n");
// 												// while (curr)
// 												// {
// 												// ft_printf("%d\n", curr->target->value);
// 												// curr = curr->next;
// 												// }
// 												ft_printf("\n");
// 	free_list(stack_a);
// 	free_list(stack_b);
// 	return (0);
// }


int main(int argc, char **argv)
{
	t_stack_node	**stack_a;
	t_stack_node	**stack_b;
	t_stack_node	*curr_a;
	t_stack_node	*curr_b;

	stack_a = malloc(sizeof(t_stack_node));
	stack_b = malloc(sizeof(t_stack_node));
	*stack_a = NULL;
	*stack_b = NULL;

	stack_init(stack_a, argc, argv);

	ft_printf("step 1) stack a\n");
	print_stack(*stack_a);

	curr_a = *stack_a;
	while (curr_a)
	{
		ft_printf("the indexes are:%d \n", curr_a->index);
		curr_a = curr_a->next;
	}
		ft_printf("\n");


	ft_printf("step 1) stack b\n");
	print_stack(*stack_b);

	curr_b = *stack_b;
	while (curr_b)
	{
		ft_printf("%d the indexes are:\n", curr_b->index);
		curr_b = curr_b->next;
	}

		ft_printf("\n");

	if (is_sorted(stack_a))
	{
		free_list(stack_a);
		free_list(stack_b);
		return (0);
	}
	sort_stack(stack_a, stack_b);

		ft_printf("\n");
	ft_printf("step 2) stack a\n");
	print_stack(*stack_a);

	ft_printf("step 2) stack b\n");
	print_stack(*stack_b);

		ft_printf("\n");

	// ft_printf("the value of the target of nodes in stack b is %d\n", (*stack_b)->next->next->target->value);

	curr_b = *stack_b;
	while(curr_b)
	{
		ft_printf("the value of the target of nodes in stack b is %d\n", curr_b->target->value);
		curr_b = curr_b->next;
	}

	free_list(stack_a);
	free_list(stack_b);
	return (0);
}

