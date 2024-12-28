/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:27:55 by osadeddi          #+#    #+#             */
/*   Updated: 2024/10/28 17:10:15 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*sort_chunk_init(t_sort_chunk *c, t_stack *s)
{
	c->mid = 0;
	c->chunk_size = 0;
	c->chunk_b2a = 0;
	c->chunk_a = 0;
	c->i = 0;
	c->rotations = 0;
	c->chunk_b2a = malloc(sizeof(int) * chunk_count(s->top_a));
	if (!c->chunk_b2a)
		return (NULL);
	return (c);
}

void	halving_b_init(t_halving_b *b)
{
	b->rotations = 0;
	b->chunk_size = 0;
	b->chunk_b = 0;
	b->flag = 0;
	b->j = 0;
	b->mid = 0;
}

void	*stack_init(t_stack **s, int argc, char **argv, int is_split)
{
	*s = malloc(sizeof(t_stack));
	if (!*s)
		return (NULL);
	(*s)->stack_a = malloc(sizeof(int) * (argc + 1));
	if (!(*s)->stack_a)
		return (NULL);
	(*s)->stack_b = malloc(sizeof(int) * (argc + 1));
	if (!(*s)->stack_b)
		return (NULL);
	(*s)->top_a = -1;
	(*s)->top_b = -1;
	if (!is_split)
	{
		while (argc > 1)
			(*s)->stack_a[++(*s)->top_a] = ft_atoi(argv[--argc]);
	}
	else
	{
		while (argc > 0)
			(*s)->stack_a[++(*s)->top_a] = ft_atoi(argv[--argc]);
	}
	return (s);
}
