/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:53:29 by osadeddi          #+#    #+#             */
/*   Updated: 2024/11/02 15:29:26 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*sort_fun(t_stack *s)
{
	int	i;
	int	*chunk;

	i = 0;
	chunk = malloc(sizeof(int) * (chunk_count(s->top_a)));
	if (!chunk)
		return (NULL);
	halving_a(s, chunk, &i);
	i--;
	if (chunk[i] == 0)
		i--;
	if (!halving_b(s, chunk, &i))
		return (NULL);
	free(chunk);
	return (s);
}

static void	sort_3(t_stack *s)
{
	if (s->stack_a[0] > s->stack_a[1] && s->stack_a[0] < s->stack_a[2])
		rotate_a(s->stack_a, &s->top_a);
	else if (s->stack_a[0] < s->stack_a[1] && s->stack_a[0] > s->stack_a[2])
	{
		reverse_rotate_a(s->stack_a, &s->top_a);
		swap_a(s->stack_a, &s->top_a);
	}
	else if (s->stack_a[0] < s->stack_a[1] && s->stack_a[1] > s->stack_a[2])
		reverse_rotate_a(s->stack_a, &s->top_a);
	else if (s->stack_a[0] > s->stack_a[1] && s->stack_a[1] < s->stack_a[2])
		swap_a(s->stack_a, &s->top_a);
	else if (!is_sorted(s->stack_a, s->top_a))
	{
		rotate_a(s->stack_a, &s->top_a);
		swap_a(s->stack_a, &s->top_a);
	}
}

static int	choose_fun(t_stack *s, int argc, char **argv, int is_split)
{
	if ((argc == 2 && !is_split) || (argc == 1 && is_split)
		|| is_sorted(s->stack_a, s->top_a))
		return (free_stack(s), free_args(argv, is_split), 1);
	else if ((argc == 3 && !is_split) || (argc == 2 && is_split))
	{
		if (s->stack_a[0] < s->stack_a[1])
			swap_a(s->stack_a, &s->top_a);
	}
	else if ((argc == 4 && !is_split) || (argc == 3 && is_split))
		sort_3(s);
	else if (!sort_fun(s))
		return (free_stack(s), free_args(argv, is_split), 0);
	return (free_stack(s), free_args(argv, is_split), 1);
}

int	main(int argc, char **argv)
{
	t_stack	*s;
	int		is_split;

	is_split = 0;
	if (argc > 1)
	{
		s = NULL;
		if (!check_input(&argc, &argv, &is_split))
			return (error_fun(NULL));
		if (!stack_init(&s, argc, argv, is_split))
			return (error_fun(s));
		if (!choose_fun(s, argc, argv, is_split))
			return (error_fun(s));
	}
	else
		return (0);
	return (0);
}
