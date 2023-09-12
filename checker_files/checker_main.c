/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:15:00 by plashkar          #+#    #+#             */
/*   Updated: 2023/09/12 10:54:56 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	**stack_a_check;
	t_stack_node	**stack_b_check;
	char			*next_line;

	stack_a_check = malloc(sizeof(t_stack_node));
	stack_b_check = malloc(sizeof(t_stack_node));
	*stack_a_check = NULL;
	*stack_b_check = NULL;
	if (argc < 3)
		return (-1);
	if (ft_check_args(argc, argv))
		return (0);
	stack_init(stack_a_check, argc, argv);
	next_line = get_next_line(STDIN_FILENO);
	while (next_line)
	{
		parsing(stack_a_check, stack_b_check, next_line);
		next_line = get_next_line(STDIN_FILENO);
	}
	ft_ok_or_ko(stack_a_check, stack_b_check);
	free_list(stack_a_check);
	free_list(stack_b_check);
}
