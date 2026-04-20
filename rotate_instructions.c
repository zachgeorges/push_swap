/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgeorges <zgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:18:36 by zgeorges          #+#    #+#             */
/*   Updated: 2026/04/01 18:36:49 by zgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_node **s)
{
	t_node	*head;
	t_node	*tail;

	if (!*s || !(*s)->next)
		return ;
	head = *s;
	tail = *s;
	while (tail->next)
		tail = tail->next;
	*s = head->next;
	(*s)->prev = NULL;
	tail->next = head;
	head->prev = tail;
	head->next = NULL;
}

void	ra(t_node **a)
{
	rotate_stack(a);
	write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	rotate_stack(b);
	write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	rotate_stack(a);
	rotate_stack(b);
	write(1, "rr\n", 3);
}
