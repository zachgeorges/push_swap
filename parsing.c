/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgeorges <zgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:59:40 by zgeorges          #+#    #+#             */
/*   Updated: 2026/03/16 15:59:40 by zgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_split(char *str, char c)
{
	char	**arr;
	int		i;

	arr = malloc(sizeof(char *) * (wrd_count(str, c) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (*str != c)
		{
			arr[i] = get_word(str, c);
			if (!arr[i])
				return (NULL);
			i++;
			while (*str && *str != c)
				str++;
		}
		else
			str++;
	}
	arr[i] = NULL;
	return (arr);
}

void	exit_msg(t_node **stack, char **flat)
{
	free_stack(stack);
	free_flat(flat);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_flat(char **flat)
{
	int	i;

	if (!flat)
		return ;
	i = 0;
	while (flat[i])
	{
		free(flat[i]);
		i++;
	}
	free(flat);
}

t_node	*create_stack(char **input)
{
	t_node	*stack;
	t_node	*node;
	int		value;
	int		i;

	stack = NULL;
	i = 0;
	while (input[i])
	{
		if (!is_int(input[i]))
			exit_msg(&stack, input);
		value = ft_atoi(input[i]);
		if (has_duplicates(stack, value))
			exit_msg(&stack, input);
		node = new_node(value);
		if (!node)
			exit_msg(&stack, input);
		append_node(&stack, node);
		i++;
	}
	free_flat(input);
	return (stack);
}
