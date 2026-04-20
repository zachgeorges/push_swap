/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgeorges <zgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:19:06 by zgeorges          #+#    #+#             */
/*   Updated: 2026/03/18 15:19:06 by zgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_node **a)
{
	t_node	*pos1;
	t_node	*pos2;
	t_node	*pos3;

	pos1 = *a;
	pos2 = (*a)->next;
	pos3 = (*a)->next->next;
	if (pos1->value > pos2->value && pos1->value > pos3->value)
		ra(a);
	else if (pos2->value > pos1->value && pos2->value > pos3->value)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	push_swap(t_node **a, t_node **b)
{
	t_node	*smallest;

	while (stack_len(*a) > 3)
		pb(b, a);
	sort_3(a);
	while (*b)
	{
		init_node_data(*a, *b);
		move_the_damn_node(a, b);
	}
	set_positions(*a);
	smallest = get_smallest(*a);
	while (smallest->pos > 0)
	{
		if (smallest->pos <= stack_len(*a) / 2)
			ra(a);
		else
			rra(a);
		set_positions(*a);
	}
}

void	cases(t_node **a, t_node **b)
{
	if (stack_len(*a) == 2)
		sa(a);
	else if (stack_len(*a) == 3)
		sort_3(a);
	else
		push_swap(a, b);
	free_stack(a);
	free_stack(b);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	char	**flat;

	if (ac < 2)
		return (0);
	flat = flatten_input(av);
	if (!flat || !flat[0])
	{
		free(flat);
		return (0);
	}
	a = create_stack(flat);
	b = NULL;
	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	cases(&a, &b);
	return (0);
}
