/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:46:55 by osadeddi          #+#    #+#             */
/*   Updated: 2024/11/02 15:34:38 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	inner_loop_b(t_stack *s, t_sort_chunk *c)
{
	while (c->chunk_size > 0)
	{
		if (s->stack_a[s->top_a] > s->stack_a[s->top_a - 1]
			&& is_smallest(s->stack_a, s->top_a - 1, s->stack_a[s->top_a]))
			swap_a(s->stack_a, &s->top_a);
		else if (s->stack_b[s->top_b] > c->mid || (c->chunk_size == 1
				&& c->rotations == 0 && c->chunk_b2a[c->i] == 0))
			c->chunk_size -= push_a(s->stack_a, s->stack_b, &s->top_a,
					&s->top_b);
		else if (c->rotations <= c->chunk_b2a[c->i])
			c->rotations += rotate_b(s->stack_b, &s->top_b);
		else if (c->rotations > 0)
			c->rotations -= reverse_rotate_b(s->stack_b, &s->top_b);
	}
}

static void	choose_chunk_size(t_sort_chunk *c)
{
	if (c->chunk_b2a[c->i] == 1)
		c->chunk_size = 1;
	else if (c->chunk_b2a[c->i] == 2)
		c->chunk_size = c->chunk_b2a[c->i];
	else
		c->chunk_size = (c->chunk_b2a[c->i]) / 2;
}

static void	*loop_b(t_stack *s, t_sort_chunk *c, int chunk)
{
	while (c->chunk_b2a[c->i] != chunk)
	{
		c->mid = mid_b(&s->stack_b[s->top_b - c->chunk_b2a[c->i] + 1],
				c->chunk_b2a[c->i] - 1);
		choose_chunk_size(c);
		c->chunk_b2a[c->i] -= c->chunk_size;
		inner_loop_b(s, c);
		if (s->stack_a[s->top_a] > s->stack_a[s->top_a - 1]
			&& is_smallest(s->stack_a, s->top_a - 1, s->stack_a[s->top_a]))
			swap_a(s->stack_a, &s->top_a);
		while (c->rotations > 0)
			c->rotations -= reverse_rotate_b(s->stack_b, &s->top_b);
		if (!is_sorted(s->stack_a, s->top_a))
		{
			if (!sort_chunk(s, c->chunk_b2a[c->i]))
				return (NULL);
		}
		if (c->chunk_b2a[c->i] == 0)
			c->i--;
	}
	return (s);
}

void	*sort_chunk(t_stack *s, int chunk)
{
	t_sort_chunk	*c;

	c = malloc(sizeof(t_sort_chunk));
	if (!c)
		return (NULL);
	if (!sort_chunk_init(c, s))
		return (free_c(c));
	c->chunk_b2a[0] = chunk;
	c->chunk_a = chunk;
	loop_a(s, c);
	if (!loop_b(s, c, chunk))
		return (free_c(c));
	free_c(c);
	return (s);
}
