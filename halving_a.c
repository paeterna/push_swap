/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   halving_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:14:29 by osadeddi          #+#    #+#             */
/*   Updated: 2024/10/27 18:45:09 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	inner_loop(t_stack *s, int mid, int *chunk_size)
{
	int	flag;

	flag = check_rotation_a(s->stack_a, s->top_a, mid);
	if (s->stack_a[s->top_a] >= mid && !flag)
		reverse_rotate_a(s->stack_a, &s->top_a);
	else if (s->stack_a[s->top_a] < mid)
	{
		push_b(s->stack_a, s->stack_b, &s->top_a, &s->top_b);
		(*chunk_size)--;
	}
	else
		rotate_a(s->stack_a, &s->top_a);
}

void	halving_a(t_stack *s, int *chunk, int *i)
{
	int	mid;
	int	chunk_size;

	*i = 0;
	while (!(is_sorted(s->stack_a, s->top_a) || s->top_a <= 1))
	{
		mid = mid_a(s->stack_a, s->top_a);
		chunk[*i] = (s->top_a + 1) / 2;
		chunk_size = chunk[*i];
		while (!(chunk_size == 0 || is_sorted(s->stack_a, s->top_a)))
			inner_loop(s, mid, &chunk_size);
		if (s->top_a == 1 && s->stack_a[s->top_a - 1] < s->stack_a[s->top_a])
			swap_a(s->stack_a, &s->top_a);
		if (chunk_size != 0)
			chunk[*i] = chunk[*i] - chunk_size;
		(*i)++;
	}
}
