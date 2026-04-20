/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgeorges <zgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:59:43 by zgeorges          #+#    #+#             */
/*   Updated: 2026/03/16 15:59:43 by zgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish_loop(t_node **stack, t_node *target, char name)
{
	int	len;

	len = stack_len(*stack);
	if (target->pos <= len / 2)
	{
		while (target->pos > 0)
		{
			if (name == 'a')
				ra(stack);
			else
				rb(stack);
			set_positions(*stack);
		}
	}
	else
	{
		while (target->pos > 0)
		{
			if (name == 'a')
				rra(stack);
			else
				rrb(stack);
			set_positions(*stack);
		}
	}
}

void	rr_looped(t_node **a, t_node **b, t_node *cheapest)
{
	while (cheapest->pos > 0 && cheapest->target_node->pos > 0)
	{
		rr(a, b);
		set_positions(*a);
		set_positions(*b);
	}
}

void	rrr_looped(t_node **a, t_node **b, t_node *cheapest)
{
	while (cheapest->pos > 0 && cheapest->target_node->pos > 0)
	{
		rrr(a, b);
		set_positions(*a);
		set_positions(*b);
	}
}

void	move_the_damn_node(t_node **a, t_node **b)
{
	t_node	*cheapest;
	int		above_b;
	int		above_t;

	cheapest = *b;
	while (!cheapest->is_cheapest)
		cheapest = cheapest->next;
	above_b = cheapest->pos <= stack_len(*b) / 2;
	above_t = cheapest->target_node->pos <= stack_len(*a) / 2;
	if (above_b && above_t)
		rr_looped(a, b, cheapest);
	else if (!above_b && !above_t)
		rrr_looped(a, b, cheapest);
	finish_loop(b, cheapest, 'b');
	finish_loop(a, cheapest->target_node, 'a');
	pa(a, b);
}
