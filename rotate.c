/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:47:45 by osadeddi          #+#    #+#             */
/*   Updated: 2024/11/02 15:35:02 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_a(int *stack_a, int *top_a)
{
	int	i;
	int	temp;

	i = *top_a;
	temp = stack_a[i];
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[i] = temp;
	write(1, "ra\n", 3);
	return (1);
}

int	rotate_b(int *stack_b, int *top_b)
{
	int	i;
	int	temp;

	i = *top_b;
	temp = stack_b[i];
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[i] = temp;
	write(1, "rb\n", 3);
	return (1);
}

int	rotate_r(int *stack_a, int *stack_b, int *top_a, int *top_b)
{
	int	i;
	int	temp;

	i = *top_a;
	temp = stack_a[i];
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[i] = temp;
	i = *top_b;
	temp = stack_b[i];
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[i] = temp;
	write(1, "rr\n", 3);
	return (1);
}
