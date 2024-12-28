/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:45:01 by osadeddi          #+#    #+#             */
/*   Updated: 2024/10/31 20:24:28 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(int *stack_a, int *top_a)
{
	int	temp;

	temp = stack_a[*top_a];
	stack_a[*top_a] = stack_a[*top_a - 1];
	stack_a[*top_a - 1] = temp;
	write(1, "sa\n", 3);
}

void	swap_b(int *stack_b, int *top_b)
{
	int	temp;

	temp = stack_b[*top_b];
	stack_b[*top_b] = stack_b[*top_b - 1];
	stack_b[*top_b - 1] = temp;
	write(1, "sb\n", 3);
}

void	swap_s(int *stack_a, int *stack_b, int *top_a, int *top_b)
{
	int	temp;

	temp = stack_a[*top_a];
	stack_a[*top_a] = stack_a[*top_a - 1];
	stack_a[*top_a - 1] = temp;
	temp = stack_b[*top_b];
	stack_b[*top_b] = stack_b[*top_b - 1];
	stack_b[*top_b - 1] = temp;
	write(1, "ss\n", 3);
}
