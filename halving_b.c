/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   halving_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:20:04 by osadeddi          #+#    #+#             */
/*   Updated: 2024/11/02 15:34:45 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	inner_loop(t_stack *s, t_halving_b *b, int *i)
{
	while (b->chunk_size > 0 && *i > -1)
	{
		b->flag = check_rotation_b(s->stack_b, s->top_b, b->mid);
		if (s->stack_a[s->top_a] > s->stack_a[s->top_a - 1] && s->top_a > 0
			&& is_smallest(s->stack_a, s->top_a - 1, s->stack_a[s->top_a]))
			swap_a(s->stack_a, &s->top_a);
		else if ((b->chunk_size == 1 && b->chunk_b == 0
				&& s->stack_b[s->top_b] >= b->mid)
			|| (s->stack_b[s->top_b] > b->mid))
			b->chunk_size -= push_a(s->stack_a, s->stack_b, &s->top_a,
					&s->top_b);
		else if (b->flag && (b->rotations <= b->chunk_b || *i == 0))
			b->rotations += rotate_b(s->stack_b, &s->top_b);
		else if ((!b->flag && *i == 0) || b->rotations > 0)
			b->rotations -= reverse_rotate_b(s->stack_b, &s->top_b);
	}
}

static void	choose_chunk_size(t_halving_b *b)
{
	if (b->chunk_b == 1)
		b->chunk_size = 1;
	else if (b->chunk_b == 2)
		b->chunk_size = b->chunk_b;
	else
		b->chunk_size = (b->chunk_b) / 2;
}

static void	*outer_loop(t_stack *s, t_halving_b *b, int *i)
{
	if (*i == 0)
		b->rotations = 0;
	b->mid = mid_b(&s->stack_b[s->top_b - b->chunk_b + 1], b->chunk_b - 1);
	choose_chunk_size(b);
	b->j = b->chunk_size;
	b->chunk_b = b->chunk_b - b->chunk_size;
	inner_loop(s, b, i);
	if (s->stack_a[s->top_a] > s->stack_a[s->top_a - 1] && s->top_a > 0
		&& is_smallest(s->stack_a, s->top_a - 1, s->stack_a[s->top_a]))
		swap_a(s->stack_a, &s->top_a);
	if (!is_sorted(s->stack_a, s->top_a))
	{
		if (!sort_chunk(s, b->j))
			return (NULL);
	}
	else if (b->chunk_b < 1)
	{
		(*i)--;
		b->chunk_size = 0;
	}
	return (s);
}

void	*halving_b(t_stack *s, int *chunk, int *i)
{
	t_halving_b	*b;

	b = malloc(sizeof(t_halving_b));
	if (!b)
		return (NULL);
	halving_b_init(b);
	while (s->top_b > -1 && *i > -1)
	{
		if (b->chunk_b == 0)
			b->chunk_b = chunk[*i];
		while (b->rotations > 0 && b->chunk_b > 0 && *i != 0)
			b->rotations -= reverse_rotate_b(s->stack_b, &s->top_b);
		if (!outer_loop(s, b, i))
			return (free(b), NULL);
	}
	free(b);
	return (s);
}
