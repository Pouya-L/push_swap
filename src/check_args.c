/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:23:43 by plashkar          #+#    #+#             */
/*   Updated: 2023/09/14 12:14:37 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Checks if the number was repeated before in the list of arguments
int	ft_is_repeated(int tmp, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == tmp)
			return (1);
		i++;
	}
	return (0);
}

//Checks if it's a number (it can also notice '-' & '+' signs and ignore it)
int	ft_is_num(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-' || num[0] == '+')
	{
		i++;
		if (!num[i])
			return (0);
	}
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

//Checks the arguments for not acceptable arguments and returns error
//Errors include: repeated numbers, numbers out of range, anything but numbers
int	ft_check_args(int argc, char **argv)
{
	char	**args;

	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = &(argv[1]);
	if (ft_check_args_2(args) != 0)
	{
		if (argc == 2)
			ft_free_string(args);
		return (1);
	}
	if (argc == 2)
		ft_free_string(args);
	return (0);
}

//Part two of check_args since it coudn't fit in 25 lines
int	ft_check_args_2(char **args)
{
	long	tmp;
	long	i;

	i = 0;
	while (args[i])
	{
		if (!ft_strcmp(args[i], ""))
		{
			ft_printf("Error\n");
			return (1);
		}
		tmp = ft_atoi(args[i]);
		if (!ft_is_num(args[i]) || ft_is_repeated(tmp, args, i) || \
		tmp < -2147483648 || tmp > 2147483647)
		{
			ft_printf("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}
