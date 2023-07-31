/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:32:41 by plashkar          #+#    #+#             */
/*   Updated: 2023/07/31 20:24:45 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					push_cost;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

void	swap(t_stack_node *head)
{
	if (head != NULL && head->next != NULL && head->prev == NULL)
	{
		size_t temp;

		temp = head->value;
		head->value = head->next->value;
		head->next->value = temp;
	}
}

void sa(t_stack_node *a)
{
	swap(a);
	printf("sa\n");
}

int main(void)
{
	t_stack_node *a;
	t_stack_node *temp;


	a = malloc(sizeof(t_stack_node));
	if (a == NULL)
		return(0);
	a->next = malloc(sizeof(t_stack_node));
	a->next->next = malloc(sizeof(t_stack_node));
	a->value = 12;
	a->next->value = 52;
	a->next->next->value = 69;

	temp = a;
	while (temp)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}
	sa(a);
	while (a)
	{
		printf("%d\n", a->value);
		a = a->next;
	}
	return(0);
}
