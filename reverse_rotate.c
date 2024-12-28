/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:48:27 by osadeddi          #+#    #+#             */
/*   Updated: 2024/10/31 20:24:08 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate_a(int *stack_a, int *top_a)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack_a[i];
	while (i < *top_a)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[i] = temp;
	write(1, "rra\n", 4);
	return (1);
}

int	reverse_rotate_b(int *stack_b, int *top_b)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack_b[i];
	while (i < *top_b)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[i] = temp;
	write(1, "rrb\n", 4);
	return (1);
}

int	reverse_rotate_r(int *stack_a, int *stack_b, int *top_a, int *top_b)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack_a[i];
	while (i < *top_a)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[i] = temp;
	i = 0;
	temp = stack_b[i];
	while (i < *top_b)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[i] = temp;
	write(1, "rrr\n", 4);
	return (1);
}
