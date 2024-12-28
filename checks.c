/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:49:07 by osadeddi          #+#    #+#             */
/*   Updated: 2024/10/28 17:03:00 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int *stack_a, int top_a)
{
	int	i;

	i = 0;
	while (i < top_a && stack_a[i] > stack_a[i + 1])
		i++;
	if (i == top_a)
		return (1);
	return (0);
}

static void	median_2(int *temp, int j)
{
	int	temp2;

	if (temp[j] > temp[j + 1])
	{
		temp2 = temp[j];
		temp[j] = temp[j + 1];
		temp[j + 1] = temp2;
	}
}

int	mid_a(int *stack, int top)
{
	int	*temp;
	int	i;
	int	j;
	int	median;

	i = 0;
	j = 0;
	temp = malloc(sizeof(int) * (top + 1));
	while (i <= top)
		temp[j++] = stack[i++];
	i = 0;
	while (i < top)
	{
		j = 0;
		while (j < top)
			median_2(temp, j++);
		i++;
	}
	if (top % 2 == 0)
		median = temp[top / 2];
	else
		median = temp[(top / 2) + 1];
	return (free(temp), median);
}

int	mid_b(int *stack, int top)
{
	int	*temp;
	int	i;
	int	j;
	int	median;

	i = 0;
	j = 0;
	temp = malloc(sizeof(int) * (top + 1));
	while (i <= top)
		temp[j++] = stack[i++];
	i = 0;
	while (i < top)
	{
		j = 0;
		while (j < top)
			median_2(temp, j++);
		i++;
	}
	median = temp[top / 2];
	return (free(temp), median);
}
