/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_instructions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgeorges <zgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:18:53 by zgeorges          #+#    #+#             */
/*   Updated: 2026/03/30 19:10:48 by zgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **a)
{
	t_node	*head;
	t_node	*tail;
	
	if (!*a || !(*a)->next)
		return ;
	tail = *a;
	while (tail->next)
		tail = tail->next;
	tail->prev->next = NULL;
	tail->next = *a;
	tail->prev = NULL;
	(*a)->prev = tail;
	*a = tail;
	write(1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	t_node	*head;
	t_node	*tail;
	
	if (!*b || !(*b)->next)
		return ;
	tail = *b;
	while (tail->next)
		tail = tail->next;
	tail->prev->next = NULL;
	tail->next = *b;
	tail->prev = NULL;
	(*b)->prev = tail;
	*b = tail;
	write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}

