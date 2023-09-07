/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:56:45 by plashkar          #+#    #+#             */
/*   Updated: 2023/09/07 17:08:04 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int	main(int argc, char **argv)
// {
// 	t_stack_node	**stack_a;
// 	t_stack_node	**stack_b;

// 	if (argc < 3)
// 		return (-1);
	// if(ft_check_args(argc, argv))
	// 	return (0);
// 	stack_a = malloc(sizeof(t_stack_node));
// 	stack_b = malloc(sizeof(t_stack_node));
// 	*stack_a = NULL;
// 	*stack_b = NULL;
// 	stack_init(stack_a, argc, argv);
// 	if (is_sorted(stack_a))
// 	{
// 		free_list(stack_a);
// 		free_list(stack_b);
// 		return (0);
// 	}
// 	sort_stack(stack_a, stack_b);
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

	if (argc <= 2)
		return (-1);
	if(ft_check_args(argc, argv))
		return (0);
	stack_a = malloc(sizeof(t_stack_node));
	stack_b = malloc(sizeof(t_stack_node));
	*stack_a = NULL;
	*stack_b = NULL;

	stack_init(stack_a, argc, argv);

									//print stack a//
							ft_printf("step 1) stack a\n");
							print_stack(*stack_a);
									//END//
									//print indexes//
							curr_a = *stack_a;
							while (curr_a)
							{
								ft_printf("the indexes are:%d \n", curr_a->index);
								curr_a = curr_a->next;
							}
								ft_printf("\n");
									//END//

									//print stack b//
							ft_printf("step 1) stack b\n");
							print_stack(*stack_b);
									//END//
									//print indexes in stack b//
							curr_b = *stack_b;
							while (curr_b)
							{
								ft_printf("%d the indexes are:\n", curr_b->index);
								curr_b = curr_b->next;
							}
								ft_printf("\n");
									//END//
	if (is_sorted(stack_a))
	{
		free_list(stack_a);
		free_list(stack_b);
		return (0);
	}
	sort_stack(stack_a, stack_b);
									//print stack a now sorted//
								ft_printf("\n");
							ft_printf("step 2) stack a\n");
							print_stack(*stack_a);
									//END//
									//print stack b//
							ft_printf("step 2) stack b\n");
							print_stack(*stack_b);
								ft_printf("\n");
									//END//

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

