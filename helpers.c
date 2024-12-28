/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:22:58 by osadeddi          #+#    #+#             */
/*   Updated: 2024/10/27 18:31:39 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunk_count(int a)
{
	int	chunks;

	chunks = 0;
	while (a > 0)
	{
		a /= 2;
		chunks++;
	}
	return (chunks);
}

int	check_rotation_b(int *stack, int top, int mid)
{
	int	i;
	int	j;

	i = 0;
	j = top;
	while (i <= top)
	{
		if (stack[i] > mid)
			break ;
		i++;
	}
	while (j > 0)
	{
		if (stack[j] > mid)
			break ;
		j--;
	}
	if (top - j < i + 1)
		return (1);
	return (0);
}

int	check_rotation_a(int *stack, int top, int mid)
{
	int	i;
	int	j;

	i = 0;
	j = top;
	while (i <= top)
	{
		if (stack[i] < mid)
			break ;
		i++;
	}
	while (j > 0)
	{
		if (stack[j] < mid)
			break ;
		j--;
	}
	if (top - j < i + 1)
		return (1);
	return (0);
}

int	is_smallest(int *stack, int top, int j)
{
	int	i;

	i = 0;
	while (stack[i] > j)
		i++;
	if (i == top)
		return (1);
	return (0);
}
