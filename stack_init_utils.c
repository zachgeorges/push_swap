/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgeorges <zgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:00:59 by zgeorges          #+#    #+#             */
/*   Updated: 2026/04/01 18:36:50 by zgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_int(char *str)
{
	long	n;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	n = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		n = n * 10 + (str[i++] - '0');
		if (n * sign > INT_MAX || n * sign < INT_MIN)
			return (0);
	}
	return (1);
}

int	ft_atoi(char *str)
{
	long	n;
	int		sign;

	n = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
		n = n * 10 + (*str++ - '0');
	return ((int)(n * sign));
}

int	has_duplicates(t_node *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->pos = 0;
	node->cost_self = 0;
	node->cost_target = 0;
	node->total_cost = 0;
	node->is_cheapest = 0;
	node->target_node = NULL;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	append_node(t_node **stack, t_node *node)
{
	t_node	*tail;

	if (!*stack)
	{
		*stack = node;
		return ;
	}
	tail = *stack;
	while (tail->next)
		tail = tail->next;
	tail->next = node;
	node->prev = tail;
}
