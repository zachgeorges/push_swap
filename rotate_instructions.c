/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgeorges <zgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:18:36 by zgeorges          #+#    #+#             */
/*   Updated: 2026/03/30 19:10:48 by zgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a)
{
	t_node	*head;
	t_node	*tail;
	
	if (!*a || !(*a)->next)
		return ;
	head = *a;
	tail = *a;
	while (tail->next)
		tail = tail->next;
	*a = head->next;
	(*a)->prev = NULL;
	tail->next = head;
	head->prev = tail;
	head->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	t_node	*head;
	t_node	*tail;
	
	if (!*b || !(*b)->next)
		return ;
	head = *b;
	tail = *b;
	while (tail->next)
		tail = tail->next;
	*b = head->next;
	(*b)->prev = NULL;
	tail->next = head;
	head->prev = tail;
	head->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}
