/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_instructions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgeorges <zgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:18:53 by zgeorges          #+#    #+#             */
/*   Updated: 2026/04/01 18:36:48 by zgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_stack(t_node **s)
{
	t_node	*tail;

	if (!*s || !(*s)->next)
		return ;
	tail = *s;
	while (tail->next)
		tail = tail->next;
	tail->prev->next = NULL;
	tail->next = *s;
	tail->prev = NULL;
	(*s)->prev = tail;
	*s = tail;
}

void	rra(t_node **a)
{
	rev_rotate_stack(a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	rev_rotate_stack(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	rev_rotate_stack(a);
	rev_rotate_stack(b);
	write(1, "rrr\n", 4);
}
