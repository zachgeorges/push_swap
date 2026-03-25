/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgeorges <zgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:19:06 by zgeorges          #+#    #+#             */
/*   Updated: 2026/03/25 18:19:45 by zgeorges         ###   ########.fr       */
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
	//While > 3 nodes in a,
	//	pb
	//once 3 remain : sort_3(a) 
	//while b not empty
	//	init_node_data(a, b)
	//	move_the_damn_node(a, b)
	//once b empty : make sure the smallest is at the top
	//	set_positions(a)
	//	get_smallest(a)
	//if in upper half, ra repeatedly
	//else, rra repeatedly
}

int	main(int ac,char **av)
{
	//If ac == 1 or ac == 2 and av[1] empty
	//	return (no output)
	//If ac == 2
	//	res = ft_split(av[1])
	//	create_stack(res)
	//	free_av = 1
}
