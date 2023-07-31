/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:50:19 by plashkar          #+#    #+#             */
/*   Updated: 2023/07/31 16:38:58 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_list
{
	int				*value;
	int				*current_position;
	int				*push_cost;
	bool			cheapest;
	struct s_list	*next;
	struct s_list	*prev;
}	t_stack_node;





#endif
