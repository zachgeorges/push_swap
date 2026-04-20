/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgeorges <zgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:59:34 by zgeorges          #+#    #+#             */
/*   Updated: 2026/04/01 18:36:46 by zgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

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
//parsing.c
char	**ft_split(char *str, char c);
void	exit_msg(t_node **stack, char **flat);
void	free_flat(char **flat);
t_node	*create_stack(char **input);

//parsing_utils.c
int		wrd_count(char *str, char c);
char	*get_word(char *str, char c);

//stack_init_utils.c
int		is_int(char *str);
int		ft_atoi(char *str);
int		has_duplicates(t_node *stack, int value);
t_node	*new_node(int value);
void	append_node(t_node **stack, t_node *node);

//main_utils.c
int		count_tokens(char **input);
char	**flatten_input(char **input);

//stack_utils.c
int		stack_len(t_node *stack);
int		is_sorted(t_node *stack);
t_node	*get_smallest(t_node *stack);
void	free_stack(t_node **node);

//swap_instructions.c
void	swap_values(t_node **s);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);

//push_instructions.c
void	pa(t_node **a, t_node **b);
void	pb(t_node **b, t_node **a);

//rotate_instructions.c
void	rotate_stack(t_node **s);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);

//reverse_rotate_instructions.c
void	rev_rotate_stack(t_node **s);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

//node_data.c
void	set_positions(t_node *stack);
void	set_targets(t_node *b, t_node *a);
void	calc_cost(t_node *cur, int len_b, int len_a);
void	set_costs(t_node *b, int len_b, int len_a);
void	init_node_data(t_node *a, t_node *b);

//algo.c
void	rr_looped(t_node **a, t_node **b, t_node *cheapest);
void	rrr_looped(t_node **a, t_node **b, t_node *cheapest);
void	finish_loop(t_node **stack, t_node *target, char name);
void	move_the_damn_node(t_node **a, t_node **b);

//main.c
void	sort_3(t_node **a);
void	push_swap(t_node **a, t_node **b);
void	cases(t_node **a, t_node **b);

#endif