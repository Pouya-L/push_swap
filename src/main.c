/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:56:45 by plashkar          #+#    #+#             */
/*   Updated: 2023/09/12 15:26:07 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	**stack_a;
	t_stack_node	**stack_b;

	if (argc < 2)
		return (-1);
	if (ft_check_args(argc, argv))
		return (0);
	stack_a = malloc(sizeof(t_stack_node));
	stack_b = malloc(sizeof(t_stack_node));
	*stack_a = NULL;
	*stack_b = NULL;
	stack_init(stack_a, argc, argv);
	if (is_sorted(stack_a))
	{
		free_list(stack_a);
		free_list(stack_b);
		return (0);
	}
	sort_stack(stack_a, stack_b);
	free_list(stack_a);
	free_list(stack_b);
	return (0);
}
