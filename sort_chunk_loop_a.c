/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk_loop_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:56:49 by osadeddi          #+#    #+#             */
/*   Updated: 2024/10/28 21:06:59 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	inner_loop_a(t_stack *s, t_sort_chunk *c)
{
	while (c->chunk_size > 0)
	{
		if (s->stack_a[s->top_a] < c->mid || (c->chunk_size == 1
				&& c->chunk_a == 0 && c->rotations == 0))
			c->chunk_size -= push_b(s->stack_a, s->stack_b, &s->top_a,
					&s->top_b);
		else if (c->rotations <= c->chunk_a)
			c->rotations += rotate_a(s->stack_a, &s->top_a);
		else if (c->rotations > 0)
			c->rotations -= reverse_rotate_a(s->stack_a, &s->top_a);
	}
}

void	loop_a(t_stack *s, t_sort_chunk *c)
{
	while (c->chunk_a > 0)
	{
		c->mid = mid_a(&s->stack_a[s->top_a - c->chunk_a + 1], c->chunk_a - 1);
		if (c->chunk_a == 1)
			c->chunk_size = 1;
		else if (c->chunk_a == 2)
			c->chunk_size = c->chunk_a;
		else
			c->chunk_size = c->chunk_a / 2;
		c->chunk_a -= c->chunk_size;
		c->chunk_b2a[++(c->i)] = c->chunk_size;
		inner_loop_a(s, c);
		while (c->rotations > 0)
			c->rotations -= reverse_rotate_a(s->stack_a, &s->top_a);
		if ((c->chunk_a == 2 || s->top_a == 1 || is_smallest(s->stack_a,
					s->top_a - 1, s->stack_a[s->top_a])) && s->stack_a[s->top_a
				- 1] < s->stack_a[s->top_a])
			swap_a(s->stack_a, &s->top_a);
		if (is_sorted(s->stack_a, s->top_a))
			break ;
	}
}
