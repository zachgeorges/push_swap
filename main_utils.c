/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgeorges <zgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 17:05:17 by zgeorges          #+#    #+#             */
/*   Updated: 2026/04/01 18:36:41 by zgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_tokens(char **input)
{
	char	**split;
	int		total;
	int		i;
	int		j;

	total = 0;
	i = 1;
	while (input[i])
	{
		split = ft_split(input[i], ' ');
		j = 0;
		while (split[j])
		{
			free(split[j]);
			total++;
			j++;
		}
		free(split);
		i++;
	}
	return (total);
}

char	**flatten_input(char **input)
{
	char	**flat;
	char	**split;
	int		i;
	int		j;
	int		k;

	flat = malloc(sizeof(char *) * (count_tokens(input) + 1));
	if (!flat)
		return (NULL);
	k = 0;
	i = 1;
	while (input[i])
	{
		split = ft_split(input[i], ' ');
		j = 0;
		while (split[j])
			flat[k++] = split[j++];
		free(split);
		i++;
	}
	flat[k] = NULL;
	return (flat);
}