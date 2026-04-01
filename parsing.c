/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgeorges <zgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:59:40 by zgeorges          #+#    #+#             */
/*   Updated: 2026/04/01 18:36:44 by zgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char **ft_split(char *str, char c)
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
	
}

void	free_flat(char **flat)
{
	
}

t_node	*create_stack(char	**input)
{
	//needs 7 helpers include in stack_init_utils.
}