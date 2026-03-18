/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgeorges <zgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:59:34 by zgeorges          #+#    #+#             */
/*   Updated: 2026/03/18 12:56:44 by zgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				pos;
	int				cost_self;
	int				cost_target;
	int				total_cost;
	int				is_cheapest;
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

char	**ft_split(char *str, char c);

t_node	*create_stack(char	**argv, int free_argv);

int		stack_len(t_node *stack);
int		is_sorted(t_node *stack);
t_node	*get_smallest(t_node *stack);

void	sort_3(t_node **a);

void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);

void	pa(t_node **a, t_node **b);
void	pb(t_node **b, t_node **a);

void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);

void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

void	set_positions(t_node *stack);
void	set_targets(t_node *a, t_node *b);
void	set_costs(t_node *b, int len_b, int len_a);
void	init_node_data(t_node *a, t_node *b);

void	rr_looped();
void	rrr_looped();
void	finish_loop();
void	move_the_damn_node(t_node **a, t_node **b);

void	push_swap(t_node **a, t_node **b);

void	free_stack(t_node **node);

#endif