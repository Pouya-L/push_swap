/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:15:00 by plashkar          #+#    #+#             */
/*   Updated: 2023/09/11 16:26:23 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	**stack_a_check;
	t_stack_node	**stack_b_check;
	int				len;
	char			*next_line;

	stack_a_check = malloc(sizeof(t_stack_node));
	stack_b_check = malloc(sizeof(t_stack_node));
	*stack_a_check = NULL;
	*stack_b_check = NULL;
	if (argc < 3)
		return (-1);
	if (ft_check_args(argc, argv))
		return (0);
	stack_init(stack_a_check, 2, argv + 1);
	next_line = get_next_line(STDIN_FILENO);
	while (next_line)
	{
		//parse_command
		next_line = get_next_line(STDIN_FILENO);
	}
	ft_ok_or_ko(stack_a_check, stack_b_check);
	free_list(stack_a_check);
	free_list(stack_b_check);
}
