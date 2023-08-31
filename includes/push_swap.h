/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:05:32 by plashkar          #+#    #+#             */
/*   Updated: 2023/08/24 18:22:47 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct t_stack_node
{
	int					value;
	int					index;
	struct t_stack_node	*next;
	struct t_stack_node	*target;
}	t_stack_node;

//List functions

int				ft_count_nodes(t_stack_node *root);
t_stack_node	*ft_find_last_node(t_stack_node *root);
t_stack_node	*ft_new_list(int value);
t_stack_node	*ft_get_biggest(t_stack_node *stack);
t_stack_node	*ft_get_smallest(t_stack_node *stack);
void			ft_list_addfront(t_stack_node **stack, t_stack_node *new_node);
void			ft_list_addend(t_stack_node **stack, t_stack_node *new_node);
int				is_sorted(t_stack_node **stack);
void			print_stack(t_stack_node *root);

//Free functions

void			free_list(t_stack_node **root);
void			ft_free_string(char **str);

//Swap functrions

void			swap(t_stack_node *root);
void			sa(t_stack_node *tail_a);
void			sb(t_stack_node *tail_b);
void			ss(t_stack_node *tail_a, t_stack_node *tail_b);

//Rotate and Reverse rotate functions

void			rotate(t_stack_node **stack);
void			ra(t_stack_node **stack_a);
void			rb(t_stack_node **stack_b);
void			rr(t_stack_node **stack_a, t_stack_node **stack_b);
void			reverse_rotate(t_stack_node **stack);
void			rra(t_stack_node **stack_a);
void			rrb(t_stack_node **stack_b);
void			rrr(t_stack_node **stack_a, t_stack_node **stack_b);

//push functions

void			push(t_stack_node **stack_a, t_stack_node **stack_b);
void			pa(t_stack_node **stack_a, t_stack_node **stack_b);
void			pb(t_stack_node **stack_a, t_stack_node **stack_b);

//stack initialaztion functions

void			stack_init(t_stack_node **stack, int argc, char **argv);
void			index_stack(t_stack_node **stack);
t_stack_node	*get_next_min(t_stack_node **stack);

//Errors and checks

void			ft_check_args(int argc, char **argv);
int				ft_is_repeated(int tmp, char **argv, int i);
int				ft_is_num(char *num);

//sort utils
int				distance_from_min(t_stack_node **stack, int index);
int				distance_from_max(t_stack_node **stack, int index);
int				get_min_top_two(t_stack_node **stack, int previous_min);
void			get_target(t_stack_node *stack_a, t_stack_node *stack_b);

//sort functions
void			sort_stack(t_stack_node **stack_a, t_stack_node **stack_b);
void			sort_3(t_stack_node **stack);
void			sort_4(t_stack_node **stack_a, t_stack_node **stack_b);
void			sort_5(t_stack_node **stack_a, t_stack_node **stack_b);
void			simple_sort(t_stack_node **stack_a, t_stack_node **stack_b);

#endif
