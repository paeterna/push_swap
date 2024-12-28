/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:17:00 by osadeddi          #+#    #+#             */
/*   Updated: 2024/11/02 15:29:20 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *s)
{
	if (s)
	{
		if (s->stack_a)
			free(s->stack_a);
		if (s->stack_b)
			free(s->stack_b);
		free(s);
	}
}

void	free_args(char **args, int is_split)
{
	int	i;

	i = 0;
	if (is_split && args)
	{
		while (args[i])
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
}

void	*free_c(t_sort_chunk *c)
{
	if (c)
	{
		if (c->chunk_b2a)
			free(c->chunk_b2a);
		free(c);
	}
	return (NULL);
}

int	error_fun(t_stack *s)
{
	if (s)
	{
		if (s->stack_a)
			free(s->stack_a);
		if (s->stack_b)
			free(s->stack_b);
		free(s);
	}
	write(2, "Error\n", 6);
	return (0);
}
