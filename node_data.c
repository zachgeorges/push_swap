/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgeorges <zgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:17:25 by zgeorges          #+#    #+#             */
/*   Updated: 2026/03/18 15:17:25 by zgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_positions(t_node *stack)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		stack->pos = pos++;
		stack = stack->next;
	}
}

void	set_targets(t_node *b, t_node *a)
{
	t_node	*best;
	t_node	*cur_a;
	t_node	*cur_b;

	cur_b = b;
	while (cur_b)
	{
		best = NULL;
		cur_a = a;
		while (cur_a)
		{
			if (cur_a->value > cur_b->value)
				if (!best || cur_a->value < best->value)
					best = cur_a;
			cur_a = cur_a->next;
		}
		if (!best)
			best = get_smallest(a);
		cur_b->target_node = best;
		cur_b = cur_b->next;
	}
}

void	calc_cost(t_node *cur, int len_b, int len_a)
{
	int	above_b;
	int	above_t;

	above_b = cur->pos <= len_b / 2;
	above_t = cur->target_node->pos <= len_a / 2;
	cur->cost_self = cur->pos;
	if (!above_b)
		cur->cost_self = len_b - cur->pos;
	cur->cost_target = cur->target_node->pos;
	if (!above_t)
		cur->cost_target = len_a - cur->target_node->pos;
	if (above_b == above_t)
	{
		if (cur->cost_self > cur->cost_target)
			cur->total_cost = cur->cost_self;
		else
			cur->total_cost = cur->cost_target;
	}
	else
		cur->total_cost = cur->cost_self + cur->cost_target;
}

void	set_costs(t_node *b, int len_b, int len_a)
{
	t_node	*cur;
	int		min_cost;

	min_cost = INT_MAX;
	cur = b;
	while (cur)
	{
		calc_cost(cur, len_b, len_a);
		if (cur->total_cost < min_cost)
			min_cost = cur->total_cost;
		cur = cur->next;
	}
	cur = b;
	while (cur)
	{
		cur->is_cheapest = (cur->total_cost == min_cost);
		cur = cur->next;
	}
}

void	init_node_data(t_node *a, t_node *b)
{
	set_positions(a);
	set_positions(b);
	set_targets(b, a);
	set_costs(b, stack_len(b), stack_len(a));
}
